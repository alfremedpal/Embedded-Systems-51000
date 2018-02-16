#ifndef CONFIG_H
#define	CONFIG_H


#include <xc.h> // include processor files - each processor file is guarded.
#include"globalDefinitions.h"

void initADC();
void wait_ms(unsigned int);
float convertAD(unsigned int);
void configPIC();

#endif	

