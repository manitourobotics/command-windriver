#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	static const int DRIVER_JOYSTICK_PORT = 1;
	static const int LAUNCHER_JOYSTICK_PORT = 2;
	
	Joystick *driverStick;
	Joystick *launcherStick;
	
public:
	OI();
	
	Joystick *getDriverJoystick();
	Joystick *getLauncherJoystick();
};

#endif
