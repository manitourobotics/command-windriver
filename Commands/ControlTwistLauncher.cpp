#include "ControlTwistLauncher.h"

ControlTwistLauncher::ControlTwistLauncher() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(launchTwister);
}

// Called just before this Command runs the first time
void ControlTwistLauncher::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void ControlTwistLauncher::Execute() {
	
	m_twistValue = oi->getLauncherJoystick()->GetRawAxis(Joystick::kTwistAxis);
	printf("twist_value: %f\n", m_twistValue );
	if(m_twistValue > 0)
	{
		launchTwister->rotateRight();
	}
	else if(m_twistValue < 0)
	{
		launchTwister->rotateLeft();
	}
	else if(m_twistValue == 0)
	{
		launchTwister->rotateOff();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ControlTwistLauncher::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ControlTwistLauncher::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ControlTwistLauncher::Interrupted() {
}
