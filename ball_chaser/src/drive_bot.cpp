#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "ball_chaser/DriveToTarget.h"

ros::Publisher motor_command_publisher;
//callback function
bool handle_drive_request(ball_chaser::DriveToTarget::Request & req, ball_chaser::DriveToTarget::Response & res)
{
    auto linear_x = (float)req.linear_x;
    auto angular_z = (float)req.angular_z;

    ROS_INFO("DriveToTargetRequest received - linear_x%1.2f, angular_z%1.2f", linear_x, angular_z);
    geometry_msgs::Twist motor_command;
    motor_command.linear.x = linear_x;
    motor_command.angular.z = angular_z;
    motor_command_publisher.publish(motor_command);
    res.msg_feedback = "move command is set - linear_x:" + std::to_string(linear_x) +", angular_z:" + std::to_string(angular_z);
    ROS_INFO_STREAM(res.msg_feedback);
    return true;

}

int main (int argc, char** argv)
{
    ros::init(argc, argv, "drive_bot");
    ros::NodeHandle n;
    motor_command_publisher = n.advertise<geometry_msgs::Twist>("/cmd_vel", 10);
    ros::ServiceServer service= n.advertiseService("/ball_chaser/command_robot", handle_drive_request);
    ROS_INFO("Bot is ready");
    ros::spin();

    return 0;
}
