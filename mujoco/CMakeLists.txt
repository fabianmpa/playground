cmake_minimum_required(VERSION 3.10)

# set the project name
project(mExample)

# add the executable
add_executable(mExample example.cpp)
include_directories(/home/fabian/Mujoco/mujoco-2.1.1/include)
target_link_libraries(mExample /home/fabian/Mujoco/mujoco-2.1.1/lib/libmujoco.so.2.1.1
                               /home/fabian/Mujoco/mujoco-2.1.1/lib/libglew.so
                               /home/fabian/Mujoco/mujoco-2.1.1/lib/libglewegl.so
                               /home/fabian/Mujoco/mujoco-2.1.1/lib/libglfw.so.3)