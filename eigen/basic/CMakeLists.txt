cmake_minimum_required (VERSION 3.0)
project (beigen)
find_package (Eigen3 REQUIRED)
add_executable (${PROJECT_NAME} eigen.cpp)
target_link_libraries (${PROJECT_NAME} Eigen3::Eigen)
