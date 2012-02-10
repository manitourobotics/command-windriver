#ifndef LAUNCHTWISTER_H
#define LAUNCHTWISTER_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author b1500048
 */
class LaunchTwister: public PIDSubsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	// set the P, I, and D constants here
	static const double Kp = 0.0;
	static const double Ki = 0.0;
	static const double Kd = 0.0;
	
	Relay* relay;
public:
	LaunchTwister();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
	
	void rotateLeft();
	void rotateRight();
	void rotateOff();
};

#endif
