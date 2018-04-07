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
#define LED PORTAbits.RA0 
#define LED_TRIS TRISAbits.RA0


#endif	/* GLOBALDEFINITIONS_H */

