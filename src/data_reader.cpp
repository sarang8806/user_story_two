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
  ReadData() {
    file_name = "/home/sarangp1/catkin_ws/src/user_story_two/src/can_data.csv";
    subscriber_obj =
        node_handler.subscribe("inject", 1, &ReadData::InjecterCallback, this);
    FileReadOperation();
  }

  void InjecterCallback(const std_msgs::String::ConstPtr &anomaly_message) {
    anomaly_timestamp = anomaly_message->data;
  }

  void FileReadOperation() {
    ros::Publisher publisher_obj =
        node_handler.advertise<std_msgs::String>("chatter", 1);
    ros::Rate loop_rate(3);
    infile.open(file_name, std::ios::in);
    signal_count = 0;
    std_msgs::String signal_data;
    std::stringstream data_stream;
    if (infile) {
      infile.ignore(500, '\n');
      while (ros::ok() || (!infile.eof())) {
        getline(infile, msg_id, ',');
        getline(infile, vehicle_speed, ',');
        getline(infile, engine_speed, ',');
        getline(infile, driver_door, ',');
        getline(infile, front_passenger_door, ',');
        getline(infile, rear_left_door, ',');
        getline(infile, rear_right_door, ',');
        infile >> timestamp;

        if (timestamp == anomaly_timestamp) {
          driver_door = "1";
          front_passenger_door = "1";
          rear_left_door = "1";
          rear_right_door = "1";
          std::cout << "Anomaly injected in timestamp: " << timestamp
                    << std::endl;
        }

        if (infile.eof()) {
          signal_data.data = data_stream.str();
          data_stream.str("");

          publisher_obj.publish(signal_data);
          ros::shutdown();
        }
        data_stream << vehicle_speed << " " << driver_door << " "
                    << front_passenger_door << " " << rear_left_door << " "
                    << rear_right_door << " " << timestamp << " ";
        ++signal_count;

        if (signal_count == WINDOW_SIZE) {
          signal_count = 0;
          signal_data.data = data_stream.str();
          data_stream.str("");

          publisher_obj.publish(signal_data);
          signal_data.data = data_stream.str();
        }
        ros::spinOnce();
        loop_rate.sleep();
      }
    }
  }

private:
  ros::NodeHandle node_handler;
  ros::Subscriber subscriber_obj;
  std::ifstream infile;
  std::string msg_id, vehicle_speed, engine_speed, driver_door,
      front_passenger_door, rear_left_door, rear_right_door, timestamp;
  int signal_count;
  std::string file_name;
};

int main(int argc, char **argv) {

  ros::init(argc, argv, "data_reader");

  ReadData read_data_obj;

  return 0;
}
