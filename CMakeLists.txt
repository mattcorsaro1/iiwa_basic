cmake_minimum_required(VERSION 2.8.3)
project(iiwa_basic)

set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

find_package(catkin REQUIRED COMPONENTS
  roscpp
  iiwa_msgs
  iiwa_ros
)

catkin_package(
 CATKIN_DEPENDS iiwa_msgs iiwa_ros
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(iiwa_basic_controller src/basic_iiwa_publisher.cpp)
add_dependencies(iiwa_basic_controller ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(iiwa_basic_controller
  ${catkin_LIBRARIES}
)
