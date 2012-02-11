#ifndef CONTROLTWISTLAUNCHER_H
#define CONTROLTWISTLAUNCHER_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Bang
 */
class ControlTwistLauncher: public CommandBase {
	float twistValue;
	float const DEAD_ZONE; // The relay moves even when the joystick is at rest
	
public:
	ControlTwistLauncher();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
