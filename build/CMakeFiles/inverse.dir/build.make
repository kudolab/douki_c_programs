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
include CMakeFiles/inverse.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/inverse.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/inverse.dir/flags.make

CMakeFiles/inverse.dir/inverse.c.o: CMakeFiles/inverse.dir/flags.make
CMakeFiles/inverse.dir/inverse.c.o: ../inverse.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tetsu/dev/douki_C_programs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/inverse.dir/inverse.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/inverse.dir/inverse.c.o   -c /Users/tetsu/dev/douki_C_programs/inverse.c

CMakeFiles/inverse.dir/inverse.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/inverse.dir/inverse.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/tetsu/dev/douki_C_programs/inverse.c > CMakeFiles/inverse.dir/inverse.c.i

CMakeFiles/inverse.dir/inverse.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/inverse.dir/inverse.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/tetsu/dev/douki_C_programs/inverse.c -o CMakeFiles/inverse.dir/inverse.c.s

# Object files for target inverse
inverse_OBJECTS = \
"CMakeFiles/inverse.dir/inverse.c.o"

# External object files for target inverse
inverse_EXTERNAL_OBJECTS =

inverse: CMakeFiles/inverse.dir/inverse.c.o
inverse: CMakeFiles/inverse.dir/build.make
inverse: CMakeFiles/inverse.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tetsu/dev/douki_C_programs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable inverse"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/inverse.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/inverse.dir/build: inverse

.PHONY : CMakeFiles/inverse.dir/build

CMakeFiles/inverse.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/inverse.dir/cmake_clean.cmake
.PHONY : CMakeFiles/inverse.dir/clean

CMakeFiles/inverse.dir/depend:
	cd /Users/tetsu/dev/douki_C_programs/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tetsu/dev/douki_C_programs /Users/tetsu/dev/douki_C_programs /Users/tetsu/dev/douki_C_programs/build /Users/tetsu/dev/douki_C_programs/build /Users/tetsu/dev/douki_C_programs/build/CMakeFiles/inverse.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/inverse.dir/depend

