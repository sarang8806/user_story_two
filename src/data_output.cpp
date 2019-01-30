#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>

class OutputNode {
public:
  OutputNode() {
    SubscriberObj =
        NodeHandler.subscribe("output", 1, &OutputNode::cCallback, this);
  }

  void cCallback(const std_msgs::String::ConstPtr &received_msg);

private:
  ros::NodeHandle NodeHandler;

  ros::Subscriber SubscriberObj;
};

void OutputNode::cCallback(const std_msgs::String::ConstPtr &received_msg) {
  std::cout << "Timestamp/s with anomaly " << received_msg->data << std::endl;
  std::cout
      << "==================================================================="
      << std::endl;
}

int main(int argc, char **argv) {

  ros::init(argc, argv, "data_output");
  OutputNode OutputNodeObj;

  ros::spin();

  return 0;
}
