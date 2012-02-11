#ifndef ARM_H
#define ARM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author azrathud
 */
class Arm: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	
	const float SET_SPEED;
	Jaguar* armMotor;
	
	DigitalInput* upPosition;
	DigitalInput* downPosition;
public:
	Arm();
	void InitDefaultCommand();
	
	void moveForward();
	void moveReverse();
	void moveOff();
};

#endif
