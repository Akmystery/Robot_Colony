################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Generated_Code/ADC0.c" \
"../Generated_Code/ADC1.c" \
"../Generated_Code/Cpu.c" \
"../Generated_Code/FTM0.c" \
"../Generated_Code/FTM1.c" \
"../Generated_Code/FTM2.c" \
"../Generated_Code/LPTMR0.c" \
"../Generated_Code/PE_LDD.c" \
"../Generated_Code/PTA.c" \
"../Generated_Code/PTB.c" \
"../Generated_Code/PTC.c" \
"../Generated_Code/PTD.c" \
"../Generated_Code/PTE.c" \
"../Generated_Code/SysTick.c" \
"../Generated_Code/UART0.c" \
"../Generated_Code/UART1.c" \
"../Generated_Code/UART2.c" \
"../Generated_Code/Vectors.c" \

C_SRCS += \
../Generated_Code/ADC0.c \
../Generated_Code/ADC1.c \
../Generated_Code/Cpu.c \
../Generated_Code/FTM0.c \
../Generated_Code/FTM1.c \
../Generated_Code/FTM2.c \
../Generated_Code/LPTMR0.c \
../Generated_Code/PE_LDD.c \
../Generated_Code/PTA.c \
../Generated_Code/PTB.c \
../Generated_Code/PTC.c \
../Generated_Code/PTD.c \
../Generated_Code/PTE.c \
../Generated_Code/SysTick.c \
../Generated_Code/UART0.c \
../Generated_Code/UART1.c \
../Generated_Code/UART2.c \
../Generated_Code/Vectors.c \

OBJS += \
./Generated_Code/ADC0.o \
./Generated_Code/ADC1.o \
./Generated_Code/Cpu.o \
./Generated_Code/FTM0.o \
./Generated_Code/FTM1.o \
./Generated_Code/FTM2.o \
./Generated_Code/LPTMR0.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/PTA.o \
./Generated_Code/PTB.o \
./Generated_Code/PTC.o \
./Generated_Code/PTD.o \
./Generated_Code/PTE.o \
./Generated_Code/SysTick.o \
./Generated_Code/UART0.o \
./Generated_Code/UART1.o \
./Generated_Code/UART2.o \
./Generated_Code/Vectors.o \

C_DEPS += \
./Generated_Code/ADC0.d \
./Generated_Code/ADC1.d \
./Generated_Code/Cpu.d \
./Generated_Code/FTM0.d \
./Generated_Code/FTM1.d \
./Generated_Code/FTM2.d \
./Generated_Code/LPTMR0.d \
./Generated_Code/PE_LDD.d \
./Generated_Code/PTA.d \
./Generated_Code/PTB.d \
./Generated_Code/PTC.d \
./Generated_Code/PTD.d \
./Generated_Code/PTE.d \
./Generated_Code/SysTick.d \
./Generated_Code/UART0.d \
./Generated_Code/UART1.d \
./Generated_Code/UART2.d \
./Generated_Code/Vectors.d \

OBJS_QUOTED += \
"./Generated_Code/ADC0.o" \
"./Generated_Code/ADC1.o" \
"./Generated_Code/Cpu.o" \
"./Generated_Code/FTM0.o" \
"./Generated_Code/FTM1.o" \
"./Generated_Code/FTM2.o" \
"./Generated_Code/LPTMR0.o" \
"./Generated_Code/PE_LDD.o" \
"./Generated_Code/PTA.o" \
"./Generated_Code/PTB.o" \
"./Generated_Code/PTC.o" \
"./Generated_Code/PTD.o" \
"./Generated_Code/PTE.o" \
"./Generated_Code/SysTick.o" \
"./Generated_Code/UART0.o" \
"./Generated_Code/UART1.o" \
"./Generated_Code/UART2.o" \
"./Generated_Code/Vectors.o" \

C_DEPS_QUOTED += \
"./Generated_Code/ADC0.d" \
"./Generated_Code/ADC1.d" \
"./Generated_Code/Cpu.d" \
"./Generated_Code/FTM0.d" \
"./Generated_Code/FTM1.d" \
"./Generated_Code/FTM2.d" \
"./Generated_Code/LPTMR0.d" \
"./Generated_Code/PE_LDD.d" \
"./Generated_Code/PTA.d" \
"./Generated_Code/PTB.d" \
"./Generated_Code/PTC.d" \
"./Generated_Code/PTD.d" \
"./Generated_Code/PTE.d" \
"./Generated_Code/SysTick.d" \
"./Generated_Code/UART0.d" \
"./Generated_Code/UART1.d" \
"./Generated_Code/UART2.d" \
"./Generated_Code/Vectors.d" \

OBJS_OS_FORMAT += \
./Generated_Code/ADC0.o \
./Generated_Code/ADC1.o \
./Generated_Code/Cpu.o \
./Generated_Code/FTM0.o \
./Generated_Code/FTM1.o \
./Generated_Code/FTM2.o \
./Generated_Code/LPTMR0.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/PTA.o \
./Generated_Code/PTB.o \
./Generated_Code/PTC.o \
./Generated_Code/PTD.o \
./Generated_Code/PTE.o \
./Generated_Code/SysTick.o \
./Generated_Code/UART0.o \
./Generated_Code/UART1.o \
./Generated_Code/UART2.o \
./Generated_Code/Vectors.o \


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/ADC0.o: ../Generated_Code/ADC0.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/ADC0.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/ADC0.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/ADC1.o: ../Generated_Code/ADC1.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/ADC1.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/ADC1.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Cpu.o: ../Generated_Code/Cpu.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/Cpu.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/Cpu.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/FTM0.o: ../Generated_Code/FTM0.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/FTM0.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/FTM0.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/FTM1.o: ../Generated_Code/FTM1.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/FTM1.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/FTM1.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/FTM2.o: ../Generated_Code/FTM2.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/FTM2.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/FTM2.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/LPTMR0.o: ../Generated_Code/LPTMR0.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/LPTMR0.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/LPTMR0.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/PE_LDD.o: ../Generated_Code/PE_LDD.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/PE_LDD.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/PE_LDD.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/PTA.o: ../Generated_Code/PTA.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/PTA.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/PTA.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/PTB.o: ../Generated_Code/PTB.c
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/PTB.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/PTB.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/PTC.o: ../Generated_Code/PTC.c
	@echo 'Building file: $<'
	@echo 'Executing target #15 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/PTC.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/PTC.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/PTD.o: ../Generated_Code/PTD.c
	@echo 'Building file: $<'
	@echo 'Executing target #16 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/PTD.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/PTD.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/PTE.o: ../Generated_Code/PTE.c
	@echo 'Building file: $<'
	@echo 'Executing target #17 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/PTE.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/PTE.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/SysTick.o: ../Generated_Code/SysTick.c
	@echo 'Building file: $<'
	@echo 'Executing target #18 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/SysTick.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/SysTick.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/UART0.o: ../Generated_Code/UART0.c
	@echo 'Building file: $<'
	@echo 'Executing target #19 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/UART0.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/UART0.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/UART1.o: ../Generated_Code/UART1.c
	@echo 'Building file: $<'
	@echo 'Executing target #20 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/UART1.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/UART1.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/UART2.o: ../Generated_Code/UART2.c
	@echo 'Building file: $<'
	@echo 'Executing target #21 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/UART2.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/UART2.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Vectors.o: ../Generated_Code/Vectors.c
	@echo 'Building file: $<'
	@echo 'Executing target #22 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/Vectors.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/Vectors.o"
	@echo 'Finished building: $<'
	@echo ' '


