#ifndef CONTROLARM_H
#define CONTROLARM_H

#include "../CommandBase.h"

/**
 *
 *
 * @author azrathud
 */
class ControlArm: public CommandBase {
public:
	ControlArm();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
