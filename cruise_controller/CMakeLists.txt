cmake_minimum_required(VERSION 3.5)
project(cruise_controller)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(tutorial_interfaces REQUIRED)                          # CHANGE

set(dependencies
  src/Csv_ReadDynamics.cpp
  src/Velocity.cpp
  src/Acceleration.cpp
  src/VehicleStatus.cpp

)

add_executable(UI src/UI.cpp)
target_include_directories(UI
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)
ament_target_dependencies(UI rclcpp std_msgs tutorial_interfaces)


add_executable(stub ${dependencies} src/stub_node.cpp)
target_include_directories(stub
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)
ament_target_dependencies(stub rclcpp std_msgs tutorial_interfaces)

add_executable(cruise ${dependencies} src/algorithum_node.cpp)
target_include_directories(cruise
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)
ament_target_dependencies(cruise rclcpp std_msgs tutorial_interfaces)

install(TARGETS
  UI
  stub
  cruise
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY
    launch
    DESTINATION share/${PROJECT_NAME})

ament_package()
