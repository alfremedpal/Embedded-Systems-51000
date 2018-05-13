#ifndef GLOBALDEFINITIONS_H
#define	GLOBALDEFINITIONS_H

//BASIC: For all applications
//PARTICULR: Unique to this application

#define _XTAL_FREQ 8000000

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
#define LED PORTAbits.RA4
#define IR PORTEbits.RE2

#define IR_TRIS TRISEbits.RE2
#define LED_TRIS TRISAbits.RA4

// === COMMANDS ===
#define FORWARD 0b111
#define REVERSE 0b100
#define LEFT    0b101
#define RIGHT   0b110
#define PARK    0b011
#define STOP    0b000
#define PULSE   PORTBbits.RB0



///===MOTOR===
    // ORANGE MOTORB
    
    #define M1FWD PORTDbits.RD2
    #define M1BCK PORTDbits.RD3

    #define M1 TRISCbits.RC2
    #define M1F_TRIS TRISDbits.RD2
    #define M1B_TRIS TRISDbits.RD3


    // BROWN MOTORB
    #define M2FWD PORTDbits.RD1
    #define M2BCK PORTDbits.RD0

    #define M2 TRISCbits.RC1
    #define M2F_TRIS TRISDbits.RD0
    #define M2B_TRIS TRISDbits.RD1


#endif	/* GLOBALDEFINITIONS_H */
