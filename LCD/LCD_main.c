/*
 * File:   LCD_main.c
 * Author: Alfredo
 *
__TRACE(id);
 * Created on 15 de febrero de 2018, 06:55 PM
 */


#include <xc.h>
#include "config.h"
#include "LCD.h"


void main(void) {
   
    configPIC();
    LCD_Init();
    
   
    TRISAbits.RA4 = OUTPUT;
  
    LCD_Init();
    
   
    
    while(1)
    {
         LCD_SetCursor(1,1);
         LCD_WriteString("Hola.");
         LCD_SetCursor(2,1);
         LCD_WriteString("Mundo");
         
         PORTAbits.RA4 = 1;
    }
    
    
}
