/*
 * File:   Carmelita_main.c
 * Author: XBUG
 *
 * Created on May 4, 2018, 11:32 PM
 */


#include <xc.h>

#include "config.h"
#include "globalDefinitions.h"

int command;

void alternate_LED(){
    if (LED){
        LED = _OFF;
    } else {
        LED = _ON;
    }
}

void flicker(){
    for(int i = 0; i < 5; i++){
        alternate_LED();
        __delay_ms(300);
    }
}

void warm_up(){ 
    LED_TRIS = OUTPUT;
    IR_TRIS = INPUT;
           
    // setup PWMs
    M1F_TRIS = OUTPUT;
    M1B_TRIS = OUTPUT;
    M2F_TRIS = OUTPUT;
    M2B_TRIS = OUTPUT;
    
    OSCCON = 0x72;      // Oscillator at 8MHz
    CCP1CON = 0x0C;     // PWM mode and no decimal value for PWM 
    CCP2CON = 0x0C;
    PR2 = 200 ;         // Open @625 Hz 
    CCPR1L = 100;        // 50% duty cycle Motorb 1
    CCPR1H = 0;
    CCPR2L = 100;        // 50% duty cycle Motorb 2
    CCPR2H = 0;
    
    T2CON = 0b00000011; // Pre scaler at 16;
    TMR2 = 0;           // Clear Timer 2
    TMR2ON = 1;         //timer ON for start counting
    
    M1 = INPUT;  // CCP1 as input - OFF            
    M2 = INPUT;  // CCP2 as input - OFF
    
    
    initADC();
    
    flicker();
}

void goBCK(){
    
    M1FWD = 1;
    M1BCK = 0;
    
    M2FWD = 1;
    M2BCK = 0;
    
    M1 = OUTPUT;  // CCP1 ON            
    M2 = OUTPUT;  // CCP2 ON
    
}

void goFWD(){
    
    M1FWD = 0;
    M1BCK = 1;
    
    M2FWD = 0;
    M2BCK = 1;
    
    M1 = OUTPUT;  // CCP1 ON            
    M2 = OUTPUT;  // CCP2 ON
}

void pivot_R(){
    M1FWD = 1;
    M1BCK = 0;
    
    M2FWD = 0;
    M2BCK = 1;
    
    M1 = OUTPUT;
    M2 = OUTPUT;
}

void pivot_L(){
    M1FWD = 0;
    M1BCK = 1;
    
    M2FWD = 1;
    M2BCK = 0;
    
    M1 = OUTPUT;
    M2 = OUTPUT;
}

void stop(){
    M1FWD = 0;
    M1BCK = 0;
    
    M2FWD = 0;
    M2BCK = 0;
}

void set_duty(unsigned int m1, unsigned int m2){
    CCPR1L = (PR2 * m1) / 100;
    CCPR2L = (PR2 * m2) / 100;
}

void park(){
    //park sequence
}

void execute(int command){
    switch(command){
        case FORWARD:
            command = STOP;
            goFWD();
            break;
        case REVERSE:
            command = STOP;
            goBCK();
            break;
        case LEFT:
            command = STOP;
            pivot_L();
            break;
        case RIGHT:
            command = STOP;
            pivot_R();
            break;
        case PARK:
            command = STOP;
            park();
            break;
    }
    while(PULSE);
    stop();
}

void interrupt isr(){
    if(INT0IF){
        INT0IF = 0;
        __delay_ms(10);
        if(PULSE){
            command = command + 0b100;
        }
        __delay_ms(10);
        if(PULSE){
            command = command + 0b010;
        }
        __delay_ms(10);
        if(PULSE){
            command = command + 0b001;
        }
        if(command = 0b000){
            stop();
        }
    }
}

void main(void) {
    configPIC(); 
    stop();
    warm_up();
    
    while(1){
        execute(command);
    }
    return;
}