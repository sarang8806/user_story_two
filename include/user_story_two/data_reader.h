#ifndef DATA_READER_H
#define DATA_READER_H

#include "ros/ros.h"
#include "std_msgs/String.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <sstream>
#include <string>
#include <vector>

#define WINDOW_SIZE 5

std::string anomaly_timestamp;

class ReadData {
public:
  ReadData();
  void InjecterCallback(const std_msgs::String::ConstPtr &anomaly_message);
  void FileReadOperation();

private:
  ros::NodeHandle node_handler;
  ros::Subscriber subscriber_obj;
  std::ifstream infile;
  std::string msg_id, vehicle_speed, engine_speed, driver_door,
      front_passenger_door, rear_left_door, rear_right_door, timestamp;
  int signal_count;
  std::string file_name;
};

#endif
