/*
 Name:    SolarMonitor.ino
 Created: 4/8/2019 11:11:27 PM
 Author:  steve
*/


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
//TFT tft = TFT(cs, dc, rst);

LightSensor* lightSensor;
TempPressureSensor* tempPressSensor;
VoltageSensor* voltageSensor;


struct DisplayData
{
	String lineStrings[2];
	int lineFontSize[2];

} disp;

void UpdateDisplay(DisplayData* dispData)
{	

}


///////////////////////////////////////////////////////
void setup() 
{
#if _DEBUG
	Serial.begin(9600);
#endif

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


}

void loop()
{
#if _DEBUG
	Serial.println("------------------------------------");
#endif

	LightData* lightData = lightSensor->read();
	TempPressureData* tempPressData = tempPressSensor->read();
	VoltageData* voltData = voltageSensor->read();

	
	char buffer[16];
	disp.lineStrings[0] = String("Light");
	disp.lineFontSize[0] = 1;
	disp.lineStrings[1] = String(sprintf(buffer, "%f ", lightData->lux));
	disp.lineFontSize[1] = 2;
	//UpdateDisplay(&disp);
	Serial.println(dispData->lineStrings[0]);
	delay(1500);

	disp.lineStrings[0] = String("Temperature");
	disp.lineFontSize[0] = 1;
	disp.lineStrings[1] = String(sprintf(buffer, "%f% cC", tempPressData->temperatureC, (char)223));
	disp.lineFontSize[1] = 2;
	//UpdateDisplay(&disp);
	delay(1500);

	disp.lineStrings[0] = String("Pressure");
	disp.lineFontSize[0] = 1;
	disp.lineStrings[1] = String(sprintf(buffer, "%f Pa", tempPressData->pressurePa));
	disp.lineFontSize[1] = 2;
	//UpdateDisplay(&disp);
	delay(1500);

	disp.lineStrings[0] = String("Altitude");
	disp.lineFontSize[0] = 1;
	disp.lineStrings[1] = String(sprintf(buffer, "%f m", tempPressData->altitudeM));
	disp.lineFontSize[1] = 2;
	//UpdateDisplay(&disp);
	delay(1500);

	disp.lineStrings[0] = String("Voltage");
	disp.lineFontSize[0] = 1;
	disp.lineStrings[1] = String(sprintf(buffer, "%f mV", voltData->shuntVoltage));
	disp.lineFontSize[1] = 2;
	//UpdateDisplay(&disp);
	delay(1500);

	disp.lineStrings[0] = String("Amps");
	disp.lineFontSize[0] = 1;
	disp.lineStrings[1] = String(sprintf(buffer, "%f mA", voltData->currentMa));
	disp.lineFontSize[1] = 2;
	//UpdateDisplay(&disp);
	delay(1500);


#if _DEBUG
	Serial.println();
#endif

	delay(1000);

}


