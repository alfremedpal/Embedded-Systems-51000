/* 
 * File:   globalDefinitions.h
 * Author: XBUG
 */

#ifndef GLOBALDEFINITIONS_H
#define	GLOBALDEFINITIONS_H

//BASIC: For all applications
//PARTICULR: Unique to this application

#define _XTAL_FREQ 4000000

//===BASIC===
#define _ON 1
#define _OFF 0

#define OUTPUT 0
#define INPUT 1

#define ENABLE 1
#define DISABLE 0

#define TRUE 1
#define FALSE 0
//============

//=== CCP ===
#define CCP1 PORTCbits.RC2
#define CCP1_TRIS TRISCbits.RC2
#define CCP2 PORTCbits.RC1
#define CCP2_TRIS TRISCbits.RC1
#define CCP_THRESH 3 // ?
#define CCP_CONST 50000

#define SIGNAL PORTAbits.RA5
#define SIGNAL_TRIS TRISAbits.RA5

#define LED PORTAbits.RA4
#define LED_TRIS TRISAbits.RA5

#define FREQ 1000
#define DUTY 60


//===LCD===
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

#endif	/* GLOBALDEFINITIONS_H */
