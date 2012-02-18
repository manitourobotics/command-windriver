#include "Camera.h"
#include "../Robotmap.h"
#include "../Commands/GetCameraData.h"

Camera::Camera() : 
Subsystem("Camera"), LENS_ANGLE(47),
RESOLUTION_WIDTH(320), RESOLUTION_HEIGHT(240) {

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

	int hueLow = 38;
	int hueHigh = 102;
	int saturationLow = 140;
	int saturationHigh = 255;
	int luminenceLow = 146;
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

void Camera::determineRects()
{
	double SCORE_THRESHOLD = 85;
	double score = 0;
	for(unsigned int i = 0; i < particles->size(); i++)
	{
		//(particle area / bounding rectangle area) * 100
		score = ((*particles)[i].particleArea / ((*particles)[i].boundingRect.width *(*particles)[i].boundingRect.height)) * 100.0 ;
		if (score > SCORE_THRESHOLD)
		{
			rects->push_back(((*particles)[i]));
		}
		
	}
}

void Camera::determineDistance()
{
	for(unsigned int i = 0; i < rects->size(); i++)
	{
		
	}
}
