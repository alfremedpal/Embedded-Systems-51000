#include "config.h"

void configPIC(void)
{
    //ADC Config
    ADCON0 = 0b00000000;        //Turn off ADC module
    
    ADCON1 = 0b00001111;
    
    //ADCON1bits.PCFG = 0b1111;
    
    // TRIS: COMMAND to define if digital pin will be output or input
    // 0: output
    // 1: input
    
    
    TRISA = 0b00000000;         //Set all pins of port A as output
    TRISB = 0b00000000;         //Set all pins of port B as output
    TRISC = 0b00000000;         //Set all pins of port C as output
    TRISD = 0b00000000;         //Set all pins of port D as output
    TRISE = 0b00000000;         //Set all pins of port E as output
    
    SW1 = INPUT;
    
    INTCONbits.GIE = _OFF;         //Turn off all interrupt 
}

