/*
 * File:   main_TurnON_LED.c
 * Author: Alfredo Medina
 *
 * Created on 19 de enero de 2018, 06:13 PM
 * @brief: Turns on an LED on energizing
 */


#include <xc.h>
#include "config.h"

void main(void) {
    
    configPIC(); //Configure modules and pins
    
    LED = _ON;
    
    
    while(1);
}
