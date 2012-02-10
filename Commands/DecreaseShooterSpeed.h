#ifndef DECREASESHOOTERSPEED_H
#define DECREASESHOOTERSPEED_H

#include "../CommandBase.h"

/**
 *
 *
 * @author b1500048
 */
class DecreaseShooterSpeed: public CommandBase {
public:
	DecreaseShooterSpeed();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
