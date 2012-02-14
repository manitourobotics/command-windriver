#ifndef CONTROLTOLAUNCHER_H
#define CONTROLTOLAUNCHER_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Bang
 */
class ControlToLauncher: public CommandBase {
public:
	ControlToLauncher();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
