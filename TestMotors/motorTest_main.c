/*
 * File:   motorTest_main.c
 * Author: Alfredo
 *
 * Created on 4 de mayo de 2018, 10:37 PM
 */


#include <xc.h>
#include "config.h"
#include "globalDefinitions.h"

void main(void) {
    
    configPIC();
    initCAR();
    
    while(1){
        PORTDbits.RD1 = 1;
    }
    
}
