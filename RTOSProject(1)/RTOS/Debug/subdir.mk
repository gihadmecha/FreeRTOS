################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO.c \
../DIO_Lcfg.c \
../Kernel_program.c \
../Timers.c \
../Timers_Services.c \
../main.c 

OBJS += \
./DIO.o \
./DIO_Lcfg.o \
./Kernel_program.o \
./Timers.o \
./Timers_Services.o \
./main.o 

C_DEPS += \
./DIO.d \
./DIO_Lcfg.d \
./Kernel_program.d \
./Timers.d \
./Timers_Services.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


