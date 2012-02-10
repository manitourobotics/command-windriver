#ifndef INCREASESHOOTERSPEED_H
#define INCREASESHOOTERSPEED_H

#include "../CommandBase.h"

/**
 *
 *
 * @author b1500048
 */
class IncreaseShooterSpeed: public CommandBase {
public:
	IncreaseShooterSpeed();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
