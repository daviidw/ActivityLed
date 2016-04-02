
#ifndef ActivityLed_H
#define ActivityLed_H

#include <inttypes.h>

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#include "pins_arduino.h"
#endif

#if defined(__arm__) && defined(CORE_TEENSY)
#define ALTSS_BASE_FREQ F_BUS
#else
#define ALTSS_BASE_FREQ F_CPU
#endif

class ActivityLed
{
public:
	ActivityLed(int LedPin, long MinTimeOn);
	void Update(bool State);
};

#endif
