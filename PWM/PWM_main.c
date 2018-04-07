/*
 * File:   PWM_main.c
 * Author: Alfredo
 *
 * Created on 28 de marzo de 2018, 07:46 PM
 */


#include <xc.h>
#include "config.h"

int dc = 0;
int sentido = 1;

void main(void) {
    
    configPIC();
    
    openPWM1(99); // Open PWM 1 @5kHz
    
    PWM1_setDC(60); // 60% duty cycle
    
    while(1);
 
//    while(sentido == 1 && dc < 250 )
//    {
//        __delay_ms(500);
//        dc = dc + 13;
//        PWM1_setDC(dc);
//        __delay_ms(500);
//        if(dc == 247)
//        {
//            dc = 249;
//            PWM1_setDC(dc);
//            sentido = -1;
//        }
//    }
//
//    while(sentido == -1 && dc < 250)
//    {
//        __delay_ms(500);
//        dc = dc - 13;
//        PWM1_setDC(dc);
//        __delay_ms(500);
//        if(dc == 2)
//            {
//                dc = 0;
//                PWM1_setDC(dc);
//                sentido = 1;
//            }
//    }
        
        
}
