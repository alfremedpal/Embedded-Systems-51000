#include "I2C_config.h"

void initI2C() {
    SSPSTAT &= 0x3F;            // power on state
    SSPCON1 = 0x00;             // power on state
    SSPCON2 = 0x00;             // power on state
    SSPCON1 |= 0b00001000;      // select serial mode
    SSPSTAT |= 0b10000000;      // slew rate on/off
    TRISBbits.RB0 = 1;          // SDA and SCL as input pin 
    TRISBbits.RB1 = 1;          // these pins can be configured either as i/p or o/p 
    SSPCON1 |= SSPENB;          // enable synchronous serial port
    SSPADD = 0x13;
}

void I2Cidle() {
    while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F)); 
}

void I2Cstart() {
    SEN = 1;        // start condition is enabled
    while(SEN);     // wait until the bit is cleared in hardware
    SSPIF = 0;
}

void I2Cstop() {
    PEN=1;          // stop enable bit  
    while(PEN);     // wait until stop condition is complete 
    SSPIF=0;
}

void I2Cwrite(unsigned char b) {
    SSPBUF = b;            /*moves the data to the buffer register */
    while(!SSPIF);       /*wait until transmission is complete */
    SSPIF = 0;
}

void ack()
{
    ACKDT=0;          /*cleared for acknowledgement */    
    ACKEN=1;          /*acknowledgment enable */           
    while(ACKEN);     /*wait until acknowledgement is complete*/ 
    SSPIF=0;
}

void not_ack()
{
    ACKDT=1;          /*set for non acknowledgement */    
    ACKEN=1;          /*acknowledgment enable */           
    while(ACKEN);     /*wait until acknowledgement is complete*/ 
    SSPIF=0;
}

unsigned char I2Cread(char ACK)
{
   while(!SSPIF); /*wait until reception is complete*/ 
   if (ACK)
      ack();      /*acknowledge the slave */
   else
      not_ack();  /*not-acknowledge the slave to stop further transmission*/
 return SSPBUF;   /*returns the received data*/
}

void IC2WriteDevice(unsigned char address, unsigned char reg, unsigned char* data, unsigned char length) {
    I2Cidle();
    I2Cstart();
    I2Cidle();
    
    I2Cwrite(address & 0xfe);
    
    I2Cidle();
    I2Cwrite(reg);
    
    I2Cidle();
    for(int i = 0; i < length; i++){
        I2Cwrite(data[i]);
        I2Cidle();
    }
    
    I2Cstop();
}

void I2CreadDevice(unsigned char address, unsigned char reg, unsigned char* data, unsigned char length){
    I2Cidle();
    I2Cstart();
    I2Cidle();
    
    I2Cwrite(address & 0xfe);
    I2Cidle();
    
    I2Cwrite(reg);
    I2Cidle();
    
    I2Cstart();
    I2Cidle();
    I2Cwrite(address | 0x01);
    I2Cidle();
    
    for(int i = 0; i < length; i++){
        data[i] = I2Cread(address);
        if(i != (length - 1))
            ack();
        else
            not_ack();
    }
    I2Cstop();
}