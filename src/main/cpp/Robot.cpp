// Copyright (c) 2020 FRC Team 3512. All Rights Reserved.

// Implementation code by Adan Silva

#include "Robot.h"

#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>
#include <units/units.h>
#include <wpi/math>

Robot::Robot()
    : encoder0{spark0},
      encoder1{spark1},
      controller0{spark0},
      controller1{spark1} {
    encoder0.SetVelocityConversionFactor(wpi::math::pi * 2.0 / 60.0);
    encoder1.SetVelocityConversionFactor(wpi::math::pi * 2.0 / 60.0);

    controller0.SetP(0.5);
    controller1.SetP(0.5);
}
void Robot::RobotInit() {}

void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {
    constexpr units::revolutions_per_minute_t kMaxSpeed = 11825_rpm;

    std::cout << "Left:" << encoder0.GetVelocity();
    std::cout << "Right:" << encoder1.GetVelocity();

    // Spark Max # 0
    if (joystick0.GetRawButtonPressed(5)) {
        reference = kMaxSpeed * 0.1;
    } else if (joystick0.GetRawButtonPressed(6)) {
        reference = kMaxSpeed * 0.2;
    } else if (joystick0.GetRawButtonPressed(3)) {
        reference = kMaxSpeed * 0.3;
    } else if (joystick0.GetRawButtonPressed(4)) {
        reference = kMaxSpeed * 0.4;
    } else if (joystick0.GetRawButtonPressed(7)) {
        reference = kMaxSpeed * 0.5;
    } else if (joystick0.GetRawButtonPressed(8)) {
        reference = kMaxSpeed * 0.6;
    } else if (joystick0.GetRawButtonPressed(9)) {
        reference = kMaxSpeed * 0.7;
    } else if (joystick0.GetRawButtonPressed(10)) {
        reference = kMaxSpeed * 0.8;
    } else if (joystick0.GetRawButtonPressed(11)) {
        reference = kMaxSpeed * 0.9;
    } else if (joystick0.GetRawButtonPressed(12)) {
        reference = kMaxSpeed;
    } else if (joystick0.GetRawButtonPressed(2)) {
        reference = 0_rpm;
    } else if (joystick0.GetRawButtonPressed(1)) {
        reference = kMaxSpeed * 0.65;
    }

    controller0.SetReference(
        units::radians_per_second_t(reference).to<double>(),
        rev::ControlType::kVelocity, reference / kMaxSpeed * 12.0);

    controller1.SetReference(
        units::radians_per_second_t(-reference).to<double>(),
        rev::ControlType::kVelocity, -reference / kMaxSpeed * 12.0);

    /* //Spark Max #1
     if (joystick1.GetRawButtonPressed(5))
       spark1.Set(-.1);
     else if (joystick1.GetRawButtonPressed(6))
       spark1.Set(-.2);
     else if (joystick1.GetRawButtonPressed(3))
       spark1.Set(-.3);
     else if (joystick1.GetRawButtonPressed(4))
       spark1.Set(-.4);
     else if (joystick1.GetRawButtonPressed(7))
       spark1.Set(-.5);
     else if (joystick1.GetRawButtonPressed(8))
       spark1.Set(-.6);
     else if (joystick1.GetRawButtonPressed(9))
       spark1.Set(-.7);
     else if (joystick1.GetRawButtonPressed(10))
       spark1.Set(-.8);
     else if (joystick1.GetRawButtonPressed(11))
       spark1.Set(-1);
     if (joystick1.GetRawButtonPressed(12))
       spark1.Set(0);
    */
}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
