#include "ControlToLauncher.h"
#include "../Robotmap.h"

ControlToLauncher::ControlToLauncher() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(toLauncher);
}

// Called just before this Command runs the first time
void ControlToLauncher::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ControlToLauncher::Execute() {
	if(oi->getDriverJoystick()->GetRawButton(TO_LAUNCHER))
	{
		toLauncher->setDirection(Relay::kForward);	
	}
	else
	{
		toLauncher->setDirection(Relay::kOff);
	}	
}

// Make this return true when this Command no longer needs to run execute()
bool ControlToLauncher::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ControlToLauncher::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ControlToLauncher::Interrupted() {
}
