################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
DCmotorControl.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: DCmotorControl.elf secondary-outputs

# Tool invocations
DCmotorControl.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,DCmotorControl.map -mmcu=atmega16 -o "DCmotorControl.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

DCmotorControl.lss: DCmotorControl.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S DCmotorControl.elf  >"DCmotorControl.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: DCmotorControl.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 DCmotorControl.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) DCmotorControl.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
