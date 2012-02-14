#include "OI.h"
#include "Robotmap.h"

OI::OI() {
	// Process operator interface input here.
	driverStick = new Joystick(DRIVER_JOYSTICK_PORT);
	launcherStick = new Joystick(LAUNCHER_JOYSTICK_PORT);
	
	}

Joystick* OI::getDriverJoystick()
{
	return driverStick;
}

Joystick* OI::getLauncherJoystick()
{
	return launcherStick;
}
