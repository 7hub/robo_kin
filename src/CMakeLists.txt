

cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 17)


file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/*.c"
    )

add_executable("${PROJECT_NAME}" "${SOURCES}")


target_link_libraries("${PROJECT_NAME}"
        Eigen3::Eigen)