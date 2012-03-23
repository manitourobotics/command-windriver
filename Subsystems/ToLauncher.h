#ifndef TOLAUNCHER_H
#define TOLAUNCHER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Bang
 */
class ToLauncher: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	
	Relay* toLauncherWheel;
	
public:
	ToLauncher();
	~ToLauncher();
	
	void InitDefaultCommand();
	
	void setDirection(Relay::Value value);
};

#endif
