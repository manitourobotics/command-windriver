#include "Arm.h"
#include "../Robotmap.h"
#include "../OI.h"
#include "../Commands/ControlArm.h"

Arm::Arm():
Subsystem("Arm"), SET_SPEED(.4)/*dummy speed*/ {
	armMotor = new Jaguar(OI::ARM_MOTOR_PORT);
}
    
void Arm::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new ControlArm());
}


void Arm::moveForward()
{
	armMotor->Set(SET_SPEED);
}

void Arm::moveReverse()
{
	armMotor->Set(SET_SPEED * -1);
}

void Arm::moveOff()
{
	armMotor->Set(0);
}
