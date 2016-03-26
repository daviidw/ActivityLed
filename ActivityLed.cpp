
#include "ActivityLed.h"

unsigned long previousMillis = 0;   // will store last time LED was updated
long interval = 100;          // interval at which to blink (milliseconds)
int PrevLedState = LOW;             // PrevLedState used to set the LED
bool Activity;
int Pin;

ActivityLed::ActivityLed(int LedPin, long MinTimeOn)
{
	Pin = LedPin;
	interval = MinTimeOn;
	pinMode(LedPin, OUTPUT);
    digitalWrite(LedPin, LOW);
}

void ActivityLed::Update(bool State)
{
	if (State)
		Activity = true;
	
	unsigned long currentMillis = millis();
	if (currentMillis - previousMillis > interval) {
		// save the last time you blinked the LED
		if (Activity)
		{
			PrevLedState = !PrevLedState;
			digitalWrite(Pin, PrevLedState);
		}
		else
		{
			PrevLedState = false;
			digitalWrite(Pin, PrevLedState); 
		}
		previousMillis = currentMillis;	
    }
}