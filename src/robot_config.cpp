// src/robot_config.cpp

#include "robot_config.h"

// Sensors
pros::Imu imu(9); // IMU on port #
//pros::adi::Encoder vertical_encoder('C', 'D', true); // Vertical tracking wheel encoder on ADI ports C and D

// PID Controllers
lemlib::ControllerSettings lateral_controller(
    10, 0, 3, 3, 1, 100, 3, 500, 20
);
lemlib::ControllerSettings angular_controller(
    2, 0, 10, 3, 1, 100, 3, 500, 0
);
