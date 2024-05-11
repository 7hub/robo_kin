# Disable in-source builds to prevent source tree corruption.
if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
    message(FATAL_ERROR "FATAL: In-source builds are not allowed.")
endif()

# set(CMAKE_C_COMPILER "C:/Program Files/mingw64/bin/gcc.exe")
# set(CMAKE_CXX_COMPILER "C:/Program Files/mingw64/bin/g++.exe")

set(This robo_kin)

cmake_minimum_required(VERSION 3.22)


project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)

LINK_DIRECTORIES( ${PROJECT_SOURCE_DIR}/lib )
INCLUDE_DIRECTORIES(  ${PROJECT_SOURCE_DIR}/include )


# include(FetchContent)
# FetchContent_Declare(GSL
#     GIT_REPOSITORY "https://github.com/microsoft/GSL"
#     GIT_TAG "v3.1.0"
# )
# FetchContent_MakeAvailable(GSL)

# FetchContent_Declare(googletest
#     GIT_REPOSITORY "https://github.com/google/googletest.git"
#     GIT_TAG "release-1.11.0"
# )
# FetchContent_MakeAvailable(googletest)

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "include/")

# set(Eigen3_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include/eigen3.4.0/cmake")
find_package(Eigen3 3.4 REQUIRED NO_MODULE)
# FetchContent_Declare(
#   eigen
#   GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
#   GIT_TAG 3.3.9
# )

# FetchContent_MakeAvailable(eigen)


add_subdirectory(src)

option(PACKAGE_TESTS "Build the tests" ON)

if(PACKAGE_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()



