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
include CMakeFiles/2chplay2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/2chplay2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/2chplay2.dir/flags.make

CMakeFiles/2chplay2.dir/2chplay2.c.o: CMakeFiles/2chplay2.dir/flags.make
CMakeFiles/2chplay2.dir/2chplay2.c.o: ../2chplay2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tetsu/dev/douki_C_programs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/2chplay2.dir/2chplay2.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/2chplay2.dir/2chplay2.c.o   -c /Users/tetsu/dev/douki_C_programs/2chplay2.c

CMakeFiles/2chplay2.dir/2chplay2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/2chplay2.dir/2chplay2.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/tetsu/dev/douki_C_programs/2chplay2.c > CMakeFiles/2chplay2.dir/2chplay2.c.i

CMakeFiles/2chplay2.dir/2chplay2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/2chplay2.dir/2chplay2.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/tetsu/dev/douki_C_programs/2chplay2.c -o CMakeFiles/2chplay2.dir/2chplay2.c.s

# Object files for target 2chplay2
2chplay2_OBJECTS = \
"CMakeFiles/2chplay2.dir/2chplay2.c.o"

# External object files for target 2chplay2
2chplay2_EXTERNAL_OBJECTS =

2chplay2: CMakeFiles/2chplay2.dir/2chplay2.c.o
2chplay2: CMakeFiles/2chplay2.dir/build.make
2chplay2: /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a
2chplay2: CMakeFiles/2chplay2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tetsu/dev/douki_C_programs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable 2chplay2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/2chplay2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/2chplay2.dir/build: 2chplay2

.PHONY : CMakeFiles/2chplay2.dir/build

CMakeFiles/2chplay2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/2chplay2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/2chplay2.dir/clean

CMakeFiles/2chplay2.dir/depend:
	cd /Users/tetsu/dev/douki_C_programs/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tetsu/dev/douki_C_programs /Users/tetsu/dev/douki_C_programs /Users/tetsu/dev/douki_C_programs/cmake-build-debug /Users/tetsu/dev/douki_C_programs/cmake-build-debug /Users/tetsu/dev/douki_C_programs/cmake-build-debug/CMakeFiles/2chplay2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/2chplay2.dir/depend

