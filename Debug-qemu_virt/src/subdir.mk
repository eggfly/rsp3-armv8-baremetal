################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/MemoryChunk.cpp \
../src/MemoryManager.cpp \
../src/generic_util.cpp \
../src/global_variables.cpp \
../src/printk.cpp 

OBJS += \
./src/MemoryChunk.o \
./src/MemoryManager.o \
./src/generic_util.o \
./src/global_variables.o \
./src/printk.o 

CPP_DEPS += \
./src/MemoryChunk.d \
./src/MemoryManager.d \
./src/generic_util.d \
./src/global_variables.d \
./src/printk.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	aarch64-elf-g++ -std=c++14 -DARCH_IS_host -I"D:\Pool\eclipse-workspace_aarch64\chap003\include" -includecxx_macros.h -O0 -Og -g3 -pedantic -pedantic-errors -Wall -Werror -c -nostdlib -Weffc++ -Wold-style-cast -fmessage-length=0 -fmax-errors=20 -ffreestanding -fno-exceptions -fno-rtti $(USER_CXX_FLAGS) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


