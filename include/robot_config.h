// include/robot_config.h

#pragma once

#include "lemlib/chassis/chassis.hpp"
#include "pros/adi.hpp"
#include "pros/imu.hpp"

// Drivetrain motor ports
#define LEFT_MOTOR_PORTS {1, 2, 3}
#define RIGHT_MOTOR_PORTS {4, 5, 6}

// Intake motor port
#define INTAKE_MOTOR_PORT 7

// Pneumatics ports
#define PNEUMATIC_PORT_1 1
//#define PNEUMATIC_PORT_2 2

// Sensors
extern pros::Imu imu;
extern pros::adi::Encoder vertical_encoder;
static pros::Rotation verticalEncoder(8); // Replace with the actual rotation sensor port

// Drivetrain physical properties
constexpr double TRACK_WIDTH = 10.5;    // Track width in inches
constexpr double WHEEL_DIAMETER = 3.25; // Wheel diameter in inches
constexpr double DRIVETRAIN_RPM = 600; // RPM of the drivetrain motors
constexpr double HORIZONTAL_DRIFT = 2; // Set to 2 by default

// Vertical tracking wheel offset
constexpr double VERTICAL_OFFSET = 0; // Offset in inches

// PID settings
extern lemlib::ControllerSettings lateral_controller;
extern lemlib::ControllerSettings angular_controller;

// Controller
extern pros::Controller master;