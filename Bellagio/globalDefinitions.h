#ifndef GLOBALDEFINITIONS_H
#define	GLOBALDEFINITIONS_H

// === PIC18F4550 ===
#define _XTAL_FREQ 8000000
#define F_CPU 8000000/64


// ===BASIC===
#define _ON 1
#define _OFF 0

#define OUTPUT 0
#define INPUT 1

#define TRUE 1
#define FALSE 0
//============

// === DEBUG ===

//#define GREEN       0
//#define RED         1
//#define YELLOW      2
//#define BLUE        3
//
//#define POT_1       PORTAbits.RA0
//#define POT_2       PORTAbits.RA1
//#define LED_BLUE    PORTAbits.RA2
//#define LED_YELLOW  PORTAbits.RA3
//#define LED_RED     PORTAbits.RA4
//#define LED_GREEN   PORTAbits.RA5
//#define BUZZER      PORTCbits.RC2
//#define BUTTON_1    PORTBbits.RB0
//#define BUTTON_2    PORTBbits.RB1
//#define BUTTON_3    PORTBbits.RB2
//#define BUTTON_4    PORTBbits.RB3
//#define RX          PORTCbits.RC7
//#define TX          PORTCbits.RC6
//
//#define TRIS_POT_1      TRISAbits.RA0
//#define TIS_POT_2       TRISAbits.RA1
//#define TRIS_LED_BLUE   TRISAbits.RA2
//#define TRIS_LED_YELLOW TRISAbits.RA3
//#define TRIS_LED_RED    TRISAbits.RA4
//#define TRIS_LED_GREEN  TRISAbits.RA5
//#define TRIS_BUZZER     TRISCbits.RC2
//#define TRIS_BUTTON_1   TRISBbits.RB0
//#define TRIS_BUTTON_2   TRISBbits.RB1
//#define TRIS_BUTTON_3   TRISBbits.RB2
//#define TRIS_BUTTON_4   TRISBbits.RB3
//#define TRIS_RX         TRISCbits.RC7
//#define TRIS_TX         TRISCbits.RC6

// === LCD ===
#define RS PORTEbits.RE1
#define EN PORTEbits.RE2
#define D0 PORTDbits.RD0
#define D1 PORTDbits.RD1
#define D2 PORTDbits.RD2
#define D3 PORTDbits.RD3
#define D4 PORTDbits.RD4
#define D5 PORTDbits.RD5
#define D6 PORTDbits.RD6
#define D7 PORTDbits.RD7

#define RS_TRIS TRISEbits.RE1
#define EN_TRIS TRISEbits.RE2
#define D0_TRIS TRISDbits.RD0
#define D1_TRIS TRISDbits.RD1
#define D2_TRIS TRISDbits.RD2
#define D3_TRIS TRISDbits.RD3
#define D4_TRIS TRISDbits.RD4
#define D5_TRIS TRISDbits.RD5
#define D6_TRIS TRISDbits.RD6
#define D7_TRIS TRISDbits.RD7

// ===UTILITY
#define bit_check(var, pos) ((var) & (1<<(pos)))    //bit_check(var, pos)
 
#define bit_set(var, pos) var |= (1 << pos)         //bit_set(var, pos)
 
#define bit_clear(var, pos) var &= (~(1 << pos))    //bit_clear(var, pos)
 
#define bit_toggle(var, pos) var ^= (1 << pos)      //bit_toggle(var, pos)

// ===PARTICULAR===
#define SAFE PORTDbits.RD3
#define BUZZER PORTDbits.RD1

#define ROW_1 PORTAbits.RA0
#define ROW_2 PORTAbits.RA1
#define ROW_3 PORTAbits.RA2
#define ROW_4 PORTAbits.RA3

#define COL_1 PORTAbits.RA4
#define COL_2 PORTAbits.RA5
#define COL_3 PORTEbits.RE0
#define COL_4 PORTEbits.RE1

#define _RESET 11
#define _LOCK 12
#define _KEY 13

#define TRIS_SAFE TRISDbits.RD3
#define TRIS_BUZZER TRISDbits.RD1
#define TRIS_ROW_1 TRISAbits.RA0
#define TRIS_ROW_2 TRISAbits.RA1
#define TRIS_ROW_3 TRISAbits.RA2
#define TRIS_ROW_4 TRISAbits.RA3
#define TRIS_COL_1 TRISAbits.RA4
#define TRIS_COL_2 TRISAbits.RA5
#define TRIS_COL_3 TRISEbits.RE0
#define TRIS_COL_4 TRISEbits.RE1


#endif	/* GLOBALDEFINITIONS_H */