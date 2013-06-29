#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include <skeleton_markers/VictimFinder.h>



ros::Publisher velocity_pub;

// This method is called whenever a blob message is received
void victimCallback(const skeleton_markers::VictimFinder::ConstPtr& msg){

  // This is the output velocity that we will publish
  geometry_msgs::Twist output;

  // This is an example print message
  std::cout << "found victim: " << msg->hasPrey << std::endl;

  

  if(msg->hasPrey){
		if(msg->angle > .5){
			std::cout<<"output.angular.z = -.3" << std::endl;
		}
		else if(msg->angle < -.5){
			std::cout<<"output.angular.z = .3"<< std::endl;;
		}	

		if(msg->distance > .5){
			std::cout<<"output.linear.x = .3"<< std::endl;;
		}
	}
	


    velocity_pub.publish(output); // publish this velocity message that we filled in
  

}


int main(int argc, char **argv){

	ros::init(argc, argv, "follower");
	ros::NodeHandle n;

	// advertise that we will publish cmd_vel messages
	velocity_pub = n.advertise<geometry_msgs::Twist>("cmd_vel", 1000);

	// subscribe to blob messages and call blobCallback when they are received
	ros::Subscriber sub = n.subscribe("victimDataTopic", 1000, victimCallback);   

	ros::Rate loop_rate(10);

	ros::spin();


	return 0;
}


