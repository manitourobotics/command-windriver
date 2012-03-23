#include "DriveWithJoystick.h"
#include "../Robotmap.h"

DriveWithJoystick::DriveWithJoystick():
modeSpeed(1) {
	// Use requires() here to declare subsystem dependencies
	Requires(chassis);
}

// Called just before this Command runs the first time
void DriveWithJoystick::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void DriveWithJoystick::Execute() {
	// gotta change for gamepad - two joysticks on one device
	
	//cout << "triggers: " << oi->getDriverJoystick()->GetRawAxis(TRIGGERS) << '\n'; // not quite sure the default value of
	
	if(oi->getDriverJoystick()->GetRawAxis(TRIGGERS) < (0)) // Right trigger -- .75 speed
	{
		modeSpeed = 0.75;
	}
	else if(oi->getDriverJoystick()->GetRawAxis(TRIGGERS) > (0)) // Left trigger .5 speed
	{
		modeSpeed = 0.5;
	}
	else
	{
		modeSpeed = 1;
	}
	
	chassis->driveWithJoystick
		(-1 * modeSpeed * oi->getDriverJoystick()->GetRawAxis(LEFT_STICK_Y), modeSpeed * oi->getDriverJoystick()->GetRawAxis(RIGHT_STICK_Y) * -1);
	//sd->PutDouble("left stick y", oi->getDriverJoystick()->GetRawAxis(LEFT_STICK_Y));
	//sd->PutDouble("right stick y", oi->getDriverJoystick()->GetRawAxis(RIGHT_STICK_Y));
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
