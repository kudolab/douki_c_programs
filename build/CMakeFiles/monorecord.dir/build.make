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
include CMakeFiles/monorecord.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/monorecord.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/monorecord.dir/flags.make

CMakeFiles/monorecord.dir/monorecord.c.o: CMakeFiles/monorecord.dir/flags.make
CMakeFiles/monorecord.dir/monorecord.c.o: ../monorecord.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tetsu/dev/douki_C_programs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/monorecord.dir/monorecord.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/monorecord.dir/monorecord.c.o   -c /Users/tetsu/dev/douki_C_programs/monorecord.c

CMakeFiles/monorecord.dir/monorecord.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/monorecord.dir/monorecord.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/tetsu/dev/douki_C_programs/monorecord.c > CMakeFiles/monorecord.dir/monorecord.c.i

CMakeFiles/monorecord.dir/monorecord.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/monorecord.dir/monorecord.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/tetsu/dev/douki_C_programs/monorecord.c -o CMakeFiles/monorecord.dir/monorecord.c.s

# Object files for target monorecord
monorecord_OBJECTS = \
"CMakeFiles/monorecord.dir/monorecord.c.o"

# External object files for target monorecord
monorecord_EXTERNAL_OBJECTS =

monorecord: CMakeFiles/monorecord.dir/monorecord.c.o
monorecord: CMakeFiles/monorecord.dir/build.make
monorecord: /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a
monorecord: CMakeFiles/monorecord.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tetsu/dev/douki_C_programs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable monorecord"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/monorecord.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/monorecord.dir/build: monorecord

.PHONY : CMakeFiles/monorecord.dir/build

CMakeFiles/monorecord.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/monorecord.dir/cmake_clean.cmake
.PHONY : CMakeFiles/monorecord.dir/clean

CMakeFiles/monorecord.dir/depend:
	cd /Users/tetsu/dev/douki_C_programs/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tetsu/dev/douki_C_programs /Users/tetsu/dev/douki_C_programs /Users/tetsu/dev/douki_C_programs/build /Users/tetsu/dev/douki_C_programs/build /Users/tetsu/dev/douki_C_programs/build/CMakeFiles/monorecord.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/monorecord.dir/depend

