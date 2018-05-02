/*
 * File:   I2C_main.c
 * Author: Alfredo
 *
 * Created on 1 de mayo de 2018, 02:14 PM
 */


#include <xc.h>
#include <stdio.h>
#include "LCD.h"
#include "config.h"
#include "I2C_config.h"


void main(void) {
 
    configPIC();
    LCD_Init();
    
    int x = 100;
    char m[8];
    
    //sprintf(m, "value: %x", x);
    
    LCD_Clear();
    LCD_SetCursor(1,0);
    LCD_WriteString("WHO AM I?");
    //LCD_SetCursor(2,0);
    //LCD_WriteString(m);
    
    char data[8];
    initI2C();
    
    
    
    while(1)
    {
     
//        I2CreadDevice(0x71, 0x75, data, 8);
//
//        sprintf(m, "value: %x", data);
//        LCD_SetCursor(2,0);
//        LCD_WriteString(m);
        
        I2Cstart();
        __delay_ms(500);
    }
 
}
