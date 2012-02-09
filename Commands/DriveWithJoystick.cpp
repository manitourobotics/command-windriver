#include "DriveWithJoystick.h"

DriveWithJoystick::DriveWithJoystick() {
	// Use requires() here to declare subsystem dependencies
	Requires(chassis);
}

// Called just before this Command runs the first time
void DriveWithJoystick::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void DriveWithJoystick::Execute() {
	// gotta change for gamepad - two joysticks on one device
	chassis->driveWithJoystick(oi->getDriverJoystick()->GetRawAxis(2), oi->getDriverJoystick()->GetRawAxis(5));
}

// Make this return true when this Command no longer needs to run execute()
bool DriveWithJoystick::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveWithJoystick::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveWithJoystick::Interrupted() {
}
