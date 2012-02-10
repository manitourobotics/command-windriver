#include "Chassis.h"
#include "../Robotmap.h"
#include "../Commands/DriveWithJoystick.h"

Chassis::Chassis() : Subsystem("Chassis") {	
	drive = new RobotDrive(1,2);
	drive->SetSafetyEnabled(false);
}
    
void Chassis::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new DriveWithJoystick());
}

void Chassis::driveWithJoystick(double left, double right)
{
	drive->TankDrive(left, right);
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
