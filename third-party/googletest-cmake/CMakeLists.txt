set(SOURCE_DIR "${CPlusPlusPlayground_SOURCE_DIR}/third-party/googletest/googletest")

add_library(_gtest "${SOURCE_DIR}/src/gtest-all.cc")
set_target_properties(_gtest PROPERTIES VERSION "1.10.0")
target_compile_definitions(_gtest INTERFACE GTEST_HAS_POSIX_RE=0)
target_link_libraries(_gtest PRIVATE stdc++ m pthread)
target_include_directories(_gtest SYSTEM PUBLIC "${SOURCE_DIR}/include")
target_include_directories(_gtest PRIVATE "${SOURCE_DIR}")

add_library(_gtest_main "${SOURCE_DIR}/src/gtest_main.cc")
set_target_properties(_gtest_main PROPERTIES VERSION "1.10.0")
target_link_libraries(_gtest_main PUBLIC _gtest)

add_library(_gtest_all INTERFACE)
target_link_libraries(_gtest_all INTERFACE _gtest _gtest_main)