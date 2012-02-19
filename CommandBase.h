#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include "Commands/Command.h"
#include "Subsystems/Chassis.h"
#include "Subsystems/Acquisition.h"
#include "Subsystems/LaunchShooter.h"
#include "Subsystems/LaunchTilter.h"
#include "Subsystems/LaunchTwister.h"
#include "Subsystems/Arm.h"
#include "Subsystems/ToLauncher.h"
#include "Subsystems/Camera.h"
#include "OI.h"


/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command {
public:
	CommandBase(const char *name);
	CommandBase();
	static void init();
	
	// Create a single static instance of all of your subsystems
	static Chassis* chassis;
	static Acquisition* acquisition;
	static LaunchShooter* launchShooter;
	static LaunchTilter* launchTilter;
	static LaunchTwister* launchTwister;
	static Arm* arm;
	static ToLauncher* toLauncher;
	static Camera* camera;
	
	static SmartDashboard* sd;
	
	static OI *oi;
};

#endif
