#include "ToLauncher.h"
#include "../Robotmap.h"
#include "../Commands/ControlToLauncher.h"
ToLauncher::ToLauncher() : Subsystem("ToLauncher") {

	toLauncherWheel = new Relay(TO_LAUNCHER_MOTOR_PORT);
}

ToLauncher::~ToLauncher(){
	delete toLauncherWheel;
}
    
void ToLauncher::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new ControlToLauncher());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

void ToLauncher::setDirection(Relay::Value value){
	if(value != Relay::kReverse) // The ToLauncher wheel should never go backwards
	{
		toLauncherWheel->Set(value);
	}
}
