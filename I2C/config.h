#ifndef CONFIG_H
#define	CONFIG_H


#include <xc.h>
#include"globalDefinitions.h"

void configPIC();
void sendINITBits();
void sendONE();
void sendZERO();
void sendADDRESS();
void sendIR(char[]);

#endif	

