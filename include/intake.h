// include/intake.h

#pragma once


#include "pros/motors.hpp"
class Intake {
public:
    Intake();
    void controlIntake();
    void setIntake(int power);  // Allows direct control for autonomous
    void stopIntake();          // Stops the intake motor
private:
    pros::Motor intakeMotor;
    bool intakeRunningForward;
    bool intakeRunningReverse;
};