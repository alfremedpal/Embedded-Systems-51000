
#include "config.h"
#include "globalDefinitions.h"
#include "LCD.h"

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
  wait_ms(5);
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
    RS_TRIS = OUTPUT;
    EN_TRIS = OUTPUT;
    D0_TRIS = OUTPUT;
    D1_TRIS = OUTPUT;
    D2_TRIS = OUTPUT;
    D3_TRIS = OUTPUT;
    D4_TRIS = OUTPUT;
    D5_TRIS = OUTPUT;
    D6_TRIS = OUTPUT;
    D7_TRIS = OUTPUT;
    
	LCD_Port(0x00);
	RS = 0;
	wait_ms(25);
    LCD_Cmd(0x30);
    wait_ms(5);
    LCD_Cmd(0x30);
	wait_ms(15);
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
   wait_ms(4);
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