/*
 * File:   main_Interruptions.c
 * Author: Alfredo
 *
 * Created on 2 de febrero de 2018, 07:18 PM
 */


#include <xc.h>
#include "config.h"

volatile int state = 0; 

void interrupt isr()
{
    if(INT0IF)
    {
        INT0IF = 0;
        LED = _ON;
    }
    
    if(INT1IF)
    {
        INT1IF = 0;
        
        if(state == _OFF)
            state = _ON;
        else
            state = _OFF;
        
    }
    
    if(INT2IF)
    {
        INT2IF = 0;
    }
}

void main(void) {
    
    configPIC();
    
    LED = _OFF;
    
    //TRISAbits.RA1 = 0;
    //PORTAbits.RA1 = 1;
    
    //while(1)
    //{
        //LED = state;
    //}
    
    
    
    
    
    
    
    
}

