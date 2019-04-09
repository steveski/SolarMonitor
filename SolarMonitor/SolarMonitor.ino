/*
 Name:    SolarMonitor.ino
 Created: 4/8/2019 11:11:27 PM
 Author:  steve
*/

//#include "BMP180.h"
//#include "INA219.h"
//#include "TSL2591.h"

#include "VoltageSensor.h"
#include "TempPressureSensor.h"
#include "LightSensor.h"
#include <SPI.h>
#include <TFT.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>



#define cs  10
#define dc  9
#define rst 8


#include "LightSensor.h"

LightSensor* lightSensor;
TempPressureSensor* tempPressSensor;
VoltageSensor* voltageSensor;
//
//TFT tft = TFT(cs, dc, rst);
//char sensorPrintout[4];


///////////////////////////////////////////////////////
void setup() 
{
	Serial.begin(9600);

	lightSensor = new LightSensor();
	lightSensor->displaySensorDetails();
	lightSensor->configure();

	tempPressSensor = new TempPressureSensor();
	tempPressSensor->configure();

	voltageSensor = new VoltageSensor();
	voltageSensor->configure();


	// Setup TFT Screen
	//tft.begin();
	//tft.background(0, 0, 0);

	//tft.stroke(255, 255, 255);
	//tft.setTextSize(2);


}

void loop()
{
	Serial.println("------------------------------------");
	lightSensor->read();
	tempPressSensor->read();
	voltageSensor->read();

	//UpdateDisplay();

	Serial.println();
	
	delay(5000);

}



//
//
//char lineBuffer[20];
//
//struct Environment
//{
//	char temperature[10];
//	char pressure[10];
//	char lumens[10];
//
//} env;
//
//
//
//void GetVoltage()
//{
//	float shuntvoltage = 0;
//	float busvoltage = 0;
//	float current_mA = 0;
//	float loadvoltage = 0;
//	float power_mW = 0;
//
//	shuntvoltage = ina219.getShuntVoltage_mV();
//	busvoltage = ina219.getBusVoltage_V();
//	current_mA = ina219.getCurrent_mA();
//	power_mW = ina219.getPower_mW();
//	loadvoltage = busvoltage + (shuntvoltage / 1000);
//
//	Serial.print("Bus Voltage:   "); Serial.print(busvoltage); Serial.println(" V");
//	Serial.print("Shunt Voltage: "); Serial.print(shuntvoltage); Serial.println(" mV");
//	Serial.print("Load Voltage:  "); Serial.print(loadvoltage); Serial.println(" V");
//	Serial.print("Current:       "); Serial.print(current_mA); Serial.println(" mA");
//	Serial.print("Power:         "); Serial.print(power_mW); Serial.println(" mW");
//	Serial.println("");
//}
//
//
//
//void GetTempAndPressure()
//{
//	String(bmp.readTemperature(), 1).toCharArray(env.temperature, 10);
//	String(bmp.readPressure()).toCharArray(env.pressure, 10);
//	//env.lumens = String(92).c_str();
//
//	Serial.print(env.temperature);
//	Serial.println(" *C");
//	Serial.print(env.pressure);
//	Serial.println(" Pa");
//
//	//tempStr.toCharArray(env.temperature, 3);
//	//pressStr.toCharArray(env.pressure, 6);
//	//lumensStr.toCharArray(env.lumens, 6);
//
//}

/*
void UpdateDisplay()
{
  sprintf(lineBuffer, "%s %cC", env.temperature, (char)223);
  tft.text(lineBuffer, 10, 30);

  sprintf(lineBuffer, "%s Pa", env.pressure);
  tft.text(lineBuffer, 10, 55);

  sprintf(lineBuffer, "%s lux", env.lumens);
  tft.text(lineBuffer, 10, 80);
}
*/