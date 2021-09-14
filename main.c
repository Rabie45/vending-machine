#include <xc.h>
#include <stdint.h>
#include <stdio.h>
#include "libs/config.h"
#include "libs/LCD.h"
#include "libs/keypad.h"
#define dolar_sw RD7

char *line1 = "ENTER the key";
void cola();
void pepsi();
void water();
void display();
unsigned char Key = '*';

int main()
{
    TRISD0 = 1;
    TRISD1 = 0;
    RD1 = 0;
    TRISD2 = 0;
    RD2 = 0;

    LCD_Init();
    keyinit();

    while (1)
    {
        display();
        LCD_Clear();

        switch (Key)
        {
        case '1':
            cola();
            break;
        case '2':
            pepsi();
            break;
        case '3':
            water();
            break;
        default:
            LCD_Write_String("error not valid");
            __delay_ms(1000);
            break;
        }
    }
}

void display()
{
    LCD_Clear();
    do
    {
        LCD_Set_Cursor(1, 1);
        LCD_Write_String("what do u need");
        Key = key();
    } while (Key == '*');
}
void cola()
{
    int half = 0, total = 0;
    unsigned int dolar = 0;
    LCD_Clear();
    LCD_Set_Cursor(1, 1);
    LCD_Write_String(" cola :put 3$");
    do
    {
        if (dolar_sw == 1)
        {
            RA0 = 1;
            dolar++;
            __delay_ms(1000);
            RA0 = 0;
        }
        total = dolar * 1;
    } while (total < 3);
    RD1 = 1;
    __delay_ms(1000);
    RD1 = 0;
    if (total > 3)
    {
        total = total - 3;
        while (total > 0)
        {
            RD2 = 1;
            __delay_ms(500);
            RD2 = 0;
            total--;
        }
    }
}

void pepsi()
{
    int total = 0;
    unsigned int dolar = 0;
    LCD_Clear();
    LCD_Set_Cursor(1, 1);
    LCD_Write_String(" pepsi :put 2$");
    do
    {
        if (dolar_sw == 1)
        {
            RA0 = 1;
            dolar++;
            __delay_ms(1000);
            RA0 = 0;
        }
        total = dolar * 1;
    } while (total < 2);
    RD1 = 1;
    __delay_ms(1000);
    RD1 = 0;
    if (total > 2)
    {
        total = total - 2;
        while (total > 0)
        {
            RD2 = 1;
            __delay_ms(500);
            RD2 = 0;
            total--;
        }
    }
}
void water()
{
    int total = 0;
    unsigned int dolar = 0;
    LCD_Clear();
    LCD_Set_Cursor(1, 1);
    LCD_Write_String(" water :put 1$");
    do
    {
        if (dolar_sw == 1)
        {
            RA0 = 1;
            dolar++;
            __delay_ms(1000);
            RA0 = 0;
        }
        total = dolar * 1;
    } while (total < 1);
    RD1 = 1;
    __delay_ms(1000);
    RD1 = 0;
    if (total > 1)
    {
        total = total - 1;
        while (total > 0)
        {
            RD2 = 1;
            __delay_ms(500);
            RD2 = 0;
            total--;
        }
    }
}