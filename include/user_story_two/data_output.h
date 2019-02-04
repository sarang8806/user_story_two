#ifndef DATA_OUTPUT_H
#define DATA_OUTPUT_H

#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>

class OutputNode {
public:
  OutputNode();
  void OutputCallback(const std_msgs::String::ConstPtr &received_msg);

private:
  ros::NodeHandle NodeHandler;

  ros::Subscriber SubscriberObj;
};

#endif
