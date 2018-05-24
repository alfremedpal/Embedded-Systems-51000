/*
 * File:   Safe_main.c
 * Author: liter
 *
 * Created on May 23, 2018, 9:16 PM
 */


#include <xc.h>

#include "config.h"
#include "OLED_config.h"
#include "globalDefinitions.h"

char lock;
char defined;
char count;

char pswd_1;
char pswd_2;
char pswd_3;


char in_1;
char in_2;
char in_3;

void alternate_LED(){
    if(SAFE){
        SAFE = _OFF;
    } else {
        SAFE = _ON;
    }
}

void beep(){
    BUZZER = _ON;
    __delay_ms(300);
    BUZZER = _OFF;
}

char read_keypad(){
    ROW_1 = _OFF;
    ROW_2 = _OFF;
    ROW_3 = _OFF;
    ROW_4 = _OFF;
    
    // === ROW 1 ===
    ROW_1 = _ON;
    if(COL_1){
        return 1;
    } else if (COL_2){
        return 2;
    } else if (COL_3){
        return 3;
    }
    ROW_1 = _OFF;
    
    // === ROW 2 ===
    ROW_2 = _ON;
    if(COL_1){
        return 4;
    } else if (COL_2){
        return 5;
    } else if (COL_3){
        return 6;
    }
    ROW_2 = _OFF;
    
    // === ROW 3 ===
    ROW_3 = _ON;
    if(COL_1){
        return 7;
    } else if (COL_2){
        return 8;
    } else if (COL_3){
        return 9;
    }
    ROW_3 = _OFF;
    
    // === ROW 4 ===
    ROW_4 = _ON;
    if(COL_1){
        return _RESET; // * es Reset
    } else if (COL_2){
        return 0;
    } else if (COL_3){
        return _LOCK; // # es Clear
    } else if (COL_4){
        return _KEY;
    }
    ROW_4 = _OFF;
    
    return 10;
}

void set_password(){
    defined = FALSE;
    count = 0;
    pswd_1 = 10;
    pswd_2 = 10;
    pswd_3 = 10;
    in_1 = 10;
    in_2 = 10;
    in_3 = 10;
    
    while(pswd_1 == 10){
        pswd_1 = read_keypad();
        if((pswd_1 == _RESET) || (pswd_1 == _LOCK) || (pswd_1 == _KEY)){
            pswd_1 = 10;
        }
    }
    // print "1"
    beep();
    
    while(pswd_2 == 10){
        pswd_2 = read_keypad();
        if((pswd_2 == _RESET) || (pswd_2 == _LOCK) || (pswd_2 == _KEY)){
            pswd_2 = 10;
        }
    }
    // print "2"
    beep();
    
    while(pswd_3 == 10){
        pswd_3 = read_keypad();
        if((pswd_3 == _RESET) || (pswd_3 == _LOCK) || (pswd_3 == _KEY)){
            pswd_3 = 10;
        }
    }
    // print "3"
    beep();
    
    defined = TRUE;
    __delay_ms(2000);
    // OLED_CLEAR();
}

void check_input(){
    in_1 = 10;
    in_2 = 10;
    in_3 = 10;
    while(in_1 == 10){
        in_1 = read_keypad();
        if((in_1 == _RESET) || (in_1 == _LOCK) || (in_1 == _KEY)){
            in_1 = 10;
        }
    }
    // print "1"
    beep();
    
    while(in_2 == 10){
        in_2 = read_keypad();
        if((in_2 == _RESET) || (in_2 == _LOCK) || (in_2 == _KEY)){
            in_2 = 10;
        }
    }
    // print "2"
    beep();
    
    while(in_3 == 10){
        in_3 = read_keypad();
        if((in_3 == _RESET) || (in_3 == _LOCK) || (in_3 == _KEY)){
            in_3 = 10;
        }
    }
    // print "3"
    beep();
    
    if ((in_1 == pswd_1) && (in_2 == pswd_2) && (in_3 == pswd_3)){
        count = 0;
        SAFE = FALSE;
        // print "200"
        __delay_ms(2000);
        // OLED_CLEAR();)
    } else {
        count++;
        // print "404"
        __delay_ms(2000);
        // OLED_CLEAR();)
        if (count > 2){
            in_1 = 10;
            while(in_1 == 10){
                in_1 = read_keypad();
                if (in_1 != _KEY){
                    in_1 = 10;
                }
            }
            set_password();
        }
    }
}

void rest(){
    in_1 = 10;
    while(in_1 == 10){
        in_1 = read_keypad();
        if (!(in_1 == _RESET) && !(in_1 == _LOCK)){
            in_1 = 10;
        }
    }
    if (in_1 == _RESET){
        set_password();
    } else if (in_1 == _LOCK){
        SAFE = TRUE;
    }
}

void setup(){
    //set CCP as
    configPIC();
    
    OpenI2C();
    initOLED();
    
    SAFE = TRUE;
    BUZZER = _OFF;
    set_password();
    
}

void main(void) {
    setup();
    while(TRUE){
//        in_1 = 10;
//        while(in_1 == 10){
//            in_1 = read_keypad();
//            if(in_1 != 5){
//                in_1 = 10;
//            }
//        }
//        beep();
//        alternate_LED();
//        __delay_ms(300);
        
        while(SAFE){
            check_input();
        }
        while(!SAFE){
            rest();
        }        
    }
    return;
}
