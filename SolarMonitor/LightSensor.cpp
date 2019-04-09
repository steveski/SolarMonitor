// 
//
// https://learn.adafruit.com/adafruit-tsl2591/wiring-and-test
// 

#include <Adafruit_Sensor.h>


#include "LightSensor.h"


LightSensor::LightSensor(uint32_t addr)
{
	if(addr == -1)
		tsl = Adafruit_TSL2591(TSL2591_ADDR);
	else
		tsl = Adafruit_TSL2591(addr);

	if (!tsl.begin())
	{
		Serial.println("No TSL2561 light sensor detected ... Check your wiring or I2C ADDR");
	}
	else
	{
		Serial.println("Found TSL2561 light sensor");

	}

}



void LightSensor::configure()
{
	// You can change the gain on the fly, to adapt to brighter/dimmer light situations
  //tsl.setGain(TSL2591_GAIN_LOW);    // 1x gain (bright light)
	tsl.setGain(TSL2591_GAIN_MED);      // 25x gain
	//tsl.setGain(TSL2591_GAIN_HIGH);   // 428x gain

	// Changing the integration time gives you a longer time over which to sense light
	// longer timelines are slower, but are good in very low light situtations!
	tsl.setTiming(TSL2591_INTEGRATIONTIME_100MS);  // shortest integration time (bright light)
	//tsl.setTiming(TSL2591_INTEGRATIONTIME_200MS);
	//tsl.setTiming(TSL2591_INTEGRATIONTIME_300MS);
	//tsl.setTiming(TSL2591_INTEGRATIONTIME_400MS);
	//tsl.setTiming(TSL2591_INTEGRATIONTIME_500MS);
	//tsl.setTiming(TSL2591_INTEGRATIONTIME_600MS);  // longest integration time (dim light)


	/* Display the gain and integration time for reference sake */
	Serial.println("------------------------------------");
	Serial.print("Gain:         ");
	tsl2591Gain_t gain = tsl.getGain();
	switch (gain)
	{
	case TSL2591_GAIN_LOW:
		Serial.println("1x (Low)");
		break;
	case TSL2591_GAIN_MED:
		Serial.println("25x (Medium)");
		break;
	case TSL2591_GAIN_HIGH:
		Serial.println("428x (High)");
		break;
	case TSL2591_GAIN_MAX:
		Serial.println("9876x (Max)");
		break;
	}
	Serial.print("Timing:       ");
	Serial.print((tsl.getTiming() + 1) * 100, DEC);
	Serial.println(" ms");
	Serial.println("------------------------------------");
	Serial.println("");

}

void LightSensor::read()
{
	/* Get a new sensor event */
	sensors_event_t event;
	tsl.getEvent(&event);

	/* Display the results (light is measured in lux) */
	Serial.print("[ "); Serial.print(event.timestamp); Serial.print(" ms ] ");
	if ((event.light == 0) |
		(event.light > 4294966000.0) |
		(event.light < -4294966000.0))
	{
		/* If event.light = 0 lux the sensor is probably saturated */
		/* and no reliable data could be generated! */
		/* if event.light is +/- 4294967040 there was a float over/underflow */
		Serial.println("Invalid data (adjust gain or timing)");
	}
	else
	{
		Serial.print(event.light); Serial.println(" lux");
	}
}


/**************************************************************************/
/*
  Displays some basic information on this sensor from the unified
  sensor API sensor_t type (see Adafruit_Sensor for more information)
*/
/**************************************************************************/
void LightSensor::displaySensorDetails()
{
	sensor_t sensor;
	tsl.getSensor(&sensor);
	Serial.println("------------------------------------");
	Serial.print("Sensor:       "); Serial.println(sensor.name);
	Serial.print("Driver Ver:   "); Serial.println(sensor.version);
	Serial.print("Unique ID:    "); Serial.println(sensor.sensor_id);
	Serial.print("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" lux");
	Serial.print("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" lux");
	Serial.print("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" lux");
	Serial.println("------------------------------------");
	Serial.println("");
	delay(500);
}
