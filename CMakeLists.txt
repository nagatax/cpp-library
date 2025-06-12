cmake_minimum_required(VERSION 3.10)
project(cpplang_library)

set(CMAKE_CXX_STANDARD 17)

# Find GoogleTest from system
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(static_libraries ${GTEST_LIBRARIES} -lpthread)

# Define source files
set(cpplang_src
        src/array.cpp
        src/hashtable.cpp
        src/math.cpp
        test/array_unittest.cpp
        test/hashtable_unittest.cpp
        test/math_unittest.cpp
        main.cpp
        )

add_executable(cpplang_library ${cpplang_src})
target_link_libraries(cpplang_library ${static_libraries})

