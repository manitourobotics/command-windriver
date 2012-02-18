#ifndef CAMERA_H
#define CAMERA_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <cmath>
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
	
	HSLImage* image;
	BinaryImage* operatedImage;
	
	double const LENS_ANGLE;
	double const RESOLUTION_WIDTH;
	double const RESOLUTION_HEIGHT;
	double distance;
	
	vector<ParticleAnalysisReport>* particles;
	vector<ParticleAnalysisReport>* rects;
	
public:
	Camera();
	~Camera();
	void InitDefaultCommand();
	
	ColorImage* getCurrentImage();
	AxisCamera* getCamera();
	
	void operateOnImage();
	void determineDistance();
	void determineRects();
};

#endif
