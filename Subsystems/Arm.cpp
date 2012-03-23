#include "Arm.h"
#include "../Robotmap.h"
#include "../Commands/ControlArm.h"

Arm::Arm():
Subsystem("Arm"), SET_SPEED(/*.416666667*/ .5)/*12v speed -> 5v*/ {
	armMotor = new Jaguar(ARM_MOTOR_PORT);
	
	upPosition = new DigitalInput(UPPER_LIMIT_ARM_PORT);
	downPosition = new DigitalInput(LOWER_LIMIT_ARM_PORT);
}
 
Arm::~Arm() {
	delete armMotor;
	delete upPosition;
	delete downPosition;
}
void Arm::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	/*if(!CommandBase::autonomousEnabled)*/
		SetDefaultCommand(new ControlArm());
}


void Arm::moveForward()
{
	//cout << "downPosition: " << downPosition->Get() << '\n';//0 closed
	 
	//cout << "SET_SPEED: " << SET_SPEED << '\n'; 
	// Move in an upwards position unless the upwards switch is set
	if(!downPosition->Get())
	{
		armMotor->Set(SET_SPEED * -1);
		//CommandBase::sd->Log("forward", "arm");
	}
	else
	{
		armMotor->Set(0);
		//CommandBase::sd->Log("off", "arm");
	}
}

void Arm::moveReverse()
{
	
	//cout << "upPosition: " << upPosition->Get() << '\n';
	// Move in a downwards position unless the downwards switch is set
	if(!upPosition->Get()) 
	{
		armMotor->Set(SET_SPEED);
		//CommandBase::sd->Log("reverse", "arm");
	}
	else
	{
		armMotor->Set(0);
		//CommandBase::sd->Log("forward", "arm");
	}
}

void Arm::moveOff()
{
	armMotor->Set(0);
	//CommandBase::sd->Log("off", "arm");
}
 
