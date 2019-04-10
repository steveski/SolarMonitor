// LightSensor.h

#ifndef _LIGHTSENSOR_h
#define _LIGHTSENSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <Adafruit_TSL2591.h>

struct LightData
{
	float lux;
};

class LightSensor
{
private:
	Adafruit_TSL2591 tsl;


public:
	LightSensor(uint32_t addr = -1);

	void configure();
	LightData* read();
	void displaySensorDetails();

};



#endif

