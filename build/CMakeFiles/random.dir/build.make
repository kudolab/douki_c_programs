# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.15.4/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.15.4/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/tetsu/dev/douki_C_programs

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/tetsu/dev/douki_C_programs/build

# Include any dependencies generated for this target.
include CMakeFiles/random.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/random.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/random.dir/flags.make

CMakeFiles/random.dir/random.c.o: CMakeFiles/random.dir/flags.make
CMakeFiles/random.dir/random.c.o: ../random.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tetsu/dev/douki_C_programs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/random.dir/random.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/random.dir/random.c.o   -c /Users/tetsu/dev/douki_C_programs/random.c

CMakeFiles/random.dir/random.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/random.dir/random.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/tetsu/dev/douki_C_programs/random.c > CMakeFiles/random.dir/random.c.i

CMakeFiles/random.dir/random.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/random.dir/random.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/tetsu/dev/douki_C_programs/random.c -o CMakeFiles/random.dir/random.c.s

# Object files for target random
random_OBJECTS = \
"CMakeFiles/random.dir/random.c.o"

# External object files for target random
random_EXTERNAL_OBJECTS =

random: CMakeFiles/random.dir/random.c.o
random: CMakeFiles/random.dir/build.make
random: CMakeFiles/random.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tetsu/dev/douki_C_programs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable random"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/random.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/random.dir/build: random

.PHONY : CMakeFiles/random.dir/build

CMakeFiles/random.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/random.dir/cmake_clean.cmake
.PHONY : CMakeFiles/random.dir/clean

CMakeFiles/random.dir/depend:
	cd /Users/tetsu/dev/douki_C_programs/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tetsu/dev/douki_C_programs /Users/tetsu/dev/douki_C_programs /Users/tetsu/dev/douki_C_programs/build /Users/tetsu/dev/douki_C_programs/build /Users/tetsu/dev/douki_C_programs/build/CMakeFiles/random.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/random.dir/depend

