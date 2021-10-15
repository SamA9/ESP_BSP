/*
 *
 *
 *
 **/
#ifndef __BSP__H_
#define __BSP__H_

/* Global includes */
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

#include "esp_timer.h"
#include "esp_log.h"

#include "driver/gpio.h"
#include "driver/adc.h" 

#ifdef __cplusplus
extern "C" {
#endif
	
	//
#define BUTTON GPIO_NUM_0
#define LED GPIO_NUM_2	
	//
#define millis() (esp_timer_get_time() / 1000)
#define micros() esp_timer_get_time()
	
#define digitalWrite(PIN,VAL) gpio_set_level(PIN,VAL)
#define digitalRead(PIN) gpio_get_level(PIN)
#define analogRead(pin) 	
	/*
	 *
	 **/
void IRAM_ATTR delayMicroseconds(uint32_t us);
/*
 *
 **/
long map(long x, long in_min, long in_max, long out_min, long out_max);
	/*
	 *
	 **/
#define delay(ms) delayMicroseconds(ms*1000)
//
#define bit(b) (1UL << (b))
#define _BV(b) (1UL << (b))
//
#ifndef __NOP 
#define __NOP asm volatile ("nop")
#endif
//	

#ifdef __cplusplus
}
#endif
#endif


