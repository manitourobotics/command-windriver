#include "GetCameraData.h"

GetCameraData::GetCameraData() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(camera);
}

// Called just before this Command runs the first time
void GetCameraData::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void GetCameraData::Execute() {
	camera->getCamera()->GetImage(camera->getCurrentImage());
	camera->operateOnImage();
}

// Make this return true when this Command no longer needs to run execute()
bool GetCameraData::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void GetCameraData::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GetCameraData::Interrupted() {
}
