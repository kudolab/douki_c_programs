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
include CMakeFiles/fftout4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fftout4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fftout4.dir/flags.make

CMakeFiles/fftout4.dir/fftout4.c.o: CMakeFiles/fftout4.dir/flags.make
CMakeFiles/fftout4.dir/fftout4.c.o: ../fftout4.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tetsu/dev/douki_C_programs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/fftout4.dir/fftout4.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fftout4.dir/fftout4.c.o   -c /Users/tetsu/dev/douki_C_programs/fftout4.c

CMakeFiles/fftout4.dir/fftout4.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fftout4.dir/fftout4.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/tetsu/dev/douki_C_programs/fftout4.c > CMakeFiles/fftout4.dir/fftout4.c.i

CMakeFiles/fftout4.dir/fftout4.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fftout4.dir/fftout4.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/tetsu/dev/douki_C_programs/fftout4.c -o CMakeFiles/fftout4.dir/fftout4.c.s

# Object files for target fftout4
fftout4_OBJECTS = \
"CMakeFiles/fftout4.dir/fftout4.c.o"

# External object files for target fftout4
fftout4_EXTERNAL_OBJECTS =

fftout4: CMakeFiles/fftout4.dir/fftout4.c.o
fftout4: CMakeFiles/fftout4.dir/build.make
fftout4: /usr/local/lib/libfftw3.a
fftout4: CMakeFiles/fftout4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tetsu/dev/douki_C_programs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable fftout4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fftout4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fftout4.dir/build: fftout4

.PHONY : CMakeFiles/fftout4.dir/build

CMakeFiles/fftout4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fftout4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fftout4.dir/clean

CMakeFiles/fftout4.dir/depend:
	cd /Users/tetsu/dev/douki_C_programs/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tetsu/dev/douki_C_programs /Users/tetsu/dev/douki_C_programs /Users/tetsu/dev/douki_C_programs/build /Users/tetsu/dev/douki_C_programs/build /Users/tetsu/dev/douki_C_programs/build/CMakeFiles/fftout4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fftout4.dir/depend

