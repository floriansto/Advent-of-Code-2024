set(TEST_PROJECT ${PROJECT_NAME}_Test)

enable_testing()

add_executable(${TEST_PROJECT} test_day1.cpp)

target_link_libraries(${TEST_PROJECT} GTest::gtest_main)
target_link_libraries(${TEST_PROJECT} ${PROJECT_NAME})

include(GoogleTest)
gtest_discover_tests(${TEST_PROJECT})
