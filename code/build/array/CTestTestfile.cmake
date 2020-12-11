# CMake generated Testfile for 
# Source directory: /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/array
# Build directory: /home/aymeric/code/C/Projet_Dilacte_Conversion/code/build/array
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test-affiche-array[valgrind] "/usr/bin/valgrind" "--leak-check=full" "--quiet" "--error-exitcode=1" "./test-affiche-array")
set_tests_properties(test-affiche-array[valgrind] PROPERTIES  _BACKTRACE_TRIPLES "/home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/array/CMakeLists.txt;51;add_test;/home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/array/CMakeLists.txt;0;")
add_test(test-affiche-array[normal] "./test-affiche-array")
set_tests_properties(test-affiche-array[normal] PROPERTIES  _BACKTRACE_TRIPLES "/home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/array/CMakeLists.txt;52;add_test;/home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/array/CMakeLists.txt;0;")
add_test(test-creat-array[valgrind] "/usr/bin/valgrind" "--leak-check=full" "--quiet" "--error-exitcode=1" "./test-creat-array")
set_tests_properties(test-creat-array[valgrind] PROPERTIES  _BACKTRACE_TRIPLES "/home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/array/CMakeLists.txt;51;add_test;/home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/array/CMakeLists.txt;0;")
add_test(test-creat-array[normal] "./test-creat-array")
set_tests_properties(test-creat-array[normal] PROPERTIES  _BACKTRACE_TRIPLES "/home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/array/CMakeLists.txt;52;add_test;/home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/array/CMakeLists.txt;0;")
