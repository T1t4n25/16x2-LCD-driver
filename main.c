/*
 * LCD Driver.c
 *
 * Created: 16/08/2024 12:32:29 PM
 * Author : Meteor
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include "LCD.h"
#include "conf.h"
#include<util/delay.h>

void intToStr(char N, char *str);


int main(void)
{
	DDRC = 0xFF;
	DDRD = 0xFF;
	LCD_init();
	// WRITE APP HERE
	
}

