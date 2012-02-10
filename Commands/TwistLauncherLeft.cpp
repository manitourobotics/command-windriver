#include "TwistLauncherLeft.h"

TwistLauncherLeft::TwistLauncherLeft() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(launchTwister);
}

// Called just before this Command runs the first time
void TwistLauncherLeft::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void TwistLauncherLeft::Execute() {
	launchTwister->rotateLeft();
	
}

// Make this return true when this Command no longer needs to run execute()
bool TwistLauncherLeft::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TwistLauncherLeft::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TwistLauncherLeft::Interrupted() {
}
