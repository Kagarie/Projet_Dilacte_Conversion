# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aymeric/code/C/Projet_Dilacte_Conversion/code/build

# Include any dependencies generated for this target.
include array/CMakeFiles/test-affiche-array.dir/depend.make

# Include the progress variables for this target.
include array/CMakeFiles/test-affiche-array.dir/progress.make

# Include the compile flags for this target's objects.
include array/CMakeFiles/test-affiche-array.dir/flags.make

array/CMakeFiles/test-affiche-array.dir/test-affiche-array.c.o: array/CMakeFiles/test-affiche-array.dir/flags.make
array/CMakeFiles/test-affiche-array.dir/test-affiche-array.c.o: /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/array/test-affiche-array.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aymeric/code/C/Projet_Dilacte_Conversion/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object array/CMakeFiles/test-affiche-array.dir/test-affiche-array.c.o"
	cd /home/aymeric/code/C/Projet_Dilacte_Conversion/code/build/array && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test-affiche-array.dir/test-affiche-array.c.o -c /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/array/test-affiche-array.c

array/CMakeFiles/test-affiche-array.dir/test-affiche-array.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test-affiche-array.dir/test-affiche-array.c.i"
	cd /home/aymeric/code/C/Projet_Dilacte_Conversion/code/build/array && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/array/test-affiche-array.c > CMakeFiles/test-affiche-array.dir/test-affiche-array.c.i

array/CMakeFiles/test-affiche-array.dir/test-affiche-array.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test-affiche-array.dir/test-affiche-array.c.s"
	cd /home/aymeric/code/C/Projet_Dilacte_Conversion/code/build/array && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/array/test-affiche-array.c -o CMakeFiles/test-affiche-array.dir/test-affiche-array.c.s

# Object files for target test-affiche-array
test__affiche__array_OBJECTS = \
"CMakeFiles/test-affiche-array.dir/test-affiche-array.c.o"

# External object files for target test-affiche-array
test__affiche__array_EXTERNAL_OBJECTS =

array/test-affiche-array: array/CMakeFiles/test-affiche-array.dir/test-affiche-array.c.o
array/test-affiche-array: array/CMakeFiles/test-affiche-array.dir/build.make
array/test-affiche-array: array/libarray.so
array/test-affiche-array: chiffreEnLettre/libchiffreEnLettre.so
array/test-affiche-array: array/CMakeFiles/test-affiche-array.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aymeric/code/C/Projet_Dilacte_Conversion/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable test-affiche-array"
	cd /home/aymeric/code/C/Projet_Dilacte_Conversion/code/build/array && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test-affiche-array.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
array/CMakeFiles/test-affiche-array.dir/build: array/test-affiche-array

.PHONY : array/CMakeFiles/test-affiche-array.dir/build

array/CMakeFiles/test-affiche-array.dir/clean:
	cd /home/aymeric/code/C/Projet_Dilacte_Conversion/code/build/array && $(CMAKE_COMMAND) -P CMakeFiles/test-affiche-array.dir/cmake_clean.cmake
.PHONY : array/CMakeFiles/test-affiche-array.dir/clean

array/CMakeFiles/test-affiche-array.dir/depend:
	cd /home/aymeric/code/C/Projet_Dilacte_Conversion/code/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/array /home/aymeric/code/C/Projet_Dilacte_Conversion/code/build /home/aymeric/code/C/Projet_Dilacte_Conversion/code/build/array /home/aymeric/code/C/Projet_Dilacte_Conversion/code/build/array/CMakeFiles/test-affiche-array.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : array/CMakeFiles/test-affiche-array.dir/depend

