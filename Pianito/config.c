#include "config.h"
#include "globalDefinitions.h"

void openPWM1(unsigned int period)
{
    PR2 = period;        /* load period value */
    TMR2 = 0;               // Clear Timer 2
    TMR2ON = 1;             //timer ON for start counting
    
    // PR2 = [Fosc/(Fpwm*4*TMR2pre)] -1
    // NOTE: If the PR2 value exceeds 255, we need to increase the TMR2 prescaler value
}

    
    
void PWM1_setDC(unsigned int dutycycle)
{
    
    CCPR1L = dutycycle;           
    
    // NOTE: CCPR1L must always be equal or less tan PR2; 
}


void configPIC()
{
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
    
    ADCON1 = 0b00001111;    //All ports set to digital I/O
                            
   // INPUTS and OUTPUTS
    
    TRISB_C = INPUT;
    TRISB_Cs = INPUT;
    TRISB_D = INPUT;
    TRISB_Ds = INPUT;
    TRISB_E = INPUT;
    TRISB_F = INPUT;
    TRISB_Fs = INPUT;
    TRISB_G = INPUT;
    TRISB_Gs = INPUT;
    TRISB_A = INPUT;
    TRISB_As = INPUT;
    TRISB_B = INPUT;
    
   // Interrupts
    
    INTCONbits.GIE = 0;         // Turn OFF ALL interrupts
    INTCONbits.PEIE_GIEL = 1;   // Turn on peripheral interrupts
    
    INTCONbits.INT0IE = 1;      // Enables interrupts from INT0
    INTCONbits.INT0IF = 0;      // INT0 flag is off
    INTCON3bits.INT1IE = 1;     // Enables interrupts from INT1
    INTCON3bits.INT1IF = 0;     // INT1 flag is off
    INTCON3bits.INT2IE = 0;     // Disables interrupts from INT2
    INTCON3bits.INT2IF = 0;     // INT1 flag is off
    
    INTCON2bits.INTEDG0 = 1;    // Low to high for INT0
    INTCON2bits.INTEDG1 = 0;    // High to low for INT1
    INTCON2bits.INTEDG2 = 0;    // High to low for INT2
    
    OSCCON = 0x72;         /* set internal clock to 8MHz */
    TRISC2 = 0;            /* Set CCP1 pin as output for PWM out */
    CCP1CON = 0x0C;        /* set PWM mode and no decimal value for PWM */                 
    T2CON = 0b00000001;     // Pre scaler at 4;
   
    //CONFIGURATION BITS
    
    // CONFIG1L
    #pragma config PLLDIV = 1           // PLL Prescaler Selection bits (No prescale (4 MHz oscillator input drives PLL directly))
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
