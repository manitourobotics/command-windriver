#include "ControlLaunchShooterSpeed.h"
#include "../Robotmap.h"

ControlLaunchShooterSpeed::ControlLaunchShooterSpeed():
currentMotorSpeeds(0), incrementSpeeds(.01){
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(launchShooter);
}

// Called just before this Command runs the first time
void ControlLaunchShooterSpeed::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void ControlLaunchShooterSpeed::Execute() {
	/*
	for(int i = 0; i < 12; i++)
	{
		//printf("button %d: %f", i, oi->getLauncherJoystick()->GetRawButton(i));
		std::cout << "button " << i << ": " << oi->getLauncherJoystick()->GetRawButton(i) << "\n";
		Wait(1);
	}
	*/
	if(oi->getLauncherJoystick()->GetRawButton(INCREASE_SHOOTER_SPEED))
	{
		currentMotorSpeeds += incrementSpeeds;
	}
	else if(oi->getLauncherJoystick()->GetRawButton(DECREASE_SHOOTER_SPEED))
	{
		currentMotorSpeeds -= incrementSpeeds;
	}
	
	
	if(currentMotorSpeeds > 1)
	{
		currentMotorSpeeds = 1;
	}
	else if(currentMotorSpeeds < 0) // The motor doesn't need to go in reverse.
	{
		currentMotorSpeeds = 0;
	}
	
	launchShooter->setMotorSpeeds(currentMotorSpeeds);
	
	
}

// Make this return true when this Command no longer needs to run execute()
bool ControlLaunchShooterSpeed::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ControlLaunchShooterSpeed::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ControlLaunchShooterSpeed::Interrupted() {
}
