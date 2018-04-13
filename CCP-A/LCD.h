/* 
 * File:   LCD.h
 * Author: Alfredo
 *
 * Created on 15 de febrero de 2018, 11:22 PM
 */

#ifndef LCD_H
#define	LCD_H

void LCD_Port(char);
void LCD_Cmd(char);
void LCD_Clear();
void LCD_SetCursor(char, char);
void LCD_Init();
void LCD_WriteChar(char);
void LCD_WriteString(char *);
void LCD_ShiftRight();
void LCD_ShiftLeft();


#endif	/* LCD_H */
