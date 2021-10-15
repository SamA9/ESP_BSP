/*
 *
 **/
#include "BSP.h"

void IRAM_ATTR delayMicroseconds(uint32_t us)
{
	uint32_t m = micros();
	if (us) {
		uint32_t e = (m + us);
		if (m > e) {
			//overflow
		   while(micros() > e) {
				__NOP;
			}
		}
		while (micros() < e) {
			__NOP;
		}
	}
}

long map(long x, long in_min, long in_max, long out_min, long out_max) {
	const long dividend = out_max - out_min;
	const long divisor = in_max - in_min;
	const long delta = x - in_min;
	if (divisor == 0) {
		ESP_LOGE("map funchion " ,"Invalid map input range, min == max");
		return -1; //AVR returns -1, SAM returns 0
	}
	return (delta * dividend + (divisor / 2)) / divisor + out_min;
}
