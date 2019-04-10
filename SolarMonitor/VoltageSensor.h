// VoltageSensor.h

#ifndef _VOLTAGESENSOR_h
#define _VOLTAGESENSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <Adafruit_INA219.h>

struct VoltageData
{
	float shuntVoltage = 0;
	float busVoltage = 0;
	float currentMa = 0;
	float loadVoltage = 0;
	float powerMw = 0;
};

class VoltageSensor
{
private:
	Adafruit_INA219* ina219;


public:
	VoltageSensor(); //uint8_t addr = -1);

	void configure();
	VoltageData* read();
	void displaySensorDetails();


};

#endif

