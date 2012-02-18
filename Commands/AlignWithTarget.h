#ifndef ALIGNWITHTARGET_H
#define ALIGNWITHTARGET_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Bang
 */
class AlignWithTarget: public CommandBase {
public:
	AlignWithTarget();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
