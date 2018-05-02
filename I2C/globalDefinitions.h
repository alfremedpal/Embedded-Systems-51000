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

#define _XTAL_FREQ 48000000

//===BASIC===
#define _ON 1
#define _OFF 0

#define OUTPUT 0
#define INPUT 1
//============

//===PARTICULAR===
#define LED PORTAbits.RA0 
#define LED_TRIS TRISAbits.RA0

//=======LCD=======
#define RS PORTDbits.RD7
#define EN PORTDbits.RD6

#define D0 PORTDbits.RD5
#define D1 PORTDbits.RD4
#define D2 PORTCbits.RC7
#define D3 PORTCbits.RC6
#define D4 PORTDbits.RD3
#define D5 PORTDbits.RD2
#define D6 PORTDbits.RD1
#define D7 PORTDbits.RD0


#endif	/* GLOBALDEFINITIONS_H */

