#include "Camera.h"
#include "../Robotmap.h"
#include "../Commands/GetCameraData.h"

Camera::Camera() : Subsystem("Camera") {

	camera = &(AxisCamera::GetInstance());
	camera->WriteResolution(AxisCamera::kResolution_320x240);
	camera->WriteBrightness(AxisCamera::kWhiteBalance_Automatic);
	camera->WriteCompression(30);
	
	image = new HSLImage();
	operatedImage = new BinaryImage();
}

Camera::~Camera() {
	delete camera;
	delete image;
	delete operatedImage;
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

void Camera::operateOnImage()
{

	int hueLow = 0;
	int hueHigh = 255;
	int saturationLow = 0;
	int saturationHigh = 255;
	int luminenceLow = 0;
	int luminenceHigh = 255;
	BinaryImage* thresholdImage  = new BinaryImage();
	thresholdImage = image->ThresholdHSL(hueLow, hueHigh, saturationLow, 
			saturationHigh, luminenceLow, luminenceHigh);
	BinaryImage* bigObjectsImage = new BinaryImage();
	bigObjectsImage = thresholdImage->RemoveSmallObjects(false, 2);
	BinaryImage* convexHullImage = new BinaryImage();
	convexHullImage = bigObjectsImage->ConvexHull(false);
	BinaryImage* filteredImage = new BinaryImage();
	//filteredImage = convexHullImage->ParticleFilter();
	
	delete thresholdImage;
	delete bigObjectsImage;
	delete convexHullImage;
	delete filteredImage;
	

}
