#ifndef DRIVEWITHJOYSTICK_H
#define DRIVEWITHJOYSTICK_H

#include "../CommandBase.h"

/**
 *
 *
 * @author b1500048
 */
class DriveWithJoystick: public CommandBase {
public:
	DriveWithJoystick();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
