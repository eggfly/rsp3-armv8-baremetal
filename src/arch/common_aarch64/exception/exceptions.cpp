#include <arch/common_aarch64/exception/exceptions.h>
#include <arch/common_aarch64/gicv3_registers.h>
#include <def.h>
#include <IntegerFormatter.h>
#include <arch/common_aarch64/gicv3_registers.h>
#include <arch/common_aarch64/system_common_registers.h>
#include <arch/common_aarch64/timer_registers.h>
#include <asm_instructions.h>
#include <io/Output.h>
#include <arch/common_aarch64/exception/svc_call.h>
#include <schedule/PidManager.h>

__asm__(//".align  11 \n\t" // for ARM, this is lower order zero bits, but seems not working. we must get depend on the final linker script
		".text \n\t"
		".align 11 \n\t"
		".global ExceptionVectorEL1 \n\t"
		"ExceptionVectorEL1:  \n\t" // this only applies to EL1

		// **Current Exception level with SP_EL0.
		"b enterSynchronousEL1ExceptionHandle_no_prologue \n\t"
		". = ExceptionVectorEL1 + 0x080 \n\t"
		"b enterIRQEL1ExceptionHandle_no_prologue\n\t"
		". = ExceptionVectorEL1 + 0x100 \n\t"
		"b enterFIQEL1ExceptionHandle_no_prologue \n\t"
		". = ExceptionVectorEL1 + 0x180 \n\t"
		"b enterSErrorEL1ExceptionHandle_no_prologue \n\t"

		// **Current Exception level with SP_ELx, x>0
		". = ExceptionVectorEL1 + 0x200 \n\t" //for EL1-->EL1,syn=0x200
		"b enterSynchronousEL1ExceptionHandle_no_prologue \n\t"  // just call for it
		". = ExceptionVectorEL1 + 0x280 \n\t" // IRQ or vIRQ
		"b enterIRQEL1ExceptionHandle_no_prologue \n\t"
		". = ExceptionVectorEL1 + 0x300 \n\t" // FIQ or vFIQ
		"b enterFIQEL1ExceptionHandle_no_prologue \n\t"
 		". = ExceptionVectorEL1 + 0x380 \n\t" // SError or vSError
		"b enterSErrorEL1ExceptionHandle_no_prologue \n\t"

		// ** aarch64下，从低异常级而来的异常
		". = ExceptionVectorEL1 + 0x400 \n\t"
		"b enterSynchronousEL1ExceptionHandle_no_prologue \n\t"
		". = ExceptionVectorEL1 + 0x480 \n\t"
		"b enterIRQEL1ExceptionHandle_no_prologue\n\t"
		". = ExceptionVectorEL1 + 0x500 \n\t"
		"b enterFIQEL1ExceptionHandle_no_prologue\n\t"
		". = ExceptionVectorEL1 + 0x580 \n\t"
		"b enterSErrorEL1ExceptionHandle_no_prologue\n\t"


		// ** aarch32下, 从低异常级而来的异常

		// 异常表的最后一项
		". = ExceptionVectorEL1 + 0x780 \n\t"
		// 为最后一项预留128字节的空间
		". =. + 0x80 \n\t"
		);
// 从高地址到低地址依次是 x0,x1,x2,....x29,x30,  x30通常也称为LR寄存器
#define SAVE_REGS() \
	__asm__ __volatile__("stp x29,x30,[sp,#-16]! \n\t"); \
	__asm__ __volatile__("stp x27,x28,[sp,#-16]! \n\t"); \
	__asm__ __volatile__("stp x25,x26,[sp,#-16]! \n\t"); \
	__asm__ __volatile__("stp x23,x24,[sp,#-16]! \n\t"); \
	__asm__ __volatile__("stp x21,x22,[sp,#-16]! \n\t"); \
	__asm__ __volatile__("stp x19,x20,[sp,#-16]! \n\t"); \
	__asm__ __volatile__("stp x17,x18,[sp,#-16]! \n\t"); \
	__asm__ __volatile__("stp x15,x16,[sp,#-16]! \n\t"); \
	__asm__ __volatile__("stp x13,x14,[sp,#-16]! \n\t"); \
	__asm__ __volatile__("stp x11,x12,[sp,#-16]! \n\t"); \
	__asm__ __volatile__("stp x9,x10,[sp,#-16]! \n\t"); \
	__asm__ __volatile__("stp x7,x8,[sp,#-16]! \n\t"); \
	__asm__ __volatile__("stp x5,x6,[sp,#-16]! \n\t"); \
	__asm__ __volatile__("stp x3,x4,[sp,#-16]! \n\t"); \
	__asm__ __volatile__("stp x1,x2,[sp,#-16]! \n\t"); \
	__asm__ __volatile__("str x0,[sp,#-8]! \n\t")
#define RESTORE_REGS() \
	__asm__ __volatile__("ldr x0,[sp],#8 \n\t"); \
	__asm__ __volatile__("ldp x1,x2,[sp],#16 \n\t"); \
	__asm__ __volatile__("ldp x3,x4,[sp],#16 \n\t"); \
	__asm__ __volatile__("ldp x5,x6,[sp],#16 \n\t"); \
	__asm__ __volatile__("ldp x7,x8,[sp],#16 \n\t"); \
	__asm__ __volatile__("ldp x9,x10,[sp],#16 \n\t"); \
	__asm__ __volatile__("ldp x11,x12,[sp],#16 \n\t"); \
	__asm__ __volatile__("ldp x13,x14,[sp],#16 \n\t"); \
	__asm__ __volatile__("ldp x15,x16,[sp],#16 \n\t"); \
	__asm__ __volatile__("ldp x17,x18,[sp],#16 \n\t"); \
	__asm__ __volatile__("ldp x19,x20,[sp],#16 \n\t"); \
	__asm__ __volatile__("ldp x21,x22,[sp],#16 \n\t"); \
	__asm__ __volatile__("ldp x23,x24,[sp],#16 \n\t"); \
	__asm__ __volatile__("ldp x25,x26,[sp],#16 \n\t"); \
	__asm__ __volatile__("ldp x27,x28,[sp],#16 \n\t"); \
	__asm__ __volatile__("ldp x29,x30,[sp],#16 \n\t");


// on entering, we must use svc or other ExceptionGeneration instructions,on leaving,we must use eret, no magics
void enterSynchronousEL1ExceptionHandle()
{
	FORCE_CODE_COHERENT_WITH_VIEW();
	__asm__("enterSynchronousEL1ExceptionHandle_no_prologue: \n\t");
	SAVE_REGS();
	__asm__(
		"mov     x0, sp \n\t"
		"bl      SynchronousEL1Handle \n\t"
	);
	RESTORE_REGS();
	asm_eret();
}
void enterIRQEL1ExceptionHandle()
{
	FORCE_CODE_COHERENT_WITH_VIEW();
	__asm__("enterIRQEL1ExceptionHandle_no_prologue: \n\t");
	SAVE_REGS();
	__asm__(
		"bl      IRQEL1Handle \n\t"
	);
	RESTORE_REGS();
	asm_eret();
}
void enterFIQEL1ExceptionHandle()
{
	FORCE_CODE_COHERENT_WITH_VIEW();
	__asm__("enterFIQEL1ExceptionHandle_no_prologue: \n\t");
	SAVE_REGS();
	__asm__(
		"bl      FIQEL1Handle \n\t"
	);
	RESTORE_REGS();
	asm_eret();
}

void enterSErrorEL1ExceptionHandle()
{
	FORCE_CODE_COHERENT_WITH_VIEW();
	__asm__("enterSErrorEL1ExceptionHandle_no_prologue: \n\t");
	SAVE_REGS();
	__asm__(
		"bl      SErrorEL1Handle \n\t"
	);
	RESTORE_REGS();
	asm_eret();
}

//========the C++ handles================
// NOTE:no eret is needed, not need to save anything



extern "C"
void SynchronousEL1Handle(uint64_t *savedRegisters)//savedRegisters[31], from X30-X0
{
	kout <<INFO<< "processing SynchronousEL1 \n";
	auto curEL = RegCurrentEL::read();
	kout << INFO << "CurrentEL = " << curEL.EL << "\n";
	uint32_t fromEL = RegSPSR_EL1::read().EL;
	kout << INFO << "From EL = " << fromEL << "\n";

	auto far = RegFAR_EL1::read();
	auto elr = RegELR_EL1::read();
	auto spsr = RegSPSR_EL1::read();
	auto esr = RegESR_EL1::read();
	esr.dump();
	elr.dump();
	far.dump();
	spsr.dump();
	if(esr.EC == ExceptionClass::UNDEF_INST)
	{
		kout << INFO << "Undefined instruction\n";
		kout << INFO << "not processing it\n";
		asm_wfe_loop();
	}

	else if(esr.EC == ExceptionClass::SVC_AA64)
	{
		uint16_t svcNumber = lowerMaskBits(16)&esr.ISS;
		kout << INFO << "svc targeting number : " << svcNumber<< "\n";
		if(svcNumber== SvcFunc::puts) //  需要参数，参数保存在哪里？保存在栈上
		{
			auto str = reinterpret_cast<const char*>(savedRegisters[0]);
			auto len = reinterpret_cast<size_t>(savedRegisters[1]);
			auto printkChars = kout.print(str, len);
			savedRegisters[0] = printkChars; // savedResult
		}else if(svcNumber == SvcFunc::killProcess){
			kout << "killing Process \n";
			// 收回资源： 占用的内存，占用的pid，打开的文件等， 将其从进程队列中清除
			PidType pid = static_cast<PidType>(savedRegisters[0]);
			int     status = *reinterpret_cast<int*>(savedRegisters+1);
			(void)status;
			if(pid == CURRENT_PID)
			{

			}
			asm_wfe_loop();
		}
	}else if(esr.EC == ExceptionClass::INSTR_ABORT_LOWER_EL){
		kout << "Instruction Abort \n";
		uint64_t ifsc=getBits(esr.ISS,0,5);
		(void)ifsc;// 7=level3 translation fault
					// 11=level3 access fault
		int   farNotValid = getBits(esr.ISS,10,10);
		kout << "farNotValid?" << farNotValid << "\n";
		if(!farNotValid)
		{
			kout << INFO << "FAR = " << RegFAR_EL1::read().faultAddr << "\n";
		}
		kout << "not processing it\n";
		asm_wfe_loop();
	}else if(esr.EC == ExceptionClass::DATA_ABORT_LOWER_EL){
		kout << INFO << "Data Abort\n";
		kout << INFO << "not processing it\n";
		asm_wfe_loop();
	}else if(esr.EC == ExceptionClass::PC_ALIGNMENT_FAULT){
		kout << INFO << "PC alignment fault\n";
		kout << INFO << "not processing it\n";
		asm_wfe_loop();
	}else if(esr.EC == ExceptionClass::SP_ALIGNMENT_FAULT){
		kout << INFO << "SP alignment fault\n";
		kout << INFO << "not processing it \n";
		asm_wfe_loop();
	}else if(esr.EC == ExceptionClass::SERROR_INTERRUPT){
		kout << INFO << "SError interrupt\n";
		kout << INFO << "not processing it\n";
		asm_wfe_loop();
	}else{
		kout << INFO << "Currently unhandled exception\n";
		asm_wfe_loop();
	}
}

extern "C"
void IRQEL1Handle()
{
	kout << INFO <<"processing IRQ_EL1 \n";

	auto iar = RegICC_IAR1_EL1::read(); // NOTE:by reading it, we  acknowledged it.So it will change to 1023 after this read
	RegICC_RPR_EL1::read().dump();
	RegICC_PMR_EL1::read().dump();
	RegGICD_ISACTIVER0::read().dump();
	RegGICR_ISACTIVER0::read().dump();
	RegGICD_ISPENDR0::read().dump();
	RegGICR_ISPENDR0::read().dump();
	RegISR_EL1::read().dump();
	iar.dump();
	RegICC_EOIR1_EL1 eoi{0};
	eoi.INTID = iar.INTID;
	eoi.write();

	// write here to make sure that the event come in order
	if(iar.INTID == 27) // virtual timer event stream
	{
		RegCNTV_CTL_EL0 ctl {0};
		ctl.ENABLE = 0;
		ctl.write();
		ctl.ENABLE = 1;
		ctl.IMASK = 0;
		ctl.write();
	}else if(iar.INTID == 30)//el1 physical timer interrupt
	{
//		RegCNTP_CTL_EL0 ctl {0};
//		ctl.ENABLE = 0;
//		writeRegCNTP_CTL_EL0(ctl);

		// rewrite this compare value will generate interrupt again
		auto cmpvPhy1 = RegCNTP_CVAL_EL0::read();
		cmpvPhy1.dump();
	//	cmpvPhy1.CompareValue = 0x2a3a4a5a;
		cmpvPhy1.CompareValue += 0x3a4a5a;
		cmpvPhy1.write();

//		ctl.ENABLE = 1;
//		ctl.IMASK = 0;
//		writeRegCNTP_CTL_EL0(ctl);
	}
}


//The CPU interface has two IARs. Reading the IAR returns the INTID, and advances the interrupt
//state machine. In a typical interrupt handler, one of the first steps when handling an interrupt is to
//read one of the IARs

extern "C"
void FIQEL1Handle()
{
	kout << INFO <<"processing FIQ_EL1 \n";
    RegICC_RPR_EL1::read().dump();
	auto iar = RegICC_IAR0_EL1::read();
	iar.dump();
	RegICC_EOIR0_EL1 eoi{0};
	eoi.INTID = iar.INTID; // this must be correctly done, else eret will causes errors
	eoi.write();
}

extern "C"
void SErrorEL1Handle()
{
	kout << INFO << "processing SErrorEL1 \n";
}





