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
//============

//===WHAC-A-MOLE===
#define LED_GREEN PORTAbits.RA5
#define LED_RED PORTAbits.RA4
#define LED_YELLOW PORTAbits.RA3
#define LED_BLUE PORTAbits.RA2

#define LEDG_TRIS TRISAbits.RA5
#define LEDR_TRIS TRISAbits.RA4
#define LEDY_TRIS TRISAbits.RA3
#define LEDB_TRIS TRISAbits.RA2

#define GREEN_PUSH PORTBbits.RB0
#define RED_PUSH PORTBbits.RB1
#define YELLOW_PUSH PORTBbits.RB2
#define BLUE_PUSH PORTBbits.RB4

#define GPUSH_TRIS TRISBbits.RB0
#define RPUSH_TRIS TRISBbits.RB1
#define YPUSH_TRIS TRISBbits.RB2
#define BPUSH_TRIS TRISBbits.RB4

#define START PORTAbits.RA0
#define START_TRIS TRISAbits.RA0

#define BUZZER PORTCbits.RC2
#define BUZZER_TRIS TRISCbits.RC2

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
