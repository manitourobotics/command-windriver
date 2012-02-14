#ifndef GETCAMERADATA_H
#define GETCAMERADATA_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Bang
 */
class GetCameraData: public CommandBase {
public:
	GetCameraData();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
