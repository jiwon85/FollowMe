#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include <skeleton_markers/VictimFinder.h>



void callbackForWhenYouGetAMessage(/*msg format*/)
{
	geometry_msgs::Twist output;
	//only if the person signals, hasPrey will be true
	if(msg->hasPrey){
		//if the person if to the right of the robot, turn right
		if(msg->angle > .5){
			output.angular.z = -.3;
		}
		//if the person if to the left of the robot, turn left 
		else if(msg->angle < -.5){
			output.angular.z = .3;
		}	
		//if there is distance between the robot and person, move forward
		if(msg->distance > .5){
			output.linear.x = .3;
		}
	}
	//publish output messages to teleop 
	velocity_pub.publish(output);
}


///////////
in the main, intialize array. assign first xCoor to first array made;


const double xPrev;
const int count;
//const double[] arr;
//const double yCoor;



//how to determine when to stop.
//needs to have the same value (transform_torso.getOrigin().x()) 10 times consecutively
	
	if(count>9){
		victimdata.hasPrey = false;
	}	
	else{
		if(transform_torso.getOrigin().x() == xPrev){
			count++;
		}
		else{
			count = 0;
			xPrev = transform_torso.getOrigin().X();
		}
	}
			
