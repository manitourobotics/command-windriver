#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:

	
	
	Joystick *driverStick;
	Joystick *launcherStick;
	
public:
	enum
	{
		DRIVER_JOYSTICK_PORT = 1,
		LAUNCHER_JOYSTICK_PORT = 2
	};
	
	enum
	{
		LEFT_DRIVE_PORT = 1,
		RIGHT_DRIVE_PORT = 2,
		TWIST_MOTOR_PORT = 4,
		TILT_MOTOR_PORT = 5,
		BELT_MOTOR_PORT = 6,
		ARM_MOTOR_PORT = 7
	};
	
	OI();
	
	Joystick *getDriverJoystick();
	Joystick *getLauncherJoystick();
};

#endif
