/*
 * File:   Mateus_Vermont_main.c
 * Author: XBUG
 *
 * Created on May 5, 2018, 8:04 PM
 */


#include <xc.h>

#include "config.h"
#include "globalDefinitions.h"

unsigned char ignite;
unsigned int value[9];
int qtr;
int qtr_max[8];
int qtr_min[8];
int qtr_thresh[8];

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
    ignite = 1;
    
    LED = _OFF;
           
    // setup PWMs
    M1F_TRIS = OUTPUT;
    M1B_TRIS = OUTPUT;
    M2F_TRIS = OUTPUT;
    M2B_TRIS = OUTPUT;
    
    OSCCON = 0x72;      // Oscillator at 8MHz
    CCP1CON = 0x0C;     // PWM mode and no decimal value for PWM 
    CCP2CON = 0x0C;
    PR2 = 124 ;         // Open @1kHz 
    CCPR1L = 110;        // 50% duty cycle Motorb 1
    CCPR1H = 0;
    CCPR2L = 110;        // 50% duty cycle Motorb 2
    CCPR2H = 0;
    
    T2CON = 0b00000011; // Pre scaler at 16;
    TMR2 = 0;           // Clear Timer 2
    TMR2ON = 1;         //timer ON for start counting
    
    TRISCbits.RC2 = 1;  // CCP1 as input - OFF            
    TRISCbits.RC1 = 1;  // CCP2 as input - OFF
    
    initADC();
}

void goBACK(){
    
    M1FWD = 1;
    M1BCK = 0;
    
    M2FWD = 1;
    M2BCK = 0;
    
    TRISCbits.RC2 = 0;  // CCP1 ON            
    TRISCbits.RC1 = 0;  // CCP2 ON
    
}

void goFWD(){
    
    M1FWD = 0;
    M1BCK = 1;
    
    M2FWD = 0;
    M2BCK = 1;
    
    TRISCbits.RC2 = 0;  // CCP1 ON            
    TRISCbits.RC1 = 0;  // CCP2 ON
}

void stop(){
    M1FWD = 1;
    M1BCK = 1;
    M2FWD = 1;
    M2BCK = 1;
}

void evade(){
    // sequence
}

void read_values(int s){
    for(int z = 0; z < s; z++){
        convertAtoD(z);
        while(ADCON0bits.GO);
        value[z] = (ADRESH<<8)+ADRESL;
    }
}
/*
void follow_line(){ 
    read_values(9);
    //SHARP
    if (value[8] > SHARP_C){
        evade();
    } else {
    //QTR
        for (int i=0; i > 8; i++){
            if(value[i] < qtr_thresh[i]){
                bit_clear(qtr, i);
            } else {
                bit_set(qtr, i);
            }
        }
        switch(qtr){
            case 0b10000000:
                CCPR1L = PR2 * 0.50;
                CCPR2L = PR2 * 0.9;
                break;
            case 0b11000000:
                CCPR1L = PR2 * 0.60;
                CCPR2L = PR2 * 0.9;
                break;
            case 0b01000000:
                CCPR1L = PR2 * 0.65;
                CCPR2L = PR2 * 0.9;
                break;
            case 0b01100000:
                CCPR1L = PR2 * 0.70;
                CCPR2L = PR2 * 0.9;
                break;
            case 0b00100000:
                CCPR1L = PR2 * 0.75;
                CCPR2L = PR2 * 0.9;
                break;
            case 0b00110000:
                CCPR1L = PR2 * 0.80;
                CCPR2L = PR2 * 0.9;
                break;
            case 0b00010000:
                CCPR1L = PR2 * 0.85;
                CCPR2L = PR2 * 0.9;
                break;
            case 0b00011000:
                CCPR1L = PR2 * 0.9;
                CCPR2L = PR2 * 0.9;
                break;
            case 0b00001000:
                CCPR1L = PR2 * 0.9;
                CCPR2L = PR2 * 0.85;
                break;
            case 0b00001100:
                CCPR1L = PR2 * 0.9;
                CCPR2L = PR2 * 0.80;
                break;
            case 0b00000100:
                CCPR1L = PR2 * 0.9;
                CCPR2L = PR2 * 0.75;
                break;
            case 0b00000110:
                CCPR1L = PR2 * 0.9;
                CCPR2L = PR2 * 0.70;
                break;
            case 0b00000010:
                CCPR1L = PR2 * 0.9;
                CCPR2L = PR2 * 0.65;
                break;
            case 0b00000011:
                CCPR1L = PR2 * 0.9;
                CCPR2L = PR2 * 0.60;
                break;
            case 0b00000001:
                CCPR1L = PR2 * 0.9;
                CCPR2L = PR2 * 0.50;
                break;
        }
    }
}
*/

void calibrate(){
    LED = _ON;
    for(int l = 0; l < 8; l++){
        qtr_max[l] = 0;
        qtr_min[l] = 1024;
    }
    for(int i = 0; i < 5000; i++){
        read_values(8);
        for(int j = 0; j < 8; j++){
            // Set Max values for each sensor
            if (value[j] > qtr_max[j]){
                qtr_max[j] = value[j];
            }
            
            // Set Min values for each sensor
            if (value[j] < qtr_min[j]){
                qtr_min[j] = value[j];
            }
        }
    }
    // Set Thresholds
    for(int k = 0; k < 8; k++){
        qtr_thresh[k] = (qtr_min[k] + qtr_max[k])/2;
    }
}

void follow_line(){
    read_values(9);
    if(value[0] > qtr_thresh[0]){
        CCPR1L = 1;
        CCPR2L = 62;
    } else if (value[7] > qtr_thresh[0]){
        CCPR1L = 62;
        CCPR2L = 1;
    } else {
        CCPR1L = 62;
        CCPR2L = 62;
    }
}

void main(void) {
    configPIC();   
    stop();
    warm_up();
    flicker();
    calibrate();
    flicker();
    goFWD();
    
    while(1){
//        if(ignite){
//            __delay_ms(100);
//            goFWD();
//            __delay_ms(500);
//            stop();
//            __delay_ms(500);
//            goBACK();
//            __delay_ms(500);
//            stop();
//            ignite = 0;
//        } else {
//            stop();
//        }
        
        follow_line();
    }
    return;
}