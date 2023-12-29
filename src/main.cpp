//
// Created by adalberto on 27/12/23.
//

#include "../include/controller.h"
#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv)
{
    // Control params
    int RATE;
    bool FORCECMDVEL;

    //Initializing ROS structure
    ros::init(argc, argv, "pose_control_node");
    ros::NodeHandle nh;
    ROS_INFO(" *** ROS node Pose Control successfully started! ***");

    // Loading and setting parameters from ROS Param Server
    ROS_INFO("Loading parameters from ROS Param Server");
    ros::param::get("pose_control/ros_control/rate", RATE);
    ros::param::get("pose_control/ros_control/force_cmd_vel", FORCECMDVEL);

    ros::Rate loopRate(RATE);
    std_msgs::String msg;
    string msgData;

    ROS_INFO("Node running...");
    int count = 0;

    Controller control(nh);

    while (nh.ok())
    {

        // TEST MODULE
        cout << "Current robot pose:\n" << control.getPose() << endl;



        // ROS control action
        ros::spinOnce();
        loopRate.sleep();
    }

    return 0;
}