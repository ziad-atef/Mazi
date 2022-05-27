cmake_minimum_required(VERSION 3.15.3)
project(stm32-blupill)

# langauge settings
enable_language(C ASM)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

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
    main.c
)

set(EXECUTABLE ${PROJECT_NAME}.out)
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
-T${CMAKE_SOURCE_DIR}/BSP/STM32F413ZHTx_FLASH.ld
-mcpu=cortex-m3
-mthumb
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
