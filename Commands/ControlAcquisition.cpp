#include "ControlAcquisition.h"

ControlAcquisition::ControlAcquisition() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(acquisition);
}

// Called just before this Command runs the first time
void ControlAcquisition::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void ControlAcquisition::Execute() {
	if(oi->getDriverJoystick()->GetRawButton(3)) //dummy buttons
	{
		acquisition->moveForward();
	}
	if(oi->getDriverJoystick()->GetRawButton(5))
	{
		acquisition->moveReverse();
	}
	if(oi->getDriverJoystick()->GetRawButton(4))
	{
		acquisition->moveOff();
	}
	
	
}

// Make this return true when this Command no longer needs to run execute()
bool ControlAcquisition::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ControlAcquisition::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ControlAcquisition::Interrupted() {
}
