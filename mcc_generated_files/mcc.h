/**
  @Generated MPLAB(c) Code Configurator Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    mcc.h

  @Summary:
    This is the mcc.h file generated using MPLAB(c) Code Configurator

  @Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.15
        Device            :  PIC18F45K50
        Version           :  1.02
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#ifndef MCC_H
#define	MCC_H
#include <xc.h>
#include "pin_manager.h"
#include <stdint.h>
#include <stdbool.h>
#include "interrupt_manager.h"
#include "eusart1.h"
#include "tmr0.h"

#define _XTAL_FREQ  16000000

#define tamSnake 			2 //Maximo inicial 12 y min 2 porque en un caso donde ambos comen fruta podria morir
#define MAX_SNAKE_LENGTH 	548 //Tamaño necesario para ganar

int gif = 0;
    //jugador uno
    unsigned char boton = 0;
    unsigned int lectAX0 = 0;
    unsigned int lectAY1 = 0;
    //jugador dos
    int lectAX2;
    int lectAY3;
    //jugador tres
    int lectBX0;
    int lectBY1;
    //jugador cuatro
    int lectBX2;
    int lectBY3;
    
    
//matriz de leds encen0didos y apagados
char matrixLed[24][40]={};

//tamanos de los snakes
int tam[4];

//vectores de coordenadas de los snake
char x[4][80]={};
char y[4][80]={};

/*direccion
1 arriba
2 abajo
3 izquierda
4 derecha
*/
//direcciones de cada jugador usadas
char dir[4]={};
//direcciones provenientes de los controles
unsigned char dirC[4]={};

//En caso de ganar, banderas se activa
char win = 0;
char numberWin = -1;
//En caso de perder, bandera se activa
char numberLose[4] = {1,1,1,1};
char gameover = 0; //en caso de que todos pierdan y acabe el juego

//Coordenadas de la fruta
char fruitX;
char fruitY;
char fruitFlag=0;

//variable auxiliares
char i;
char j;
unsigned char k;

/*
 Variables para el display
 */
unsigned char MatrizDisplay [3][41];
unsigned char Columna = 0;
unsigned char index = 0; //USART REC
unsigned char colum = 0; //USART REC
unsigned char buffer [40];

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Initializes the device to the default states configured in the
 *                  MCC GUI
 * @Example
    SYSTEM_Initialize(void);
 */
void SYSTEM_Initialize(void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Initializes the oscillator to the default states configured in the
 *                  MCC GUI
 * @Example
    OSCILLATOR_Initialize(void);
 */
void OSCILLATOR_Initialize(void);

#endif	/* MCC_H */
/**
 End of File
*/