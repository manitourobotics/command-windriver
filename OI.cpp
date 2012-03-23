#include "OI.h"
#include "Robotmap.h"
//#include "Commands/AlignWithTarget.h"
//#include "commands/SetLauncherSpeed.h"

OI::OI() {
	// Process operator interface input here.
	driverStick = new Joystick(DRIVER_JOYSTICK_PORT);
	/*
	launcherStick = new Joystick(LAUNCHER_JOYSTICK_PORT);
	topSpeed = new JoystickButton(launcherStick, TOP_LAUNCHER_SPEED);
	mediumSpeed = new JoystickButton(launcherStick, MEDIUM_LAUNCHER_SPEED);
	bottomSpeed = new JoystickButton(launcherStick, BOTTOM_LAUNCHER_SPEED);
	targettingButton = new JoystickButton(launcherStick, START_TARGETTING);
	
	targettingButton->WhenPressed(new AlignWithTarget());
	topSpeed->WhenPressed(new SetLauncherSpeed(1));
	mediumSpeed->WhenPressed(new SetLauncherSpeed(0.5));
	bottomSpeed->WhenPressed(new SetLauncherSpeed(0));
	*/
	
}

Joystick* OI::getDriverJoystick()
{
	return driverStick;
}

Joystick* OI::getLauncherJoystick()
{
	return launcherStick;
}
