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
include CMakeFiles/scaling_max_instant_amp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/scaling_max_instant_amp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/scaling_max_instant_amp.dir/flags.make

CMakeFiles/scaling_max_instant_amp.dir/scaling_max_instant_amp.c.o: CMakeFiles/scaling_max_instant_amp.dir/flags.make
CMakeFiles/scaling_max_instant_amp.dir/scaling_max_instant_amp.c.o: ../scaling_max_instant_amp.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tetsu/dev/douki_C_programs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/scaling_max_instant_amp.dir/scaling_max_instant_amp.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/scaling_max_instant_amp.dir/scaling_max_instant_amp.c.o   -c /Users/tetsu/dev/douki_C_programs/scaling_max_instant_amp.c

CMakeFiles/scaling_max_instant_amp.dir/scaling_max_instant_amp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/scaling_max_instant_amp.dir/scaling_max_instant_amp.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/tetsu/dev/douki_C_programs/scaling_max_instant_amp.c > CMakeFiles/scaling_max_instant_amp.dir/scaling_max_instant_amp.c.i

CMakeFiles/scaling_max_instant_amp.dir/scaling_max_instant_amp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/scaling_max_instant_amp.dir/scaling_max_instant_amp.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/tetsu/dev/douki_C_programs/scaling_max_instant_amp.c -o CMakeFiles/scaling_max_instant_amp.dir/scaling_max_instant_amp.c.s

# Object files for target scaling_max_instant_amp
scaling_max_instant_amp_OBJECTS = \
"CMakeFiles/scaling_max_instant_amp.dir/scaling_max_instant_amp.c.o"

# External object files for target scaling_max_instant_amp
scaling_max_instant_amp_EXTERNAL_OBJECTS =

scaling_max_instant_amp: CMakeFiles/scaling_max_instant_amp.dir/scaling_max_instant_amp.c.o
scaling_max_instant_amp: CMakeFiles/scaling_max_instant_amp.dir/build.make
scaling_max_instant_amp: CMakeFiles/scaling_max_instant_amp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tetsu/dev/douki_C_programs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable scaling_max_instant_amp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/scaling_max_instant_amp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/scaling_max_instant_amp.dir/build: scaling_max_instant_amp

.PHONY : CMakeFiles/scaling_max_instant_amp.dir/build

CMakeFiles/scaling_max_instant_amp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/scaling_max_instant_amp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/scaling_max_instant_amp.dir/clean

CMakeFiles/scaling_max_instant_amp.dir/depend:
	cd /Users/tetsu/dev/douki_C_programs/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tetsu/dev/douki_C_programs /Users/tetsu/dev/douki_C_programs /Users/tetsu/dev/douki_C_programs/cmake-build-debug /Users/tetsu/dev/douki_C_programs/cmake-build-debug /Users/tetsu/dev/douki_C_programs/cmake-build-debug/CMakeFiles/scaling_max_instant_amp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/scaling_max_instant_amp.dir/depend

