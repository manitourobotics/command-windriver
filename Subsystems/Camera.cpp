#include "Camera.h"
#include "../Robotmap.h"
#include "../Commands/GetCameraData.h"

Camera::Camera() : 
Subsystem("Camera"), LENS_ANGLE(54),
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
	int luminenceHigh = 255;
	BinaryImage* thresholdImage  = new BinaryImage();
	thresholdImage = image->ThresholdHSL(hueLow, hueHigh, saturationLow, 
			saturationHigh, luminenceLow, luminenceHigh);
	BinaryImage* bigObjectsImage = new BinaryImage();
	bigObjectsImage = thresholdImage->RemoveSmallObjects(false, 2);
	BinaryImage* convexHullImage = new BinaryImage();
	convexHullImage = bigObjectsImage->ConvexHull(false);
	//BinaryImage* filteredImage = new BinaryImage();
	
	particles = convexHullImage->GetOrderedParticleAnalysisReports();
	//filteredImage = convexHullImage->ParticleFilter();
	
	delete thresholdImage;
	delete bigObjectsImage;
	delete convexHullImage;
	
	//delete filteredImage;
}

void Camera::determineRects()
{
	
	double const RECT_SCORE_THRESHOLD = 85;
	double rect_score = 0;
	
	double const ASPECT_SCORE_DEVIATION = .2;
	double const ASPECT = 1.33333333;
	double aspect_score = 0;
	cout << "particle size: " << particles->size() << '\n';
	
	for(unsigned int i = 0; i < particles->size(); i++)
	{
		cout << "rect score: " << rect_score << '\n';
		cout << "aspect_score: " << aspect_score << '\n';
		
		//(particle area / bounding rectangle area) * 100
		rect_score = ((*particles)[i].particleArea / ((*particles)[i].boundingRect.width *(*particles)[i].boundingRect.height)) * 100.0 ;
		aspect_score = (*particles)[i].boundingRect.width / (*particles)[i].boundingRect.height;
		if (rect_score > RECT_SCORE_THRESHOLD && aspect_score > (ASPECT - ASPECT_SCORE_DEVIATION) 
				&& aspect_score < (ASPECT + ASPECT_SCORE_DEVIATION))
		{
			rects->push_back(((*particles)[i]));
		}
	}
	cout << "size: " << rects->size() << '\n';
}

void Camera::determineDistance()
{
	/*
	for(unsigned int i = 0; i < rects->size(); i++)
	{
		
	}
	*/ 
	distance = tan(LENS_ANGLE/2) / ((RESOLUTION_WIDTH*2) / ((*rects)[0].boundingRect.width / 2));
	cout << "distance: " << distance << '\n';
	CommandBase::sd->PutDouble("camera", distance);
}
