#include "../include/user_story_two/anomaly_detector.h"

AnomalyDetection::AnomalyDetection() {
  publisher_obj = node_handle_obj.advertise<std_msgs::String>("output", 1);
  subcriber_obj = node_handle_obj.subscribe("signal", 1,
                                            &AnomalyDetection::scallback, this);
}

void AnomalyDetection::scallback(
    const std_msgs::String::ConstPtr &receive_msg) {

  // Call CheckAnomaly()
  std_msgs::String send_to_output_node;
  std::string data_from_input_node = receive_msg->data;
  std::stringstream anomaly_timestamp = CheckAnomaly(data_from_input_node);
  if (!anomaly_timestamp.str().empty()) {
    std::cout << "Anomaly Detected! Sending Info..." << std::endl;
    send_to_output_node.data = anomaly_timestamp.str();
    publisher_obj.publish(send_to_output_node);
  }
}

std::stringstream AnomalyDetection::CheckAnomaly(std::string input_signals) {
  std::vector<std::string>
      signal_sample; // signal parameter eg. vehicle_speed, doors etc.
  std::stringstream signal(input_signals); // CAN signals from input node
  std::string
      signal_sample_value; // eg. vehicle_speed = 50.32, driver_door = 0;
  std::stringstream
      anomaly_signal_timestamp; // Anomaly affected signal timestamp

  for (int signal_count = 0; signal_count < 5; ++signal_count) {
    for (int i = 0; i < 6; ++i) {
      getline(signal, signal_sample_value, ' ');
      signal_sample.push_back(signal_sample_value);
    }
    if (signal_sample.at(0) != "") {
      if ((std::stof(signal_sample.at(0)) > 0) &&
          (std::stoi(signal_sample.at(1)) || std::stoi(signal_sample.at(2)) ||
           std::stoi(signal_sample.at(3)) || std::stoi(signal_sample.at(4)))) {
        anomaly_signal_timestamp << signal_sample.at(5) + " ";
      }
    }
    signal_sample.clear();
  }
  signal.str("");
  return anomaly_signal_timestamp; // Returning anomaly affected signal
                                   // timestamp
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "anomaly_detector");
  AnomalyDetection anomaly_detection_obj;
  ros::spin();
  return 0;
}
