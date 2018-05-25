#ifndef GLOBALDEFINITIONS_H
#define	GLOBALDEFINITIONS_H

//BASIC: For all applications
//PARTICULR: Unique to this application

#define _XTAL_FREQ 8000000
#define F_CPU 8000000/64

//===BASIC===
#define _ON 1
#define _OFF 0

#define OUTPUT 0
#define INPUT 1

#define LED PORTAbits.RA4
#define LED_TRIS TRISAbits.RA4
//============

//===UTILITY
#define bit_check(var, pos) ((var) & (1<<(pos)))
//CHECK_BIT(var, pos)
 
#define bit_set(var, pos) var |= (1 << pos)
//SET_BIT(var, pos)
 
#define bit_clear(var, pos) var &= (~(1 << pos))
//CLEAR_BIT(var, pos)
 
#define bit_toggle(var, pos) var ^= (1 << pos)
//TOGGLE_BIT(var, pos)

//===PARTICULAR===

//===QTR-8A===
#define QTR1 PORTAbits.AN0 // A0
#define QTR2 PORTAbits.AN1 // A1
#define QTR3 PORTAbits.AN2 // A2
#define QTR4 PORTAbits.AN3 // A3
#define QTR5 PORTAbits.AN4 // A5
#define QTR6 PORTEbits.AN5 // E0
#define QTR7 PORTEbits.AN6 // E1
#define QTR8 PORTEbits.AN7 // E2

#define TRISQ1 TRISAbits.TRISA0 // A0
#define TRISQ2 TRISAbits.TRISA1 // A1
#define TRISQ3 TRISAbits.TRISA2 // A2
#define TRISQ4 TRISAbits.TRISA3 // A3
#define TRISQ5 TRISAbits.TRISA5 // A5
#define TRISQ6 TRISEbits.TRISE0 // A3
#define TRISQ7 TRISEbits.TRISE1 // A3
#define TRISQ8 TRISEbits.TRISE2 // A3

//===GP2Y0A41SK0F===
#define SHARP PORTBbits.RB2 // B0
#define TRIS_S TRISBbits.RB2
#define SHARP_C 512

///===MOTOR===
    // YELLOW MOTORB
    #define M1FWD PORTDbits.RD0
    #define M1BCK PORTDbits.RD3

    #define M1F_TRIS TRISDbits.RD0
    #define M1B_TRIS TRISDbits.RD3


    // BLUE MOTORB
    #define M2FWD PORTDbits.RD2
    #define M2BCK PORTDbits.RD1

    #define M2F_TRIS TRISDbits.RD2
    #define M2B_TRIS TRISDbits.RD1

// === GLOVET ===
#define STOP 's'
#define FORWARD 'f'
#define BACK 'b'
#define RIGHT 'r'
#define LEFT 'l'
#endif	/* GLOBALDEFINITIONS_H */
