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
<<<<<<< HEAD
CMAKE_SOURCE_DIR = /Users/tetsu/dev/douki_c_programs

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/tetsu/dev/douki_c_programs/cmake-build-debug
=======
CMAKE_SOURCE_DIR = /Users/tetsu/dev/douki_C_programs

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/tetsu/dev/douki_C_programs/cmake-build-debug
>>>>>>> feature/dir

# Include any dependencies generated for this target.
include CMakeFiles/fftout2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fftout2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fftout2.dir/flags.make

<<<<<<< HEAD
CMakeFiles/fftout2.dir/fftout2.c.o: CMakeFiles/fftout2.dir/flags.make
CMakeFiles/fftout2.dir/fftout2.c.o: ../fftout2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tetsu/dev/douki_c_programs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/fftout2.dir/fftout2.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fftout2.dir/fftout2.c.o   -c /Users/tetsu/dev/douki_c_programs/fftout2.c

CMakeFiles/fftout2.dir/fftout2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fftout2.dir/fftout2.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/tetsu/dev/douki_c_programs/fftout2.c > CMakeFiles/fftout2.dir/fftout2.c.i

CMakeFiles/fftout2.dir/fftout2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fftout2.dir/fftout2.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/tetsu/dev/douki_c_programs/fftout2.c -o CMakeFiles/fftout2.dir/fftout2.c.s

# Object files for target fftout2
fftout2_OBJECTS = \
"CMakeFiles/fftout2.dir/fftout2.c.o"
=======
CMakeFiles/fftout2.dir/fftw/src/fftout2.c.o: CMakeFiles/fftout2.dir/flags.make
CMakeFiles/fftout2.dir/fftw/src/fftout2.c.o: ../fftw/src/fftout2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tetsu/dev/douki_C_programs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/fftout2.dir/fftw/src/fftout2.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fftout2.dir/fftw/src/fftout2.c.o   -c /Users/tetsu/dev/douki_C_programs/fftw/src/fftout2.c

CMakeFiles/fftout2.dir/fftw/src/fftout2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fftout2.dir/fftw/src/fftout2.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/tetsu/dev/douki_C_programs/fftw/src/fftout2.c > CMakeFiles/fftout2.dir/fftw/src/fftout2.c.i

CMakeFiles/fftout2.dir/fftw/src/fftout2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fftout2.dir/fftw/src/fftout2.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/tetsu/dev/douki_C_programs/fftw/src/fftout2.c -o CMakeFiles/fftout2.dir/fftw/src/fftout2.c.s

# Object files for target fftout2
fftout2_OBJECTS = \
"CMakeFiles/fftout2.dir/fftw/src/fftout2.c.o"
>>>>>>> feature/dir

# External object files for target fftout2
fftout2_EXTERNAL_OBJECTS =

<<<<<<< HEAD
fftout2: CMakeFiles/fftout2.dir/fftout2.c.o
fftout2: CMakeFiles/fftout2.dir/build.make
fftout2: /usr/local/lib/libfftw3.a
fftout2: CMakeFiles/fftout2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tetsu/dev/douki_c_programs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable fftout2"
=======
fftout2: CMakeFiles/fftout2.dir/fftw/src/fftout2.c.o
fftout2: CMakeFiles/fftout2.dir/build.make
fftout2: /usr/local/lib/libfftw3.a
fftout2: CMakeFiles/fftout2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tetsu/dev/douki_C_programs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable fftout2"
>>>>>>> feature/dir
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fftout2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fftout2.dir/build: fftout2

.PHONY : CMakeFiles/fftout2.dir/build

CMakeFiles/fftout2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fftout2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fftout2.dir/clean

CMakeFiles/fftout2.dir/depend:
<<<<<<< HEAD
	cd /Users/tetsu/dev/douki_c_programs/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tetsu/dev/douki_c_programs /Users/tetsu/dev/douki_c_programs /Users/tetsu/dev/douki_c_programs/cmake-build-debug /Users/tetsu/dev/douki_c_programs/cmake-build-debug /Users/tetsu/dev/douki_c_programs/cmake-build-debug/CMakeFiles/fftout2.dir/DependInfo.cmake --color=$(COLOR)
=======
	cd /Users/tetsu/dev/douki_C_programs/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tetsu/dev/douki_C_programs /Users/tetsu/dev/douki_C_programs /Users/tetsu/dev/douki_C_programs/cmake-build-debug /Users/tetsu/dev/douki_C_programs/cmake-build-debug /Users/tetsu/dev/douki_C_programs/cmake-build-debug/CMakeFiles/fftout2.dir/DependInfo.cmake --color=$(COLOR)
>>>>>>> feature/dir
.PHONY : CMakeFiles/fftout2.dir/depend

