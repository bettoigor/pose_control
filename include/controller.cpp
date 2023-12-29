//
// Created by adalberto on 27/12/23.
//

#include "controller.h"

Controller::Controller(ros::NodeHandle nh)
{
    ROS_INFO("Start controller...");
    this->init(nh);

}

Controller::~Controller()
{
    // Class destructor
}

void Controller::init(ros::NodeHandle nh)
{

    ROS_INFO("Starting ROS objects...");

    //Creating the publishers
    pubCmdVel = nh.advertise<geometry_msgs::Twist>("cmd_vel", 1000);

    // Creating the subscribers
    subOdom = nh.subscribe("odom", 1000, &Controller::callbackOdom, this);
}

void Controller::callbackOdom(nav_msgs::Odometry msg)
{

    // Computing orientation using quaternion to Euler conversion
    tf::Quaternion q(msg.pose.pose.orientation.x,
                     msg.pose.pose.orientation.y,
                     msg.pose.pose.orientation.z,
                     msg.pose.pose.orientation.w);
    tf::Matrix3x3 m(q);
    double roll, pitch, yaw;
    m.getRPY(roll, pitch, yaw);
    float theta = yaw;

    pose.x = msg.pose.pose.position.x;
    pose.y = msg.pose.pose.position.y;
    pose.theta = theta;

}

geometry_msgs::Pose2D Controller::getPose()
{
    return pose;
}
