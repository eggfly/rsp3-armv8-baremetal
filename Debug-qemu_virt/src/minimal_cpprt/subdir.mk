################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/minimal_cpprt/__throw_bad_function_call.cpp \
../src/minimal_cpprt/operator_delete.cpp \
../src/minimal_cpprt/operator_new.cpp 

OBJS += \
./src/minimal_cpprt/__throw_bad_function_call.o \
./src/minimal_cpprt/operator_delete.o \
./src/minimal_cpprt/operator_new.o 

CPP_DEPS += \
./src/minimal_cpprt/__throw_bad_function_call.d \
./src/minimal_cpprt/operator_delete.d \
./src/minimal_cpprt/operator_new.d 


# Each subdirectory must supply rules for building sources it contributes
src/minimal_cpprt/%.o: ../src/minimal_cpprt/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	aarch64-elf-g++ -std=c++14 -DARCH_IS_host -I"D:\Pool\eclipse-workspace_aarch64\chap003\include" -includecxx_macros.h -O0 -Og -g3 -pedantic -pedantic-errors -Wall -Werror -c -nostdlib -Weffc++ -Wold-style-cast -fmessage-length=0 -fmax-errors=20 -ffreestanding -fno-exceptions -fno-rtti $(USER_CXX_FLAGS) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


