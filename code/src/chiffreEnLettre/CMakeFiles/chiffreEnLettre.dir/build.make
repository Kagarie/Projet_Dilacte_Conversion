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
include src/chiffreEnLettre/CMakeFiles/chiffreEnLettre.dir/depend.make

# Include the progress variables for this target.
include src/chiffreEnLettre/CMakeFiles/chiffreEnLettre.dir/progress.make

# Include the compile flags for this target's objects.
include src/chiffreEnLettre/CMakeFiles/chiffreEnLettre.dir/flags.make

src/chiffreEnLettre/CMakeFiles/chiffreEnLettre.dir/chiffreEnLettre.c.o: src/chiffreEnLettre/CMakeFiles/chiffreEnLettre.dir/flags.make
src/chiffreEnLettre/CMakeFiles/chiffreEnLettre.dir/chiffreEnLettre.c.o: src/chiffreEnLettre/chiffreEnLettre.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aymeric/code/C/Projet_Dilacte_Conversion/code/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/chiffreEnLettre/CMakeFiles/chiffreEnLettre.dir/chiffreEnLettre.c.o"
	cd /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/chiffreEnLettre && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/chiffreEnLettre.dir/chiffreEnLettre.c.o -c /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/chiffreEnLettre/chiffreEnLettre.c

src/chiffreEnLettre/CMakeFiles/chiffreEnLettre.dir/chiffreEnLettre.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/chiffreEnLettre.dir/chiffreEnLettre.c.i"
	cd /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/chiffreEnLettre && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/chiffreEnLettre/chiffreEnLettre.c > CMakeFiles/chiffreEnLettre.dir/chiffreEnLettre.c.i

src/chiffreEnLettre/CMakeFiles/chiffreEnLettre.dir/chiffreEnLettre.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/chiffreEnLettre.dir/chiffreEnLettre.c.s"
	cd /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/chiffreEnLettre && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/chiffreEnLettre/chiffreEnLettre.c -o CMakeFiles/chiffreEnLettre.dir/chiffreEnLettre.c.s

# Object files for target chiffreEnLettre
chiffreEnLettre_OBJECTS = \
"CMakeFiles/chiffreEnLettre.dir/chiffreEnLettre.c.o"

# External object files for target chiffreEnLettre
chiffreEnLettre_EXTERNAL_OBJECTS =

src/chiffreEnLettre/libchiffreEnLettre.so.0.0.1: src/chiffreEnLettre/CMakeFiles/chiffreEnLettre.dir/chiffreEnLettre.c.o
src/chiffreEnLettre/libchiffreEnLettre.so.0.0.1: src/chiffreEnLettre/CMakeFiles/chiffreEnLettre.dir/build.make
src/chiffreEnLettre/libchiffreEnLettre.so.0.0.1: src/chiffreEnLettre/CMakeFiles/chiffreEnLettre.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aymeric/code/C/Projet_Dilacte_Conversion/code/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library libchiffreEnLettre.so"
	cd /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/chiffreEnLettre && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/chiffreEnLettre.dir/link.txt --verbose=$(VERBOSE)
	cd /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/chiffreEnLettre && $(CMAKE_COMMAND) -E cmake_symlink_library libchiffreEnLettre.so.0.0.1 libchiffreEnLettre.so.1 libchiffreEnLettre.so

src/chiffreEnLettre/libchiffreEnLettre.so.1: src/chiffreEnLettre/libchiffreEnLettre.so.0.0.1
	@$(CMAKE_COMMAND) -E touch_nocreate src/chiffreEnLettre/libchiffreEnLettre.so.1

src/chiffreEnLettre/libchiffreEnLettre.so: src/chiffreEnLettre/libchiffreEnLettre.so.0.0.1
	@$(CMAKE_COMMAND) -E touch_nocreate src/chiffreEnLettre/libchiffreEnLettre.so

# Rule to build all files generated by this target.
src/chiffreEnLettre/CMakeFiles/chiffreEnLettre.dir/build: src/chiffreEnLettre/libchiffreEnLettre.so

.PHONY : src/chiffreEnLettre/CMakeFiles/chiffreEnLettre.dir/build

src/chiffreEnLettre/CMakeFiles/chiffreEnLettre.dir/clean:
	cd /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/chiffreEnLettre && $(CMAKE_COMMAND) -P CMakeFiles/chiffreEnLettre.dir/cmake_clean.cmake
.PHONY : src/chiffreEnLettre/CMakeFiles/chiffreEnLettre.dir/clean

src/chiffreEnLettre/CMakeFiles/chiffreEnLettre.dir/depend:
	cd /home/aymeric/code/C/Projet_Dilacte_Conversion/code && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aymeric/code/C/Projet_Dilacte_Conversion/code /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/chiffreEnLettre /home/aymeric/code/C/Projet_Dilacte_Conversion/code /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/chiffreEnLettre /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/chiffreEnLettre/CMakeFiles/chiffreEnLettre.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/chiffreEnLettre/CMakeFiles/chiffreEnLettre.dir/depend

