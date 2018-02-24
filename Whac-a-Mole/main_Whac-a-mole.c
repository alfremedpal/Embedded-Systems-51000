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
unsigned int seed;

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
    LCD_Clear();
    sprintf(m, "Level: %d", level);
    sprintf(n, "Puntaje: %d", score);
    
    LCD_SetCursor(1,0);
    LCD_WriteString(m);
    LCD_SetCursor(2,0);
    LCD_WriteString(n);
}

void check_buzzer(){
    if(!LED_GREEN && !LED_RED && !LED_YELLOW && !LED_BLUE){
        BUZZER = _OFF;
    }
}

void interrupt isr(){
    if(INT0IF){
        INT0IF = 0;
        if((tokens > 0) && green_token){
            tokens--;
            green_token = 0;
            if(LED_GREEN){
                LED_GREEN = _OFF;
                score = score + 10;
            } else if (!LED_GREEN){
                score = score -10;
            }
        }
    }
    
    if(INT1IF){
        INT1IF = 0;
        if((tokens > 0) && red_token){
            tokens--;
            red_token = 0;
            if(LED_RED){
                LED_RED = _OFF;
                score = score + 10;
            } else if (!LED_RED){
                score = score -10;
            }
        }
    }
    
    if(INT2IF){
        INT2IF = 0;
        if((tokens > 0) && yellow_token){
            tokens--;
            yellow_token = 0;
            if(LED_YELLOW){
                LED_YELLOW = _OFF;
                score = score + 10;
            } else if (!LED_YELLOW){
                score = score -10;
            }
        }
    }
    
    if(RBIF){
        RBIF = 0;
        if((tokens > 0) && blue_token){
            tokens--;
            blue_token = 0;
            if(LED_BLUE){
                LED_BLUE = _OFF;
                score = score + 10;
            } else if (!LED_BLUE){
                score = score -10;
            }
        }
    }
    check_buzzer();
    
}

void init_whacamole(){
    credits = 0;
    score = 0;
    tokens = 0;
    green_token = 0;
    red_token = 0;
    yellow_token = 0;
    blue_token = 0;
    BUZZER = _OFF;
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
    score = score - (tokens * 10);
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
    for(int j = 0; j != mole_amount; j++){
        tokens = moles;
        spawn_tokens();
        R1 = rand()%4 + 1;
        R2 = rand()%4 + 1;
        BUZZER = _ON;
        while(R2 == R1){
            R2 = rand()%4 +1;
        }
        
        if(moles == 1){
            mole_on(R1);
        }
        if(moles == 2){
            mole_on(R1);
            mole_on(R2);
            
        }
        if(moles == 3){
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
        wait_ms(mole_duration);
        BUZZER = _OFF;
        kill_moles();
        print_score();
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
    if(level != 9){
        wait_ms(1000);
    }
}

void game_start(){
    for(level = 1; level < 9; level++){
        play_level();
        start_level();
    }
}

void attract(){
    if(seed < 1000){
        seed++;
    } else if (seed == 1000){
        seed = 0;
    }
    if(seed < 250){
       LED_GREEN = _ON; 
    } else if ((seed > 250) && (seed < 500)){
        LED_RED = _ON;
    } else if ((seed > 500) && (seed < 750)){
        LED_YELLOW = _ON;
    } else if (seed > 750){
        LED_BLUE = _ON;
    }
    wait_ms(1);
    kill_moles();
}

void prepare(){
    kill_moles();
    srand(seed);
    score = 0;
    level = 1;
    LCD_Clear();
    LCD_SetCursor(1,0);
        LCD_WriteString("STARTING IN");
        LCD_SetCursor(2,0);
        LCD_WriteString("5");
        wait_ms(1000);
        LCD_SetCursor(1,0);
        LCD_WriteString("STARTING IN");
        LCD_SetCursor(2,0);
        LCD_WriteString("4");
        wait_ms(1000);
        LCD_SetCursor(1,0);
        LCD_WriteString("STARTING IN");
        LCD_SetCursor(2,0);
        LCD_WriteString("3");
        wait_ms(1000);
        LCD_SetCursor(1,0);
        LCD_WriteString("STARTING IN");
        LCD_SetCursor(2,0);
        LCD_WriteString("2");
        wait_ms(1000);
        LCD_SetCursor(1,0);
        LCD_WriteString("STARTING IN");
        LCD_SetCursor(2,0);
        LCD_WriteString("1");
        wait_ms(1000);
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

void intro(){
    LCD_Clear();
    LCD_SetCursor(1,0);
    LCD_WriteString("PRESS THE");
    LCD_SetCursor(2,0);
    LCD_WriteString("START BUTTON");
}

void game_over(){
    sprintf(m, "SCORE: %d", score);
    LCD_Clear();
    LCD_SetCursor(1,0);
    LCD_WriteString(m);
    LCD_SetCursor(2,0);
    LCD_WriteString("PRESS START");
}

void main(void) {
    
    configPIC();
    LCD_Init();
    LCD_Clear();
    init_whacamole();
    kill_moles();

    while(1){
        intro();
        while(!START){
            attract();
        }
        prepare();
        print_score();
        game_start();
        game_over();
        while(!START);
        wait_ms(100);
    }
    return;
}