cmake_minimum_required(VERSION 3.16)
project(occupancy_grid)

include_directories(include)
include_directories(/usr/include/eigen3)
include_directories(/home/ddario/Workspace/robot_model/include/)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

set(SOURCES 
    src/main.cpp
    src/utils.cpp
    src/occupancy_grid.cpp)

set(HEADERS
    include/utils.hpp
    include/occupancy_grid.hpp)

add_executable(occupancy_grid ${SOURCES} ${HEADERS})
target_link_libraries(occupancy_grid 
                        ${OpenCV_LIBS}
                        /home/ddario/Workspace/robot_model/build/librobot_model.so)
