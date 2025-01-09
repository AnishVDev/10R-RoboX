//src/drivetrain.cpp

#include "drivetrain.h"
#include "main.h"
#include "robot_config.h"

// Tracking wheel setup
static lemlib::TrackingWheel verticalTrackingWheel(&verticalEncoder, lemlib::Omniwheel::NEW_2, VERTICAL_OFFSET);

Drivetrain::Drivetrain()
    : leftMotors({1, -2, 3}),    // Adjusted for reversed motors on left
      rightMotors({-4, -5, -6}) { // Adjusted for reversed motors on right
}

void Drivetrain::driveControl() {
    int forward = -master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int turn = -master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

    // Calculate motor speeds for left and right sides using arcade drive
    int leftSpeed = forward + turn;  // Left side of bot
    int rightSpeed = forward - turn; // Right side of bot

    leftMotors.move(leftSpeed);
    rightMotors.move(rightSpeed);
}

// LemLib configuration getters
lemlib::Drivetrain Drivetrain::getDrivetrainSettings() {
    return lemlib::Drivetrain(&leftMotors, &rightMotors, TRACK_WIDTH, WHEEL_DIAMETER, DRIVETRAIN_RPM, HORIZONTAL_DRIFT);
}

lemlib::OdomSensors Drivetrain::getOdomSensors() {
    return lemlib::OdomSensors(&verticalTrackingWheel, nullptr, nullptr, nullptr, &imu);
}

lemlib::ControllerSettings Drivetrain::getLateralPID() {
    return lemlib::ControllerSettings(10, 0, 3, 3, 1, 100, 3, 500, 20);
}

lemlib::ControllerSettings Drivetrain::getAngularPID() {
    return lemlib::ControllerSettings(2, 0, 10, 3, 1, 100, 3, 500, 0);
}
