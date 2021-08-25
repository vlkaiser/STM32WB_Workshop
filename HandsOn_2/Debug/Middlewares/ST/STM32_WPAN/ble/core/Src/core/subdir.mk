################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/ST/STM32_WPAN/ble/core/Src/core/ble_gap_aci.c \
../Middlewares/ST/STM32_WPAN/ble/core/Src/core/ble_gatt_aci.c \
../Middlewares/ST/STM32_WPAN/ble/core/Src/core/ble_hal_aci.c \
../Middlewares/ST/STM32_WPAN/ble/core/Src/core/ble_hci_le.c \
../Middlewares/ST/STM32_WPAN/ble/core/Src/core/ble_l2cap_aci.c \
../Middlewares/ST/STM32_WPAN/ble/core/Src/core/osal.c 

OBJS += \
./Middlewares/ST/STM32_WPAN/ble/core/Src/core/ble_gap_aci.o \
./Middlewares/ST/STM32_WPAN/ble/core/Src/core/ble_gatt_aci.o \
./Middlewares/ST/STM32_WPAN/ble/core/Src/core/ble_hal_aci.o \
./Middlewares/ST/STM32_WPAN/ble/core/Src/core/ble_hci_le.o \
./Middlewares/ST/STM32_WPAN/ble/core/Src/core/ble_l2cap_aci.o \
./Middlewares/ST/STM32_WPAN/ble/core/Src/core/osal.o 

C_DEPS += \
./Middlewares/ST/STM32_WPAN/ble/core/Src/core/ble_gap_aci.d \
./Middlewares/ST/STM32_WPAN/ble/core/Src/core/ble_gatt_aci.d \
./Middlewares/ST/STM32_WPAN/ble/core/Src/core/ble_hal_aci.d \
./Middlewares/ST/STM32_WPAN/ble/core/Src/core/ble_hci_le.d \
./Middlewares/ST/STM32_WPAN/ble/core/Src/core/ble_l2cap_aci.d \
./Middlewares/ST/STM32_WPAN/ble/core/Src/core/osal.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/ST/STM32_WPAN/ble/core/Src/core/ble_gap_aci.o: ../Middlewares/ST/STM32_WPAN/ble/core/Src/core/ble_gap_aci.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER '-DOPENTHREAD_CONFIG_FILE=<openthread_api_config_ftd.h>' -DDEBUG -DSTM32WB55xx -c -I../Core/Inc -I../Drivers/STM32WBxx_HAL_Driver/Inc -I../Drivers/STM32WBxx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32WBxx/Include -I../Drivers/CMSIS/Include -I../STM32_WPAN/App -I../Middlewares/ST/STM32_WPAN -I../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread -I../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/tl -I../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/shci -I../Middlewares/ST/STM32_WPAN/utilities -I../Middlewares/ST/STM32_WPAN/ble -I../Middlewares/ST/STM32_WPAN/ble/core/Inc -I../Middlewares/ST/STM32_WPAN/ble/core/Inc/core -I../Middlewares/ST/STM32_WPAN/ble/core/Src/core -I../Middlewares/ST/STM32_WPAN/ble/core/Src/blesvc -I../Middlewares/ST/STM32_WPAN/ble/core/Inc/blesvc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/ST/STM32_WPAN/ble/core/Src/core/ble_gap_aci.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/ST/STM32_WPAN/ble/core/Src/core/ble_gatt_aci.o: ../Middlewares/ST/STM32_WPAN/ble/core/Src/core/ble_gatt_aci.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER '-DOPENTHREAD_CONFIG_FILE=<openthread_api_config_ftd.h>' -DDEBUG -DSTM32WB55xx -c -I../Core/Inc -I../Drivers/STM32WBxx_HAL_Driver/Inc -I../Drivers/STM32WBxx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32WBxx/Include -I../Drivers/CMSIS/Include -I../STM32_WPAN/App -I../Middlewares/ST/STM32_WPAN -I../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread -I../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/tl -I../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/shci -I../Middlewares/ST/STM32_WPAN/utilities -I../Middlewares/ST/STM32_WPAN/ble -I../Middlewares/ST/STM32_WPAN/ble/core/Inc -I../Middlewares/ST/STM32_WPAN/ble/core/Inc/core -I../Middlewares/ST/STM32_WPAN/ble/core/Src/core -I../Middlewares/ST/STM32_WPAN/ble/core/Src/blesvc -I../Middlewares/ST/STM32_WPAN/ble/core/Inc/blesvc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/ST/STM32_WPAN/ble/core/Src/core/ble_gatt_aci.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/ST/STM32_WPAN/ble/core/Src/core/ble_hal_aci.o: ../Middlewares/ST/STM32_WPAN/ble/core/Src/core/ble_hal_aci.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER '-DOPENTHREAD_CONFIG_FILE=<openthread_api_config_ftd.h>' -DDEBUG -DSTM32WB55xx -c -I../Core/Inc -I../Drivers/STM32WBxx_HAL_Driver/Inc -I../Drivers/STM32WBxx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32WBxx/Include -I../Drivers/CMSIS/Include -I../STM32_WPAN/App -I../Middlewares/ST/STM32_WPAN -I../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread -I../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/tl -I../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/shci -I../Middlewares/ST/STM32_WPAN/utilities -I../Middlewares/ST/STM32_WPAN/ble -I../Middlewares/ST/STM32_WPAN/ble/core/Inc -I../Middlewares/ST/STM32_WPAN/ble/core/Inc/core -I../Middlewares/ST/STM32_WPAN/ble/core/Src/core -I../Middlewares/ST/STM32_WPAN/ble/core/Src/blesvc -I../Middlewares/ST/STM32_WPAN/ble/core/Inc/blesvc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/ST/STM32_WPAN/ble/core/Src/core/ble_hal_aci.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/ST/STM32_WPAN/ble/core/Src/core/ble_hci_le.o: ../Middlewares/ST/STM32_WPAN/ble/core/Src/core/ble_hci_le.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER '-DOPENTHREAD_CONFIG_FILE=<openthread_api_config_ftd.h>' -DDEBUG -DSTM32WB55xx -c -I../Core/Inc -I../Drivers/STM32WBxx_HAL_Driver/Inc -I../Drivers/STM32WBxx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32WBxx/Include -I../Drivers/CMSIS/Include -I../STM32_WPAN/App -I../Middlewares/ST/STM32_WPAN -I../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread -I../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/tl -I../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/shci -I../Middlewares/ST/STM32_WPAN/utilities -I../Middlewares/ST/STM32_WPAN/ble -I../Middlewares/ST/STM32_WPAN/ble/core/Inc -I../Middlewares/ST/STM32_WPAN/ble/core/Inc/core -I../Middlewares/ST/STM32_WPAN/ble/core/Src/core -I../Middlewares/ST/STM32_WPAN/ble/core/Src/blesvc -I../Middlewares/ST/STM32_WPAN/ble/core/Inc/blesvc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/ST/STM32_WPAN/ble/core/Src/core/ble_hci_le.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/ST/STM32_WPAN/ble/core/Src/core/ble_l2cap_aci.o: ../Middlewares/ST/STM32_WPAN/ble/core/Src/core/ble_l2cap_aci.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER '-DOPENTHREAD_CONFIG_FILE=<openthread_api_config_ftd.h>' -DDEBUG -DSTM32WB55xx -c -I../Core/Inc -I../Drivers/STM32WBxx_HAL_Driver/Inc -I../Drivers/STM32WBxx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32WBxx/Include -I../Drivers/CMSIS/Include -I../STM32_WPAN/App -I../Middlewares/ST/STM32_WPAN -I../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread -I../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/tl -I../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/shci -I../Middlewares/ST/STM32_WPAN/utilities -I../Middlewares/ST/STM32_WPAN/ble -I../Middlewares/ST/STM32_WPAN/ble/core/Inc -I../Middlewares/ST/STM32_WPAN/ble/core/Inc/core -I../Middlewares/ST/STM32_WPAN/ble/core/Src/core -I../Middlewares/ST/STM32_WPAN/ble/core/Src/blesvc -I../Middlewares/ST/STM32_WPAN/ble/core/Inc/blesvc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/ST/STM32_WPAN/ble/core/Src/core/ble_l2cap_aci.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/ST/STM32_WPAN/ble/core/Src/core/osal.o: ../Middlewares/ST/STM32_WPAN/ble/core/Src/core/osal.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER '-DOPENTHREAD_CONFIG_FILE=<openthread_api_config_ftd.h>' -DDEBUG -DSTM32WB55xx -c -I../Core/Inc -I../Drivers/STM32WBxx_HAL_Driver/Inc -I../Drivers/STM32WBxx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32WBxx/Include -I../Drivers/CMSIS/Include -I../STM32_WPAN/App -I../Middlewares/ST/STM32_WPAN -I../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread -I../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/tl -I../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/shci -I../Middlewares/ST/STM32_WPAN/utilities -I../Middlewares/ST/STM32_WPAN/ble -I../Middlewares/ST/STM32_WPAN/ble/core/Inc -I../Middlewares/ST/STM32_WPAN/ble/core/Inc/core -I../Middlewares/ST/STM32_WPAN/ble/core/Src/core -I../Middlewares/ST/STM32_WPAN/ble/core/Src/blesvc -I../Middlewares/ST/STM32_WPAN/ble/core/Inc/blesvc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/ST/STM32_WPAN/ble/core/Src/core/osal.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

