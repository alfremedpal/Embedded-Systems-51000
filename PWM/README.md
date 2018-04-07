# PWM 

## Generate a PWM signal @5kHz with a duty cycle of 60
```
 openPWM1(99);    // Open PWM 1 @5kHz
 PWM1_setDC(60);  // 60% duty cycle
    
```

* NOTE: For more information on the input values for 'open1PWM' and 'PWM1_setDC' read 'config.c'

## Generate a PWM signal @2kHz with a duty cycle that increments every half second by 5% until maximum DC and then decreases at the same rate, looping the whole process
```
    while(sentido == 1 && dc < 250 )
    {
        __delay_ms(500);
        dc = dc + 13;
        PWM1_setDC(dc);
        __delay_ms(500);
        if(dc == 247)
        {
            dc = 249;
            PWM1_setDC(dc);
            sentido = -1;
        }
    }

    while(sentido == -1 && dc < 250)
    {
        __delay_ms(500);
        dc = dc - 13;
        PWM1_setDC(dc);
        __delay_ms(500);
        if(dc == 2)
            {
                dc = 0;
                PWM1_setDC(dc);
                sentido = 1;
            }
    }
        
```
* NOTE: 'sentido' and 'dc' are global variables
