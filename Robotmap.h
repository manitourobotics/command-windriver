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
		TILT_MOTOR_PORT = 10,
		ARM_MOTOR_PORT = 8


	};
	
	//Relay ports
	enum
	{
		TWIST_MOTOR_PORT = 1,
		TO_LAUNCHER_MOTOR_PORT = 5,


		
	};
	
	//Digital I/O ports
	enum
	{	
		DIGITAL_ENCODER_A = 1,
		DIGITAL_ENCODER_B = 2,
		LOWER_LIMIT_TILT_PORT = 3,
		UPPER_LIMIT_TILT_PORT = 4,
		LOWER_LIMIT_ARM_PORT = 5,
		UPPER_LIMIT_ARM_PORT = 6
		
	};
	
	// Controller buttons
	enum
	{
		FORWARD_ACQUISITION = 1,
		STOP_ACQUISITION = 2,
		TO_LAUNCHER = 3, // X button
		REVERSE_ACQUISITION = 4,
		FORWARD_ARM = 5,
	};
	
	// Joystick buttons
	enum
	{
		DECREASE_SHOOTER_SPEED = 3,
		INCREASE_SHOOTER_SPEED = 5
	};
	
	// Controller Axises
	enum axis
		{
		    LEFT_STICK_X = 1,
		    LEFT_STICK_Y,
		    TRIGGERS,
		    RIGHT_STICK_X,
		    RIGHT_STICK_Y
		    
		};
	
	
	//voltage
	enum
	{
		FINAL_ARM_POSITION = 4,
		STARTING_ARM_POSITION = 1
	};
	
	
	
	// Joystick 
	

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// #define RANGE_FINDER_PORT 1
// #define RANGE_FINDER_MODULE 1

#endif
