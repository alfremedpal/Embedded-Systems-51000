/*
 * File:   main_ADC.c
 * Author: Alfredo Medina
 *
 * Created on 8 de febrero de 2018, 05:40 PM
 */


#include <xc.h>
#include "config.h"

void main(void) {
    
    configPIC();
    initADC();
    
    while(1)
    {
        float volt = convertAD(0);
        
        if(volt > 3)
            LED = _ON;
        else
            LED = _OFF;
    }
    
}
