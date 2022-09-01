This is a tool that reads PCD files, and publishes ROS PointCloud.

# pcd_PointCloud

## Requirements
ROS environment

## How to compile?
```bash
$ source source /opt/ros/noetic/setup.bash
$ mkdir -p ros_ws/src && cd ros_ws/src
$ git clong https://github.com/JEFFCHANG0501/pcd_PointCloud.git
$ cd ../ && catkin_make

```

## How to use?
```bash
$ source devel/setup.bash
$ roscore
$ rosrun pcd_pointcloud pcd_pointcloud {pcd_path}

```