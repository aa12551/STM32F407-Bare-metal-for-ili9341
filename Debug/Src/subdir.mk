################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Mydriver.c \
../Src/adc.c \
../Src/i2c.c \
../Src/main.c \
../Src/screen.c \
../Src/spi.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/systick.c \
../Src/tim.c \
../Src/uart.c 

OBJS += \
./Src/Mydriver.o \
./Src/adc.o \
./Src/i2c.o \
./Src/main.o \
./Src/screen.o \
./Src/spi.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/systick.o \
./Src/tim.o \
./Src/uart.o 

C_DEPS += \
./Src/Mydriver.d \
./Src/adc.d \
./Src/i2c.d \
./Src/main.d \
./Src/screen.d \
./Src/spi.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/systick.d \
./Src/tim.d \
./Src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -DSTM32F407xx -c -I../Inc -I"C:/Users/s94009880225/Desktop/driver pratice/driver_practice/Inc/include/Core" -I"C:/Users/s94009880225/Desktop/driver pratice/driver_practice/Inc/include/driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/Mydriver.d ./Src/Mydriver.o ./Src/adc.d ./Src/adc.o ./Src/i2c.d ./Src/i2c.o ./Src/main.d ./Src/main.o ./Src/screen.d ./Src/screen.o ./Src/spi.d ./Src/spi.o ./Src/syscalls.d ./Src/syscalls.o ./Src/sysmem.d ./Src/sysmem.o ./Src/systick.d ./Src/systick.o ./Src/tim.d ./Src/tim.o ./Src/uart.d ./Src/uart.o

.PHONY: clean-Src

