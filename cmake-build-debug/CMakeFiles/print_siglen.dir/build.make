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
include CMakeFiles/print_siglen.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/print_siglen.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/print_siglen.dir/flags.make

<<<<<<< HEAD
CMakeFiles/print_siglen.dir/print_siglen.c.o: CMakeFiles/print_siglen.dir/flags.make
CMakeFiles/print_siglen.dir/print_siglen.c.o: ../print_siglen.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tetsu/dev/douki_c_programs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/print_siglen.dir/print_siglen.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/print_siglen.dir/print_siglen.c.o   -c /Users/tetsu/dev/douki_c_programs/print_siglen.c

CMakeFiles/print_siglen.dir/print_siglen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/print_siglen.dir/print_siglen.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/tetsu/dev/douki_c_programs/print_siglen.c > CMakeFiles/print_siglen.dir/print_siglen.c.i

CMakeFiles/print_siglen.dir/print_siglen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/print_siglen.dir/print_siglen.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/tetsu/dev/douki_c_programs/print_siglen.c -o CMakeFiles/print_siglen.dir/print_siglen.c.s

# Object files for target print_siglen
print_siglen_OBJECTS = \
"CMakeFiles/print_siglen.dir/print_siglen.c.o"
=======
CMakeFiles/print_siglen.dir/common/src/print_siglen.c.o: CMakeFiles/print_siglen.dir/flags.make
CMakeFiles/print_siglen.dir/common/src/print_siglen.c.o: ../common/src/print_siglen.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tetsu/dev/douki_C_programs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/print_siglen.dir/common/src/print_siglen.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/print_siglen.dir/common/src/print_siglen.c.o   -c /Users/tetsu/dev/douki_C_programs/common/src/print_siglen.c

CMakeFiles/print_siglen.dir/common/src/print_siglen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/print_siglen.dir/common/src/print_siglen.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/tetsu/dev/douki_C_programs/common/src/print_siglen.c > CMakeFiles/print_siglen.dir/common/src/print_siglen.c.i

CMakeFiles/print_siglen.dir/common/src/print_siglen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/print_siglen.dir/common/src/print_siglen.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/tetsu/dev/douki_C_programs/common/src/print_siglen.c -o CMakeFiles/print_siglen.dir/common/src/print_siglen.c.s

# Object files for target print_siglen
print_siglen_OBJECTS = \
"CMakeFiles/print_siglen.dir/common/src/print_siglen.c.o"
>>>>>>> feature/dir

# External object files for target print_siglen
print_siglen_EXTERNAL_OBJECTS =

<<<<<<< HEAD
print_siglen: CMakeFiles/print_siglen.dir/print_siglen.c.o
print_siglen: CMakeFiles/print_siglen.dir/build.make
print_siglen: CMakeFiles/print_siglen.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tetsu/dev/douki_c_programs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable print_siglen"
=======
print_siglen: CMakeFiles/print_siglen.dir/common/src/print_siglen.c.o
print_siglen: CMakeFiles/print_siglen.dir/build.make
print_siglen: CMakeFiles/print_siglen.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tetsu/dev/douki_C_programs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable print_siglen"
>>>>>>> feature/dir
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/print_siglen.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/print_siglen.dir/build: print_siglen

.PHONY : CMakeFiles/print_siglen.dir/build

CMakeFiles/print_siglen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/print_siglen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/print_siglen.dir/clean

CMakeFiles/print_siglen.dir/depend:
<<<<<<< HEAD
	cd /Users/tetsu/dev/douki_c_programs/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tetsu/dev/douki_c_programs /Users/tetsu/dev/douki_c_programs /Users/tetsu/dev/douki_c_programs/cmake-build-debug /Users/tetsu/dev/douki_c_programs/cmake-build-debug /Users/tetsu/dev/douki_c_programs/cmake-build-debug/CMakeFiles/print_siglen.dir/DependInfo.cmake --color=$(COLOR)
=======
	cd /Users/tetsu/dev/douki_C_programs/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tetsu/dev/douki_C_programs /Users/tetsu/dev/douki_C_programs /Users/tetsu/dev/douki_C_programs/cmake-build-debug /Users/tetsu/dev/douki_C_programs/cmake-build-debug /Users/tetsu/dev/douki_C_programs/cmake-build-debug/CMakeFiles/print_siglen.dir/DependInfo.cmake --color=$(COLOR)
>>>>>>> feature/dir
.PHONY : CMakeFiles/print_siglen.dir/depend

