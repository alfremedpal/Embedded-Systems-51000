#ifndef CONFIG_H
#define	CONFIG_H


#include <xc.h>
#include"globalDefinitions.h"

void initUSART(long);
char transmitUSART(char);
char recieveUSART();
void configPIC();
void openPWM1(unsigned int);
void PWM1_setDC(unsigned int);
void initADC();
void convertAtoD(unsigned int);

#endif	
