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
include utils/CMakeFiles/test-my_strcat.dir/depend.make

# Include the progress variables for this target.
include utils/CMakeFiles/test-my_strcat.dir/progress.make

# Include the compile flags for this target's objects.
include utils/CMakeFiles/test-my_strcat.dir/flags.make

utils/CMakeFiles/test-my_strcat.dir/test-my_strcat.c.o: utils/CMakeFiles/test-my_strcat.dir/flags.make
utils/CMakeFiles/test-my_strcat.dir/test-my_strcat.c.o: /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/utils/test-my_strcat.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aymeric/code/C/Projet_Dilacte_Conversion/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object utils/CMakeFiles/test-my_strcat.dir/test-my_strcat.c.o"
	cd /home/aymeric/code/C/Projet_Dilacte_Conversion/code/build/utils && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test-my_strcat.dir/test-my_strcat.c.o -c /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/utils/test-my_strcat.c

utils/CMakeFiles/test-my_strcat.dir/test-my_strcat.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test-my_strcat.dir/test-my_strcat.c.i"
	cd /home/aymeric/code/C/Projet_Dilacte_Conversion/code/build/utils && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/utils/test-my_strcat.c > CMakeFiles/test-my_strcat.dir/test-my_strcat.c.i

utils/CMakeFiles/test-my_strcat.dir/test-my_strcat.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test-my_strcat.dir/test-my_strcat.c.s"
	cd /home/aymeric/code/C/Projet_Dilacte_Conversion/code/build/utils && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/utils/test-my_strcat.c -o CMakeFiles/test-my_strcat.dir/test-my_strcat.c.s

# Object files for target test-my_strcat
test__my_strcat_OBJECTS = \
"CMakeFiles/test-my_strcat.dir/test-my_strcat.c.o"

# External object files for target test-my_strcat
test__my_strcat_EXTERNAL_OBJECTS =

utils/test-my_strcat: utils/CMakeFiles/test-my_strcat.dir/test-my_strcat.c.o
utils/test-my_strcat: utils/CMakeFiles/test-my_strcat.dir/build.make
utils/test-my_strcat: utils/libutils.so
utils/test-my_strcat: utils/CMakeFiles/test-my_strcat.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aymeric/code/C/Projet_Dilacte_Conversion/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable test-my_strcat"
	cd /home/aymeric/code/C/Projet_Dilacte_Conversion/code/build/utils && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test-my_strcat.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
utils/CMakeFiles/test-my_strcat.dir/build: utils/test-my_strcat

.PHONY : utils/CMakeFiles/test-my_strcat.dir/build

utils/CMakeFiles/test-my_strcat.dir/clean:
	cd /home/aymeric/code/C/Projet_Dilacte_Conversion/code/build/utils && $(CMAKE_COMMAND) -P CMakeFiles/test-my_strcat.dir/cmake_clean.cmake
.PHONY : utils/CMakeFiles/test-my_strcat.dir/clean

utils/CMakeFiles/test-my_strcat.dir/depend:
	cd /home/aymeric/code/C/Projet_Dilacte_Conversion/code/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/utils /home/aymeric/code/C/Projet_Dilacte_Conversion/code/build /home/aymeric/code/C/Projet_Dilacte_Conversion/code/build/utils /home/aymeric/code/C/Projet_Dilacte_Conversion/code/build/utils/CMakeFiles/test-my_strcat.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : utils/CMakeFiles/test-my_strcat.dir/depend

