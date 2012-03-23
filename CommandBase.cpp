#include "CommandBase.h"
#include "Subsystems/Chassis.h"
#include "Subsystems/Acquisition.h"
//#include "Subsystems/LaunchShooter.h"
//#include "Subsystems/LaunchTilter.h"
#include "Subsystems/Arm.h"
#include "Commands/Scheduler.h"

CommandBase::CommandBase(const char *name) : Command(name) {
}

CommandBase::CommandBase() : Command() {
}

Chassis* CommandBase::chassis = NULL;
Acquisition* CommandBase::acquisition = NULL;
LaunchShooter* CommandBase::launchShooter = NULL;
LaunchTilter* CommandBase::launchTilter = NULL;
Arm* CommandBase::arm = NULL;
ToLauncher* CommandBase::toLauncher = NULL;
/*
SmartDashboard* CommandBase::sd = NULL;
Camera* CommandBase::camera = NULL;
*/
OI* CommandBase::oi = NULL;

bool CommandBase::autonomousEnabled = false;
int CommandBase::mode = -1;


void CommandBase::init() {
    // Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	chassis = new Chassis();
	acquisition = new Acquisition();
	launchShooter = new LaunchShooter();
	launchTilter = new LaunchTilter();
	arm = new Arm();
	toLauncher = new ToLauncher();
	//sd = SmartDashboard::GetInstance();
	//sd->init();
	
	//camera = new Camera();
	
	oi = new OI();
	
}
