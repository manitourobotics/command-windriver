#include "ControlArm.h"

ControlArm::ControlArm() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(arm);
}

// Called just before this Command runs the first time
void ControlArm::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void ControlArm::Execute() {
	if(oi->getDriverJoystick()->GetRawButton(5))/*dummy button*/{
		arm->moveForward();
	}
	else if(oi->getDriverJoystick()->GetRawButton(4)){
		arm->moveReverse();
	}
	else if (oi->getDriverJoystick()->GetRawButton(2))
	{
		arm->moveOff();
	}
	
}

// Make this return true when this Command no longer needs to run execute()
bool ControlArm::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ControlArm::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ControlArm::Interrupted() {
}
