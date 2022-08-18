cmake_minimum_required(VERSION 3.0.2)
project(pcd_pointcloud)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  sensor_msgs
  # pcl_ros
  pcl_conversions
)
find_package(PCL 1.2 REQUIRED)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES pcd_pointcloud
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
  ${PCL_INCLUDE_DIRS}
)

add_executable(pcd_pointcloud src/pcd_pointcloud_node.cpp)
target_link_libraries(pcd_pointcloud ${PCL_LIBRRARIES} ${catkin_LIBRARIES})