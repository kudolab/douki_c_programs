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
include CMakeFiles/imp_add.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/imp_add.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/imp_add.dir/flags.make

CMakeFiles/imp_add.dir/imp_add.c.o: CMakeFiles/imp_add.dir/flags.make
CMakeFiles/imp_add.dir/imp_add.c.o: ../imp_add.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tetsu/dev/douki_C_programs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/imp_add.dir/imp_add.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/imp_add.dir/imp_add.c.o   -c /Users/tetsu/dev/douki_C_programs/imp_add.c

CMakeFiles/imp_add.dir/imp_add.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/imp_add.dir/imp_add.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/tetsu/dev/douki_C_programs/imp_add.c > CMakeFiles/imp_add.dir/imp_add.c.i

CMakeFiles/imp_add.dir/imp_add.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/imp_add.dir/imp_add.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/tetsu/dev/douki_C_programs/imp_add.c -o CMakeFiles/imp_add.dir/imp_add.c.s

# Object files for target imp_add
imp_add_OBJECTS = \
"CMakeFiles/imp_add.dir/imp_add.c.o"

# External object files for target imp_add
imp_add_EXTERNAL_OBJECTS =

imp_add: CMakeFiles/imp_add.dir/imp_add.c.o
imp_add: CMakeFiles/imp_add.dir/build.make
imp_add: CMakeFiles/imp_add.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tetsu/dev/douki_C_programs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable imp_add"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/imp_add.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/imp_add.dir/build: imp_add

.PHONY : CMakeFiles/imp_add.dir/build

CMakeFiles/imp_add.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/imp_add.dir/cmake_clean.cmake
.PHONY : CMakeFiles/imp_add.dir/clean

CMakeFiles/imp_add.dir/depend:
	cd /Users/tetsu/dev/douki_C_programs/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tetsu/dev/douki_C_programs /Users/tetsu/dev/douki_C_programs /Users/tetsu/dev/douki_C_programs/build /Users/tetsu/dev/douki_C_programs/build /Users/tetsu/dev/douki_C_programs/build/CMakeFiles/imp_add.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/imp_add.dir/depend

