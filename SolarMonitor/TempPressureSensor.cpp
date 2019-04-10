// 
// 
// 


#include "TempPressureSensor.h"

TempPressureData tempPressureData;

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

TempPressureData* TempPressureSensor::read()
{
	tempPressureData.temperatureC = bmp.readTemperature();
	tempPressureData.pressurePa = bmp.readPressure();
	tempPressureData.altitudeM = bmp.readAltitude();

#if _DEBUG
	Serial.print("Temp: "); Serial.print(tempPressureData.temperatureC); Serial.println(" C");
	Serial.print("Pressure: "); Serial.print(tempPressureData.pressurePa); Serial.println(" Pa");
	Serial.print("Altitude: "); Serial.println(tempPressureData.altitudeM); //Serial.print(" ");
#endif

}


void TempPressureSensor::displaySensorDetails()
{

}