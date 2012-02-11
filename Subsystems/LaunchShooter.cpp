#include "LaunchShooter.h"
#include "../Robotmap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "../Commands/IncreaseShooterSpeed.h"
#include "../Commands/ControlLaunchShooterSpeed.h"

LaunchShooter::LaunchShooter() : 
PIDSubsystem("LaunchShooter", Kp, Ki, Kd), BOTTOM_MOTOR_PORPORTIONALITY_CONSTANT(0.8), 
MAX_SPEED(0.416666667)/* MAX SPEED temporary for testing encoding motor */{ 
	// Use these to get going:
	// SetSetpoint() -  Sets where the PID controller should move the system
	//                  to
	// Enable() - Enables the PID controller.
	
	topMotor = new Jaguar(TOP_MOTOR_PORT);
	bottomMotor = new Jaguar(BOTTOM_MOTOR_PORT);
	digitalEncoder = new Encoder(DIGITAL_ENCODER_A, DIGITAL_ENCODER_B);
	
	digitalEncoder->Start();
	SetSetpoint(FINAL_ARM_POSITION);
	Enable();
	
	//drive = new RobotDrive(TOP_MOTOR_PORT, BOTTOM_MOTOR_PORT);
	
}

double LaunchShooter::ReturnPIDInput() {
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;

	cout << digitalEncoder->Get();
	return digitalEncoder->Get();
}

void LaunchShooter::UsePIDOutput(double output) {
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
	topMotor->Set(output);
}

void LaunchShooter::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//setDefaultCommand(new MySpecialCommand());
	//SetDefaultCommand(new IncreaseShooterSpeed());
	SetDefaultCommand(new ControlLaunchShooterSpeed());
}

/*void LaunchShooter::arcadeDrive(Joystick* stick) {
	drive->ArcadeDrive(stick);
}*/

void LaunchShooter::setMotorSpeeds(float speed){	
	topMotor->Set(speed * MAX_SPEED);
	bottomMotor->Set(speed * BOTTOM_MOTOR_PORPORTIONALITY_CONSTANT * MAX_SPEED);
}
	
void LaunchShooter::stopMotors(){
	topMotor->Set(0);
	bottomMotor->Set(0);

}

Encoder* LaunchShooter::getDigitalEncoder(){
	return digitalEncoder;
}
