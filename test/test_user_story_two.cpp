#include "../include/user_story_two/anomaly_detector.h"
#include "../include/user_story_two/anomaly_injector.h"
#include "../include/user_story_two/data_output.h"
#include "../include/user_story_two/data_reader.h"

#include <gtest/gtest.h>
#include <iostream>
#include <ros/ros.h>
#include <sstream>
#include <string>

TEST(AnomalyDetection1, AnomalyDetectionTest1) {
  AnomalyDetection anomaly_detection_obj;
  std::stringstream ss;
  ss = anomaly_detection_obj.CheckAnomaly(
      "46.640625 0 1 1 0 8417174 46.984375 0 0 0 1 8417221 47.09375 0 0 0 1 "
      "8417252 47.109375 0 0 0 0 8417283 47.4375 0 0 0 0 8417314");
  std::string testStr = "8417174 8417221 8417252 ";
  EXPECT_EQ(testStr, ss.str());
}

TEST(AnomalyDetection2, AnomalyDetectionTest2) {
  AnomalyDetection anomaly_detection_obj;
  std::stringstream ss;
  ss = anomaly_detection_obj.CheckAnomaly(
      "46.640625 0 0 0 0 8417174 46.984375 0 0 0 0 8417221 47.09375 0 0 0 0 "
      "8417252 47.109375 0 0 0 0 8417283 47.4375 0 0 0 0 8417314");
  std::string testStr = "";
  EXPECT_EQ(testStr, ss.str());
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  ros::init(argc, argv, "test_user_story_two");
  ros::NodeHandle node_handler;
  return RUN_ALL_TESTS();
  ros::shutdown();
}
