# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /media/passantabdelgalil/D/GitHub/Mazi

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/passantabdelgalil/D/GitHub/Mazi

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /media/passantabdelgalil/D/GitHub/Mazi/CMakeFiles /media/passantabdelgalil/D/GitHub/Mazi//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /media/passantabdelgalil/D/GitHub/Mazi/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named stm32-blupill.elf

# Build rule for target.
stm32-blupill.elf: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 stm32-blupill.elf
.PHONY : stm32-blupill.elf

# fast build rule for target.
stm32-blupill.elf/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/stm32-blupill.elf.dir/build.make CMakeFiles/stm32-blupill.elf.dir/build
.PHONY : stm32-blupill.elf/fast

Drivers/ADC/ADC.obj: Drivers/ADC/ADC.c.obj
.PHONY : Drivers/ADC/ADC.obj

# target to build an object file
Drivers/ADC/ADC.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/stm32-blupill.elf.dir/build.make CMakeFiles/stm32-blupill.elf.dir/Drivers/ADC/ADC.c.obj
.PHONY : Drivers/ADC/ADC.c.obj

Drivers/ADC/ADC.i: Drivers/ADC/ADC.c.i
.PHONY : Drivers/ADC/ADC.i

# target to preprocess a source file
Drivers/ADC/ADC.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/stm32-blupill.elf.dir/build.make CMakeFiles/stm32-blupill.elf.dir/Drivers/ADC/ADC.c.i
.PHONY : Drivers/ADC/ADC.c.i

Drivers/ADC/ADC.s: Drivers/ADC/ADC.c.s
.PHONY : Drivers/ADC/ADC.s

# target to generate assembly for a file
Drivers/ADC/ADC.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/stm32-blupill.elf.dir/build.make CMakeFiles/stm32-blupill.elf.dir/Drivers/ADC/ADC.c.s
.PHONY : Drivers/ADC/ADC.c.s

Drivers/EXTI/EXTINT.obj: Drivers/EXTI/EXTINT.c.obj
.PHONY : Drivers/EXTI/EXTINT.obj

# target to build an object file
Drivers/EXTI/EXTINT.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/stm32-blupill.elf.dir/build.make CMakeFiles/stm32-blupill.elf.dir/Drivers/EXTI/EXTINT.c.obj
.PHONY : Drivers/EXTI/EXTINT.c.obj

Drivers/EXTI/EXTINT.i: Drivers/EXTI/EXTINT.c.i
.PHONY : Drivers/EXTI/EXTINT.i

# target to preprocess a source file
Drivers/EXTI/EXTINT.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/stm32-blupill.elf.dir/build.make CMakeFiles/stm32-blupill.elf.dir/Drivers/EXTI/EXTINT.c.i
.PHONY : Drivers/EXTI/EXTINT.c.i

Drivers/EXTI/EXTINT.s: Drivers/EXTI/EXTINT.c.s
.PHONY : Drivers/EXTI/EXTINT.s

# target to generate assembly for a file
Drivers/EXTI/EXTINT.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/stm32-blupill.elf.dir/build.make CMakeFiles/stm32-blupill.elf.dir/Drivers/EXTI/EXTINT.c.s
.PHONY : Drivers/EXTI/EXTINT.c.s

Drivers/GPIO/_HAL_GPIO.obj: Drivers/GPIO/_HAL_GPIO.c.obj
.PHONY : Drivers/GPIO/_HAL_GPIO.obj

# target to build an object file
Drivers/GPIO/_HAL_GPIO.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/stm32-blupill.elf.dir/build.make CMakeFiles/stm32-blupill.elf.dir/Drivers/GPIO/_HAL_GPIO.c.obj
.PHONY : Drivers/GPIO/_HAL_GPIO.c.obj

Drivers/GPIO/_HAL_GPIO.i: Drivers/GPIO/_HAL_GPIO.c.i
.PHONY : Drivers/GPIO/_HAL_GPIO.i

# target to preprocess a source file
Drivers/GPIO/_HAL_GPIO.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/stm32-blupill.elf.dir/build.make CMakeFiles/stm32-blupill.elf.dir/Drivers/GPIO/_HAL_GPIO.c.i
.PHONY : Drivers/GPIO/_HAL_GPIO.c.i

Drivers/GPIO/_HAL_GPIO.s: Drivers/GPIO/_HAL_GPIO.c.s
.PHONY : Drivers/GPIO/_HAL_GPIO.s

# target to generate assembly for a file
Drivers/GPIO/_HAL_GPIO.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/stm32-blupill.elf.dir/build.make CMakeFiles/stm32-blupill.elf.dir/Drivers/GPIO/_HAL_GPIO.c.s
.PHONY : Drivers/GPIO/_HAL_GPIO.c.s

Drivers/Maze/Maze.obj: Drivers/Maze/Maze.c.obj
.PHONY : Drivers/Maze/Maze.obj

# target to build an object file
Drivers/Maze/Maze.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/stm32-blupill.elf.dir/build.make CMakeFiles/stm32-blupill.elf.dir/Drivers/Maze/Maze.c.obj
.PHONY : Drivers/Maze/Maze.c.obj

Drivers/Maze/Maze.i: Drivers/Maze/Maze.c.i
.PHONY : Drivers/Maze/Maze.i

# target to preprocess a source file
Drivers/Maze/Maze.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/stm32-blupill.elf.dir/build.make CMakeFiles/stm32-blupill.elf.dir/Drivers/Maze/Maze.c.i
.PHONY : Drivers/Maze/Maze.c.i

Drivers/Maze/Maze.s: Drivers/Maze/Maze.c.s
.PHONY : Drivers/Maze/Maze.s

# target to generate assembly for a file
Drivers/Maze/Maze.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/stm32-blupill.elf.dir/build.make CMakeFiles/stm32-blupill.elf.dir/Drivers/Maze/Maze.c.s
.PHONY : Drivers/Maze/Maze.c.s

Drivers/Motors/Motors.obj: Drivers/Motors/Motors.c.obj
.PHONY : Drivers/Motors/Motors.obj

# target to build an object file
Drivers/Motors/Motors.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/stm32-blupill.elf.dir/build.make CMakeFiles/stm32-blupill.elf.dir/Drivers/Motors/Motors.c.obj
.PHONY : Drivers/Motors/Motors.c.obj

Drivers/Motors/Motors.i: Drivers/Motors/Motors.c.i
.PHONY : Drivers/Motors/Motors.i

# target to preprocess a source file
Drivers/Motors/Motors.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/stm32-blupill.elf.dir/build.make CMakeFiles/stm32-blupill.elf.dir/Drivers/Motors/Motors.c.i
.PHONY : Drivers/Motors/Motors.c.i

Drivers/Motors/Motors.s: Drivers/Motors/Motors.c.s
.PHONY : Drivers/Motors/Motors.s

# target to generate assembly for a file
Drivers/Motors/Motors.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/stm32-blupill.elf.dir/build.make CMakeFiles/stm32-blupill.elf.dir/Drivers/Motors/Motors.c.s
.PHONY : Drivers/Motors/Motors.c.s

Drivers/PWM/PWM.obj: Drivers/PWM/PWM.c.obj
.PHONY : Drivers/PWM/PWM.obj

# target to build an object file
Drivers/PWM/PWM.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/stm32-blupill.elf.dir/build.make CMakeFiles/stm32-blupill.elf.dir/Drivers/PWM/PWM.c.obj
.PHONY : Drivers/PWM/PWM.c.obj

Drivers/PWM/PWM.i: Drivers/PWM/PWM.c.i
.PHONY : Drivers/PWM/PWM.i

# target to preprocess a source file
Drivers/PWM/PWM.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/stm32-blupill.elf.dir/build.make CMakeFiles/stm32-blupill.elf.dir/Drivers/PWM/PWM.c.i
.PHONY : Drivers/PWM/PWM.c.i

Drivers/PWM/PWM.s: Drivers/PWM/PWM.c.s
.PHONY : Drivers/PWM/PWM.s

# target to generate assembly for a file
Drivers/PWM/PWM.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/stm32-blupill.elf.dir/build.make CMakeFiles/stm32-blupill.elf.dir/Drivers/PWM/PWM.c.s
.PHONY : Drivers/PWM/PWM.c.s

Drivers/Sensors/Sensors.obj: Drivers/Sensors/Sensors.c.obj
.PHONY : Drivers/Sensors/Sensors.obj

# target to build an object file
Drivers/Sensors/Sensors.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/stm32-blupill.elf.dir/build.make CMakeFiles/stm32-blupill.elf.dir/Drivers/Sensors/Sensors.c.obj
.PHONY : Drivers/Sensors/Sensors.c.obj

Drivers/Sensors/Sensors.i: Drivers/Sensors/Sensors.c.i
.PHONY : Drivers/Sensors/Sensors.i

# target to preprocess a source file
Drivers/Sensors/Sensors.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/stm32-blupill.elf.dir/build.make CMakeFiles/stm32-blupill.elf.dir/Drivers/Sensors/Sensors.c.i
.PHONY : Drivers/Sensors/Sensors.c.i

Drivers/Sensors/Sensors.s: Drivers/Sensors/Sensors.c.s
.PHONY : Drivers/Sensors/Sensors.s

# target to generate assembly for a file
Drivers/Sensors/Sensors.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/stm32-blupill.elf.dir/build.make CMakeFiles/stm32-blupill.elf.dir/Drivers/Sensors/Sensors.c.s
.PHONY : Drivers/Sensors/Sensors.c.s

Includes/systick_time.obj: Includes/systick_time.c.obj
.PHONY : Includes/systick_time.obj

# target to build an object file
Includes/systick_time.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/stm32-blupill.elf.dir/build.make CMakeFiles/stm32-blupill.elf.dir/Includes/systick_time.c.obj
.PHONY : Includes/systick_time.c.obj

Includes/systick_time.i: Includes/systick_time.c.i
.PHONY : Includes/systick_time.i

# target to preprocess a source file
Includes/systick_time.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/stm32-blupill.elf.dir/build.make CMakeFiles/stm32-blupill.elf.dir/Includes/systick_time.c.i
.PHONY : Includes/systick_time.c.i

Includes/systick_time.s: Includes/systick_time.c.s
.PHONY : Includes/systick_time.s

# target to generate assembly for a file
Includes/systick_time.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/stm32-blupill.elf.dir/build.make CMakeFiles/stm32-blupill.elf.dir/Includes/systick_time.c.s
.PHONY : Includes/systick_time.c.s

main.obj: main.c.obj
.PHONY : main.obj

# target to build an object file
main.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/stm32-blupill.elf.dir/build.make CMakeFiles/stm32-blupill.elf.dir/main.c.obj
.PHONY : main.c.obj

main.i: main.c.i
.PHONY : main.i

# target to preprocess a source file
main.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/stm32-blupill.elf.dir/build.make CMakeFiles/stm32-blupill.elf.dir/main.c.i
.PHONY : main.c.i

main.s: main.c.s
.PHONY : main.s

# target to generate assembly for a file
main.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/stm32-blupill.elf.dir/build.make CMakeFiles/stm32-blupill.elf.dir/main.c.s
.PHONY : main.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... stm32-blupill.elf"
	@echo "... Drivers/ADC/ADC.obj"
	@echo "... Drivers/ADC/ADC.i"
	@echo "... Drivers/ADC/ADC.s"
	@echo "... Drivers/EXTI/EXTINT.obj"
	@echo "... Drivers/EXTI/EXTINT.i"
	@echo "... Drivers/EXTI/EXTINT.s"
	@echo "... Drivers/GPIO/_HAL_GPIO.obj"
	@echo "... Drivers/GPIO/_HAL_GPIO.i"
	@echo "... Drivers/GPIO/_HAL_GPIO.s"
	@echo "... Drivers/Maze/Maze.obj"
	@echo "... Drivers/Maze/Maze.i"
	@echo "... Drivers/Maze/Maze.s"
	@echo "... Drivers/Motors/Motors.obj"
	@echo "... Drivers/Motors/Motors.i"
	@echo "... Drivers/Motors/Motors.s"
	@echo "... Drivers/PWM/PWM.obj"
	@echo "... Drivers/PWM/PWM.i"
	@echo "... Drivers/PWM/PWM.s"
	@echo "... Drivers/Sensors/Sensors.obj"
	@echo "... Drivers/Sensors/Sensors.i"
	@echo "... Drivers/Sensors/Sensors.s"
	@echo "... Includes/systick_time.obj"
	@echo "... Includes/systick_time.i"
	@echo "... Includes/systick_time.s"
	@echo "... main.obj"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
