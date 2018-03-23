#ifndef CONFIG_H
#define	CONFIG_H

#include <xc.h> // include processor files - each processor file is guarded.  

void configPIC(void);
void wait_ms(unsigned int);
void convertAtoD(unsigned int);

void beep_on();
void beep_off();


#endif	/* CONFIG_H */