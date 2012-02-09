#include "Pickup.h"

Pickup::Pickup() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void Pickup::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void Pickup::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool Pickup::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Pickup::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Pickup::Interrupted() {
}
