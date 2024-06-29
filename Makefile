##### Project #####

PROJECT			?= app
BUILD_DIR		= Build


##### Options #####

# Programmer, jlink or pyocd
FLASH_PROGRM	?= jlink


##### Toolchains #######

ARM_TOOCHAIN	?= /Applications/ArmGNUToolchain/12.2.rel1/arm-none-eabi/bin

# path to JLinkExe
JLINKEXE		?= /Applications/SEGGER/JLink_V794e/JLinkExe 
JLINK_DEVICE	?= AT32F403ACGU7
JLINK_EXT_DEVICE?= AT32F403A_EXT_TYPE2_REAMP1_16MB
# path to PyOCD
PYOCD_EXE		?= pyocd
PYOCD_DEVICE	?= _at32f403acgu7

##### Paths ############

# Link descript file for this chip
LDSCRIPT		= Libraries/cmsis/cm4/device_support/startup/gcc/linker/AT32F403AxG_FLASH.ld
# Library build flags
LIB_FLAGS		= USE_STDPERIPH_DRIVER AT32F403ACGU7

# C source folders
CDIRS	:= User \
		User/src \
		Libraries/cmsis/cm4/device_support \
		Libraries/drivers/src 
		
# C source files (if there are any single ones)
CFILES := 

# ASM source folders
ADIRS	:= User/src
# ASM single files
AFILES	:= Libraries/cmsis/cm4/device_support/startup/gcc/startup_at32f403a_407.s

# Include paths
INCLUDES	:= User \
			User/inc \
			Libraries/cmsis/cm4/core_support \
			Libraries/cmsis/cm4/device_support \
			Libraries/drivers/inc 

include ./rules.mk
