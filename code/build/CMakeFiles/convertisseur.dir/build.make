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
CMAKE_SOURCE_DIR = /home/aymeric/code/C/Projet/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aymeric/code/C/Projet/build

# Include any dependencies generated for this target.
include CMakeFiles/convertisseur.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/convertisseur.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/convertisseur.dir/flags.make

CMakeFiles/convertisseur.dir/convertisseur.c.o: CMakeFiles/convertisseur.dir/flags.make
CMakeFiles/convertisseur.dir/convertisseur.c.o: /home/aymeric/code/C/Projet/src/convertisseur.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aymeric/code/C/Projet/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/convertisseur.dir/convertisseur.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/convertisseur.dir/convertisseur.c.o -c /home/aymeric/code/C/Projet/src/convertisseur.c

CMakeFiles/convertisseur.dir/convertisseur.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/convertisseur.dir/convertisseur.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aymeric/code/C/Projet/src/convertisseur.c > CMakeFiles/convertisseur.dir/convertisseur.c.i

CMakeFiles/convertisseur.dir/convertisseur.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/convertisseur.dir/convertisseur.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aymeric/code/C/Projet/src/convertisseur.c -o CMakeFiles/convertisseur.dir/convertisseur.c.s

# Object files for target convertisseur
convertisseur_OBJECTS = \
"CMakeFiles/convertisseur.dir/convertisseur.c.o"

# External object files for target convertisseur
convertisseur_EXTERNAL_OBJECTS =

convertisseur: CMakeFiles/convertisseur.dir/convertisseur.c.o
convertisseur: CMakeFiles/convertisseur.dir/build.make
convertisseur: CMakeFiles/convertisseur.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aymeric/code/C/Projet/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable convertisseur"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/convertisseur.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/convertisseur.dir/build: convertisseur

.PHONY : CMakeFiles/convertisseur.dir/build

CMakeFiles/convertisseur.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/convertisseur.dir/cmake_clean.cmake
.PHONY : CMakeFiles/convertisseur.dir/clean

CMakeFiles/convertisseur.dir/depend:
	cd /home/aymeric/code/C/Projet/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aymeric/code/C/Projet/src /home/aymeric/code/C/Projet/src /home/aymeric/code/C/Projet/build /home/aymeric/code/C/Projet/build /home/aymeric/code/C/Projet/build/CMakeFiles/convertisseur.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/convertisseur.dir/depend
