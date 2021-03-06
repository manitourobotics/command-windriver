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
	static const double Kp = .25;
	static const double Ki = 0.0;
	static const double Kd = 0.0;
	
	Jaguar* topMotor;
	Jaguar* bottomMotor;
	
	Encoder* digitalEncoder;


	const float BOTTOM_MOTOR_PORPORTIONALITY_CONSTANT; // The bottom motor must spin slower than the upper one.
	const float MAX_SPEED;
	double speed;
	double rpm;

	
	/*RobotDrive * drive;*/
	
public:
	LaunchShooter();
	~LaunchShooter();
	
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
	
	void arcadeDrive(Joystick* stick);
	void incrementMotorSpeeds(float speed);
	void setMotorSpeeds(float speed);
	void stopMotors();
	
	Encoder* getDigitalEncoder();
};

#endif
