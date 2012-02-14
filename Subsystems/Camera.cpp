#include "Camera.h"
#include "../Robotmap.h"
#include "../Commands/GetCameraData.h"

Camera::Camera() : Subsystem("Camera") {

	camera = &(AxisCamera::GetInstance());
	camera->WriteResolution(AxisCamera::kResolution_320x240);
	camera->WriteBrightness(0);
}

Camera::~Camera() {
	delete camera;
}
    
void Camera::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new GetCameraData());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

ColorImage* Camera::getCurrentImage()
{
	return image;
}

AxisCamera* Camera::getCamera()
{
	return camera;
}
