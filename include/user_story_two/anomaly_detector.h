#ifndef ANOMALY_DETECTOR_H
#define ANOMALY_DETECTOR_H

#include "ros/ros.h"
#include "std_msgs/String.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#define COLUMN_COUNT 6

class AnomalyDetection {
public:
  AnomalyDetection();
  void DetectorCallback(const std_msgs::String::ConstPtr &receive_msg);
  std::stringstream CheckAnomaly(std::string input_signals);

private:
  ros::Subscriber subcriber_obj;
  ros::Publisher publisher_obj;
  ros::NodeHandle node_handle_obj;
};

#endif
