#include "Chassis.h"
#include "../Robotmap.h"
#include "../Commands/DriveWithJoystick.h"

Chassis::Chassis() : Subsystem("Chassis") {	
	drive = new RobotDrive(1,2);
	drive->SetSafetyEnabled(false);
	
	watchdog = new Watchdog();
}
    
void Chassis::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new DriveWithJoystick());
}

void Chassis::driveWithJoystick(double left, double right)
{
	watchdog->Feed();
	drive->TankDrive(left, right);
}
