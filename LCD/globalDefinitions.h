/* 
 * File:   globalDefinitions.h
 * Author: Alfredo Medina
 *
 * Created on 15 de febrero de 2018, 06:55 PM
 */

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
#define LED PORTAbits.RA4 
#define LED_TRIS TRISAbits.RA4

//===LCD===
#define RS PORTDbits.RD5
#define EN PORTDbits.RD7
#define D0 PORTBbits.RB0
#define D1 PORTBbits.RB1
#define D2 PORTBbits.RB2
#define D3 PORTBbits.RB3
#define D4 PORTBbits.RB4
#define D5 PORTBbits.RB5
#define D6 PORTBbits.RB6
#define D7 PORTBbits.RB7




#endif	/* GLOBALDEFINITIONS_H */

