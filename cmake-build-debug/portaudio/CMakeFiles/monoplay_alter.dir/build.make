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
include portaudio/CMakeFiles/monoplay_alter.dir/depend.make

# Include the progress variables for this target.
include portaudio/CMakeFiles/monoplay_alter.dir/progress.make

# Include the compile flags for this target's objects.
include portaudio/CMakeFiles/monoplay_alter.dir/flags.make

portaudio/CMakeFiles/monoplay_alter.dir/src/monoplay_alter.c.o: portaudio/CMakeFiles/monoplay_alter.dir/flags.make
portaudio/CMakeFiles/monoplay_alter.dir/src/monoplay_alter.c.o: ../portaudio/src/monoplay_alter.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tetsu/dev/douki_C_programs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object portaudio/CMakeFiles/monoplay_alter.dir/src/monoplay_alter.c.o"
	cd /Users/tetsu/dev/douki_C_programs/cmake-build-debug/portaudio && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/monoplay_alter.dir/src/monoplay_alter.c.o   -c /Users/tetsu/dev/douki_C_programs/portaudio/src/monoplay_alter.c

portaudio/CMakeFiles/monoplay_alter.dir/src/monoplay_alter.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/monoplay_alter.dir/src/monoplay_alter.c.i"
	cd /Users/tetsu/dev/douki_C_programs/cmake-build-debug/portaudio && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/tetsu/dev/douki_C_programs/portaudio/src/monoplay_alter.c > CMakeFiles/monoplay_alter.dir/src/monoplay_alter.c.i

portaudio/CMakeFiles/monoplay_alter.dir/src/monoplay_alter.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/monoplay_alter.dir/src/monoplay_alter.c.s"
	cd /Users/tetsu/dev/douki_C_programs/cmake-build-debug/portaudio && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/tetsu/dev/douki_C_programs/portaudio/src/monoplay_alter.c -o CMakeFiles/monoplay_alter.dir/src/monoplay_alter.c.s

# Object files for target monoplay_alter
monoplay_alter_OBJECTS = \
"CMakeFiles/monoplay_alter.dir/src/monoplay_alter.c.o"

# External object files for target monoplay_alter
monoplay_alter_EXTERNAL_OBJECTS =

portaudio/monoplay_alter: portaudio/CMakeFiles/monoplay_alter.dir/src/monoplay_alter.c.o
portaudio/monoplay_alter: portaudio/CMakeFiles/monoplay_alter.dir/build.make
portaudio/monoplay_alter: /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a
portaudio/monoplay_alter: portaudio/CMakeFiles/monoplay_alter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tetsu/dev/douki_C_programs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable monoplay_alter"
	cd /Users/tetsu/dev/douki_C_programs/cmake-build-debug/portaudio && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/monoplay_alter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
portaudio/CMakeFiles/monoplay_alter.dir/build: portaudio/monoplay_alter

.PHONY : portaudio/CMakeFiles/monoplay_alter.dir/build

portaudio/CMakeFiles/monoplay_alter.dir/clean:
	cd /Users/tetsu/dev/douki_C_programs/cmake-build-debug/portaudio && $(CMAKE_COMMAND) -P CMakeFiles/monoplay_alter.dir/cmake_clean.cmake
.PHONY : portaudio/CMakeFiles/monoplay_alter.dir/clean

portaudio/CMakeFiles/monoplay_alter.dir/depend:
	cd /Users/tetsu/dev/douki_C_programs/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tetsu/dev/douki_C_programs /Users/tetsu/dev/douki_C_programs/portaudio /Users/tetsu/dev/douki_C_programs/cmake-build-debug /Users/tetsu/dev/douki_C_programs/cmake-build-debug/portaudio /Users/tetsu/dev/douki_C_programs/cmake-build-debug/portaudio/CMakeFiles/monoplay_alter.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : portaudio/CMakeFiles/monoplay_alter.dir/depend

