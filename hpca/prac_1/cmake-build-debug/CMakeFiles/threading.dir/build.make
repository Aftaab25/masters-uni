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
include CMakeFiles/threading.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/threading.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/threading.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/threading.dir/flags.make

CMakeFiles/threading.dir/threading.c.o: CMakeFiles/threading.dir/flags.make
CMakeFiles/threading.dir/threading.c.o: /home/batman/masters-uni/hpca/prac_1/threading.c
CMakeFiles/threading.dir/threading.c.o: CMakeFiles/threading.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/batman/masters-uni/hpca/prac_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/threading.dir/threading.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/threading.dir/threading.c.o -MF CMakeFiles/threading.dir/threading.c.o.d -o CMakeFiles/threading.dir/threading.c.o -c /home/batman/masters-uni/hpca/prac_1/threading.c

CMakeFiles/threading.dir/threading.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/threading.dir/threading.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/batman/masters-uni/hpca/prac_1/threading.c > CMakeFiles/threading.dir/threading.c.i

CMakeFiles/threading.dir/threading.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/threading.dir/threading.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/batman/masters-uni/hpca/prac_1/threading.c -o CMakeFiles/threading.dir/threading.c.s

# Object files for target threading
threading_OBJECTS = \
"CMakeFiles/threading.dir/threading.c.o"

# External object files for target threading
threading_EXTERNAL_OBJECTS =

threading: CMakeFiles/threading.dir/threading.c.o
threading: CMakeFiles/threading.dir/build.make
threading: CMakeFiles/threading.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/batman/masters-uni/hpca/prac_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable threading"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/threading.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/threading.dir/build: threading
.PHONY : CMakeFiles/threading.dir/build

CMakeFiles/threading.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/threading.dir/cmake_clean.cmake
.PHONY : CMakeFiles/threading.dir/clean

CMakeFiles/threading.dir/depend:
	cd /home/batman/masters-uni/hpca/prac_1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/batman/masters-uni/hpca/prac_1 /home/batman/masters-uni/hpca/prac_1 /home/batman/masters-uni/hpca/prac_1/cmake-build-debug /home/batman/masters-uni/hpca/prac_1/cmake-build-debug /home/batman/masters-uni/hpca/prac_1/cmake-build-debug/CMakeFiles/threading.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/threading.dir/depend

