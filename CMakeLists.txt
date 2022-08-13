project(occupancy_grid)

include_directories(include)
include_directories(/usr/include/eigen3)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

set(SOURCES 
    src/main.cpp)

set(HEADERS)

add_executable(occupancy_grid ${SOURCES} ${HEADERS})
target_link_libraries(occupancy_grid ${OpenCV_LIBS})
