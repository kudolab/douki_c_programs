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
include CMakeFiles/make_whitenoise.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/make_whitenoise.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/make_whitenoise.dir/flags.make

CMakeFiles/make_whitenoise.dir/make_whitenoise.c.o: CMakeFiles/make_whitenoise.dir/flags.make
CMakeFiles/make_whitenoise.dir/make_whitenoise.c.o: ../make_whitenoise.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tetsu/dev/douki_C_programs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/make_whitenoise.dir/make_whitenoise.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/make_whitenoise.dir/make_whitenoise.c.o   -c /Users/tetsu/dev/douki_C_programs/make_whitenoise.c

CMakeFiles/make_whitenoise.dir/make_whitenoise.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/make_whitenoise.dir/make_whitenoise.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/tetsu/dev/douki_C_programs/make_whitenoise.c > CMakeFiles/make_whitenoise.dir/make_whitenoise.c.i

CMakeFiles/make_whitenoise.dir/make_whitenoise.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/make_whitenoise.dir/make_whitenoise.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/tetsu/dev/douki_C_programs/make_whitenoise.c -o CMakeFiles/make_whitenoise.dir/make_whitenoise.c.s

# Object files for target make_whitenoise
make_whitenoise_OBJECTS = \
"CMakeFiles/make_whitenoise.dir/make_whitenoise.c.o"

# External object files for target make_whitenoise
make_whitenoise_EXTERNAL_OBJECTS =

make_whitenoise: CMakeFiles/make_whitenoise.dir/make_whitenoise.c.o
make_whitenoise: CMakeFiles/make_whitenoise.dir/build.make
make_whitenoise: /usr/local/lib/libfftw3.a
make_whitenoise: CMakeFiles/make_whitenoise.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tetsu/dev/douki_C_programs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable make_whitenoise"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/make_whitenoise.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/make_whitenoise.dir/build: make_whitenoise

.PHONY : CMakeFiles/make_whitenoise.dir/build

CMakeFiles/make_whitenoise.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/make_whitenoise.dir/cmake_clean.cmake
.PHONY : CMakeFiles/make_whitenoise.dir/clean

CMakeFiles/make_whitenoise.dir/depend:
	cd /Users/tetsu/dev/douki_C_programs/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tetsu/dev/douki_C_programs /Users/tetsu/dev/douki_C_programs /Users/tetsu/dev/douki_C_programs/build /Users/tetsu/dev/douki_C_programs/build /Users/tetsu/dev/douki_C_programs/build/CMakeFiles/make_whitenoise.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/make_whitenoise.dir/depend

