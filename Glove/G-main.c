#include <pic18f4550.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "USART_Header_File.h"      /* Include USART header file */
#include "I2C_Master_File.h"
#include "MPU6050_res_define.h"
#include "Configuration_header_file.h"

#define _XTAL_FREQ 8000000

#define PI 3.14159265359
#define dt 0.01

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

#define OUTPUT 0
#define INPUT 1

void LCD_Port(char a)
{
	if(a & 1)
		D0 = 1;
	else 
		D0 = 0;
	
	if(a & 2)
		D1 = 1;
	else
		D1 = 0;
	
	if(a & 4)
		D2 = 1;
	else
		D2 = 0;
	
	if(a & 8)
		D3 = 1;
	else
		D3 = 0;
	
	if(a & 16)
		D4 = 1;
	else
		D4 = 0;

	if(a & 32)
		D5 = 1;
	else
		D5 = 0;
	
	if(a & 64)
		D6 = 1;
	else 
		D6 = 0;
	
	if(a & 128)
		D7 = 1;
	else
		D7 = 0;
}

void LCD_Cmd(char a)
{ 
  RS = 0;             // => RS = 0
  LCD_Port(a);             //Data transfer
  EN  = 1;             // => E = 1
  __delay_ms(5);
  EN  = 0;             // => E = 0
}

void LCD_Clear()
{
	  LCD_Cmd(1);
}

void LCD_SetCursor(char a, char b)
{
	if(a == 1)
	  LCD_Cmd(0x80 + b);
	else if(a == 2)
		LCD_Cmd(0xC0 + b);
}

void LCD_Init()
{
    
    TRISDbits.RD6 = OUTPUT;
    TRISDbits.RD7 = OUTPUT;
    
    TRISDbits.RD5 = OUTPUT;
    TRISDbits.RD4 = OUTPUT;
    TRISCbits.RC7 = OUTPUT;
    TRISCbits.RC6 = OUTPUT;
    TRISDbits.RD3 = OUTPUT;
    TRISDbits.RD2 = OUTPUT;
    TRISDbits.RD1 = OUTPUT;
    TRISDbits.RD0 = OUTPUT;
    

    
	LCD_Port(0x00);
	RS = 0;
	__delay_ms(5);(25);
    LCD_Cmd(0x30);
    __delay_ms(5);(5);
    LCD_Cmd(0x30);
	__delay_ms(5);(15);
    LCD_Cmd(0x30);
    LCD_Cmd(0x38);    // Function set
    LCD_Cmd(0x0C);    // Display on, cursor off, blink off
    LCD_Cmd(0x01);    // Clear display
    LCD_Cmd(0x06);    // Entry mode, set increment
}

void LCD_WriteChar(char a)
{
   RS = 1;             // => RS = 1
   LCD_Port(a);             //Data transfer
   EN  = 1;             // => E = 1
   __delay_ms(5);(4);
   EN  = 0;             // => E = 04
}

void LCD_WriteString(char *a)
{
	int i;
	for(i=0;a[i]!='\0';i++)
	 LCD_WriteChar(a[i]);
}

void LCD_ShiftRight()
{
	LCD_Cmd(0x1C);
}

void LCD_ShiftLeft()
{
	LCD_Cmd(0x18);
}


void MPU6050_Init()										/* Gyro initialization function */
{
	MSdelay(150);		/* Power up time >100ms */
	I2C_Start_Wait(0xD0);	/* Start with device write address */
	I2C_Write(SMPLRT_DIV);	/* Write to sample rate register */
	I2C_Write(0x07);	/* 1KHz sample rate */
	I2C_Stop();

	I2C_Start_Wait(0xD0);
	I2C_Write(PWR_MGMT_1);	/* Write to power management register */
	I2C_Write(0x01);	/* X axis gyroscope reference frequency */
	I2C_Stop();

	I2C_Start_Wait(0xD0);
	I2C_Write(CONFIG);	/* Write to Configuration register */
	I2C_Write(0x00);	/* Fs = 8KHz */
	I2C_Stop();

	I2C_Start_Wait(0xD0);
	I2C_Write(GYRO_CONFIG);	/* Write to Gyro configuration register */
	I2C_Write(0x18);	/* Full scale range +/- 2000 degree/C */
	I2C_Stop();

	I2C_Start_Wait(0xD0);
	I2C_Write(INT_ENABLE);	/* Write to interrupt enable register */
	I2C_Write(0x01);
	I2C_Stop();

}

void MPU_Start_Loc()

{
	I2C_Start_Wait(0xD0);								/* I2C start with device write address */
	I2C_Write(ACCEL_XOUT_H);							/* Write start location address from where to read */ 
	I2C_Repeated_Start(0xD1);							/* I2C start with device read address */
}

void main()

{
    //=================================
    // Variables
    //char A[32], B[32];
	int Ax,Ay,Az,T,Gx,Gy,Gz;
	float Xa,Ya,Za,t,Xg,Yg,Zg;
    float angleGx, angleGy, angleGz;
    float angleAx, angleAy, angleAz;
    //float angleCx, angleCy;
    //char buffer[20];
    //=================================
    
    OSCCON = 0x72;
  
    I2C_Init();											/* Initialize I2C */
	MPU6050_Init();										/* Initialize Gyro */

	//USART_Init(9600);									/* Initialize USART with 9600 baud rate */

    TRISAbits.RA0 = 0;
    TRISAbits.RA1 = 0;
    TRISAbits.RA2 = 0;
    TRISAbits.RA3 = 0;
    
    PORTAbits.RA0 = 1;
    PORTAbits.RA1 = 1;
    PORTAbits.RA2 = 1;
    PORTAbits.RA3 = 1;


	
	while(1)
	{
        PORTAbits.RA0 = 0;
        PORTAbits.RA1 = 0;
        PORTAbits.RA2 = 0;
        PORTAbits.RA3 = 0;
        
        //==================================================
        // Raw values
		MPU_Start_Loc();								
		Ax = (((int)I2C_Read(0)<<8) | (int)I2C_Read(0));
		Ay = (((int)I2C_Read(0)<<8) | (int)I2C_Read(0));
		Az = (((int)I2C_Read(0)<<8) | (int)I2C_Read(0));
		T = (((int)I2C_Read(0)<<8) | (int)I2C_Read(0));
		Gx = (((int)I2C_Read(0)<<8) | (int)I2C_Read(0));
		Gy = (((int)I2C_Read(0)<<8) | (int)I2C_Read(0));
		Gz = (((int)I2C_Read(0)<<8) | (int)I2C_Read(1));
		I2C_Stop();
		//==================================================
        
        //==================================================
        // Actual measurements
        Xa = (float)Ax/16384.0;							
		Ya = (float)Ay/16384.0;
		Za = (float)Az/16384.0;
		Xg = (float)Gx/131.0;
		Yg = (float)Gy/131.0;
		Zg = (float)Gz/131.0;
		t = ((float)T/340.00)+36.53;					
		//==================================================
        
        //==================================================
        // Calculating angles
        angleAx = atan2((float)Ya, (float)Za) * 180 / PI;
        angleAy = atan2((float)Xa, (float)Za) * 180 / PI;
        angleAz = atan2((float)Xa, (float)Ya) * 180 / PI;
        
        
//        angleGx +=  Gx * dt;
//        angleGy -=  Gy * dt;
        //==================================================
        
        //==================================================
        // Complementary filter
//        int forceMagnitudeApprox = abs(Ax) + abs(Ay) + abs(Az);
//        if (forceMagnitudeApprox > 8192 && forceMagnitudeApprox < 32768) {
//        angleGx = angleGx*0.98 + angleAx*0.02;
//        angleGy = angleGy*0.98 + angleAy*0.02;
//        }
       
        //==================================================
//        
//        sprintf(A, "X:%1.2f Y:%1.2f", angleAx, angleAy);
//        sprintf(B, "Z:%1.2f", angleAz);
        
		//sprintf(buffer," Ay:%1.2f g\t",Ya);
		//USART_SendString(buffer);
		
		//sprintf(buffer," Az = %.2f g \n",Za);
		//USART_SendString(buffer);

        if(angleAx > 30)
            PORTAbits.RA2 = 1;
        else if(angleAx < -30)
            PORTAbits.RA3 = 1;
        else if(angleAy > 30)
            PORTAbits.RA0 = 1;
        else if(angleAy < -30)
            PORTAbits.RA1 = 1;
        //else
            //stop
        
        
        
//        LCD_SetCursor(1,0);
//        LCD_WriteString(A);
//        LCD_SetCursor(2,0);
//        LCD_WriteString(B);   
        
        __delay_ms(100);
	}
}

