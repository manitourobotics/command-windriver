#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
//#include "Commands/AutonomousGroup.h"

class CommandBasedRobot : public IterativeRobot {
private:
	Command *autonomousCommand;
	
	virtual void RobotInit() {
		CommandBase::init();
		/*autonomousCommand = new AutonomousGroup();*/
	}
	
	virtual void AutonomousInit() {
		/*
        CommandBase::autonomousEnabled = true;
		autonomousCommand->Start();
		m_watchdog.SetEnabled(false);*/
	}
	
	virtual void AutonomousPeriodic() {
		/*
		Scheduler::GetInstance()->Run();
		*/
	}
	
	virtual void TeleopInit() {
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		//autonomousCommand->Cancel();
        //CommandBase::autonomousEnabled = false;
        //m_watchdog.SetEnabled(false);
	}
	
	virtual void TeleopPeriodic() {
		Scheduler::GetInstance()->Run();
		m_watchdog.Feed();

	}
};

START_ROBOT_CLASS(CommandBasedRobot);

