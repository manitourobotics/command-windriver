#include "LaunchTilter.h"
#include "../Robotmap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "../Commands/ControlTiltLauncher.h"

LaunchTilter::LaunchTilter() : PIDSubsystem("LaunchTilter", Kp, Ki, Kd) {
	// Use these to get going:
	// SetSetpoint() -  Sets where the PID controller should move the system
	//                  to
	// Enable() - Enables the PID controller.
	relay = new Relay(TILT_MOTOR_PORT);
	
}

double LaunchTilter::ReturnPIDInput() {
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;
	return 0.0;
}

void LaunchTilter::UsePIDOutput(double output) {
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
}

void LaunchTilter::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//setDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new ControlTiltLauncher());
}

void LaunchTilter::rotatePositive(){
	relay->Set(Relay::kForward);
}

void LaunchTilter::rotateNegative(){
	relay->Set(Relay::kReverse);
}

void LaunchTilter::rotateOff(){
	relay->Set(Relay::kOff);
}
