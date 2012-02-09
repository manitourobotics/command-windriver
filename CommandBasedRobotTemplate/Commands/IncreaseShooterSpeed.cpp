#include "IncreaseShooterSpeed.h"

IncreaseShooterSpeed::IncreaseShooterSpeed() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(launchShooter);
	
}

// Called just before this Command runs the first time
void IncreaseShooterSpeed::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void IncreaseShooterSpeed::Execute() 
{
	launchShooter->arcadeDrive(oi->getLauncherJoystick());	
}

// Make this return true when this Command no longer needs to run execute()
bool IncreaseShooterSpeed::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void IncreaseShooterSpeed::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IncreaseShooterSpeed::Interrupted() {
}

