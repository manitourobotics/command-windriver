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
	
	enum axis
	{
	    LEFT_STICK_X = 1,
	    LEFT_STICK_Y,
	    TRIGGERS,
	    RIGHT_STICK_X,
	    RIGHT_STICK_Y
	};
	
	DriveWithJoystick();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
