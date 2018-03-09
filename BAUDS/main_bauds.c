/*
 * File:   serial_main.c
 * Author: XBUG
 *
 * Created on 28 de febrero de 2018, 06:58 PM
 */


#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"
#include "globalDefinitions.h"




void main(void) {
    
    configPIC();
    initUSART(9600);
    wait_ms(50);
    
    LED = _OFF;
    
    
    char sending[SIZE]; 
    char data[SIZE];
    
    char onarray[SIZE];
    char offarray[SIZE];
    
    sprintf(onarray, "ON");
    sprintf(offarray, "OFF");
    
    char test;
    
    while(1)
    {
        for(int i = 0; i < SIZE; i++){
            data[i] = NULL;
        }
        
        if(PUSH_ON || PUSH_OFF)
        {
            if(PUSH_ON){
                sprintf(sending, "ON");
                // USART_TXS("ON");
                
                /*
                transmitUSART('a');
                wait_ms(5);
                test = recieveUSART();
                 */
            }
            if(PUSH_OFF){
                sprintf(sending, "OFF");
                /*
                transmitUSART('b');
                wait_ms(5);
                test = recieveUSART();
                 */
            }
            
            for(int i = 0; i < SIZE; i++){
                transmitUSART(sending[i]);
                wait_ms(5);
                data[i] = recieveUSART();
            }
            
        }
        
        if(!strcmp(data, onarray)){
            LED = _ON;
        } else if (!strcmp(data, offarray)){
            LED = _OFF;
        }
    }
}