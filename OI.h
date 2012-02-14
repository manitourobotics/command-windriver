#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:

	
	
	Joystick *driverStick;
	Joystick *launcherStick;
	
	JoystickButton *toLauncher;
	
public:

	OI();
	
	Joystick *getDriverJoystick();
	Joystick *getLauncherJoystick();
	
	JoystickButton* getToLauncher();
};

#endif
