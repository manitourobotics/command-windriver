#ifndef CHASSIS_H
#define CHASSIS_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author b1500048
 */
class Chassis: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	RobotDrive* drive;
	Watchdog* watchdog;
	
public:
	Chassis();
	void InitDefaultCommand();
	
	void driveWithJoystick(double left, double right);
};

#endif
