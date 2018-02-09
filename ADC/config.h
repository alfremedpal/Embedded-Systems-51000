#ifndef CONFIG_H
#define	CONFIG_H


#include <xc.h> // include processor files - each processor file is guarded.
#include"globalDefinitions.h"

void initADC();
float convertAD(unsigned int);
void configPIC();

#endif	

