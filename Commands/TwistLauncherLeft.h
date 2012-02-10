#ifndef TWISTLAUNCHERLEFT_H
#define TWISTLAUNCHERLEFT_H

#include "../CommandBase.h"

/**
 *
 *
 * @author b1500048
 */
class TwistLauncherLeft: public CommandBase {
public:
	TwistLauncherLeft();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
