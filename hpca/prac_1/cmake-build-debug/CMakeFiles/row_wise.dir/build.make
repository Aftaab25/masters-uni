# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

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
CMAKE_COMMAND = /home/batman/.local/share/JetBrains/Toolbox/apps/clion/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /home/batman/.local/share/JetBrains/Toolbox/apps/clion/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/batman/masters-uni/hpca/prac_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/batman/masters-uni/hpca/prac_1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/row_wise.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/row_wise.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/row_wise.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/row_wise.dir/flags.make

CMakeFiles/row_wise.dir/row_wise_multithreading.c.o: CMakeFiles/row_wise.dir/flags.make
CMakeFiles/row_wise.dir/row_wise_multithreading.c.o: /home/batman/masters-uni/hpca/prac_1/row_wise_multithreading.c
CMakeFiles/row_wise.dir/row_wise_multithreading.c.o: CMakeFiles/row_wise.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/batman/masters-uni/hpca/prac_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/row_wise.dir/row_wise_multithreading.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/row_wise.dir/row_wise_multithreading.c.o -MF CMakeFiles/row_wise.dir/row_wise_multithreading.c.o.d -o CMakeFiles/row_wise.dir/row_wise_multithreading.c.o -c /home/batman/masters-uni/hpca/prac_1/row_wise_multithreading.c

CMakeFiles/row_wise.dir/row_wise_multithreading.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/row_wise.dir/row_wise_multithreading.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/batman/masters-uni/hpca/prac_1/row_wise_multithreading.c > CMakeFiles/row_wise.dir/row_wise_multithreading.c.i

CMakeFiles/row_wise.dir/row_wise_multithreading.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/row_wise.dir/row_wise_multithreading.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/batman/masters-uni/hpca/prac_1/row_wise_multithreading.c -o CMakeFiles/row_wise.dir/row_wise_multithreading.c.s

# Object files for target row_wise
row_wise_OBJECTS = \
"CMakeFiles/row_wise.dir/row_wise_multithreading.c.o"

# External object files for target row_wise
row_wise_EXTERNAL_OBJECTS =

row_wise: CMakeFiles/row_wise.dir/row_wise_multithreading.c.o
row_wise: CMakeFiles/row_wise.dir/build.make
row_wise: CMakeFiles/row_wise.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/batman/masters-uni/hpca/prac_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable row_wise"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/row_wise.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/row_wise.dir/build: row_wise
.PHONY : CMakeFiles/row_wise.dir/build

CMakeFiles/row_wise.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/row_wise.dir/cmake_clean.cmake
.PHONY : CMakeFiles/row_wise.dir/clean

CMakeFiles/row_wise.dir/depend:
	cd /home/batman/masters-uni/hpca/prac_1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/batman/masters-uni/hpca/prac_1 /home/batman/masters-uni/hpca/prac_1 /home/batman/masters-uni/hpca/prac_1/cmake-build-debug /home/batman/masters-uni/hpca/prac_1/cmake-build-debug /home/batman/masters-uni/hpca/prac_1/cmake-build-debug/CMakeFiles/row_wise.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/row_wise.dir/depend

