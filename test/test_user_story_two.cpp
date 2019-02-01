#include "../include/user_story_two/anomaly_detector.h"
#include "../include/user_story_two/anomaly_injector.h"
#include "../include/user_story_two/data_output.h"
#include "../include/user_story_two/data_reader.h"

#include <gtest/gtest.h>
#include <string>
#include <iostream>

TEST(AnomalyDetection, AnomalyDetectionTest) {
	AnomalyDetection anomaly_detection_obj;
	//EXPECT_STREQ("", anomaly_detection_obj.CheckAnomaly("50.53125 0 0 0 0 8417751").str());
	//EXPECT_STREQ("8417455", anomaly_detection_obj.CheckAnomaly("48.14063 0 1 1 0 8417455").str());
}


int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	ros::init(argc, argv, "test_user_story_two");
	ros::NodeHandle node_handler;	
	return RUN_ALL_TESTS();		
}

