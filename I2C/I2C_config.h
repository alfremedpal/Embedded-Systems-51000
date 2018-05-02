#ifndef I2C_CONFIG_H
#define	I2C_CONFIG_H

#include <xc.h>
#include"globalDefinitions.h"

void initI2C();
void I2Cidle();
void I2Cstart();
void I2Cstop();
void I2Cwrite(unsigned char);
void ack();
void not_ack();
unsigned char I2Cread(char);
void IC2WriteDevice(unsigned char, unsigned char, unsigned char*, unsigned char);
void I2CreadDevice(unsigned char, unsigned char, unsigned char*, unsigned char);



#endif	

