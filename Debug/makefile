################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/TIMER/subdir.mk
-include MCAL/MGIE/subdir.mk
-include MCAL/MEXTI/subdir.mk
-include MCAL/MDIO/subdir.mk
-include MCAL/MADC/subdir.mk
-include HAL/HLED/subdir.mk
-include HAL/HKPD/subdir.mk
-include HAL/HCLCD/subdir.mk
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
keypad_with_seven_segment_project.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: keypad_with_seven_segment_project.elf secondary-outputs

# Tool invocations
keypad_with_seven_segment_project.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,keypad_with_seven_segment_project.map -mmcu=atmega16 -o "keypad_with_seven_segment_project.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

keypad_with_seven_segment_project.lss: keypad_with_seven_segment_project.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S keypad_with_seven_segment_project.elf  >"keypad_with_seven_segment_project.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: keypad_with_seven_segment_project.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 keypad_with_seven_segment_project.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) keypad_with_seven_segment_project.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
