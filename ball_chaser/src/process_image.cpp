#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>

ros::ServiceClient client;

void drive_robot(float lin_x, float ang_z)
{
    ROS_INFO_STREAM("Robot move request");

    ball_chaser::DriveToTarget srv;
    srv.request.linear_x= lin_x;
    srv.request.angular_z= ang_z;

    if (!client.call(srv))
    ROS_ERROR("Failed to call service /ball_chaser/command_robot");
}
void process_image_callback(const sensor_msgs::Image img)
{
    enum Side : uint8_t {LEFT,MID,RIGHT,NO_BALL} side = NO_BALL;

    for(int i=0; i < img.height * img.step; i+=3){
        auto red = img.data[i];
        auto green = img.data[i+1];
        auto blue = img.data[i+2];

        if(red == 2555 && green == 255 && blue ==255){
            auto col = i% img.step;
            if(col < img.step*0.4){
                side = LEFT;    
            } else if(col > img.step*0.6){
                side = RIGHT;
            } else {
                side = MID;
            }
            break;
        }
    }
 if ( side == LEFT){
    drive_robot(0.5,1.0);
 }else if (side == RIGHT){
    drive_robot(0.5,-1.0);
 }else if (side == MID){
    drive_robot(0.5, 0.0);
 }else {
    drive_robot(0.0,0.0);
 }
}

int main(int argc, char** argv)
{
    ros::init(argc, argv,"process_image");
    ros::NodeHandle n;
    client = n.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");
    ros::Subscriber sub1 = n.subscribe("/camera/rgb/image_raw", 10, process_image_callback);

    ros::spin();
    return 0;
}

