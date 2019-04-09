// 
// 
// 


#include "TempPressureSensor.h"


TempPressureSensor::TempPressureSensor(uint32_t addr)
{
	bmp = Adafruit_BMP085();
	
	if (!bmp.begin())
	{
		Serial.println("No BMP180 sensor detected ... Check your wiring or I2C ADDR");
	}
	else
	{
		Serial.println("Found BMP180 sensor");

	}

}



void TempPressureSensor::configure()
{
	

}

void TempPressureSensor::read()
{
	float temp = bmp.readTemperature();
	float pa = bmp.readPressure();
	float alt = bmp.readAltitude();

	Serial.print("Temp: "); Serial.print(temp); Serial.println(" C");
	Serial.print("Pressure: "); Serial.print(pa); Serial.println(" Pa");
	Serial.print("Altitude: "); Serial.println(alt); //Serial.print(" ");

}


void TempPressureSensor::displaySensorDetails()
{

}