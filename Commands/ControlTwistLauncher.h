#ifndef CONTROLTWISTLAUNCHER_H
#define CONTROLTWISTLAUNCHER_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Bang
 */
class ControlTwistLauncher: public CommandBase {
	float m_twistValue;
public:
	ControlTwistLauncher();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
