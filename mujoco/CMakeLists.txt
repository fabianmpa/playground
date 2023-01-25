cmake_minimum_required(VERSION 3.10)

# set the project name
project(mExample)

# add the executable
add_executable(mExample example.cpp)
include_directories(/home/fabsmpa/Mujoco/mujoco-2.2.0/include/mujoco/)
target_link_libraries(mExample /home/fabsmpa/Mujoco/mujoco-2.2.0/lib/libmujoco.so)