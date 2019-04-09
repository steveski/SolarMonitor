// TempPressureSensor.h

#ifndef _TEMPPRESSURESENSOR_h
#define _TEMPPRESSURESENSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <Adafruit_BMP085.h>

class TempPressureSensor
{
private:
	Adafruit_BMP085 bmp;


public:
	TempPressureSensor(uint32_t addr = -1);

	void configure();
	void read();
	void displaySensorDetails();

};

#endif

