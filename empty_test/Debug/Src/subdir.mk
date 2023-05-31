################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU ARM Embedded (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Esp_program.c \
../Src/GPIO_program.c \
../Src/RCC_program.c \
../Src/STk_program.c \
../Src/USART_program.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/Esp_program.o \
./Src/GPIO_program.o \
./Src/RCC_program.o \
./Src/STk_program.o \
./Src/USART_program.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/Esp_program.d \
./Src/GPIO_program.d \
./Src/RCC_program.d \
./Src/STk_program.d \
./Src/USART_program.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/Esp_program.cyclo ./Src/Esp_program.d ./Src/Esp_program.o ./Src/Esp_program.su ./Src/GPIO_program.cyclo ./Src/GPIO_program.d ./Src/GPIO_program.o ./Src/GPIO_program.su ./Src/RCC_program.cyclo ./Src/RCC_program.d ./Src/RCC_program.o ./Src/RCC_program.su ./Src/STk_program.cyclo ./Src/STk_program.d ./Src/STk_program.o ./Src/STk_program.su ./Src/USART_program.cyclo ./Src/USART_program.d ./Src/USART_program.o ./Src/USART_program.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

