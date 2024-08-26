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
	
	char number[4];
	char FirstRow[4] = " = ";
	for(unsigned char i = 0; i < 255; i++){
		intToStr(i, number);
		LCD_WRITE_STRING(number);
		LCD_WRITE_STRING(FirstRow);
		LCD_WRITE_CHAR(i);
		_delay_ms(10);
		SEND_COMMAND(CLEAR_DISPLAY);
		SEND_COMMAND(RETURN_HOME);
	}
	
}

void intToStr(char N, char *str) {
	int i = 0;
	
	// Save the copy of the number for sign
	char sign = N;

	// If the number is negative, make it positive
	if (N < 0)
	N = -N;

	// Extract digits from the number and add them to the
	// string
	while (N > 0) {
		
		// Convert integer digit to character and store
		// it in the str
		str[i++] = N % 10 + '0';
		N /= 10;
	}

	// If the number was negative, add a minus sign to the
	// string
	if (sign < 0) {
		str[i++] = '-';
	}

	// Null-terminate the string
	str[i] = '\0';

	// Reverse the string to get the correct order
	for (int j = 0, k = i - 1; j < k; j++, k--) {
		char temp = str[j];
		str[j] = str[k];
		str[k] = temp;
	}
}