#include "Acquisition.h"
#include "../Robotmap.h"
#include "../Commands/ControlAcquisition.h"


Acquisition::Acquisition(): 
Subsystem("Acquisition"), MAX_SPEED(1),
LIMIT_DEAD_INTERVAL(.5), currentState(-1){
	beltMotor = new Jaguar(BELT_MOTOR_PORT);
	
	limitStopTime = new Timer();
	limitStopTime->Start();
	
	firstLimit = new DigitalInput(ACQUISITION_HOLD_PORT);
}

Acquisition::~Acquisition() {
	delete beltMotor;
	delete limitStopTime;
}
    
void Acquisition::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//if(!CommandBase::autonomousEnabled)
		SetDefaultCommand(new ControlAcquisition());
}

void Acquisition::moveForward() {	
	beltMotor->Set(MAX_SPEED);
	setState(Acquisition::FORWARD);
	//CommandBase::sd->Log("forward", "acquisition");
}

void Acquisition::moveReverse() {
	beltMotor->Set(MAX_SPEED * -1);
	setState(Acquisition::REVERSE);
	//CommandBase::sd->Log("reverse", "acquisition");
}

void Acquisition::moveOff(){
	beltMotor->Set(0);
	setState(Acquisition::STOP);
	//CommandBase::sd->Log("stop", "acquisition");
}

DigitalInput* Acquisition::getLimit()
{
	return firstLimit;
}

Timer* Acquisition::getTimer()
{
	return limitStopTime;
}

double Acquisition::getLimitInterval()
{
	return LIMIT_DEAD_INTERVAL;
}

int Acquisition::getState()
{
	return currentState;
}

void Acquisition::setState(int currentState)
{
	this->currentState = currentState;
}



