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
include CMakeFiles/monoplay.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/monoplay.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/monoplay.dir/flags.make

CMakeFiles/monoplay.dir/monoplay.c.o: CMakeFiles/monoplay.dir/flags.make
CMakeFiles/monoplay.dir/monoplay.c.o: ../monoplay.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tetsu/dev/douki_C_programs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/monoplay.dir/monoplay.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/monoplay.dir/monoplay.c.o   -c /Users/tetsu/dev/douki_C_programs/monoplay.c

CMakeFiles/monoplay.dir/monoplay.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/monoplay.dir/monoplay.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/tetsu/dev/douki_C_programs/monoplay.c > CMakeFiles/monoplay.dir/monoplay.c.i

CMakeFiles/monoplay.dir/monoplay.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/monoplay.dir/monoplay.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/tetsu/dev/douki_C_programs/monoplay.c -o CMakeFiles/monoplay.dir/monoplay.c.s

# Object files for target monoplay
monoplay_OBJECTS = \
"CMakeFiles/monoplay.dir/monoplay.c.o"

# External object files for target monoplay
monoplay_EXTERNAL_OBJECTS =

monoplay: CMakeFiles/monoplay.dir/monoplay.c.o
monoplay: CMakeFiles/monoplay.dir/build.make
monoplay: /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a
monoplay: CMakeFiles/monoplay.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tetsu/dev/douki_C_programs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable monoplay"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/monoplay.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/monoplay.dir/build: monoplay

.PHONY : CMakeFiles/monoplay.dir/build

CMakeFiles/monoplay.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/monoplay.dir/cmake_clean.cmake
.PHONY : CMakeFiles/monoplay.dir/clean

CMakeFiles/monoplay.dir/depend:
	cd /Users/tetsu/dev/douki_C_programs/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tetsu/dev/douki_C_programs /Users/tetsu/dev/douki_C_programs /Users/tetsu/dev/douki_C_programs/cmake-build-debug /Users/tetsu/dev/douki_C_programs/cmake-build-debug /Users/tetsu/dev/douki_C_programs/cmake-build-debug/CMakeFiles/monoplay.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/monoplay.dir/depend

