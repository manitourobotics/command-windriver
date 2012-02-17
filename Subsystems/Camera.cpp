#include "Camera.h"
#include "../Robotmap.h"
#include "../Commands/GetCameraData.h"

Camera::Camera() : Subsystem("Camera") {

	camera = &(AxisCamera::GetInstance());
	camera->WriteResolution(AxisCamera::kResolution_320x240);

	camera->WriteWhiteBalance(AxisCamera::kWhiteBalance_FixedOutdoor1);
	camera->WriteExposureControl(AxisCamera::kExposure_FlickerFree50Hz);
	camera->WriteExposurePriority(50); //none
	camera->WriteCompression(30);
	
	image = new HSLImage();
	operatedImage = new BinaryImage();
}

Camera::~Camera() {
	delete camera;
	delete image;
	delete operatedImage;
	delete particles;
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

	int hueLow = 80;
	int hueHigh = 147;
	int saturationLow = 61;
	int saturationHigh = 255;
	int luminenceLow = 145;
	int luminenceHigh = 253;
	BinaryImage* thresholdImage  = new BinaryImage();
	thresholdImage = image->ThresholdHSL(hueLow, hueHigh, saturationLow, 
			saturationHigh, luminenceLow, luminenceHigh);
	BinaryImage* bigObjectsImage = new BinaryImage();
	bigObjectsImage = thresholdImage->RemoveSmallObjects(false, 2);
	BinaryImage* convexHullImage = new BinaryImage();
	convexHullImage = bigObjectsImage->ConvexHull(false);
	//BinaryImage* filteredImage = new BinaryImage();
	
	vector<ParticleAnalysisReport>* particles = convexHullImage->GetOrderedParticleAnalysisReports();
	//filteredImage = convexHullImage->ParticleFilter();
	
	delete thresholdImage;
	delete bigObjectsImage;
	delete convexHullImage;
	
	//delete filteredImage;
	

}
