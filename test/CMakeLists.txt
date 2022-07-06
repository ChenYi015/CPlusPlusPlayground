enable_testing()

add_subdirectory(basic)
add_subdirectory(io)
add_subdirectory(multi-threading)
add_subdirectory(oop)

# factorial_test
add_executable(factorial_test factorial_test.cpp)

target_link_libraries(
    factorial_test
    _gtest_main
    pthread
)

# algorithm_test
add_executable(
    algorithm_test
    algorithm_test.cpp
)

target_link_libraries(
    algorithm_test
    _gtest_main
)

target_include_directories(
    algorithm_test
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

# sort_test
add_executable(sort_test sort_test.cpp)

target_link_libraries(
    sort_test
    _gtest_main
)

target_include_directories(
    sort_test
    PUBLIC "${PROJECT_SOURCE_DIR}/include"
)