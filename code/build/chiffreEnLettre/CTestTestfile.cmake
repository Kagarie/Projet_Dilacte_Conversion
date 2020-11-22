# CMake generated Testfile for 
# Source directory: /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/chiffreEnLettre
# Build directory: /home/aymeric/code/C/Projet_Dilacte_Conversion/code/build/chiffreEnLettre
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test-creat[valgrind] "/usr/bin/valgrind" "--leak-check=full" "--quiet" "--error-exitcode=1" "./test-creat")
set_tests_properties(test-creat[valgrind] PROPERTIES  _BACKTRACE_TRIPLES "/home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/chiffreEnLettre/CMakeLists.txt;32;add_test;/home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/chiffreEnLettre/CMakeLists.txt;0;")
add_test(test-creat[normal] "./test-creat")
set_tests_properties(test-creat[normal] PROPERTIES  _BACKTRACE_TRIPLES "/home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/chiffreEnLettre/CMakeLists.txt;34;add_test;/home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/chiffreEnLettre/CMakeLists.txt;0;")
add_test(test-get[valgrind] "/usr/bin/valgrind" "--leak-check=full" "--quiet" "--error-exitcode=1" "./test-get")
set_tests_properties(test-get[valgrind] PROPERTIES  _BACKTRACE_TRIPLES "/home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/chiffreEnLettre/CMakeLists.txt;32;add_test;/home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/chiffreEnLettre/CMakeLists.txt;0;")
add_test(test-get[normal] "./test-get")
set_tests_properties(test-get[normal] PROPERTIES  _BACKTRACE_TRIPLES "/home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/chiffreEnLettre/CMakeLists.txt;34;add_test;/home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/chiffreEnLettre/CMakeLists.txt;0;")
