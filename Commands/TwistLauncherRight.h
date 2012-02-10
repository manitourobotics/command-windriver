#ifndef TWISTLAUNCHERRIGHT_H
#define TWISTLAUNCHERRIGHT_H

#include "../CommandBase.h"

/**
 *
 *
 * @author b1500048
 */
class TwistLauncherRight: public CommandBase {
public:
	TwistLauncherRight();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
