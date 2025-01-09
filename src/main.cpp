/**

 * @file main.cpp
 * @brief This file contains the main code for the robot's operation.
 *
 * Robot Controller:
 *
 * Tank Drive
 * Left Joystick (Vertical): Controls left side of drivetrain (forward/backward).
 * Right Joystick (Vertical): Controls right side of drivetrain (forward/backward).
 *
 * Arcade Drive
 * Left Joystick (Vertical): Controls movement of the drivetrain (forward/backward).
 * Right Joystick (Horizontal): Controls rotation of the drivetrain (left/right).
 *
 * Controller Settings:
 * L1: Press once to start the intake moving forward. Press again to stop the intake (if it's already running forward).
 * L2: Press once to start the intake moving in reverse. Press again to stop the intake (if it's already running in reverse).
 * R1: Opens the clamp by activating the pistons.
 * R2: Closes the clamp by deactivating the pistons.
 *
 * Motor Settings:
 * Motor Ports: 1-6 (left ports: 1, 2, and 3; right ports: 4, 5, and 6)
 * Intake Port: Port 7
 * Pneumatics (Clamp Pistons): ADI Port A
 * Controller: USB Ports to wirelessly connect to VEX Brain
 * Lady Brown: Used for high stake intake (port 11)
 *
 * Sensors:
 * 
 * 
 * 
 * 
 * Ports:
 * 1 - Left motor (contors wheels 1 & 2)
 * 2 - Left motor (contors wheels 2 & 3)
 * 3 - Left motor (contors wheels 3 & 4)
 * 4 - Right motor (contors wheels 5 & 6)
 * 5 - Right motor (contors wheels 6 & 7)
 * 6 - Right motor (contors wheels 7 & 8)
 * 7 - Intake motor
 * 8 - Tracking Wheel
 * 9 - 
 *    _____         .__       .__  ____   ____________                
 *   /  _  \   ____ |__| _____|  |_\   \ /   /\______ \   _______  __ 
 *  /  /_\  \ /    \|  |/  ___/  |  \   Y   /  |    |  \_/ __ \  \/ / 
 * /    |    \   |  \  |\___ \|   Y  \     /   |    `   \  ___/\   /  
 * \____|__  /___|  /__/____  >___|  /\___/   /_______  /\___  >\_/   
 *         \/     \/        \/     \/                 \/     \/       
 *  ___________ __________ 
 * /_   \   _  \\______   \
 *  |   /  /_\  \|       _/
 *  |   \  \_/   \    |   \
 *  |___|\_____  /____|_  /
 *             \/       \/ 
 */

#include "main.h"
#include "drivetrain.h"
#include "intake.h"
#include "pneumatics.h"
#include "pros/llemu.hpp"

// Global objects
pros::Controller master(pros::E_CONTROLLER_MASTER);
Drivetrain drivetrain;
Pneumatics pneumatics;
Intake intake;

lemlib::Chassis chassis(
    drivetrain.getDrivetrainSettings(),
    drivetrain.getLateralPID(),
    drivetrain.getAngularPID(),
    drivetrain.getOdomSensors()
);

void initialize() {
    pros::lcd::initialize();
    chassis.calibrate(); // Calibrate IMU and tracking wheel
}

ASSET(path_jerryio_txt)
ASSET(path_jerryio2_txt)

void autonomous() {
    // set chassis pose
    chassis.setPose(0, 0, 0);

    /**
    // Move forward to position (48, 0), facing 0 degrees with a 2-second timeout
    chassis.moveToPose(48, 0, 0, 2000);

    // Close the clamp
    pneumatics.setClampState(true);
    pros::delay(500); // Ensure the clamp actuates

    // Turn on the intake
    intake.setIntake(130);
    pros::delay(500); // Run intake for 0.5 seconds
    intake.stopIntake(); // Stop the intake
    pros::delay(500);

    // Open the clamp
    pneumatics.setClampState(false);
    pros::delay(100);

    // Reverse to (0, 0), facing 0 degrees with a 2-second timeout
    chassis.moveToPose(0, 0, 0, 2000);

    // Turn to face 125 degrees
    chassis.moveToPose(0, 0, 125, 2000);

    // Move backward to (-48, 0), still facing 125 degrees
    chassis.moveToPose(-48, 0, 125, 2000);

    // Move forward to (48, 0), facing 125 degrees
    chassis.moveToPose(48, 0, 125, 2000);

    // Reverse to (-60, 0), facing 125 degrees
    chassis.moveToPose(-60, 0, 125, 2000);

    // Forward to (60, 0), facing 125 degrees
    chassis.moveToPose(60, 0, 125, 2000);
    */

    // lookahead distance: 15 inches
    // timeout: 2000 ms
    chassis.follow(path_jerryio_txt, 15, 2000, false);

    // Close the clamp
    pneumatics.setClampState(true);
    pros::delay(500); // Ensure the clamp actuates

    // Turn on the intake
    intake.setIntake(130);
    pros::delay(500); // Run intake for 0.5 seconds
    intake.stopIntake(); // Stop the intake
    pros::delay(500);

    chassis.follow(path_jerryio2_txt, 15, 2000, true);

    // Turn on the intake
    intake.setIntake(130);
    pros::delay(500); // Run intake for 0.5 seconds
    intake.stopIntake(); // Stop the intake
    pros::delay(500);
}


void opcontrol() {
    while (true) {
        drivetrain.driveControl();
        intake.controlIntake();
        pneumatics.controlClamp();
        pros::delay(20);
    }
}