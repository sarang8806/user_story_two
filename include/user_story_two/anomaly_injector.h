#ifndef ANOMALY_INJECTOR_H
#define ANOMALY_INJECTOR_H

#include "ros/ros.h"
#include "std_msgs/String.h"
#include <fstream>
#include <iostream>
#include <string>

class InjectorNode {
public:
  InjectorNode();
  void GenerateAnomalyTimestamp();

private:
  std::ifstream infile;
  std::string msg_id, vehicle_speed, engine_speed, driver_door, front_passenger,
      rear_left_door, rear_right_door, timestamp;
  std_msgs::String publisher_message;
  int line_count;
  std::string file_name;
  ros::Publisher publisher_obj;
};

#endif
