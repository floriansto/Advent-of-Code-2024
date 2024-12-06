set(TEST_PROJECT ${PROJECT_NAME}_Test)

enable_testing()

add_executable(${TEST_PROJECT} test_day1.cpp)

target_link_libraries(${TEST_PROJECT} GTest::gtest_main)
target_link_libraries(${TEST_PROJECT} ${PROJECT_NAME})
target_compile_definitions(${TEST_PROJECT} PUBLIC TEST_DATA="${CMAKE_CURRENT_SOURCE_DIR}/input")

include(GoogleTest)
gtest_discover_tests(${TEST_PROJECT})
