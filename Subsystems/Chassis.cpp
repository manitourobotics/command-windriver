#include "Chassis.h"
#include "../Robotmap.h"
#include "../Commands/DriveWithJoystick.h"

Chassis::Chassis() : Subsystem("Chassis") {	
	drive = new RobotDrive(LEFT_DRIVE_PORT, RIGHT_DRIVE_PORT);
	drive->SetSafetyEnabled(false);
	//watchdog = new Watchdog();
}

Chassis::~Chassis() {
	//delete watchdog;
	delete drive;
}
    
void Chassis::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new DriveWithJoystick());
}

void Chassis::driveWithJoystick(double left, double right)
{
	//watchdog->Feed();
	drive->TankDrive(left, right);
}
