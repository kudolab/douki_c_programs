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
include CMakeFiles/playrec_2ch_inPath.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/playrec_2ch_inPath.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/playrec_2ch_inPath.dir/flags.make

<<<<<<< HEAD
CMakeFiles/playrec_2ch_inPath.dir/playrec_2ch_inPath.c.o: CMakeFiles/playrec_2ch_inPath.dir/flags.make
CMakeFiles/playrec_2ch_inPath.dir/playrec_2ch_inPath.c.o: ../playrec_2ch_inPath.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tetsu/dev/douki_c_programs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/playrec_2ch_inPath.dir/playrec_2ch_inPath.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/playrec_2ch_inPath.dir/playrec_2ch_inPath.c.o   -c /Users/tetsu/dev/douki_c_programs/playrec_2ch_inPath.c

CMakeFiles/playrec_2ch_inPath.dir/playrec_2ch_inPath.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/playrec_2ch_inPath.dir/playrec_2ch_inPath.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/tetsu/dev/douki_c_programs/playrec_2ch_inPath.c > CMakeFiles/playrec_2ch_inPath.dir/playrec_2ch_inPath.c.i

CMakeFiles/playrec_2ch_inPath.dir/playrec_2ch_inPath.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/playrec_2ch_inPath.dir/playrec_2ch_inPath.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/tetsu/dev/douki_c_programs/playrec_2ch_inPath.c -o CMakeFiles/playrec_2ch_inPath.dir/playrec_2ch_inPath.c.s

# Object files for target playrec_2ch_inPath
playrec_2ch_inPath_OBJECTS = \
"CMakeFiles/playrec_2ch_inPath.dir/playrec_2ch_inPath.c.o"
=======
CMakeFiles/playrec_2ch_inPath.dir/portaudio/src/playrec_2ch_inPath.c.o: CMakeFiles/playrec_2ch_inPath.dir/flags.make
CMakeFiles/playrec_2ch_inPath.dir/portaudio/src/playrec_2ch_inPath.c.o: ../portaudio/src/playrec_2ch_inPath.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tetsu/dev/douki_C_programs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/playrec_2ch_inPath.dir/portaudio/src/playrec_2ch_inPath.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/playrec_2ch_inPath.dir/portaudio/src/playrec_2ch_inPath.c.o   -c /Users/tetsu/dev/douki_C_programs/portaudio/src/playrec_2ch_inPath.c

CMakeFiles/playrec_2ch_inPath.dir/portaudio/src/playrec_2ch_inPath.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/playrec_2ch_inPath.dir/portaudio/src/playrec_2ch_inPath.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/tetsu/dev/douki_C_programs/portaudio/src/playrec_2ch_inPath.c > CMakeFiles/playrec_2ch_inPath.dir/portaudio/src/playrec_2ch_inPath.c.i

CMakeFiles/playrec_2ch_inPath.dir/portaudio/src/playrec_2ch_inPath.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/playrec_2ch_inPath.dir/portaudio/src/playrec_2ch_inPath.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/tetsu/dev/douki_C_programs/portaudio/src/playrec_2ch_inPath.c -o CMakeFiles/playrec_2ch_inPath.dir/portaudio/src/playrec_2ch_inPath.c.s

# Object files for target playrec_2ch_inPath
playrec_2ch_inPath_OBJECTS = \
"CMakeFiles/playrec_2ch_inPath.dir/portaudio/src/playrec_2ch_inPath.c.o"
>>>>>>> feature/dir

# External object files for target playrec_2ch_inPath
playrec_2ch_inPath_EXTERNAL_OBJECTS =

<<<<<<< HEAD
playrec_2ch_inPath: CMakeFiles/playrec_2ch_inPath.dir/playrec_2ch_inPath.c.o
playrec_2ch_inPath: CMakeFiles/playrec_2ch_inPath.dir/build.make
playrec_2ch_inPath: /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a
playrec_2ch_inPath: CMakeFiles/playrec_2ch_inPath.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tetsu/dev/douki_c_programs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable playrec_2ch_inPath"
=======
playrec_2ch_inPath: CMakeFiles/playrec_2ch_inPath.dir/portaudio/src/playrec_2ch_inPath.c.o
playrec_2ch_inPath: CMakeFiles/playrec_2ch_inPath.dir/build.make
playrec_2ch_inPath: /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a
playrec_2ch_inPath: CMakeFiles/playrec_2ch_inPath.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tetsu/dev/douki_C_programs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable playrec_2ch_inPath"
>>>>>>> feature/dir
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/playrec_2ch_inPath.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/playrec_2ch_inPath.dir/build: playrec_2ch_inPath

.PHONY : CMakeFiles/playrec_2ch_inPath.dir/build

CMakeFiles/playrec_2ch_inPath.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/playrec_2ch_inPath.dir/cmake_clean.cmake
.PHONY : CMakeFiles/playrec_2ch_inPath.dir/clean

CMakeFiles/playrec_2ch_inPath.dir/depend:
<<<<<<< HEAD
	cd /Users/tetsu/dev/douki_c_programs/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tetsu/dev/douki_c_programs /Users/tetsu/dev/douki_c_programs /Users/tetsu/dev/douki_c_programs/cmake-build-debug /Users/tetsu/dev/douki_c_programs/cmake-build-debug /Users/tetsu/dev/douki_c_programs/cmake-build-debug/CMakeFiles/playrec_2ch_inPath.dir/DependInfo.cmake --color=$(COLOR)
=======
	cd /Users/tetsu/dev/douki_C_programs/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tetsu/dev/douki_C_programs /Users/tetsu/dev/douki_C_programs /Users/tetsu/dev/douki_C_programs/cmake-build-debug /Users/tetsu/dev/douki_C_programs/cmake-build-debug /Users/tetsu/dev/douki_C_programs/cmake-build-debug/CMakeFiles/playrec_2ch_inPath.dir/DependInfo.cmake --color=$(COLOR)
>>>>>>> feature/dir
.PHONY : CMakeFiles/playrec_2ch_inPath.dir/depend

