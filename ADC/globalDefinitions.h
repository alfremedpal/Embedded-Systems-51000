
#ifndef GLOBALDEFINITIONS_H
#define	GLOBALDEFINITIONS_H

#define SIGNALa PORTAbits.AN0
#define SIGNALa_TRIS TRISAbits.TRISA0
#define SIGNALb PORTAbits.AN1
#define SIGNALb_TRIS TRISAbits.TRISA1
#define VREFP PORTAbits.RA2
#define VREFP_TRIS TRISAbits.RA2
#define VREFN PORTAbits.RA3
#define VREFN_TRIS TRISAbits.RA3
#define LEDa PORTAbits.RA4
#define LEDa_TRIS TRISAbits.RA4
#define LEDb PORTAbits.RA5
#define LEDb_TRIS TRISAbits.RA5

#define _XTAL_FREQ 4000000

#define _ON 1
#define _OFF 0

#define INPUT 1
#define OUTPUT 0

#define SW1_TRIS TRISCbits.RC2

#endif	/* GLOBALDEFINITIONS_H */

