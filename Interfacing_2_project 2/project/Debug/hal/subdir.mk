################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../hal/buzzer.c \
../hal/lcd.c \
../hal/led.c \
../hal/ultrasonic.c 

OBJS += \
./hal/buzzer.o \
./hal/lcd.o \
./hal/led.o \
./hal/ultrasonic.o 

C_DEPS += \
./hal/buzzer.d \
./hal/lcd.d \
./hal/led.d \
./hal/ultrasonic.d 


# Each subdirectory must supply rules for building sources it contributes
hal/%.o: ../hal/%.c hal/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


