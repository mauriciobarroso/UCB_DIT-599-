/*
 * bitec_button.h
 *
 * Created on: Mar 29, 2021
 * Author: Mauricio Barroso Benavides
 */

#ifndef _BITEC_BUTTON_H_
#define _BITEC_BUTTON_H_

/* inclusions ----------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"

#include "driver/gpio.h"

/* cplusplus -----------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

/* macros --------------------------------------------------------------------*/

#define BUTTON_SHORT_PRESS_BIT	BIT0
#define BUTTON_MEDIUM_PRESS_BIT	BIT1
#define BUTTON_LONG_PRESS_BIT	BIT2

/* typedef -------------------------------------------------------------------*/

typedef enum
{
	FALLING_MODE = 0,
	RISING_MODE
} button_mode_e;

/* Button states */
typedef enum
{
	UP_STATE,
	DOWN_STATE,
	FALLING_STATE,
	RISING_STATE
} button_state_e;

typedef struct
{

	button_state_e state;
	button_mode_e mode;
	gpio_num_t pin;
	TickType_t tick_counter;
	uint8_t falling_counter;
	uint8_t rising_counter;
	void (* short_function)(void *);
	void (* medium_function)(void *);
	void (* long_function)(void *);
	void * short_arg;
	void * medium_arg;
	void * long_arg;
	EventGroupHandle_t event_group;		/*!< todo: set description */
} bitec_button_t;

/* external data declaration -------------------------------------------------*/

/* external functions declaration --------------------------------------------*/

esp_err_t bitec_button_init(bitec_button_t * const me);

/* cplusplus -----------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

/** @} doxygen end group definition */

/* end of file ---------------------------------------------------------------*/

#endif /* #ifndef _BITEC_BUTTON_H_ */
