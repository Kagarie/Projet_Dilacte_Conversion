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
include src/utils/CMakeFiles/utils.dir/depend.make

# Include the progress variables for this target.
include src/utils/CMakeFiles/utils.dir/progress.make

# Include the compile flags for this target's objects.
include src/utils/CMakeFiles/utils.dir/flags.make

src/utils/CMakeFiles/utils.dir/utils.c.o: src/utils/CMakeFiles/utils.dir/flags.make
src/utils/CMakeFiles/utils.dir/utils.c.o: src/utils/utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aymeric/code/C/Projet_Dilacte_Conversion/code/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/utils/CMakeFiles/utils.dir/utils.c.o"
	cd /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/utils && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/utils.dir/utils.c.o -c /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/utils/utils.c

src/utils/CMakeFiles/utils.dir/utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/utils.dir/utils.c.i"
	cd /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/utils && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/utils/utils.c > CMakeFiles/utils.dir/utils.c.i

src/utils/CMakeFiles/utils.dir/utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/utils.dir/utils.c.s"
	cd /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/utils && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/utils/utils.c -o CMakeFiles/utils.dir/utils.c.s

# Object files for target utils
utils_OBJECTS = \
"CMakeFiles/utils.dir/utils.c.o"

# External object files for target utils
utils_EXTERNAL_OBJECTS =

src/utils/libutils.so.0.0.1: src/utils/CMakeFiles/utils.dir/utils.c.o
src/utils/libutils.so.0.0.1: src/utils/CMakeFiles/utils.dir/build.make
src/utils/libutils.so.0.0.1: src/utils/CMakeFiles/utils.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aymeric/code/C/Projet_Dilacte_Conversion/code/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library libutils.so"
	cd /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/utils && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/utils.dir/link.txt --verbose=$(VERBOSE)
	cd /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/utils && $(CMAKE_COMMAND) -E cmake_symlink_library libutils.so.0.0.1 libutils.so.1 libutils.so

src/utils/libutils.so.1: src/utils/libutils.so.0.0.1
	@$(CMAKE_COMMAND) -E touch_nocreate src/utils/libutils.so.1

src/utils/libutils.so: src/utils/libutils.so.0.0.1
	@$(CMAKE_COMMAND) -E touch_nocreate src/utils/libutils.so

# Rule to build all files generated by this target.
src/utils/CMakeFiles/utils.dir/build: src/utils/libutils.so

.PHONY : src/utils/CMakeFiles/utils.dir/build

src/utils/CMakeFiles/utils.dir/clean:
	cd /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/utils && $(CMAKE_COMMAND) -P CMakeFiles/utils.dir/cmake_clean.cmake
.PHONY : src/utils/CMakeFiles/utils.dir/clean

src/utils/CMakeFiles/utils.dir/depend:
	cd /home/aymeric/code/C/Projet_Dilacte_Conversion/code && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aymeric/code/C/Projet_Dilacte_Conversion/code /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/utils /home/aymeric/code/C/Projet_Dilacte_Conversion/code /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/utils /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/utils/CMakeFiles/utils.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/utils/CMakeFiles/utils.dir/depend

