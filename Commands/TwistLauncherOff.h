#ifndef TWISTLAUNCHEROFF_H
#define TWISTLAUNCHEROFF_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Bang
 */
class TwistLauncherOff: public CommandBase {
public:
	TwistLauncherOff();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
