/*
 ===================================================
 Author    : Abdel Rhman Helal Saleh
 File Name : main.c
 Data      : Oct 12, 2023
 Time      : 9:18:10 PM
 ===================================================
 */
#include<avr/io.h>
#include "../hal/lcd.h"
#include "../hal/ultrasonic.h"
int main(void) {
	/*Enable Global interput*/
	SREG |= (1 << 7);
	Ultrasonic_init();
	LCD_init();
	LCD_displayString("Distance= ");
	uint16 distance = 0;
	for (;;) {
		distance = Ultrasonic_readDistance();
		LCD_moveCursor(0, 10);
		LCD_intgerToString(distance);
		LCD_displayString("cm ");
	}
}
