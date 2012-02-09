#ifndef PICKUP_H
#define PICKUP_H

#include "../CommandBase.h"

/**
 *
 *
 * @author b1500048
 */
class Pickup: public CommandBase {
public:
	Pickup();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
