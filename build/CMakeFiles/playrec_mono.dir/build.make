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
include CMakeFiles/playrec_mono.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/playrec_mono.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/playrec_mono.dir/flags.make

CMakeFiles/playrec_mono.dir/playrec_mono.c.o: CMakeFiles/playrec_mono.dir/flags.make
CMakeFiles/playrec_mono.dir/playrec_mono.c.o: ../playrec_mono.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tetsu/dev/douki_C_programs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/playrec_mono.dir/playrec_mono.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/playrec_mono.dir/playrec_mono.c.o   -c /Users/tetsu/dev/douki_C_programs/playrec_mono.c

CMakeFiles/playrec_mono.dir/playrec_mono.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/playrec_mono.dir/playrec_mono.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/tetsu/dev/douki_C_programs/playrec_mono.c > CMakeFiles/playrec_mono.dir/playrec_mono.c.i

CMakeFiles/playrec_mono.dir/playrec_mono.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/playrec_mono.dir/playrec_mono.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/tetsu/dev/douki_C_programs/playrec_mono.c -o CMakeFiles/playrec_mono.dir/playrec_mono.c.s

# Object files for target playrec_mono
playrec_mono_OBJECTS = \
"CMakeFiles/playrec_mono.dir/playrec_mono.c.o"

# External object files for target playrec_mono
playrec_mono_EXTERNAL_OBJECTS =

playrec_mono: CMakeFiles/playrec_mono.dir/playrec_mono.c.o
playrec_mono: CMakeFiles/playrec_mono.dir/build.make
playrec_mono: /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a
playrec_mono: CMakeFiles/playrec_mono.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tetsu/dev/douki_C_programs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable playrec_mono"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/playrec_mono.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/playrec_mono.dir/build: playrec_mono

.PHONY : CMakeFiles/playrec_mono.dir/build

CMakeFiles/playrec_mono.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/playrec_mono.dir/cmake_clean.cmake
.PHONY : CMakeFiles/playrec_mono.dir/clean

CMakeFiles/playrec_mono.dir/depend:
	cd /Users/tetsu/dev/douki_C_programs/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tetsu/dev/douki_C_programs /Users/tetsu/dev/douki_C_programs /Users/tetsu/dev/douki_C_programs/build /Users/tetsu/dev/douki_C_programs/build /Users/tetsu/dev/douki_C_programs/build/CMakeFiles/playrec_mono.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/playrec_mono.dir/depend

