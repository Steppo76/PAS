// Flasher.h

#ifndef _FLASHER_h
#define _FLASHER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class FlasherClass
{
 protected:
	 int pinLED;
	 long OnTime;
	 long OffTime;
	 int ledState;
	 unsigned long previousMillis;
	 unsigned long currentMillis;

 public:
	void Flasher(int, long, long);
	void UpdateLED();
	void offLED();
};

extern FlasherClass Flasher;

#endif