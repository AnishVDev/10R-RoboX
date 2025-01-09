// intake/drivetrain.h

#pragma once


#include "lemlib/chassis/chassis.hpp"
class Drivetrain {
public:
    Drivetrain();
    void driveControl();

    // LemLib configuration getters
    lemlib::Drivetrain getDrivetrainSettings();
    lemlib::OdomSensors getOdomSensors();
    lemlib::ControllerSettings getLateralPID();
    lemlib::ControllerSettings getAngularPID();

private:
    pros::MotorGroup leftMotors;
    pros::MotorGroup rightMotors;
};
