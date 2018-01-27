#include "config.h"

void wait_5seg() // Pre-scaler needs to be 1:256
{
    unsigned int count = 0;
    TMR0L = 131;
    T0IF = 0;
    TMR0ON = 1;
    while(count < 1875)
    {
        while(T0IF == 0);
        count++;
        T0IF = 0;
        TMR0L = 131;
    }
    TMR0ON = 0;
}

void wait_ms(unsigned int ms) // Pre-scaler needs to be 1:4 
{
    unsigned int countF = 0;
    while(countF < ms)
    {
        unsigned int count = 0;
        TMR0L = 131;
        T0IF = 0;
        TMR0ON = 1;
        while(count < 24)
        {
            while(T0IF == 0);
            count++;
            T0IF = 0;
            TMR0L = 131;
        }
        TMR0ON = 0;
        countF++;
    }
    
}

void configPIC()
{
    //All analog pins need to be input
    //Output: 0; Input: 1
    
    TRISA = 0b00000000;     //Set all pins of port A as output
    TRISB = 0b00000000;     //Set all pins of port B as output
    TRISC = 0b00000000;     //Set all pins of port C as output
    TRISD = 0b00000000;     //Set all pins of port D as output
    TRISE = 0b00000000;     //Set all pins of part E as output
    
    INTCONbits.GIE = 0;     //Turn off ALL interrupts
    
    
    T0CON = 0b01000001;     // TIMER 0
                            // Timer 0 enabled; configured as 8-bit timer;
                            // internal clock; increment on low to high;
                            // pre-scaler is assigned; pre-scaler is 1:4
    
    
     
    ADCON0 = 0b00000000;    //Left-MSB; Right-LSB
                            //ADC module is off
    
    ADCON1 = 0b00001111;    //All ports set to digital I/O
    

                            
   
    LED_TRIS = OUTPUT;
   
    
    //CONFIGURATION BITS
    
// CONFIG1L
#pragma config PLLDIV = 1               // PLL Prescaler Selection bits (No prescale (4 MHz oscillator input drives PLL directly))
#pragma config CPUDIV = OSC1_PLL2       // System Clock Postscaler Selection bits ([Primary Oscillator Src: /1][96 MHz PLL Src: /2])

// CONFIG1H
#pragma config FOSC = HSPLL_HS          // Oscillator Selection bits (EC oscillator, CLKO function on RA6 (EC))
#pragma config FCMEN = OFF              // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)

// CONFIG2L
#pragma config BORV = 3                 // Brown-out Reset Voltage bits (Minimum setting 2.05V)

// CONFIG2H
#pragma config WDT = OFF                // Watchdog Timer Enable bit (WDT enabled)

// CONFIG3H
#pragma config MCLRE = ON               // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)

// CONFIG4L
#pragma config LVP = OFF                // Single-Supply ICSP Enable bit (Single-Supply ICSP enabled)
}

