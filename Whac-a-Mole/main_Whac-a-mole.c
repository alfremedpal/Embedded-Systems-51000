/*
 * File:   main_Whac-a-mole.c
 * Author: XBUG
 *
 * Created on February 20, 2018, 4:38 PM
 */


#include <xc.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "config.h"
#include "LCD.h"
#include "globalDefinitions.h"


unsigned int credits;
unsigned int tokens;
unsigned int level;

unsigned int green_token;
unsigned int red_token;
unsigned int yellow_token;
unsigned int blue_token;

unsigned int mole_duration;
unsigned int mole_amount;
unsigned int moles;

char m[16];
char n[16];

time_t toc;
int randrange;
int score;

unsigned int TEST;

unsigned int random_number(){
    unsigned int number = 0;
    number = rand()%3 + 1;
    return rand;
}

void print_score(){
    sprintf(m, "Level: %d", level);
    sprintf(n, "Puntaje: %d", score);
    
    LCD_SetCursor(1,0);
    LCD_WriteString(m);
    LCD_SetCursor(2,0);
    LCD_WriteString(n);
}

void interrupt isr(){
    if(INT0IF){
        INT0IF = 0;
        LED_GREEN = _OFF;
        /*
        if(LED_GREEN && green_token && (tokens > 0)){
            green_token = 0;
            tokens--;
            LED_GREEN = _OFF;
            score = score + 10;
        } else if(green_token) {
            green_token = 0;
            score = score - 10;
        }
        print_score();
         */
        TEST = 1;
    }
    
    if(INT1IF){
        INT1IF = 0;
        LED_RED = _OFF;
        TEST = 2;
    }
    
    if(INT2IF){
        INT2IF = 0;
        LED_YELLOW = _OFF;
        TEST = 3;
    }
    
    if(RBIF){
        RBIF = 0;
        LED_BLUE = _OFF;
        TEST = 4;
    }
    
    //if(STARTIF){
        //STARTIF = 0;
        //start = 1;
}

void init_whacamole(){
    credits = 0;
    score = 0;
    tokens = 0;
    green_token = 0;
    red_token = 0;
    yellow_token = 0;
    blue_token = 0;
}

void mole_on(unsigned int topo){
    switch(topo){
        case 1:
            LED_GREEN = _ON;
            break;
        case 2:
            LED_RED = _ON;
            break;
        case 3:
            LED_YELLOW = _ON;
            break;
        case 4:
            LED_BLUE = _ON;
            break;
    }
}

void mole_off(unsigned int topo){
    switch(topo){
        case 1:
            LED_GREEN = _OFF;
            break;
        case 2:
            LED_RED = _OFF;
            break;
        case 3:
            LED_YELLOW = _OFF;
            break;
        case 4:
            LED_BLUE = _OFF;
            break;
    }
}

void spawn_moles(){
    LED_GREEN = _ON;
    LED_RED = _ON;
    LED_YELLOW = _ON;
    LED_BLUE = _ON;
}

void kill_moles(){
    LED_GREEN = _OFF;
    LED_RED = _OFF;
    LED_YELLOW = _OFF;
    LED_BLUE = _OFF;
}

void spawn_tokens(){
    green_token = 1;
    red_token = 1;
    yellow_token = 1;
    blue_token = 1;
}

void start_level(){
    unsigned int R1;
    unsigned int R2;
    for(int j = 1; 1 != mole_amount; j++){
        tokens = moles;
        spawn_tokens();
        //generate random number R;
        if(moles == 1){
            R1 = 1;
            mole_on(R1);
            wait_ms(mole_duration);
            mole_off(R1);
        }
        if(moles == 2){
            R1 = 1;
            R2 = 2;
            mole_on(R1);
            mole_on(R2);
            wait_ms(mole_duration);
            mole_off(R1);
            mole_off(R2);
        }
        if(moles == 3){
            R1 = 3;
            switch(R1){
                case 1:
                    mole_on(2);
                    mole_on(3);
                    mole_on(4);
                    break;
                case 2:
                    mole_on(1);
                    mole_on(3);
                    mole_on(4);
                    break;
                case 3:
                    mole_on(1);
                    mole_on(2);
                    mole_on(4);
                    break;
                case 4:
                    mole_on(1);
                    mole_on(2);
                    mole_on(3);
                    break;
            }
        }
    }
}

void play_level(){
    switch(level){
        case 1:
            mole_duration = 800;
            mole_amount = 7;
            moles = 1;
            break;
        case 2:
            mole_duration = 700;
            mole_amount = 8;
            moles = 1;
            break;
        case 3:
            mole_duration = 600;
            mole_amount = 10;
            moles = 1;
            break;
        case 4:
            mole_duration = 500;
            mole_amount = 12;
            moles = 1;
            break;
        case 5:
            mole_duration = 700;
            mole_amount = 8;
            moles = 2;
            break;
        case 6:
            mole_duration = 600;
            mole_amount = 10;
            moles = 2;
            break;
        case 7:
            mole_duration = 500;
            mole_amount = 12;
            moles = 2;
            break;
        case 8:
            mole_duration = 600;
            mole_amount = 10;
            moles = 3;
            break;
    }    
    start_level();
}

void game_start(){
    for(level = 1; level < 9; level++){
        play_level(level);
    }
}

void attract(){
    // quick fancy stuff
}

void testing(){
    kill_moles();
    if(TEST == 1){
        LED_GREEN = _ON;
        sprintf(m, "GREEN  ");
    }
    if(TEST == 2){
        LED_RED = _ON;
        sprintf(m, "RED    ");
    }
    if(TEST == 3){
        LED_YELLOW = _ON;
        sprintf(m, "YELLOW ");
    }
    if(TEST == 4){
        LED_BLUE = _ON;
        sprintf(m, "BLUE   ");
    }
}

void main(void) {
    
    configPIC();
    LCD_Init();
    LCD_Clear();
    init_whacamole();
    kill_moles();

    while(1){
        /*
        if((credits > 0) && START){
            credits--;
            game_start();
        }
        attract();
         */
        LCD_SetCursor(1,0);
        LCD_WriteString("TESTING");
        testing();
        LCD_SetCursor(2,0);
        LCD_WriteString(m); 
    }
    return;
}