/*
 * File:   main_turn_ON_LED.c
 * Author: EstebanB
 *
 * Created on January 19, 2018, 6:11 PM
 */


#include <xc.h>
#include "config.h"


void main(void) {
    
    configPIC();  //configurar todos los modulos y pines del PIC
    
    LED = _ON;
    
    while(1);
    
}
