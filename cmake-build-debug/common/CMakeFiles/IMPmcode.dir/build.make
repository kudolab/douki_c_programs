# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/tetsu/dev/douki_C_programs

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/tetsu/dev/douki_C_programs/cmake-build-debug

# Include any dependencies generated for this target.
include common/CMakeFiles/IMPmcode.dir/depend.make

# Include the progress variables for this target.
include common/CMakeFiles/IMPmcode.dir/progress.make

# Include the compile flags for this target's objects.
include common/CMakeFiles/IMPmcode.dir/flags.make

common/CMakeFiles/IMPmcode.dir/src/IMPmcode.c.o: common/CMakeFiles/IMPmcode.dir/flags.make
common/CMakeFiles/IMPmcode.dir/src/IMPmcode.c.o: ../common/src/IMPmcode.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tetsu/dev/douki_C_programs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object common/CMakeFiles/IMPmcode.dir/src/IMPmcode.c.o"
	cd /Users/tetsu/dev/douki_C_programs/cmake-build-debug/common && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/IMPmcode.dir/src/IMPmcode.c.o   -c /Users/tetsu/dev/douki_C_programs/common/src/IMPmcode.c

common/CMakeFiles/IMPmcode.dir/src/IMPmcode.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/IMPmcode.dir/src/IMPmcode.c.i"
	cd /Users/tetsu/dev/douki_C_programs/cmake-build-debug/common && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/tetsu/dev/douki_C_programs/common/src/IMPmcode.c > CMakeFiles/IMPmcode.dir/src/IMPmcode.c.i

common/CMakeFiles/IMPmcode.dir/src/IMPmcode.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/IMPmcode.dir/src/IMPmcode.c.s"
	cd /Users/tetsu/dev/douki_C_programs/cmake-build-debug/common && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/tetsu/dev/douki_C_programs/common/src/IMPmcode.c -o CMakeFiles/IMPmcode.dir/src/IMPmcode.c.s

# Object files for target IMPmcode
IMPmcode_OBJECTS = \
"CMakeFiles/IMPmcode.dir/src/IMPmcode.c.o"

# External object files for target IMPmcode
IMPmcode_EXTERNAL_OBJECTS =

common/IMPmcode: common/CMakeFiles/IMPmcode.dir/src/IMPmcode.c.o
common/IMPmcode: common/CMakeFiles/IMPmcode.dir/build.make
common/IMPmcode: common/CMakeFiles/IMPmcode.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tetsu/dev/douki_C_programs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable IMPmcode"
	cd /Users/tetsu/dev/douki_C_programs/cmake-build-debug/common && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/IMPmcode.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
common/CMakeFiles/IMPmcode.dir/build: common/IMPmcode

.PHONY : common/CMakeFiles/IMPmcode.dir/build

common/CMakeFiles/IMPmcode.dir/clean:
	cd /Users/tetsu/dev/douki_C_programs/cmake-build-debug/common && $(CMAKE_COMMAND) -P CMakeFiles/IMPmcode.dir/cmake_clean.cmake
.PHONY : common/CMakeFiles/IMPmcode.dir/clean

common/CMakeFiles/IMPmcode.dir/depend:
	cd /Users/tetsu/dev/douki_C_programs/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tetsu/dev/douki_C_programs /Users/tetsu/dev/douki_C_programs/common /Users/tetsu/dev/douki_C_programs/cmake-build-debug /Users/tetsu/dev/douki_C_programs/cmake-build-debug/common /Users/tetsu/dev/douki_C_programs/cmake-build-debug/common/CMakeFiles/IMPmcode.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : common/CMakeFiles/IMPmcode.dir/depend

