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
	
	//PWM ports
	enum
	{
		LEFT_DRIVE_PORT = 1,
		RIGHT_DRIVE_PORT = 2,
		TOP_MOTOR_PORT = 5,
		BOTTOM_MOTOR_PORT = 6,
		BELT_MOTOR_PORT = 7,
		ARM_MOTOR_PORT = 9

	};
	
	//Relay ports
	enum
	{
		TWIST_MOTOR_PORT = 1,
		TILT_MOTOR_PORT = 3,

		LOWER_LIMIT_ARM_PORT = 13,
		UPPER_LIMIT_ARM_PORT = 14
	};
	
	// Controller buttons
	enum
	{
		FORWARD_ACQUISITION = 1,
		STOP_ACQUISITION = 2,
		REVERSE_ACQUISITION = 4,
		FORWARD_ARM = 5
		
	};
	
	// Joystick buttons
	enum
	{
		DECREASE_SHOOTER_SPEED = 3,
		INCREASE_SHOOTER_SPEED = 5
		
	};
	
	// Joystick 
	

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// #define RANGE_FINDER_PORT 1
// #define RANGE_FINDER_MODULE 1

#endif
