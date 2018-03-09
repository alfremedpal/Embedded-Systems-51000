#include "config.h"
#include "globalDefinitions.h"


void initUSART(long baudRate)
{
    float temp;
    
    TRISCbits.RC6 = OUTPUT;
    TRISCbits.RC7 = INPUT;
    
     /* Baud rate = 9600, SPBRG = (F_CPU /(64*9600))-1*/
    temp= (( (float) (F_CPU) / (float) baudRate ) - 1);     
    SPBRG = (int) temp;	
    
    TXSTA=0x20;                     
    RCSTA=0x90;  

}

char transmitUSART(char out)
{
   while (TXIF == 0);	/* Wait for transmit interrupt flag*/
   TXREG = out;         /* Write char data to transmit register */   
}

//void USART_TXS(const char *s){
//    while(*s){
//        transmitUSART(*s);
//        s++;
//    }
//}

char recieveUSART()
{
    while(RCIF == 0); /*wait for receive interrupt flag*/
    if(RCSTAbits.OERR)
    {           
        CREN = 0;
        NOP();
        CREN=1;
    }
    return(RCREG);  /*received in RCREG register and return to main program */
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
    
    
    T0CON = 0b01000001;     // TIMER 0
                            // Timer 0 disabled; configured as 8-bit counter;
                            // T0CKI pin; increment on low to high;
                            // pre-scaler is NOT assigned; pre-scaler is 1:4
    
    
     
    ADCON0 = 0b00000000;    //Left-MSB; Right-LSB
                            //ADC module is off
    
    ADCON1 = 0b00001111;    //All ports set to digital I/O
    

                            
   // INPUTS and OUTPUTS
    
    
    LED_TRIS = OUTPUT;
    TRIS_PUSH_ON = INPUT;
    TRIS_PUSH_OFF = INPUT;
    
    
   // Interrupts
    
    INTCONbits.GIE = 1;         // Turn on ALL interrupts
    INTCONbits.PEIE_GIEL = 1;   // Turn on peripheral interrupts
    
    INTCONbits.INT0IE = 1;      // Enables interrupts from INT0
    INTCONbits.INT0IF = 0;      // INT0 flag is off
    INTCON3bits.INT1IE = 1;     // Enables interrupts from INT1
    INTCON3bits.INT1IF = 0;     // INT1 flag is off
    INTCON3bits.INT2IE = 0;     // Disables interrupts from INT2
    INTCON3bits.INT2IF = 0;     // INT1 flag is off
    
    INTCON2bits.INTEDG0 = 1;    // Low to high for INT0
    INTCON2bits.INTEDG1 = 0;   // High to low for INT1
    INTCON2bits.INTEDG2 = 0;    // High to low for INT2
    

    
   
    
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
