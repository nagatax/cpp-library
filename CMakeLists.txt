cmake_minimum_required(VERSION 3.14)
project(cpplang_library)

set(CMAKE_CXX_STANDARD 17)

# Add include directories
include_directories(${PROJECT_SOURCE_DIR}/vendor/googletest/include)

# Define linking static libraries
set(static_libraries
        ${PROJECT_SOURCE_DIR}/vendor/googletest/lib/libgtest.a
        ${PROJECT_SOURCE_DIR}/vendor/googletest/lib/libgtest_main.a
        )

# Define source files
set(cpplang_src
        src/array.cpp
        test/array_unittest.cpp
        main.cpp
        )

add_executable(cpplang_library ${cpplang_src})
target_link_libraries(cpplang_library ${static_libraries})

