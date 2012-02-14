#include "CommandBase.h"
#include "Subsystems/Chassis.h"
#include "Subsystems/Acquisition.h"
#include "Subsystems/LaunchShooter.h"
#include "Subsystems/LaunchTilter.h"
#include "Subsystems/LaunchTwister.h"
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
LaunchTwister* CommandBase::launchTwister = NULL;
Arm* CommandBase::arm = NULL;
Camera* CommandBase::camera = NULL;
ToLauncher* CommandBase::toLauncher = NULL;

//SmartDashboard* CommandBase::sd = NULL;

OI* CommandBase::oi = NULL;


void CommandBase::init() {
    // Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	chassis = new Chassis();
	acquisition = new Acquisition();
	launchShooter = new LaunchShooter();
	launchTilter = new LaunchTilter();
	launchTwister = new LaunchTwister();
	arm = new Arm();
	camera = new Camera();
	toLauncher = new ToLauncher();
	
	oi = new OI();
	/*
	sd->PutData(chassis);
	sd->PutData(acquisition);
	sd->PutData(launchShooter);
	sd->PutData(launchTilter);
	sd->PutData(launchTwister);
	sd->PutData(arm);
	*/
}
