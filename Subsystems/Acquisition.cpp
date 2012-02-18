#include "Acquisition.h"
#include "../Robotmap.h"
#include "../Commands/ControlAcquisition.h"


Acquisition::Acquisition(): 
Subsystem("Acquisition"), MAX_SPEED(1/* for testing aquisiotion*/ /*.416666667*/)/*12v speed -> 5v*/ {
	beltMotor = new Jaguar(BELT_MOTOR_PORT);
}

Acquisition::~Acquisition() {
	delete beltMotor;
}
    
void Acquisition::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new ControlAcquisition());
}

void Acquisition::moveForward() {	
	beltMotor->Set(MAX_SPEED);
}

void Acquisition::moveReverse() {
	beltMotor->Set(MAX_SPEED * -1);
}

void Acquisition::moveOff(){
	beltMotor->Set(0);
}
