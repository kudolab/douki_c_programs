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
include CMakeFiles/FileLib_osx.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/FileLib_osx.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FileLib_osx.dir/flags.make

CMakeFiles/FileLib_osx.dir/FileLib_osx.c.o: CMakeFiles/FileLib_osx.dir/flags.make
CMakeFiles/FileLib_osx.dir/FileLib_osx.c.o: ../FileLib_osx.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tetsu/dev/douki_C_programs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/FileLib_osx.dir/FileLib_osx.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/FileLib_osx.dir/FileLib_osx.c.o   -c /Users/tetsu/dev/douki_C_programs/FileLib_osx.c

CMakeFiles/FileLib_osx.dir/FileLib_osx.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FileLib_osx.dir/FileLib_osx.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/tetsu/dev/douki_C_programs/FileLib_osx.c > CMakeFiles/FileLib_osx.dir/FileLib_osx.c.i

CMakeFiles/FileLib_osx.dir/FileLib_osx.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FileLib_osx.dir/FileLib_osx.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/tetsu/dev/douki_C_programs/FileLib_osx.c -o CMakeFiles/FileLib_osx.dir/FileLib_osx.c.s

# Object files for target FileLib_osx
FileLib_osx_OBJECTS = \
"CMakeFiles/FileLib_osx.dir/FileLib_osx.c.o"

# External object files for target FileLib_osx
FileLib_osx_EXTERNAL_OBJECTS =

FileLib_osx: CMakeFiles/FileLib_osx.dir/FileLib_osx.c.o
FileLib_osx: CMakeFiles/FileLib_osx.dir/build.make
FileLib_osx: CMakeFiles/FileLib_osx.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tetsu/dev/douki_C_programs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable FileLib_osx"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FileLib_osx.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FileLib_osx.dir/build: FileLib_osx

.PHONY : CMakeFiles/FileLib_osx.dir/build

CMakeFiles/FileLib_osx.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FileLib_osx.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FileLib_osx.dir/clean

CMakeFiles/FileLib_osx.dir/depend:
	cd /Users/tetsu/dev/douki_C_programs/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tetsu/dev/douki_C_programs /Users/tetsu/dev/douki_C_programs /Users/tetsu/dev/douki_C_programs/cmake-build-debug /Users/tetsu/dev/douki_C_programs/cmake-build-debug /Users/tetsu/dev/douki_C_programs/cmake-build-debug/CMakeFiles/FileLib_osx.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FileLib_osx.dir/depend

