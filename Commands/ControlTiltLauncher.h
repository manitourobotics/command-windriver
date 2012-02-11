#ifndef CONTROLTILTLAUNCHER_H
#define CONTROLTILTLAUNCHER_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Bang
 */
class ControlTiltLauncher: public CommandBase {
private:
	
	float tiltValue;
	float const DEAD_ZONE;
	
public:
	ControlTiltLauncher();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
