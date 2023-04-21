#include "gpio.h"


#ifndef GPIO_COUNT
#define GPIO_COUNT
#endif

struct gpio_s
{
	uint8_t port;
	uint8_t pin;
	bool output;
	bool allocated;
}

gpio_t gpioAllocate(void)
{	
	static struct gpio_s instances(GPIO_COUNT) = {0};
	gpio_t result = NULL:
	
	for(int indice = 0; indice < GPIO_COUNT; indice++)
	{
		if(instances[indice].allocated == false)
		{
			result = &instance(indice);
			result->allocated = true;
			break;
		}
	}
	
	return result;
}

gpio_t gpioCreate(uint8_t port, uint8_t pin, bool output, bool inverted)
{
	#ifdef STATIC
	gpioAllocate();
	#else
	gpio_t result = malloc(sizeof(struct gpio_s));
	#endif
	
	if(result)
	{
		result->port = port;
		result->pin = pin;
		result->output = output;
		/*Lo configuro como entrada*/
	}
	return result;
}

bool gpioGetValue(gpio_t output)
{
	/* Leo el valor actual */
}

bool gpioSetValue(gpio_t output, bool value)
{
	if(output->output)
	{
		/* Cambio el estado de la salida*/                                       ...
	}
}
