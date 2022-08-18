#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_cloud.h>
#include <pcl/console/parse.h>
#include <pcl_conversions/pcl_conversions.h> 

#include <dirent.h>
#include <vector>

using namespace std;

void read_dir(std::string dir_path, std::vector<std::string>& files)
{
    struct dirent *ptr = NULL;
    DIR *dir = opendir(dir_path.c_str());
    if (dir != NULL)
    {
        while ((ptr = readdir(dir)) != NULL)
        {
            if (ptr->d_name[0] == '.')
                continue;
            // std::cout << ptr->d_name << std::endl;
            
            string file_path = dir_path + "/" + (ptr->d_name);
            files.push_back(file_path);
        }
        closedir(dir);
    }
}

int main(int argc, char **argv)
{
    string dir_path = argv[1];
    vector<string> files;
    read_dir(dir_path, files);

    ros::init(argc, argv, "pcd_pointcloud");
    ros::NodeHandle nh;

    ros::Publisher pcd_pub = nh.advertise<sensor_msgs::PointCloud2> ("points_cloud", 10);
    
    ros::Rate loop_rate(10);
    int index = 0;
    
    while (ros::ok())
    {
        
        pcl::PointCloud<pcl::PointXYZ> cloud;
        sensor_msgs::PointCloud2 output;

        pcl::io::loadPCDFile(files[index], cloud);
        cout << files[index] << endl;
        pcl::toROSMsg(cloud, output);
        output.header.frame_id = "livox_frame";

        pcd_pub.publish(output);
        index++;
        if (index == files.size())
            break;
        ros::spinOnce();
        loop_rate.sleep();
    }
    
    return 0;
}