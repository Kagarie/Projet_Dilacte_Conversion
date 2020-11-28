# CMake generated Testfile for 
# Source directory: /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/chiffreEnLettre
# Build directory: /home/aymeric/code/C/Projet_Dilacte_Conversion/code/build/chiffreEnLettre
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test-creat-ChiffreEnLettre[valgrind] "/usr/bin/valgrind" "--leak-check=full" "--quiet" "--error-exitcode=1" "./test-creat-ChiffreEnLettre")
set_tests_properties(test-creat-ChiffreEnLettre[valgrind] PROPERTIES  _BACKTRACE_TRIPLES "/home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/chiffreEnLettre/CMakeLists.txt;62;add_test;/home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/chiffreEnLettre/CMakeLists.txt;0;")
add_test(test-creat-ChiffreEnLettre[normal] "./test-creat-ChiffreEnLettre")
set_tests_properties(test-creat-ChiffreEnLettre[normal] PROPERTIES  _BACKTRACE_TRIPLES "/home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/chiffreEnLettre/CMakeLists.txt;64;add_test;/home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/chiffreEnLettre/CMakeLists.txt;0;")
add_test(test-get-ChiffreEnLettre[valgrind] "/usr/bin/valgrind" "--leak-check=full" "--quiet" "--error-exitcode=1" "./test-get-ChiffreEnLettre")
set_tests_properties(test-get-ChiffreEnLettre[valgrind] PROPERTIES  _BACKTRACE_TRIPLES "/home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/chiffreEnLettre/CMakeLists.txt;62;add_test;/home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/chiffreEnLettre/CMakeLists.txt;0;")
add_test(test-get-ChiffreEnLettre[normal] "./test-get-ChiffreEnLettre")
set_tests_properties(test-get-ChiffreEnLettre[normal] PROPERTIES  _BACKTRACE_TRIPLES "/home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/chiffreEnLettre/CMakeLists.txt;64;add_test;/home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/chiffreEnLettre/CMakeLists.txt;0;")
