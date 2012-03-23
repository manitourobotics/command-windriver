#include "ControlArm.h"
#include "../Robotmap.h"

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
	
	//cout << "Forward_arm: " << oi->getDriverJoystick()->GetRawButton(FORWARD_ARM) << '\n';
	//The arm should only move outwards when the button is pressed
	if(oi->getDriverJoystick()->GetRawButton(FORWARD_ARM))/*dummy button*/{
		arm->moveForward();
	}
	else/* if()*/
	{
		arm->moveReverse();
	}
	/* need to add sensor code*/
	
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
