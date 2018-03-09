/* 
 * File:   globalDefinitions.h
 * Author: XBUG
 */

#ifndef GLOBALDEFINITIONS_H
#define	GLOBALDEFINITIONS_H

//BASIC: For all applications
//PARTICULR: Unique to this application

#define _XTAL_FREQ 4000000
#define F_CPU 4000000/64

//===BASIC===
#define _ON 1
#define _OFF 0

#define OUTPUT 0
#define INPUT 1

#define ENABLE 1
#define DISABLE 0
//============

//===BAUDS===
#define LED PORTAbits.RA4
#define PUSH_ON PORTAbits.RA2
#define PUSH_OFF PORTAbits.RA3

#define LED_TRIS TRISAbits.RA4
#define TRIS_PUSH_ON TRISAbits.RA2
#define TRIS_PUSH_OFF TRISAbits.RA3

#define SIZE 16

//===LCD===
#define RS PORTDbits.RD0
#define EN PORTDbits.RD1
#define D0 PORTDbits.RD2
#define D1 PORTDbits.RD3
#define D2 PORTCbits.RC6
#define D3 PORTCbits.RC7
#define D4 PORTDbits.RD4
#define D5 PORTDbits.RD5
#define D6 PORTDbits.RD6
#define D7 PORTDbits.RD7

#define RS_TRIS TRISDbits.RD0
#define EN_TRIS TRISDbits.RD1
#define D0_TRIS TRISDbits.RD2
#define D1_TRIS TRISDbits.RD3
#define D2_TRIS TRISCbits.RC6
#define D3_TRIS TRISCbits.RC7
#define D4_TRIS TRISDbits.RD4
#define D5_TRIS TRISDbits.RD5
#define D6_TRIS TRISDbits.RD6
#define D7_TRIS TRISDbits.RD7

#endif	/* GLOBALDEFINITIONS_H */
