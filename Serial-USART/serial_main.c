/*
 * File:   serial_main.c
 * Author: Alfredo
 *
 * Created on 3 de marzo de 2018, 02:38 PM
 */


#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include "globalDefinitions.h"




void main(void) {
    
    configPIC();
    initUSART(9600);
    wait_ms(50);
    
    TRISAbits.RA2 = INPUT;
    LED = _OFF;
    
    
    char data;
    
    while(1)
    {
        data = NULL;
        
        if(PORTAbits.RA2)
        {
            transmitUSART('a');
            wait_ms(5);
            data = recieveUSART();
        }
        
        if(data == 'a')
        {
            if(LED)
                LED = _OFF;
            else
                LED = _ON;
            
            wait_ms(100);
        }
    }
}
