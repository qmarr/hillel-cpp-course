add_executable(projectmanager-tests test_core.cpp)
target_link_libraries(projectmanager-tests PRIVATE
  projectmanager::core
  GTest::gtest
  GTest::gtest_main
)
pm_apply_warnings(projectmanager-tests)

include(GoogleTest)
gtest_discover_tests(projectmanager-tests)
