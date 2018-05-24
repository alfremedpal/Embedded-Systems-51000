#include <pic18f4550.h>
#include "globalDefinitions.h"

void initUSART(long baudRate){
    float temp;
    
    TRISCbits.RC6 = OUTPUT;
    TRISCbits.RC7 = INPUT;
    
     /* Baud rate = 38400, SPBRG = (F_CPU /(64*38400))-1*/
    temp= (( (float) (F_CPU) / (float) baudRate ) - 1);     
    SPBRG = (int) temp;	
    
    TXSTA=0x20;                     
    RCSTA=0x90;  
}

char transmitUSART(char out){
   while (TXIF == 0);	/* Wait for transmit interrupt flag*/
   TXREG = out;         /* Write char data to transmit register */   
}

char recieveUSART(){
    while(RCIF == 0); /*wait for receive interrupt flag*/
    if(RCSTAbits.OERR)
    {           
        CREN = 0;
        NOP();
        CREN=1;
    }
    return(RCREG);  /*received in RCREG register and return to main program */
}

void configPIC(){
    TRISA = 0b00000000;     //Set all pins of port A as output
    TRISB = 0b00000000;     //Set all pins of port B as output
    TRISC = 0b00000000;     //Set all pins of port C as output
    TRISD = 0b00000000;     //Set all pins of port D as output
    TRISE = 0b00000000;     //Set all pins of part E as output
    
    T0CON = 0b01000001;     // TIMER 0
                            // Timer 0 disabled; configured as 8-bit counter;
                            // T0CKI pin; increment on low to high;
                            // pre-scaler IS assigned; pre-scaler is 1:4
    
    ADCON0 = 0b00000000;    //Left-MSB; Right-LSB
                            //ADC module is off
    
    ADCON1 = 0b00001111;    //All ports set to analog I/O
                            
   // INPUTS and OUTPUTS
    TRIS_SAFE = OUTPUT;
    TRIS_BUZZER = OUTPUT;
    TRIS_ROW_1 = OUTPUT;
    TRIS_ROW_2 = OUTPUT;
    TRIS_ROW_3 = OUTPUT;
    TRIS_ROW_4 = OUTPUT;
    TRIS_COL_1 = INPUT;
    TRIS_COL_2 = INPUT;
    TRIS_COL_3 = INPUT;
    TRIS_COL_4 = INPUT;
    
   // Interrupts
    
    INTCONbits.GIE = 0;         // Turn OFF ALL interrupts
    INTCONbits.PEIE_GIEL = 1;   // Turn on peripheral interrupts
    
    OSCCON = 0x72;             /* set internal clock to 8MHz */
    TRISCbits.RC2;             /* Set CCP1 pin as output for PWM out */
    CCP1CON = 0x0C;            /* set PWM mode and no decimal value for PWM */                 
    T2CON = 0b00000001;        // Pre scaler at 4;
   
    //CONFIGURATION BITS
    
    // CONFIG1L
    #pragma config PLLDIV = 5           // PLL Prescaler Selection bits (No prescale (4 MHz oscillator input drives PLL directly))
    #pragma config CPUDIV = OSC1_PLL2   // System Clock Postscaler Selection bits ([Primary Oscillator Src: /1][96 MHz PLL Src: /2])

    // CONFIG1H
    #pragma config FOSC = HSPLL_HS      // Oscillator Selection bits (EC oscillator, CLKO function on RA6 (EC))
    #pragma config FCMEN = OFF          // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)

    // CONFIG2L
    #pragma config BORV = 3             // Brown-out Reset Voltage bits (Minimum setting 2.05V)

    // CONFIG2H
    #pragma config WDT = OFF            // Watchdog Timer Enable bit (WDT enabled)

    // CONFIG3H
    #pragma config MCLRE = ON           // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)

    // CONFIG4L
    #pragma config LVP = OFF            // Single-Supply ICSP Enable bit (Single-Supply ICSP enabled)
}