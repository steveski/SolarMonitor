// 
// 
// 

#include "VoltageSensor.h"

VoltageData theData;

VoltageSensor::VoltageSensor() //uint8_t addr)
{
	ina219 = new Adafruit_INA219(); // INA219_ADDRESS);
	/*if (addr == -1)
		ina219 = new Adafruit_INA219(INA219_ADDRESS);
	else
		ina219 = new Adafruit_INA219(addr);
	*/

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

VoltageData* VoltageSensor::read()
{
	theData.shuntVoltage = ina219->getShuntVoltage_mV();
	theData.busVoltage = ina219->getBusVoltage_V();
	theData.currentMa = ina219->getCurrent_mA();
	theData.loadVoltage = theData.busVoltage + (theData.shuntVoltage / 1000);
	theData.powerMw = ina219->getPower_mW();
	
#if _DEBUG
	Serial.print("Bus Voltage: "); Serial.print(theData.busVoltage); Serial.println(" V");
	Serial.print("Shunt Voltage: "); Serial.print(theData.shuntVoltage); Serial.println(" mV");
	Serial.print("Load Voltage: "); Serial.print(theData.loadVoltage); Serial.println(" V");
	Serial.print("Current: "); Serial.print(theData.currentMa); Serial.println(" mA");
	Serial.print("Power: "); Serial.print(theData.powerMw); Serial.println(" mW");
#endif

}


void VoltageSensor::displaySensorDetails()
{

}

