/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

//Implementation code by Adan Silva

#pragma once

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <rev/CANSparkMax.h>
#include <frc/Joystick.h>

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

 private:
    frc::Joystick joystick0{0};
    //frc::Joystick joystick1{1};
    rev::CANEncoder  encoder0;
    rev::CANEncoder  encoder1;
    rev::CANPIDController controller0;
    rev::CANPIDController controller1;
    rev::CANSparkMax spark0{14, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax spark1{15, rev::CANSparkMax::MotorType::kBrushless};
    units::revolutions_per_minute_t reference = 0.0_rpm;
};
