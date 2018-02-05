/* 
 * File:   globalDefinitions.h
 * Author: Alfredo Medina
 *
 * Created on 2 de febrero de 2018, 07:18 PM
 */

#ifndef GLOBALDEFINITIONS_H
#define	GLOBALDEFINITIONS_H

//BASIC: For all applications
//PARTICULR: Unique to this application

//===BASIC===
#define _ON 1
#define _OFF 0

#define OUTPUT 0
#define INPUT 1
//============

//===PARTICULAR===
#define LED PORTAbits.RA0
#define LED_TRIS TRISAbits.RA0


#define INTE0 PORTBbits.RB0
#define INTE0_TRIS TRISBbits.RB0
#define INTE1 PORTBbits.RB1
#define INTE1_TRIS TRISBbits.RB1
#define INTE2 PORTBbits.RB2
#define INTE2_TRIS TRISBbits.RB2

#endif	/* GLOBALDEFINITIONS_H */

