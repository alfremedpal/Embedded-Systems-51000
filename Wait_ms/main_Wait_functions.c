/*
 * File:   main_Wait_functions.c
 * Author: Alfredo Medina
 *
 * Created on 26 de enero de 2018, 06:58 PM
 */


#include <xc.h>
#include "config.h"


void main(void) {
    
    configPIC();
    
    while(1)
    {
        LED = _ON;
        wait_ms(250);
        LED = _OFF;
        wait_ms(250);
    }
    
}
