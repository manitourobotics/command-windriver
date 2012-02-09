#ifndef TILTLAUNCHERDOWN_H
#define TILTLAUNCHERDOWN_H

#include "../CommandBase.h"

/**
 *
 *
 * @author b1500048
 */
class TiltLauncherDown: public CommandBase {
public:
	TiltLauncherDown();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
