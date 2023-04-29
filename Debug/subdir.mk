################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APPL.c \
../DIO_PROGRAM.c \
../EXTI_PROGRAM.c \
../GI_PROGRAM.c 

OBJS += \
./APPL.o \
./DIO_PROGRAM.o \
./EXTI_PROGRAM.o \
./GI_PROGRAM.o 

C_DEPS += \
./APPL.d \
./DIO_PROGRAM.d \
./EXTI_PROGRAM.d \
./GI_PROGRAM.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


