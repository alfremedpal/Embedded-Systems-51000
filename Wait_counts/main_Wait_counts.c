/*
 * File:   main_Wait_counts.c
 * Author: Alfredo Medina
 *
 * Created on 31 de enero de 2018, 11:08 AM
 */


#include <xc.h>
#include "config.h"

void main(void) {
    
    configPIC();
    
    while(1)
    {
        LED = _ON;
        wait_counts(30, 0);
        LED = _OFF;
        wait_counts(30, 0);
    }
}
