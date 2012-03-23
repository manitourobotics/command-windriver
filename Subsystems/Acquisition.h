#ifndef ACQUISITION_H
#define ACQUISITION_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author b1500048
 */
class Acquisition: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	
	const float MAX_SPEED;
	
	Timer* limitStopTime;
	Jaguar* beltMotor;
	
	DigitalInput* firstLimit;
	double const LIMIT_DEAD_INTERVAL;
	int currentState;
	
public:
	Acquisition();
	~Acquisition();
	void InitDefaultCommand();
	
	//void setSpeed(float speed);
	void moveForward();
	void moveReverse();
	void moveOff();
	
	DigitalInput* getLimit();
	Timer* getTimer();
	double getLimitInterval();
	
	int getState();
	void setState(int current_state);
	
	enum state
	{
		REVERSE,
		FORWARD,
		STOP
	};
	


};

#endif
