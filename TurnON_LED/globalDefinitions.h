/* 
 * File:   globalDefinitions.h
 * Author: Alfredo Medina
 *
 * Created on 19 de enero de 2018, 07:37 PM
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
#define SW1 PORTAbits.RA1
#define LED_TRIS TRISAbits.RA0
#define SW1_TRIS TRISAbits.RA1

#endif	/* GLOBALDEFINITIONS_H */

