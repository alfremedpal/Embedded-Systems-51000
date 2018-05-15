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

int qtr[8];
int qtr_max[8];
int qtr_min[8];
int qtr_thresh[8];

int sharp;
double distance;

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
    PR2 = 200 ;         // Open @625 Hz 
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

void read_values(){
    for(int z = 0; z < 8; z++){
        convertAtoD(z);
        while(ADCON0bits.GO);
        qtr[z] = (ADRESH<<8)+ADRESL;
    }
    
    convertAtoD(8);
    while(ADCON0bits.GO);
    sharp = (ADRESH<<8)+ADRESL;
    //distance = 13/(sharp * 0.004853515);
}

void calibrate(){
    flicker();
    LED = _ON;
    for(int l = 0; l < 8; l++){
        qtr_max[l] = 0;
        qtr_min[l] = 1024;
    }
    for(int i = 0; i < 5000; i++){
        read_values(8);
        for(int j = 0; j < 8; j++){
            // Set Max values for each sensor
            if (qtr[j] > qtr_max[j]){
                qtr_max[j] = qtr[j];
            }
            
            // Set Min values for each sensor
            if (qtr[j] < qtr_min[j]){
                qtr_min[j] = qtr[j];
            }
        }
    }
    // Set Thresholds
    for(int k = 0; k < 8; k++){
        qtr_thresh[k] = (qtr_min[k] + qtr_max[k])/2;
    }
    flicker();
}

void set_duty(unsigned int m1, unsigned int m2){
    CCPR1L = (PR2 * m1) / 100;
    CCPR2L = (PR2 * m2) / 100;
}

void evade_right(){   
    // MOVE TO RIGHT
    set_duty(40,03);
    __delay_ms(1500);
    set_duty(03,40);
    __delay_ms(800);
    set_duty(35,35);
    __delay_ms(800);
    set_duty(03,40);
    __delay_ms(500);
    set_duty(35,35);
}

void evade_left(){
    set_duty(10,45);
    __delay_ms(1000);
    set_duty(45,10);
}

void follow_line(){
//    === HOME ===
//    if(qtr[0] > qtr_thresh[0]){           // 1000 0000
//        set_duty(05,45);
//    } else if (qtr[1] > qtr_thresh[1]){   // X100 0000
//        set_duty(10,45);
//    } else if (qtr[2] > qtr_thresh[2]){   // XX10 0000
//        set_duty(15,45);
//    } else if ((qtr[3] > qtr_thresh[3]) && (qtr[4] < qtr_thresh[4])){   // XXX1 0000
//        set_duty(20,45);
//    } else if (qtr[7] > qtr_thresh[7]){   // 0000 0001
//        set_duty(45,05);
//    } else if (qtr[6] > qtr_thresh[6]){   // 0000 001X
//        set_duty(45, 10);
//    } else if (qtr[5] > qtr_thresh[5]){   // 0000 01XX
//        set_duty(45, 15);
//    } else if (qtr[4] > qtr_thresh[4] && (qtr[3] < qtr_thresh[3])){   // 0000 1XXX
//        set_duty(45, 20);
//    } else {
//        set_duty(40,40);
//    }
    // === OVAL CIRCUIT ===
//    if(qtr[0] > qtr_thresh[0]){                                         // 1000 0000
//        set_duty(01,40);
//    } else if (qtr[1] > qtr_thresh[1]){                                 // X100 0000
//        set_duty(05,35);
//    } else if (qtr[2] > qtr_thresh[2]){                                 // XX10 0000
//        set_duty(10,35);
//    } else if ((qtr[3] > qtr_thresh[3]) && (qtr[4] < qtr_thresh[4])){   // XXX1 0000
//        set_duty(15,35);
//    } else if (qtr[7] > qtr_thresh[7]){                                 // 0000 0001
//        set_duty(40,01);
//    } else if (qtr[6] > qtr_thresh[6]){                                 // 0000 001X
//        set_duty(35, 05);
//    } else if (qtr[5] > qtr_thresh[5]){                                 // 0000 01XX
//        set_duty(35, 10);
//    } else if (qtr[4] > qtr_thresh[4] && (qtr[3] < qtr_thresh[3])){     // 0000 1XXX
//        set_duty(35, 15);
//    } else {                                                            // 0001 1000
//        set_duty(35,35);
//    }
    
    // === FINAL CIRCUIT ===
    if(qtr[0] > qtr_thresh[0]){                                         // 1000 0000
        set_duty(05,50);
    } else if (qtr[1] > qtr_thresh[1]){                                 // X100 0000
        set_duty(05,35);
    } else if (qtr[2] > qtr_thresh[2]){                                 // XX10 0000
        set_duty(10,35);
    } else if ((qtr[3] > qtr_thresh[3]) && (qtr[4] < qtr_thresh[4])){   // XXX1 0000
        set_duty(15,35);
    } else if (qtr[7] > qtr_thresh[7]){                                 // 0000 0001
        set_duty(50,05);
    } else if (qtr[6] > qtr_thresh[6]){                                 // 0000 001X
        set_duty(35,05);
    } else if (qtr[5] > qtr_thresh[5]){                                 // 0000 01XX
        set_duty(35,10);
    } else if (qtr[4] > qtr_thresh[4] && (qtr[3] < qtr_thresh[3])){     // 0000 1XXX
        set_duty(35,15);
    } else if((qtr[3] > qtr_thresh[3]) && (qtr[4] > qtr_thresh[4])){    // 0001 1000                                                            // 0001 1000
        set_duty(50,50);
    }
}

void main(void) {
    configPIC();   
    stop();
    warm_up();
    calibrate();
    goFWD();
    sharp = 0;
    while(1){
        read_values();
         follow_line();
        
        //     CAR ___d___ WALL ____ if d < 17, then i should evade, else i should follow the line
//        if(sharp > 200){
//            evade_right();
//        } else {
//            follow_line();
//        }
    }
    return;
}