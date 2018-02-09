# Interrupts practice

- [x] Turn on an LED with INT0
- [x] Toggle the state of an LED with INT1
- [x] Turn on an LED with INT2 only if at least 10 seconds have passed

## Configuration bits
Also available inside the 'configPic' function in config.c:
```
    INTCONbits.GIE = 1;         // Turn on ALL interrupts
    INTCONbits.PEIE_GIEL = 1;   // Turn on peripheral interrupts
    
    INTCONbits.INT0IE = 1;      // Enables interrupts from INT0
    INTCONbits.INT0IF = 0;      // INT0 flag is off
    INTCON3bits.INT1IE = 1;     // Enables interrupts from INT1
    INTCON3bits.INT1IF = 0;     // INT1 flag is off
    INTCON3bits.INT2IE = 1;     // Enables interrupts from INT2
    INTCON3bits.INT2IF = 0;     // INT1 flag is off
    
    INTCON2bits.INTEDG0 = 1;    // Low to high for INT0
    INTCON2bits.INTEDG1 = 0;    // High to low for INT1
    INTCON2bits.INTEDG2 = 0;    // High to low for INT2
```
