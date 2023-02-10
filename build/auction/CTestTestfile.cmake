# CMake generated Testfile for 
# Source directory: /home/gkasha/Documents/maae/src/auction
# Build directory: /home/gkasha/Documents/maae/build/auction
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(cppcheck "/usr/bin/python3.10" "-u" "/home/gkasha/ros2_humble/install/ament_cmake_test/share/ament_cmake_test/cmake/run_test.py" "/home/gkasha/Documents/maae/build/auction/test_results/auction/cppcheck.xunit.xml" "--package-name" "auction" "--output-file" "/home/gkasha/Documents/maae/build/auction/ament_cppcheck/cppcheck.txt" "--command" "/home/gkasha/ros2_humble/install/ament_cppcheck/bin/ament_cppcheck" "--xunit-file" "/home/gkasha/Documents/maae/build/auction/test_results/auction/cppcheck.xunit.xml")
set_tests_properties(cppcheck PROPERTIES  LABELS "cppcheck;linter" TIMEOUT "300" WORKING_DIRECTORY "/home/gkasha/Documents/maae/src/auction" _BACKTRACE_TRIPLES "/home/gkasha/ros2_humble/install/ament_cmake_test/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/home/gkasha/ros2_humble/install/ament_cmake_cppcheck/share/ament_cmake_cppcheck/cmake/ament_cppcheck.cmake;66;ament_add_test;/home/gkasha/ros2_humble/install/ament_cmake_cppcheck/share/ament_cmake_cppcheck/cmake/ament_cmake_cppcheck_lint_hook.cmake;83;ament_cppcheck;/home/gkasha/ros2_humble/install/ament_cmake_cppcheck/share/ament_cmake_cppcheck/cmake/ament_cmake_cppcheck_lint_hook.cmake;0;;/home/gkasha/ros2_humble/install/ament_cmake_core/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/home/gkasha/ros2_humble/install/ament_lint_auto/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/home/gkasha/ros2_humble/install/ament_lint_auto/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/home/gkasha/ros2_humble/install/ament_cmake_core/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/home/gkasha/ros2_humble/install/ament_cmake_core/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/gkasha/Documents/maae/src/auction/CMakeLists.txt;48;ament_package;/home/gkasha/Documents/maae/src/auction/CMakeLists.txt;0;")
add_test(lint_cmake "/usr/bin/python3.10" "-u" "/home/gkasha/ros2_humble/install/ament_cmake_test/share/ament_cmake_test/cmake/run_test.py" "/home/gkasha/Documents/maae/build/auction/test_results/auction/lint_cmake.xunit.xml" "--package-name" "auction" "--output-file" "/home/gkasha/Documents/maae/build/auction/ament_lint_cmake/lint_cmake.txt" "--command" "/home/gkasha/ros2_humble/install/ament_lint_cmake/bin/ament_lint_cmake" "--xunit-file" "/home/gkasha/Documents/maae/build/auction/test_results/auction/lint_cmake.xunit.xml")
set_tests_properties(lint_cmake PROPERTIES  LABELS "lint_cmake;linter" TIMEOUT "60" WORKING_DIRECTORY "/home/gkasha/Documents/maae/src/auction" _BACKTRACE_TRIPLES "/home/gkasha/ros2_humble/install/ament_cmake_test/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/home/gkasha/ros2_humble/install/ament_cmake_lint_cmake/share/ament_cmake_lint_cmake/cmake/ament_lint_cmake.cmake;47;ament_add_test;/home/gkasha/ros2_humble/install/ament_cmake_lint_cmake/share/ament_cmake_lint_cmake/cmake/ament_cmake_lint_cmake_lint_hook.cmake;21;ament_lint_cmake;/home/gkasha/ros2_humble/install/ament_cmake_lint_cmake/share/ament_cmake_lint_cmake/cmake/ament_cmake_lint_cmake_lint_hook.cmake;0;;/home/gkasha/ros2_humble/install/ament_cmake_core/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/home/gkasha/ros2_humble/install/ament_lint_auto/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/home/gkasha/ros2_humble/install/ament_lint_auto/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/home/gkasha/ros2_humble/install/ament_cmake_core/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/home/gkasha/ros2_humble/install/ament_cmake_core/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/gkasha/Documents/maae/src/auction/CMakeLists.txt;48;ament_package;/home/gkasha/Documents/maae/src/auction/CMakeLists.txt;0;")
add_test(uncrustify "/usr/bin/python3.10" "-u" "/home/gkasha/ros2_humble/install/ament_cmake_test/share/ament_cmake_test/cmake/run_test.py" "/home/gkasha/Documents/maae/build/auction/test_results/auction/uncrustify.xunit.xml" "--package-name" "auction" "--output-file" "/home/gkasha/Documents/maae/build/auction/ament_uncrustify/uncrustify.txt" "--command" "/home/gkasha/ros2_humble/install/ament_uncrustify/bin/ament_uncrustify" "--xunit-file" "/home/gkasha/Documents/maae/build/auction/test_results/auction/uncrustify.xunit.xml")
set_tests_properties(uncrustify PROPERTIES  LABELS "uncrustify;linter" TIMEOUT "60" WORKING_DIRECTORY "/home/gkasha/Documents/maae/src/auction" _BACKTRACE_TRIPLES "/home/gkasha/ros2_humble/install/ament_cmake_test/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/home/gkasha/ros2_humble/install/ament_cmake_uncrustify/share/ament_cmake_uncrustify/cmake/ament_uncrustify.cmake;70;ament_add_test;/home/gkasha/ros2_humble/install/ament_cmake_uncrustify/share/ament_cmake_uncrustify/cmake/ament_cmake_uncrustify_lint_hook.cmake;34;ament_uncrustify;/home/gkasha/ros2_humble/install/ament_cmake_uncrustify/share/ament_cmake_uncrustify/cmake/ament_cmake_uncrustify_lint_hook.cmake;0;;/home/gkasha/ros2_humble/install/ament_cmake_core/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/home/gkasha/ros2_humble/install/ament_lint_auto/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/home/gkasha/ros2_humble/install/ament_lint_auto/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/home/gkasha/ros2_humble/install/ament_cmake_core/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/home/gkasha/ros2_humble/install/ament_cmake_core/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/gkasha/Documents/maae/src/auction/CMakeLists.txt;48;ament_package;/home/gkasha/Documents/maae/src/auction/CMakeLists.txt;0;")
add_test(xmllint "/usr/bin/python3.10" "-u" "/home/gkasha/ros2_humble/install/ament_cmake_test/share/ament_cmake_test/cmake/run_test.py" "/home/gkasha/Documents/maae/build/auction/test_results/auction/xmllint.xunit.xml" "--package-name" "auction" "--output-file" "/home/gkasha/Documents/maae/build/auction/ament_xmllint/xmllint.txt" "--command" "/home/gkasha/ros2_humble/install/ament_xmllint/bin/ament_xmllint" "--xunit-file" "/home/gkasha/Documents/maae/build/auction/test_results/auction/xmllint.xunit.xml")
set_tests_properties(xmllint PROPERTIES  LABELS "xmllint;linter" TIMEOUT "60" WORKING_DIRECTORY "/home/gkasha/Documents/maae/src/auction" _BACKTRACE_TRIPLES "/home/gkasha/ros2_humble/install/ament_cmake_test/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/home/gkasha/ros2_humble/install/ament_cmake_xmllint/share/ament_cmake_xmllint/cmake/ament_xmllint.cmake;50;ament_add_test;/home/gkasha/ros2_humble/install/ament_cmake_xmllint/share/ament_cmake_xmllint/cmake/ament_cmake_xmllint_lint_hook.cmake;18;ament_xmllint;/home/gkasha/ros2_humble/install/ament_cmake_xmllint/share/ament_cmake_xmllint/cmake/ament_cmake_xmllint_lint_hook.cmake;0;;/home/gkasha/ros2_humble/install/ament_cmake_core/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/home/gkasha/ros2_humble/install/ament_lint_auto/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/home/gkasha/ros2_humble/install/ament_lint_auto/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/home/gkasha/ros2_humble/install/ament_cmake_core/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/home/gkasha/ros2_humble/install/ament_cmake_core/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/gkasha/Documents/maae/src/auction/CMakeLists.txt;48;ament_package;/home/gkasha/Documents/maae/src/auction/CMakeLists.txt;0;")
