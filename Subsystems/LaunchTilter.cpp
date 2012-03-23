#include "LaunchTilter.h"
#include "../Robotmap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "../Commands/ControlTiltLauncher.h"
#include <cassert>

LaunchTilter::LaunchTilter() :PIDSubsystem("LaunchTilter", Kp, Ki, Kd), SPEED(0.416666667) {
	// Use these to get going:
	// SetSetpoint() -  Sets where the PID controller should move the system
	//                  to
	// Enable() - Enables the PID controller.
	jaguar = new Jaguar(TILT_MOTOR_PORT);
	
	upPosition = new DigitalInput(UPPER_LIMIT_TILT_PORT);
	downPosition = new DigitalInput(LOWER_LIMIT_TILT_PORT);
}

LaunchTilter::~LaunchTilter() {
	delete jaguar;
	delete upPosition;
	delete downPosition;
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
	//if(!CommandBase::autonomousEnabled)
		SetDefaultCommand(new ControlTiltLauncher());
}

void LaunchTilter::rotatePositive(){
	//cout << "downPosition: " << downPosition->Get() << '\n';
	//relay->Set(Relay::kForward);
	if(downPosition->Get()) 
	{
		jaguar->Set(SPEED);
	}
	else
	{
		jaguar->Set(0);
	}
}

void LaunchTilter::rotateNegative(){
	//relay->Set(Relay::kReverse);
	
	//cout << "upPosition: " << upPosition->Get() << '\n';

	
	if(upPosition->Get())
	{
		jaguar->Set(-1 * SPEED);
	}
	else
	{
		jaguar->Set(0);
	}
}

void LaunchTilter::rotateOff(){
	//relay->Set(Relay::kOff);
	jaguar->Set(0);
}
