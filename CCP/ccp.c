/*
 * File:   ccp.c
 * Author: XBUG
 * 
 *      Use the CCP module to analyze an input signal, and calculate
 *      the frequency and duty cycle of said signal (square signal)
 *
 * Created on March 20, 2018, 6:15 PM
 */


#include <xc.h>
#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "LCD.h"
#include "globalDefinitions.h"

unsigned int rising_1;
unsigned int rising_2;
unsigned int bajadita;
unsigned char lock;

float period;
float duty;
float freq;

unsigned char m[16];
unsigned char n[16];

unsigned char end;
unsigned char count;

void interrupt isr(){
    if (CCP1IF ){
        CCP1IF = 0;
        if(count > 3){
            if(end){
                rising_2 = CCPR1;
                T3CONbits.TMR3ON = _OFF;
            } else if (!end){
                rising_1 = 0;
                T3CONbits.TMR3ON = _ON;
            }
            count++;
        }
        
    }
    if(CCP2IF){
        CCP2IF = 0;
        if(count > 3){
            bajadita = CCPR2;
            count++;
        }
    }
}

void update_LCD(){
    LCD_Clear();
    sprintf(m, "Freq: %6.0f", freq);
    sprintf(n, "Duty: %2.2f", duty);
    
    LCD_SetCursor(1,0);
    LCD_WriteString(m);
    LCD_SetCursor(2,0);
    LCD_WriteString(n);
}

void ccp_init(){
    rising_1 = 0;
    rising_2 = 0;
    bajadita = 0;
    count = 0;
    end = 0;
    update_LCD();
}

void main(void) {
    
        //setup
    configPIC();
    LCD_Init();
    LCD_Clear();
    ccp_init();
    
    while(1){
        while(count != 3);
        period = (rising_2-rising_1) * CCP_CONST;
        freq = 1/period;
        duty = (bajadita - rising_1) * CCP_CONST;
        update_LCD();
        count = 0;
    }
    return;
}
