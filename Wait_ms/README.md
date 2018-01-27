# wait_ms() function
Recieves the amount of miliseconds to wait or delay.

Pre-scaler is set as 1:4, with count = 24, and TMR0L = 131. Substituting this values in 
```
f = 48MHz/[4*prescaler*(256-TMR0L)*count] 
```
yields a frequency of 1000Hz. Inverting that value to get time (in s) we obtain 1 milisecond.


NOTE: This code assumes you are using a 4MHz crystal and therefore PLLDIV = 1; if you are using a 20MHz crystal set PLLDIV = 5
