#ifndef CONTROLACQUISITION_H
#define CONTROLACQUISITION_H

#include "../CommandBase.h"

/**
 *
 *
 * @author azrathud
 */
class ControlAcquisition: public CommandBase {
public:
	ControlAcquisition();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
