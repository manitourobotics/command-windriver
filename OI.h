#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:

	
	
	Joystick *driverStick;
	Joystick *launcherStick;
	
public:

	OI();
	
	Joystick *getDriverJoystick();
	Joystick *getLauncherJoystick();
};

#endif
