// 
// 
// 

#include "Flasher.h"

void FlasherClass::Flasher(int pin, long on, long off)
{
	this->pinLED = pin;
	pinMode(this->pinLED, OUTPUT);

	this->OnTime = on;
	this->OffTime = off;

	this->ledState = LOW;
	this->previousMillis = 0;
}

void FlasherClass::UpdateLED()
{
	this->currentMillis = millis();

	if ((this->ledState == HIGH) && (this->currentMillis - this->previousMillis >= this->OnTime))
	{
		this->ledState = LOW;
		this->previousMillis = this->currentMillis;
		digitalWrite(this->pinLED, this->ledState);
	}
	else if ((this->ledState == LOW) && (this->currentMillis - this->previousMillis >= this->OffTime))
	{
		this->ledState = HIGH;
		this->previousMillis = this->currentMillis;
		digitalWrite(this->pinLED, this->ledState);
	}
}

void FlasherClass::offLED()
{
	digitalWrite(this->pinLED, LOW);
	this->ledState = LOW;
}

FlasherClass Flasher;

