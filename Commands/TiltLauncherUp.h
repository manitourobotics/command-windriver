#ifndef TILTLAUNCHERUP_H
#define TILTLAUNCHERUP_H

#include "../CommandBase.h"

/**
 *
 *
 * @author b1500048
 */
class TiltLauncherUp: public CommandBase {
public:
	TiltLauncherUp();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
