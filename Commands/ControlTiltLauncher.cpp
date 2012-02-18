#include "ControlTiltLauncher.h"

ControlTiltLauncher::ControlTiltLauncher():
DEAD_ZONE(0.8){
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(launchTilter);
}

// Called just before this Command runs the first time
void ControlTiltLauncher::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void ControlTiltLauncher::Execute() {
	tiltValue = oi->getLauncherJoystick()->GetRawAxis(Joystick::kZAxis);
	//printf("tilt_value: %f\n", tiltValue );
	if(tiltValue > DEAD_ZONE)
	{
		launchTilter->rotateNegative();
	}
	else if(tiltValue < DEAD_ZONE * -1)
	{
		launchTilter->rotatePositive();
	}
	else
	{
		launchTilter->rotateOff();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ControlTiltLauncher::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ControlTiltLauncher::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ControlTiltLauncher::Interrupted() {
}
