/*
 * File:   main_Sivir.c
 * Author: XBUG
 *
 * Created on February 7, 2018
 */
unsigned int RES;

#include <xc.h>
#include "config.h"
#include "globalDefinitions.h"

void interrupt isr(){
    if(ADIF){
        ADIF = 0;
        RES = (ADRESH<<8)+ADRESL;
        ADCON0bits.ADON = _OFF;
    }
}
void main(void) {
    
    configPIC();
    LEDa = _OFF;
    while(1){
        if(!ADCON0bits.GO){
            convertAtoD(0);
        }
        if((419 < RES)&&(RES < 735)){ //1.93 y 3.39 V :c
            LEDa = _ON;
        } else {
            LEDa = _OFF;
        }
    }
    return;
}
