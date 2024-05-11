cmake_minimum_required(VERSION 3.22)

set(This kinTest)

# project(${This} CXX)
# set(CMAKE_CXX_STANDARD 17)

set(Sources kin_test.cpp)

enable_testing()

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_executable(${This} ${Sources})

# target_link_libraries(${This} PUBLIC
#   robo_kin
#   )

# INCLUDE_DIRECTORIES(  ${PROJECT_SOURCE_DIR}/include )
# LINK_DIRECTORIES( ${PROJECT_SOURCE_DIR}/lib)
target_link_libraries(
  ${This} PUBLIC
  gtest
  gtest_main
  gmock
  gmock_main
  )



include(GoogleTest)
gtest_discover_tests(${This})

# add_test(NAME ${This} COMMAND ${This})



