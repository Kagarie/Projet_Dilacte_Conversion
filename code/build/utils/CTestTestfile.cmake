# CMake generated Testfile for 
# Source directory: /home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/utils
# Build directory: /home/aymeric/code/C/Projet_Dilacte_Conversion/code/build/utils
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test-my_strcat[valgrind] "/usr/bin/valgrind" "--leak-check=full" "--quiet" "--error-exitcode=1" "./test-my_strcat")
set_tests_properties(test-my_strcat[valgrind] PROPERTIES  _BACKTRACE_TRIPLES "/home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/utils/CMakeLists.txt;53;add_test;/home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/utils/CMakeLists.txt;0;")
add_test(test-my_strcat[normal] "./test-my_strcat")
set_tests_properties(test-my_strcat[normal] PROPERTIES  _BACKTRACE_TRIPLES "/home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/utils/CMakeLists.txt;54;add_test;/home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/utils/CMakeLists.txt;0;")
add_test(test-mystrcmp[valgrind] "/usr/bin/valgrind" "--leak-check=full" "--quiet" "--error-exitcode=1" "./test-mystrcmp")
set_tests_properties(test-mystrcmp[valgrind] PROPERTIES  _BACKTRACE_TRIPLES "/home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/utils/CMakeLists.txt;53;add_test;/home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/utils/CMakeLists.txt;0;")
add_test(test-mystrcmp[normal] "./test-mystrcmp")
set_tests_properties(test-mystrcmp[normal] PROPERTIES  _BACKTRACE_TRIPLES "/home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/utils/CMakeLists.txt;54;add_test;/home/aymeric/code/C/Projet_Dilacte_Conversion/code/src/utils/CMakeLists.txt;0;")
