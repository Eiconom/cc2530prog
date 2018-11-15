/*
 * Linux GPIO backend using sysfs
 *
 * Copyright (C) 2010, Florian Fainelli <f.fainelli@gmail.com>
 *
 * This file is part of "cc2530prog", this file is distributed under
 * a 2-clause BSD license, see LICENSE for details.
 */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <wiringPi.h>

#include "gpio.h"

static int _setup=0;

void setup(void)
{
   _setup=1;
   wiringPiSetup();
}

int gpio_export(int n)
{
	return 0;
}

int gpio_unexport(int n)
{	
	return 0;
}

int gpio_set_direction(int n, enum gpio_direction direction)
{
    if (_setup==0) setup();

    switch(direction) {
    	case GPIO_DIRECTION_IN: 
			pinMode(n,INPUT); 
			pullUpDnControl(n,PUD_DOWN);
			break;
    	case GPIO_DIRECTION_OUT: 
			pinMode(n,OUTPUT); 
			pullUpDnControl(n,PUD_OFF);
			break;
    	case GPIO_DIRECTION_HIGH: 
			pinMode(n,INPUT); 
			pullUpDnControl(n,PUD_UP);
			break;
	}
				  
}

int gpio_get_value(int n, bool *value)
{
	*value = digitalRead(n);
}

int gpio_set_value(int n, bool value)
{
	digitalWrite(n,value);
}
