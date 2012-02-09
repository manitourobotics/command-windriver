#ifndef ACQUISITION_H
#define ACQUISITION_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author b1500048
 */
class Acquisition: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Acquisition();
	void InitDefaultCommand();
};

#endif
