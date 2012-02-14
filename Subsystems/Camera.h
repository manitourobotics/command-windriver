#ifndef CAMERA_H
#define CAMERA_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Bang
 */
class Camera: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	
	AxisCamera* camera;
	
public:
	Camera();
	~Camera();
	void InitDefaultCommand();
};

#endif
