if(EXISTS "/workspaces/cs225env/release-f22/lab_debug/build/test_tests-b12d07c.cmake")
  include("/workspaces/cs225env/release-f22/lab_debug/build/test_tests-b12d07c.cmake")
else()
  add_test(test_NOT_BUILT-b12d07c test_NOT_BUILT-b12d07c)
endif()
