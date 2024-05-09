# Disable in-source builds to prevent source tree corruption.
if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
    message(FATAL_ERROR "FATAL: In-source builds are not allowed.")
endif()

# set(CMAKE_C_COMPILER "C:/Program Files/mingw64/bin/gcc.exe")
# set(CMAKE_CXX_COMPILER "C:/Program Files/mingw64/bin/g++.exe")

cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 17)

project(robo_kin CXX)

include(FetchContent)

FetchContent_Declare(GSL
    GIT_REPOSITORY "https://github.com/microsoft/GSL"
    GIT_TAG "v3.1.0"
)
FetchContent_MakeAvailable(GSL)

FetchContent_Declare(googletest
    GIT_REPOSITORY "https://github.com/google/googletest.git"
    GIT_TAG "release-1.11.0"
)
FetchContent_MakeAvailable(googletest)

FetchContent_Declare(
  eigen
  GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
  GIT_TAG 3.3.9
)

FetchContent_MakeAvailable(eigen)
# output directory
set(EXECUTABLE_OUTPUT_PATH  "${PROJECT_SOURCE_DIR}/build/bin")

add_subdirectory(src)

option(PACKAGE_TESTS "Build the tests" ON)

if(PACKAGE_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()



