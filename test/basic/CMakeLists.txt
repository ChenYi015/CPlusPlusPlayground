# 0001_auto_test
add_executable(0001_auto_test 0001_auto_test.cpp)

target_link_libraries(
    0001_auto_test
    stdc++
    _gtest_main
)

# 0002_default_test
add_executable(0002_default_test 0002_default_test.cpp)

target_link_libraries(
    0002_default_test
    _gtest_main
)

# 0003_delete_test
add_executable(0003_delete_test 0003_delete_test.cpp)

target_link_libraries(
    0003_delete_test
    stdc++
    _gtest_main
)

# 0004_override_test
add_executable(0004_override_test 0004_override_test.cpp)

target_link_libraries(
    0004_override_test
    stdc++
    _gtest_main
)

# 0005_final_test
add_executable(0005_final_test 0005_final_test.cpp)

target_link_libraries(
    0005_final_test
    stdc++
    _gtest_main
)

# 0006_decltype_test
add_executable(0006_decltype_test 0006_decltype_test.cpp)

target_link_libraries(
    0006_decltype_test
    _gtest_main
)

# 0007_noexcept_test
add_executable(0007_noexcept_test 0007_noexcept_test.cpp)

target_link_libraries(
    0007_noexcept_test
    _gtest_main
)

# 0008_foreach_test
add_executable(0008_foreach_test 0008_foreach_test.cpp)

target_link_libraries(
    0008_foreach_test
    stdc++
    _gtest_main
)

# 0009_lambda_test
add_executable(0009_lambda_test 0009_lambda_test.cpp)

target_link_libraries(
    0009_lambda_test
    stdc++
    _gtest_main
)

target_include_directories(
    0009_lambda_test
    PUBLIC "${PROJECT_SOURCE_DIR}/include"
)

# 0010_shared_ptr_test
add_executable(0010_shared_ptr_test 0010_shared_ptr_test.cpp)

target_link_libraries(
    0010_shared_ptr_test
    stdc++
    _gtest_main
)

# 0011_unique_ptr_test
add_executable(0011_unique_ptr_test 0011_unique_ptr_test.cpp)

target_link_libraries(
    0011_unique_ptr_test
    stdc++
    _gtest_main
)

# TODO: 0012_weak_ptr_test
