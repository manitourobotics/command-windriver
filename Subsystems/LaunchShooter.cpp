#include "LaunchShooter.h"
#include "../Robotmap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "../Commands/ControlLaunchShooterSpeed.h"

LaunchShooter::LaunchShooter() : 
PIDSubsystem("LaunchShooter", Kp, Ki, Kd), BOTTOM_MOTOR_PORPORTIONALITY_CONSTANT(0.9), 
MAX_SPEED(1)/* MAX SPEED temporary for testing encoding motor */,
speed(0){ 
	// Use these to get going:
	// SetSetpoint() -  Sets where the PID controller should move the system
	//                  to
	// Enable() - Enables the PID controller.
	
	//topMotor = new Jaguar(TOP_MOTOR_PORT);
	bottomMotor = new Jaguar(BOTTOM_MOTOR_PORT);
	//digitalEncoder = new Encoder(DIGITAL_ENCODER_A, DIGITAL_ENCODER_B,0);
	
	//digitalEncoder->Start();
	//digitalEncoder->SetDistancePerPulse()
	//SetSetpoint(DESIRED_SPEED);
	//Enable();
	
	
	//drive = new RobotDrive(TOP_MOTOR_PORT, BOTTOM_MOTOR_PORT);
	
}

LaunchShooter::~LaunchShooter() {
	//delete topMotor;
	delete bottomMotor;
}

double LaunchShooter::ReturnPIDInput() {
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;

	//cout << digitalEncoder->Get();
	rpm = (1/(digitalEncoder->GetPeriod()))/250*60;
	//CommandBase::sd->Log(rpm, "rpm");
	return rpm;
}

void LaunchShooter::UsePIDOutput(double output) {
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
	//topMotor->Set(output);
	bottomMotor->Set(output);
}

void LaunchShooter::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//setDefaultCommand(new MySpecialCommand());
	//SetDefaultCommand(new IncreaseShooterSpeed());
	//if(!CommandBase::autonomousEnabled)
		SetDefaultCommand(new ControlLaunchShooterSpeed());
}

/*void LaunchShooter::arcadeDrive(Joystick* stick) {
	drive->ArcadeDrive(stick); 
}*/

void LaunchShooter::incrementMotorSpeeds(float speed){
	cout << "speed:" << speed << '\n';
	
	this->speed += speed;
	if(this->speed > 1)
	{
		this->speed = 1;
	}
	else if(this->speed < 0) // The motor doesn't need to go in reverse.
	{
			this->speed = 0;
	}
	bottomMotor->Set(this->speed * -1);
	//CommandBase::sd->Log(speed, "launcher speed");
}

void LaunchShooter::setMotorSpeeds(float speed){
	cout << "speed:" << speed << '\n';
	if(speed > 1)
	{
		speed = 1;
	}
	else if(speed < 0) // The motor doesn't need to go in reverse.
	{
			speed = 0;
	}
	this->speed = speed;
	bottomMotor->Set(this->speed * -1);
	//CommandBase::sd->Log(speed, "launcher speed");
}
void LaunchShooter::stopMotors(){
	this->speed = 0;
	bottomMotor->Set(0);

}

Encoder* LaunchShooter::getDigitalEncoder(){
	return digitalEncoder;
}
