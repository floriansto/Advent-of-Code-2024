add_library(day1_lib day1.cpp)
add_executable(day1 main.cpp)
target_link_libraries(day1 day1_lib)
add_executable(test_day1 test_day1.cpp)

target_link_libraries(test_day1
                      GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_day1)
