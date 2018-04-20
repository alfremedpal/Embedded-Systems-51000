/*
 * File:   PWM_main.c
 * Author: XBUG
 *
 * Created on 18 de abril de 2018, 06:28 PM
 */

#include <xc.h>

#include "globalDefinitions.h"
#include "config.h"

unsigned char keyboard(){
    if(B_A || B_As || B_B || B_C || B_Cs || B_D || B_Ds || B_E || B_F || B_Fs || B_G || B_Gs){
        return 1;
    } else {
        return 0;
    }
}

int get_note(){
    if(B_C){
        return 3;
    } else if(B_Cs){
        return 4;
    } else if(B_D){
        return 5;
    } else if(B_Ds){
        return 6;
    } else if(B_E){
        return 7;
    } else if(B_F){
        return 8;
    } else if(B_Fs){
        return 9;
    } else if(B_G){
        return 10;
    } else if(B_Gs){
        return 11;
    } else if(B_A){
        return 0;
    } else if(B_As){
        return 1;
    } else if(B_B){
        return 2;
    } else {
        return -1;
    }
}

void play_note(int note){
    switch(note){
        case 0:
            openPWM1(8000000/(N7_A * 16));
            break;
        case 1:
            openPWM1(8000000/(N7_As * 16));
            break;
        case 2:
            openPWM1(8000000/(N7_B * 16));
            break;
        case 3:
            openPWM1(8000000/(N7_C * 16));
            break;
        case 4:
            openPWM1(8000000/(N7_Cs * 16));
            break;
        case 5:
            openPWM1(8000000/(N7_D * 16));
            break;
        case 6:
            openPWM1(8000000/(N7_Ds * 16));
            break;
        case 7:
            openPWM1(8000000/(N7_E * 16));
            break;
        case 8:
            openPWM1(8000000/(N7_F * 16));
            break;
        case 9:
            openPWM1(8000000/(N7_Fs * 16));
            break;
        case 10:
            openPWM1(8000000/(N7_G * 16));
            break;
        case 11:
            openPWM1(8000000/(N7_Gs * 16));
            break;
    }
    if(note >= 0){
        PWM1_setDC(PR2/2);
    }
    while(!keyboard);
}

void main(void) {
    
    configPIC();
    
//    while(1){
//        TMR2ON = _OFF;
//        while(keyboard);
//        play_note(get_note);
//        
//    }
//    
    openPWM1(0);
    PWM1_setDC(0);
    
    while(1)
    {
        PR2 = 0;
        TMR2 = 0;
        TMR2ON = 0;
        PWM1_setDC(0);
        PORTCbits.RC2 = 0;
        
        while(B_C || CCP1)
        {
            //PR2 = 8000000/(N7_C * 16);
            PR2 = 238;
            PWM1_setDC(PR2/2);
            TMR2ON = 1;
        }
        while(B_Cs || CCP1)
        {
            //PR2 = 8000000/(N7_Cs * 16);
            PR2 = 225;
            PWM1_setDC(PR2/2);
            TMR2ON = 1;
        }
        while(B_D || CCP1)
        {
            //PR2 = 8000000/(N7_D * 16);
            PR2 = 211;
            PWM1_setDC(PR2/2);
            TMR2ON = 1;
        }
        while(B_Ds || CCP1)
        {
            //PR2 = 8000000/(N7_Ds * 16);
            PR2 = 200;
            PWM1_setDC(PR2/2);
            TMR2ON = 1;
        }
        while(B_E || CCP1)
        {
            //PR2 = 8000000/(N7_E * 16);
            PR2 = 189;
            PWM1_setDC(PR2/2);
            TMR2ON = 1;
        }
        while(B_F || CCP1)
        {
            //PR2 = 8000000/(N7_F * 16);
            PR2 = 178;
            PWM1_setDC(PR2/2);
            TMR2ON = 1;
        }
        while(B_Fs || CCP1)
        {
            //PR2 = 8000000/(N7_Fs * 16);
            PR2 = 168;
            PWM1_setDC(PR2/2);
            TMR2ON = 1;
        }
        while(B_G || CCP1)
        {
            //PR2 = 8000000/(N7_G * 16);
            PR2 = 158;
            PWM1_setDC(PR2/2);
            TMR2ON = 1;
        }
        while(B_Gs || CCP1)
        {
            //PR2 = 8000000/(N7_Gs * 16);
            PR2 = 150;
            PWM1_setDC(PR2/2);
            TMR2ON = 1;
        }
        while(B_A || CCP1)
        {
            //PR2 = 8000000/(N7_A * 16);
            PR2 = 141;
            PWM1_setDC(PR2/2);
            TMR2ON = 1;
        }
        while(B_As || CCP1)
        {
            //PR2 = 8000000/(N7_As * 16)
            PR2 = 133;
            PWM1_setDC(PR2/2);
            TMR2ON = 1;
        }
        while(B_B || CCP1)
        {
            //PR2 = 8000000/(N7_B * 16);
            PR2 = 125;
            PWM1_setDC(PR2/2);
            TMR2ON = 1;
        }
        
    }
    
    
    
}