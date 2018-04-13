/*
 * File:   comparator_a_main.c
 * Author: liter
 *
 * Created on April 6, 2018, 7:08 PM
 */


#include <xc.h>
#include <stdio.h>

#include "config.h"
#include "LCD.h"
#include "globalDefinitions.h"

float period;
float frequency;
float duty;

unsigned char state;
unsigned char m[16];
unsigned char n[16];

void alternate_LED(){
    if(LED){
        LED = _OFF;
    } else {
        LED = _ON;
    }
}

void update_LCD(){
    sprintf(m, "Freq: %4.1f Hz", frequency);
    sprintf(n, "Duty: %3.1f %%", duty);
    LCD_Clear();
    LCD_SetCursor(1,0);
    LCD_WriteString(m);
    LCD_SetCursor(2,0);
    LCD_WriteString(n);
}

void setup_variables(){
    frequency = FREQ;
    duty = DUTY;
    period = 1000000/FREQ;
    TMR3 = 0;
    state = 0;
    LED = _OFF;
    SIGNAL = _OFF;
    CCPR1 = 7130;
    CCPR2 = 11900;
    update_LCD();
    TMR3 = 0;
    T3CONbits.TMR3ON = _ON;
}

void interrupt isr(){
    if(CCP1IF){
        CCP1IF = 0;
        
        state = 0;
    }
    if(CCP2IF){
        CCP2IF = 0;
        state = 1;
        TMR3 = 0;
    }
}

void main(void) {
    // === SETUP ===
    configPIC();
    LCD_Init();
    setup_variables();

    // === LOOP ===
    while(1){
        //encendido 60%
        SIGNAL = state;
        // encendido 40%
    }
    return;
}