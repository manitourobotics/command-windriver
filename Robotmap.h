#ifndef ROBOTMAP_H
#define ROBOTMAP_H


/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// #define LEFTMOTOR 1
// #define RIGHTMOTOR 2
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
	

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// #define RANGE_FINDER_PORT 1
// #define RANGE_FINDER_MODULE 1

#endif
