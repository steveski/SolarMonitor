// 
// 
// 

#include "VoltageSensor.h"

VoltageSensor::VoltageSensor(uint8_t addr)
{
	if (addr == -1)
		ina219 = new Adafruit_INA219(INA219_ADDRESS);
	else
		ina219 = new Adafruit_INA219(addr);
	

	ina219->begin();
	/*if (!ina219->begin())
	{
		Serial.println("No INA219 sensor detected ... Check your wiring or I2C ADDR");
	}
	else
	{
		Serial.println("Found INA219 sensor");

	}*/

}



void VoltageSensor::configure()
{


}

void VoltageSensor::read()
{
	float shuntVoltage = ina219->getShuntVoltage_mV();
	float busVoltage = ina219->getBusVoltage_V();
	float currentMa = ina219->getCurrent_mA();
	float loadVoltage = busVoltage + (shuntVoltage / 1000);
	float powerMw = ina219->getPower_mW();
	

	Serial.print("Bus Voltage: "); Serial.print(busVoltage); Serial.println(" V");
	Serial.print("Shunt Voltage: "); Serial.print(shuntVoltage); Serial.println(" mV");
	Serial.print("Load Voltage: "); Serial.print(loadVoltage); Serial.println(" V");
	Serial.print("Current: "); Serial.print(currentMa); Serial.println(" mA");
	Serial.print("Power: "); Serial.print(powerMw); Serial.println(" mW");

}


void VoltageSensor::displaySensorDetails()
{

}

