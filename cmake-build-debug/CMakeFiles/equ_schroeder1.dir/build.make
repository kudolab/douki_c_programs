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
include CMakeFiles/equ_schroeder1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/equ_schroeder1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/equ_schroeder1.dir/flags.make

<<<<<<< HEAD
CMakeFiles/equ_schroeder1.dir/equ_schroeder1.c.o: CMakeFiles/equ_schroeder1.dir/flags.make
CMakeFiles/equ_schroeder1.dir/equ_schroeder1.c.o: ../equ_schroeder1.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tetsu/dev/douki_c_programs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/equ_schroeder1.dir/equ_schroeder1.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/equ_schroeder1.dir/equ_schroeder1.c.o   -c /Users/tetsu/dev/douki_c_programs/equ_schroeder1.c

CMakeFiles/equ_schroeder1.dir/equ_schroeder1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/equ_schroeder1.dir/equ_schroeder1.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/tetsu/dev/douki_c_programs/equ_schroeder1.c > CMakeFiles/equ_schroeder1.dir/equ_schroeder1.c.i

CMakeFiles/equ_schroeder1.dir/equ_schroeder1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/equ_schroeder1.dir/equ_schroeder1.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/tetsu/dev/douki_c_programs/equ_schroeder1.c -o CMakeFiles/equ_schroeder1.dir/equ_schroeder1.c.s

# Object files for target equ_schroeder1
equ_schroeder1_OBJECTS = \
"CMakeFiles/equ_schroeder1.dir/equ_schroeder1.c.o"
=======
CMakeFiles/equ_schroeder1.dir/common/src/equ_schroeder1.c.o: CMakeFiles/equ_schroeder1.dir/flags.make
CMakeFiles/equ_schroeder1.dir/common/src/equ_schroeder1.c.o: ../common/src/equ_schroeder1.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tetsu/dev/douki_C_programs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/equ_schroeder1.dir/common/src/equ_schroeder1.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/equ_schroeder1.dir/common/src/equ_schroeder1.c.o   -c /Users/tetsu/dev/douki_C_programs/common/src/equ_schroeder1.c

CMakeFiles/equ_schroeder1.dir/common/src/equ_schroeder1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/equ_schroeder1.dir/common/src/equ_schroeder1.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/tetsu/dev/douki_C_programs/common/src/equ_schroeder1.c > CMakeFiles/equ_schroeder1.dir/common/src/equ_schroeder1.c.i

CMakeFiles/equ_schroeder1.dir/common/src/equ_schroeder1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/equ_schroeder1.dir/common/src/equ_schroeder1.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/tetsu/dev/douki_C_programs/common/src/equ_schroeder1.c -o CMakeFiles/equ_schroeder1.dir/common/src/equ_schroeder1.c.s

# Object files for target equ_schroeder1
equ_schroeder1_OBJECTS = \
"CMakeFiles/equ_schroeder1.dir/common/src/equ_schroeder1.c.o"
>>>>>>> feature/dir

# External object files for target equ_schroeder1
equ_schroeder1_EXTERNAL_OBJECTS =

<<<<<<< HEAD
equ_schroeder1: CMakeFiles/equ_schroeder1.dir/equ_schroeder1.c.o
equ_schroeder1: CMakeFiles/equ_schroeder1.dir/build.make
equ_schroeder1: CMakeFiles/equ_schroeder1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tetsu/dev/douki_c_programs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable equ_schroeder1"
=======
equ_schroeder1: CMakeFiles/equ_schroeder1.dir/common/src/equ_schroeder1.c.o
equ_schroeder1: CMakeFiles/equ_schroeder1.dir/build.make
equ_schroeder1: CMakeFiles/equ_schroeder1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tetsu/dev/douki_C_programs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable equ_schroeder1"
>>>>>>> feature/dir
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/equ_schroeder1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/equ_schroeder1.dir/build: equ_schroeder1

.PHONY : CMakeFiles/equ_schroeder1.dir/build

CMakeFiles/equ_schroeder1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/equ_schroeder1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/equ_schroeder1.dir/clean

CMakeFiles/equ_schroeder1.dir/depend:
<<<<<<< HEAD
	cd /Users/tetsu/dev/douki_c_programs/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tetsu/dev/douki_c_programs /Users/tetsu/dev/douki_c_programs /Users/tetsu/dev/douki_c_programs/cmake-build-debug /Users/tetsu/dev/douki_c_programs/cmake-build-debug /Users/tetsu/dev/douki_c_programs/cmake-build-debug/CMakeFiles/equ_schroeder1.dir/DependInfo.cmake --color=$(COLOR)
=======
	cd /Users/tetsu/dev/douki_C_programs/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tetsu/dev/douki_C_programs /Users/tetsu/dev/douki_C_programs /Users/tetsu/dev/douki_C_programs/cmake-build-debug /Users/tetsu/dev/douki_C_programs/cmake-build-debug /Users/tetsu/dev/douki_C_programs/cmake-build-debug/CMakeFiles/equ_schroeder1.dir/DependInfo.cmake --color=$(COLOR)
>>>>>>> feature/dir
.PHONY : CMakeFiles/equ_schroeder1.dir/depend

