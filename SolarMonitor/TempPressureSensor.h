// TempPressureSensor.h

#ifndef _TEMPPRESSURESENSOR_h
#define _TEMPPRESSURESENSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <Adafruit_BMP085.h>

struct TempPressureData
{
	float temperatureC = 0;
	float pressurePa = 0;
	float altitudeM = 0;
};

class TempPressureSensor
{
private:
	Adafruit_BMP085 bmp;


public:
	TempPressureSensor(uint32_t addr = -1);

	void configure();
	TempPressureData* read();
	void displaySensorDetails();

};

#endif

