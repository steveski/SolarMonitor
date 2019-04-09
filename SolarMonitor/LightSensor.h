// LightSensor.h

#ifndef _LIGHTSENSOR_h
#define _LIGHTSENSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <Adafruit_TSL2591.h>

class LightSensor
{
private:
	Adafruit_TSL2591 tsl;


public:
	LightSensor(uint32_t addr = -1);

	void configure();
	void read();
	void displaySensorDetails();

};



#endif

