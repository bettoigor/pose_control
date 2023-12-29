//
// Created by adalberto on 27/12/23.
//

#ifndef POSE_CONTROL_CONTROLLER_H
#define POSE_CONTROL_CONTROLLER_H

#include <ros/ros.h>
#include <ros/console.h>
#include <sensor_msgs/Image.h>
#include <std_msgs/Bool.h>
#include <image_transport/image_transport.h>
#include <geometry_msgs/Pose2D.h>
#include <geometry_msgs/Twist.h>
#include <nav_msgs/Odometry.h>
#include <tf/transform_datatypes.h>
#include <pose_control/Mission.h>
#include <nav_msgs/Odometry.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <thread>

using namespace std;


class Controller {

private:

    // Creating ROS publisher and subscribers
    ros::Publisher pubCmdVel;
    ros::Publisher pubStatus;
    ros::Subscriber subOdom;
    ros::Subscriber subStart;
    ros::Subscriber subMission;


    // Gain vector
    vector<float> GAINS{0.0, 0.0, 0.0};

    // Control variables
    pose_control::Mission mission;
    std_msgs::Bool isStart;
    geometry_msgs::Twist cmdVel;
    geometry_msgs::Pose2D pose;

public:

    // Public Variables


    // Constructors
    Controller(ros::NodeHandle nh);

    ~Controller();

    void init(ros::NodeHandle nh);


    // Getters
    geometry_msgs::Pose2D getPose();

    // Setters


    // Callbacks
    void callbackOdom(nav_msgs::Odometry msg);
    void callbackMission(pose_control::Mission msg);

    // Workers


};


#endif //POSE_CONTROL_CONTROLLER_H
