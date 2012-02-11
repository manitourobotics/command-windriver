#ifndef LAUNCHSHOOTER_H
#define LAUNCHSHOOTER_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author b1500048
 */
class LaunchShooter: public PIDSubsystem {
private:
	

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	// set the P, I, and D constants here
	static const double Kp = 0.0;
	static const double Ki = 0.0;
	static const double Kd = 0.0;
	
	Jaguar* topMotor;
	Jaguar* bottomMotor;
	
	float BOTTOM_MOTOR_PORPORTIONALITY_CONSTANT; // The bottom motor must spin slower than the upper one.
	
	/*RobotDrive * drive;*/
	
public:
	LaunchShooter();
	
	void arcadeDrive(Joystick* stick);
	
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
	
	void setMotorSpeeds(float speed);
	void stopMotors();
};

#endif
