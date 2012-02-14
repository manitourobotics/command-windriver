#include "LaunchTwister.h"
#include "../Robotmap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "../Commands/ControlTwistLauncher.h"

LaunchTwister::LaunchTwister() : PIDSubsystem("LaunchTwister", Kp, Ki, Kd) {
	// Use these to get going:
	// SetSetpoint() -  Sets where the PID controller should move the system
	//                  to
	// Enable() - Enables the PID controller.
	relay = new Relay(TWIST_MOTOR_PORT);
	relay->Set(Relay::kOn);
}

LaunchTwister::~LaunchTwister(){
	delete relay;
}

double LaunchTwister::ReturnPIDInput() {
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;
	return 0.0;
}

void LaunchTwister::UsePIDOutput(double output) {
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
}

void LaunchTwister::InitDefaultCommand() {
	SetDefaultCommand(new ControlTwistLauncher());
}

void LaunchTwister::rotateLeft()
{
	relay->Set(Relay::kForward);
}

void LaunchTwister::rotateRight()
{
	relay->Set(Relay::kReverse);
}

void LaunchTwister::rotateOff()
{
	relay->Set(Relay::kOff);
}
