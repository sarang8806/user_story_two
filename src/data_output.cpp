#include "../include/user_story_two/data_output.h"

OutputNode::OutputNode() {
  SubscriberObj =
      NodeHandler.subscribe("output", 1, &OutputNode::OutputCallback, this);
}

void OutputNode::OutputCallback(
    const std_msgs::String::ConstPtr &received_msg) {
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
