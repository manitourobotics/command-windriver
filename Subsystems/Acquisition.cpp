#include "Acquisition.h"
#include "../Robotmap.h"
#include "../Commands/ControlAcquisition.h"


Acquisition::Acquisition(): 
Subsystem("Acquisition"), MAX_SPEED(0.5) {
	beltMotor = new Jaguar(BELT_MOTOR_PORT);
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
