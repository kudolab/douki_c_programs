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
CMAKE_SOURCE_DIR = /Users/tetsu/dev/douki_c_programs

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/tetsu/dev/douki_c_programs/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/douki_new.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/douki_new.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/douki_new.dir/flags.make

CMakeFiles/douki_new.dir/douki_new.c.o: CMakeFiles/douki_new.dir/flags.make
CMakeFiles/douki_new.dir/douki_new.c.o: ../douki_new.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tetsu/dev/douki_c_programs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/douki_new.dir/douki_new.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/douki_new.dir/douki_new.c.o   -c /Users/tetsu/dev/douki_c_programs/douki_new.c

CMakeFiles/douki_new.dir/douki_new.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/douki_new.dir/douki_new.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/tetsu/dev/douki_c_programs/douki_new.c > CMakeFiles/douki_new.dir/douki_new.c.i

CMakeFiles/douki_new.dir/douki_new.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/douki_new.dir/douki_new.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/tetsu/dev/douki_c_programs/douki_new.c -o CMakeFiles/douki_new.dir/douki_new.c.s

# Object files for target douki_new
douki_new_OBJECTS = \
"CMakeFiles/douki_new.dir/douki_new.c.o"

# External object files for target douki_new
douki_new_EXTERNAL_OBJECTS =

douki_new: CMakeFiles/douki_new.dir/douki_new.c.o
douki_new: CMakeFiles/douki_new.dir/build.make
douki_new: CMakeFiles/douki_new.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tetsu/dev/douki_c_programs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable douki_new"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/douki_new.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/douki_new.dir/build: douki_new

.PHONY : CMakeFiles/douki_new.dir/build

CMakeFiles/douki_new.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/douki_new.dir/cmake_clean.cmake
.PHONY : CMakeFiles/douki_new.dir/clean

CMakeFiles/douki_new.dir/depend:
	cd /Users/tetsu/dev/douki_c_programs/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tetsu/dev/douki_c_programs /Users/tetsu/dev/douki_c_programs /Users/tetsu/dev/douki_c_programs/cmake-build-debug /Users/tetsu/dev/douki_c_programs/cmake-build-debug /Users/tetsu/dev/douki_c_programs/cmake-build-debug/CMakeFiles/douki_new.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/douki_new.dir/depend

