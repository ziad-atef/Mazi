cmake_minimum_required(VERSION 3.15.3)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR ARM)

if(MINGW OR CYGWIN OR WIN32)
    set(UTIL_SEARCH_CMD where)
elseif(UNIX OR APPLE)
    set(UTIL_SEARCH_CMD which)
endif()

set(TOOLCHAIN_PREFIX arm-none-eabi-)
set(TOOLCHAIN_PATH "/opt/gcc-arm-none-eabi/bin/")
execute_process(
  COMMAND ${UTIL_SEARCH_CMD} ${TOOLCHAIN_PREFIX}gcc
  OUTPUT_VARIABLE BINUTILS_PATH
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

get_filename_component(ARM_TOOLCHAIN_DIR ${BINUTILS_PATH} DIRECTORY)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(CMAKE_C_COMPILER ${TOOLCHAIN_PATH}arm-none-eabi-gcc)
set(CMAKE_ASM_COMPILER ${TOOLCHAIN_PATH}arm-none-eabi-as)
set(CMAKE_CXX_COMPILER ${TOOLCHAIN_PATH}arm-none-eabi-g++)

set(CMAKE_OBJCOPY ${TOOLCHAIN_PATH}arm-none-eabi-objcopy CACHE INTERNAL "objcopy tool")
set(CMAKE_SIZE_UTIL ${TOOLCHAIN_PATH}arm-none-eabi-size CACHE INTERNAL "size tool")

set(CMAKE_FIND_ROOT_PATH ${BINUTILS_PATH})
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

project(stm32-blupill C ASM)

# set(CMAKE_C_STANDARD 17)
# set(CMAKE_C_STANDARD_REQUIRED ON)
# set(CMAKE_C_EXTENSIONS OFF)


include_directories("${CMAKE_SOURCE_DIR}/Include" "${CMAKE_SOURCE_DIR}/Drivers")

set(STM32_FILES
    Drivers/ADC/ADC.c
    Drivers/ADC/ADC.h
    Drivers/EXTI/EXTINT.c
    Drivers/EXTI/EXTINT.h
    Drivers/GPIO/_HAL_GPIO.c
    Drivers/GPIO/_HAL_GPIO.h
    Drivers/Motors/Motors.c
    Drivers/Motors/Motors.h
    Drivers/PWM/PWM.c
    Drivers/PWM/PWM.h
    Drivers/Sensors/Sensors.c
    Drivers/Sensors/Sensors.h
    Drivers/Maze/Maze.c
    Drivers/Maze/Maze.h
    Includes/CMSIS-Include/arm_common_tables.h
    Includes/CMSIS-Include/arm_const_structs.h
    Includes/CMSIS-Include/arm_math.h
    Includes/CMSIS-Include/cmsis_armcc_V6.h
    Includes/CMSIS-Include/cmsis_armcc.h
    Includes/CMSIS-Include/cmsis_gcc.h
    Includes/CMSIS-Include/core_cm0.h
    Includes/CMSIS-Include/core_cm0plus.h
    Includes/CMSIS-Include/core_cm3.h
    Includes/CMSIS-Include/core_cm4.h
    Includes/CMSIS-Include/core_cm7.h
    Includes/CMSIS-Include/core_cmFunc.h
    Includes/CMSIS-Include/core_cmInstr.h
    Includes/CMSIS-Include/core_cmSimd.h
    Includes/CMSIS-Include/core_sc000.h
    Includes/CMSIS-Include/core_sc300.h
    Includes/stm32/stm32f10x_conf.h
    Includes/stm32/stm32f10x.h
    Includes/stm32/system_stm32f10x.h
    Includes/Common_Macros.h
    Includes/Platform_Types.h
    Includes/Std_Types.h
    Includes/systick_time.c
    Includes/systick_time.h
    main.c
    )
    
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/arm-none-eabi-gcc.cmake")
set(EXECUTABLE ${PROJECT_NAME}.elf)
add_executable(${EXECUTABLE} ${STM32_FILES})

target_compile_definitions(${EXECUTABLE} PRIVATE
        -DUSE_HAL_DRIVER
        -DSTM32F413xx
        )
target_include_directories(${EXECUTABLE} PRIVATE 
        Mazi/Includes
        Mazi/Drivers
)
add_compile_options(-mcpu=cortex-m3)
add_compile_options(-mthumb)
add_compile_options(-mfpu=fpv4-sp-d16)
add_compile_options(-mfloat-abi=hard)
add_compile_options(-Og)
add_compile_options(-Wall)
add_compile_options(-fdata-sections)
add_compile_options(-ffunction-sections)
add_compile_options(-march=arm-v7e-m)

target_link_options(${EXECUTABLE} PRIVATE
-mfpu=fpv4-sp-d16
-mfloat-abi=hard
--specs=nano.specs
--specs=nosys.specs
-lc
-lm
-lnosys
-Wl,-Map=${PROJECT_NAME}.map,--cref
-Wl,--gc-sections
)
set(LINK_SCRIPT "${CMAKE_SOURCE_DIR}/STM32F103C8TX_FLASH.ld")
set(CMAKE_EXE_LINKER_FLAGS "-T ${LINK_SCRIPT}")
set(CMAKE_C_FLAGS "-ffreestanding -mthumb -mcpu=cortex-m3")

# # Add files to SOURCE_FILES

# # Cross-compiling settings
# set(CMAKE_C_IMPLICIT_LINK_LIBRARIES "")
# set(CMAKE_C_IMPLICIT_LINK_DIRECTORIES "")

# # Output
# set_target_properties(${PROJECT_NAME}.elf PROPERTIES LINK_DEPENDS "${LINK_SCRIPT}")
# set_target_properties(${PROJECT_NAME}.elf PROPERTIES SUFFIX "")
# add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD COMMAND "${ARM_GCC_BIN_DIR}/arm-none-eabi-objcopy" -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.bin)