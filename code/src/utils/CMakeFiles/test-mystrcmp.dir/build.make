# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = /home/aymeric/code/C/Projet_Dilacte_Conversion/code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aymeric/code/C/Projet_Dilacte_Conversion/code

# Include any dependencies generated for this target.
include src/utils/CMakeFiles/test-mystrcmp.dir/depend.make

# Include the progress variables for this target.
include src/utils/CMakeFiles/test-mystrcmp.dir/progress.make

# Include the compile flags for this target's objects.
include src/utils/CMakeFiles/test-mystrcmp.dir/flags.make

src/utils/CMakeFiles/test-mystrcmp.dir/test-mystrcmp.c.o: src/utils/CMakeFiles/test-mystrcmp.dir/flags.make
src/utils/CMakeFiles/test-mystrcmp.dir/test-mystrcmp.c.o: src/utils/test-mystrcmp.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aymeric/code/C/Projet_Dilacte_Conversion/code/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/utils/CMakeFiles/test-mystrcmp.dir/test-mystrcmp.c.o"
	cd /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/utils && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test-mystrcmp.dir/test-mystrcmp.c.o -c /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/utils/test-mystrcmp.c

src/utils/CMakeFiles/test-mystrcmp.dir/test-mystrcmp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test-mystrcmp.dir/test-mystrcmp.c.i"
	cd /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/utils && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/utils/test-mystrcmp.c > CMakeFiles/test-mystrcmp.dir/test-mystrcmp.c.i

src/utils/CMakeFiles/test-mystrcmp.dir/test-mystrcmp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test-mystrcmp.dir/test-mystrcmp.c.s"
	cd /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/utils && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/utils/test-mystrcmp.c -o CMakeFiles/test-mystrcmp.dir/test-mystrcmp.c.s

# Object files for target test-mystrcmp
test__mystrcmp_OBJECTS = \
"CMakeFiles/test-mystrcmp.dir/test-mystrcmp.c.o"

# External object files for target test-mystrcmp
test__mystrcmp_EXTERNAL_OBJECTS =

src/utils/test-mystrcmp: src/utils/CMakeFiles/test-mystrcmp.dir/test-mystrcmp.c.o
src/utils/test-mystrcmp: src/utils/CMakeFiles/test-mystrcmp.dir/build.make
src/utils/test-mystrcmp: src/utils/libutils.so.0.0.1
src/utils/test-mystrcmp: src/utils/CMakeFiles/test-mystrcmp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aymeric/code/C/Projet_Dilacte_Conversion/code/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable test-mystrcmp"
	cd /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/utils && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test-mystrcmp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/utils/CMakeFiles/test-mystrcmp.dir/build: src/utils/test-mystrcmp

.PHONY : src/utils/CMakeFiles/test-mystrcmp.dir/build

src/utils/CMakeFiles/test-mystrcmp.dir/clean:
	cd /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/utils && $(CMAKE_COMMAND) -P CMakeFiles/test-mystrcmp.dir/cmake_clean.cmake
.PHONY : src/utils/CMakeFiles/test-mystrcmp.dir/clean

src/utils/CMakeFiles/test-mystrcmp.dir/depend:
	cd /home/aymeric/code/C/Projet_Dilacte_Conversion/code && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aymeric/code/C/Projet_Dilacte_Conversion/code /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/utils /home/aymeric/code/C/Projet_Dilacte_Conversion/code /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/utils /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/utils/CMakeFiles/test-mystrcmp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/utils/CMakeFiles/test-mystrcmp.dir/depend
