#include "LaunchShooter.h"
#include "../Robotmap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "../Commands/IncreaseShooterSpeed.h"

LaunchShooter::LaunchShooter() : PIDSubsystem("LaunchShooter", Kp, Ki, Kd) {
	// Use these to get going:
	// SetSetpoint() -  Sets where the PID controller should move the system
	//                  to
	// Enable() - Enables the PID controller.
	
	//topMotor = new Jaguar(TOP_MOTOR_PORT);
	//bottomMotor = new Jaguar(BOTTOM_MOTOR_PORT);
	
	drive = new RobotDrive(5,6);
	
}

void LauncherShooter::InitDefaultComman() {
	SetDefaultCommand(new IncreaseShooterSpeed());
}

double LaunchShooter::ReturnPIDInput() {
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;
	return 0.0;
}

void LaunchShooter::UsePIDOutput(double output) {
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
}

void LaunchShooter::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//setDefaultCommand(new MySpecialCommand());
}

void LaunchShooter::arcadeDrive(Joystick* stick) {
	drive->ArcadeDrive(stick);
}
