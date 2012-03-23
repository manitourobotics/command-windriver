#ifndef CONTROLLAUNCHSHOOTERSPEED_H
#define CONTROLLAUNCHSHOOTERSPEED_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Bang
 */
class ControlLaunchShooterSpeed: public CommandBase {
private:
	float incrementSpeeds;
public:
	ControlLaunchShooterSpeed();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
