#include "AlignWithTarget.h"

AlignWithTarget::AlignWithTarget() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void AlignWithTarget::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void AlignWithTarget::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool AlignWithTarget::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void AlignWithTarget::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AlignWithTarget::Interrupted() {
}
