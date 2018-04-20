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
//============

//===PARTICULAR===

// Note frequencies
#define N7_C 2093
#define N7_Cs 2217
#define N7_D 2349
#define N7_Ds 2489
#define N7_E 2637
#define N7_F 2793
#define N7_Fs 2959
#define N7_G 3135
#define N7_Gs 3322
#define N7_A 3520
#define N7_As 3729
#define N7_B 3951

// Note buttons
#define B_C PORTDbits.RD1
#define B_Cs PORTDbits.RD0
#define B_D PORTCbits.RC0
#define B_Ds PORTEbits.RE2
#define B_E PORTEbits.RE1
#define B_F PORTEbits.RE0
#define B_Fs PORTAbits.RA5
#define B_G PORTAbits.RA4
#define B_Gs PORTAbits.RA3
#define B_A PORTAbits.RA2
#define B_As PORTAbits.RA1
#define B_B PORTAbits.RA0

// Note Button TRIS
#define TRISB_C TRISDbits.RD1
#define TRISB_Cs TRISDbits.RD0
#define TRISB_D TRISCbits.RC0
#define TRISB_Ds TRISEbits.RE2
#define TRISB_E TRISEbits.RE1
#define TRISB_F TRISEbits.RE0
#define TRISB_Fs TRISAbits.RA5
#define TRISB_G TRISAbits.RA4
#define TRISB_Gs TRISAbits.RA3
#define TRISB_A TRISAbits.RA2
#define TRISB_As TRISAbits.RA1
#define TRISB_B TRISAbits.RA0


#endif	/* GLOBALDEFINITIONS_H */