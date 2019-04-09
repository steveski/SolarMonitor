// VoltageSensor.h

#ifndef _VOLTAGESENSOR_h
#define _VOLTAGESENSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <Adafruit_INA219.h>


class VoltageSensor
{
private:
	Adafruit_INA219* ina219;


public:
	VoltageSensor(uint8_t addr = -1);

	void configure();
	void read();
	void displaySensorDetails();

};

#endif

