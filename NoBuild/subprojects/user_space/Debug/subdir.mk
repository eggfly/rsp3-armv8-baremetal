################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../subprojects/user_space/Debug/aux-check-link-script.cpp 

O_SRCS += \
../subprojects/user_space/Debug/aux-check-link-script.o 

OBJS += \
./subprojects/user_space/Debug/aux-check-link-script.o 

CPP_DEPS += \
./subprojects/user_space/Debug/aux-check-link-script.d 


# Each subdirectory must supply rules for building sources it contributes
subprojects/user_space/Debug/%.o: ../subprojects/user_space/Debug/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	aarch64-elf-g++ -std=c++14 -I"D:\Pool\eclipse-workspace_aarch64\newspace\raspiOS\include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


