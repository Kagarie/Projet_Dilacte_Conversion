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
include chiffreEnLettre/CMakeFiles/test-creat-ChiffreEnLettre.dir/depend.make

# Include the progress variables for this target.
include chiffreEnLettre/CMakeFiles/test-creat-ChiffreEnLettre.dir/progress.make

# Include the compile flags for this target's objects.
include chiffreEnLettre/CMakeFiles/test-creat-ChiffreEnLettre.dir/flags.make

chiffreEnLettre/CMakeFiles/test-creat-ChiffreEnLettre.dir/test-creat-ChiffreEnLettre.c.o: chiffreEnLettre/CMakeFiles/test-creat-ChiffreEnLettre.dir/flags.make
chiffreEnLettre/CMakeFiles/test-creat-ChiffreEnLettre.dir/test-creat-ChiffreEnLettre.c.o: /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/chiffreEnLettre/test-creat-ChiffreEnLettre.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aymeric/code/C/Projet_Dilacte_Conversion/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object chiffreEnLettre/CMakeFiles/test-creat-ChiffreEnLettre.dir/test-creat-ChiffreEnLettre.c.o"
	cd /home/aymeric/code/C/Projet_Dilacte_Conversion/code/build/chiffreEnLettre && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test-creat-ChiffreEnLettre.dir/test-creat-ChiffreEnLettre.c.o -c /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/chiffreEnLettre/test-creat-ChiffreEnLettre.c

chiffreEnLettre/CMakeFiles/test-creat-ChiffreEnLettre.dir/test-creat-ChiffreEnLettre.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test-creat-ChiffreEnLettre.dir/test-creat-ChiffreEnLettre.c.i"
	cd /home/aymeric/code/C/Projet_Dilacte_Conversion/code/build/chiffreEnLettre && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/chiffreEnLettre/test-creat-ChiffreEnLettre.c > CMakeFiles/test-creat-ChiffreEnLettre.dir/test-creat-ChiffreEnLettre.c.i

chiffreEnLettre/CMakeFiles/test-creat-ChiffreEnLettre.dir/test-creat-ChiffreEnLettre.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test-creat-ChiffreEnLettre.dir/test-creat-ChiffreEnLettre.c.s"
	cd /home/aymeric/code/C/Projet_Dilacte_Conversion/code/build/chiffreEnLettre && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/chiffreEnLettre/test-creat-ChiffreEnLettre.c -o CMakeFiles/test-creat-ChiffreEnLettre.dir/test-creat-ChiffreEnLettre.c.s

# Object files for target test-creat-ChiffreEnLettre
test__creat__ChiffreEnLettre_OBJECTS = \
"CMakeFiles/test-creat-ChiffreEnLettre.dir/test-creat-ChiffreEnLettre.c.o"

# External object files for target test-creat-ChiffreEnLettre
test__creat__ChiffreEnLettre_EXTERNAL_OBJECTS =

chiffreEnLettre/test-creat-ChiffreEnLettre: chiffreEnLettre/CMakeFiles/test-creat-ChiffreEnLettre.dir/test-creat-ChiffreEnLettre.c.o
chiffreEnLettre/test-creat-ChiffreEnLettre: chiffreEnLettre/CMakeFiles/test-creat-ChiffreEnLettre.dir/build.make
chiffreEnLettre/test-creat-ChiffreEnLettre: chiffreEnLettre/libchiffreEnLettre.so
chiffreEnLettre/test-creat-ChiffreEnLettre: chiffreEnLettre/CMakeFiles/test-creat-ChiffreEnLettre.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aymeric/code/C/Projet_Dilacte_Conversion/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable test-creat-ChiffreEnLettre"
	cd /home/aymeric/code/C/Projet_Dilacte_Conversion/code/build/chiffreEnLettre && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test-creat-ChiffreEnLettre.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
chiffreEnLettre/CMakeFiles/test-creat-ChiffreEnLettre.dir/build: chiffreEnLettre/test-creat-ChiffreEnLettre

.PHONY : chiffreEnLettre/CMakeFiles/test-creat-ChiffreEnLettre.dir/build

chiffreEnLettre/CMakeFiles/test-creat-ChiffreEnLettre.dir/clean:
	cd /home/aymeric/code/C/Projet_Dilacte_Conversion/code/build/chiffreEnLettre && $(CMAKE_COMMAND) -P CMakeFiles/test-creat-ChiffreEnLettre.dir/cmake_clean.cmake
.PHONY : chiffreEnLettre/CMakeFiles/test-creat-ChiffreEnLettre.dir/clean

chiffreEnLettre/CMakeFiles/test-creat-ChiffreEnLettre.dir/depend:
	cd /home/aymeric/code/C/Projet_Dilacte_Conversion/code/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/chiffreEnLettre /home/aymeric/code/C/Projet_Dilacte_Conversion/code/build /home/aymeric/code/C/Projet_Dilacte_Conversion/code/build/chiffreEnLettre /home/aymeric/code/C/Projet_Dilacte_Conversion/code/build/chiffreEnLettre/CMakeFiles/test-creat-ChiffreEnLettre.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : chiffreEnLettre/CMakeFiles/test-creat-ChiffreEnLettre.dir/depend

