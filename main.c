    /**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using MPLAB(c) Code Configurator

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.15
        Device            :  PIC18F45K50
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "usart.h"
#include "adc.h"

void createStringMat();
////////////////////////////////////////////////////////////////////////////////
/*void write_EEPROM(unsigned int address, unsigned int dat)
{
  unsigned int temp;
  StartI2C1(); // issue I2C start signal
  WriteI2C1(0xA0); // send byte via I2C (device address + W)
  temp = address >> 8; //saving higher order address to temp
  WriteI2C1(temp); //sending higher order address
  WriteI2C1(address); //sending lower order address
  WriteI2C1(dat); // send data (data to be written)
  StopI2C1(); // issue I2C stop signal
  __delay_ms(20);
}

unsigned int read_EEPROM(unsigned int address)
{
  unsigned int temp;
  StartI2C1(); // issue I2C start signal
  WriteI2C1(0xA0); // send byte via I2C (device address + W)
  temp = address >> 8; //saving higher order address to temp
  WriteI2C1(temp); //sending higher order address
  WriteI2C1(address); //sending lower order address
  RestartI2C1(); // issue I2C signal repeated start
  WriteI2C1(0xA1); // send byte (device address + R)
  temp = ReadI2C1(); // Read the data (NO acknowledge)
  StopI2C1();
  return temp;
}*/
////////////////////////////////////////////////////////////////////////////////
int ADC(int channel){
    ADCON0bits.CHS = channel;    

    // Turn on the ADC module
    ADCON0bits.ADON = 1;

    // Start the conversion
    ADCON0bits.GO_nDONE = 1;

    // Wait for the conversion to finish
    while (ADCON0bits.GO_nDONE)
    {
    }
    // Conversion finished, return the result
    return ((ADRESH << 8) + ADRESL);
}
char countBoton=0;
void GenerateDir(){
        //lee puertos analogicos
        //lectAX0 = ADC(14); //RC2
        //lectAY1 = ADC(7); //RE2  
        //if(PORTCbits.RC7 == 1){ //boton de seleccion
          //      boton = 1;
        //}
        
        PORTCbits.RC0 = 0;
        PORTCbits.RC1 = 0;
        lectAX0 = ADC(14);
        
        PORTCbits.RC0 = 1;
        PORTCbits.RC1 = 0;
        lectAY1 = ADC(14);
        
        PORTCbits.RC0 = 0;
        PORTCbits.RC1 = 1;
        lectAX2 = ADC(14);
        
        PORTCbits.RC0 = 1;
        PORTCbits.RC1 = 1;
        lectAY3 = ADC(14);
        
        
        
        PORTCbits.RC0 = 0;
        PORTCbits.RC1 = 0;
        lectBX0 = ADC(7);
        
        PORTCbits.RC0 = 1;
        PORTCbits.RC1 = 0;
        lectBY1 = ADC(7);
        
        PORTCbits.RC0 = 0;
        PORTCbits.RC1 = 1;
        lectBX2 = ADC(7);
        
        PORTCbits.RC0 = 1;
        PORTCbits.RC1 = 1;
        lectBY3 = ADC(7);
        
//1     
        int a  = 20;
        int b = 700;
        
        if(lectAX0 <= a && lectAY1 > a && lectAY1 < b) //derecha
            dirC[0]=4;
        if(lectAX0 >= b && lectAY1 > a && lectAY1 < b )//izq
            dirC[0]=3;
        if(lectAY1 <= a && lectAX0 > a && lectAX0 < b )//arriba
            dirC[0]=1;
        if(lectAY1 >= b && lectAX0 > a && lectAX0 < b )//abajo
            dirC[0]=2;
//2     
        if(lectAX2 <= a && lectAY3 > a && lectAY3 < b) //izq
            dirC[1]=4;
        if(lectAX2 >= b && lectAY3 > a && lectAY3 < b )//derecha
            dirC[1]=3;
        if(lectAY3 <= a && lectAX2 > a && lectAX2 < b )//arriba
            dirC[1]=1;
        if(lectAY3 >= b && lectAX2 > a && lectAX2 < b )//abajo
            dirC[1]=2;

//3      
        if(lectBX0 <=a && lectBY1 > a && lectBY1 < b) //izq
            dirC[2]=4;
        if(lectBX0 >= b && lectBY1 > a && lectBY1 < b )//derecha
            dirC[2]=3;
        if(lectBY1 <=a && lectBX0 > a && lectBX0 < b )//arriba
            dirC[2]=1;
        if(lectBY1 >= b && lectBX0 > a && lectBX0 < b )//abajo
            dirC[2]=2;
 //4       
        if(lectBX2 <= a && lectBY3 > a && lectBY3 < b) //izq
            dirC[3]=4;
        if(lectBX2 >= b && lectBY3 > a && lectBY3 < b )//derecha
            dirC[3]=3;
        if(lectBY3 <= a && lectBX2 > a && lectBX2 < b )//arriba
            dirC[3]=1;
        if(lectBY3 >= b && lectBX2 > a && lectBX2 < b )//abajo
            dirC[3]=2;   
}


//Resetear matriz, inicializar
void resetVariables(){
	for(i=0; i<4; i++)
		numberLose[i] = 1;
	for(i=0; i<24; i++)
		for(j=0; j<40; j++)
			matrixLed[i][j] = 0;
	fruitFlag=0;
	win = 0;
	numberWin = -1;
}
//Decodifica numero para insertarlo
void Dnumber(char number, char row, char col){
	if(number < 0){
		//insertarMat(cleanM, row, col);
		matrixLed[row][col] 	= 0;
		matrixLed[row][col+1] 	= 0;
		matrixLed[row][col+2] 	= 0;

		matrixLed[row+1][col] 	= 0;
		matrixLed[row+1][col+1] = 0;
		matrixLed[row+1][col+2] = 0;

		matrixLed[row+2][col] 	= 0;
		matrixLed[row+2][col+1] = 0;
		matrixLed[row+2][col+2] = 0;

		matrixLed[row+3][col] 	= 0;
		matrixLed[row+3][col+1] = 0;
		matrixLed[row+3][col+2] = 0;

		matrixLed[row+4][col] 	= 0;
		matrixLed[row+4][col+1] = 0;
		matrixLed[row+4][col+2] = 0;
	}
	if(number == 0){
		//insertarMat(CERO, row, col);
		matrixLed[row][col] 	= 1;
		matrixLed[row][col+1] 	= 1;
		matrixLed[row][col+2] 	= 1;

		matrixLed[row+1][col] 	= 1;
		matrixLed[row+1][col+1] = 0;
		matrixLed[row+1][col+2] = 1;

		matrixLed[row+2][col] 	= 1;
		matrixLed[row+2][col+1] = 0;
		matrixLed[row+2][col+2] = 1;

		matrixLed[row+3][col] 	= 1;
		matrixLed[row+3][col+1] = 0;
		matrixLed[row+3][col+2] = 1;

		matrixLed[row+4][col] 	= 1;
		matrixLed[row+4][col+1] = 1;
		matrixLed[row+4][col+2] = 1;
	}
	if(number == 1){
		//insertarMat(UNO, row, col);
		matrixLed[row][col] 	= 0;
		matrixLed[row][col+1] 	= 1;
		matrixLed[row][col+2] 	= 1;

		matrixLed[row+1][col] 	= 0;
		matrixLed[row+1][col+1] = 0;
		matrixLed[row+1][col+2] = 1;

		matrixLed[row+2][col] 	= 0;
		matrixLed[row+2][col+1] = 0;
		matrixLed[row+2][col+2] = 1;

		matrixLed[row+3][col] 	= 0;
		matrixLed[row+3][col+1] = 0;
		matrixLed[row+3][col+2] = 1;

		matrixLed[row+4][col] 	= 0;
		matrixLed[row+4][col+1] = 0;
		matrixLed[row+4][col+2] = 1;
	}
	if(number == 2){
		//insertarMat(DOS, row, col);
		matrixLed[row][col] 	= 1;
		matrixLed[row][col+1] 	= 1;
		matrixLed[row][col+2] 	= 1;

		matrixLed[row+1][col] 	= 0;
		matrixLed[row+1][col+1] = 0;
		matrixLed[row+1][col+2] = 1;

		matrixLed[row+2][col] 	= 1;
		matrixLed[row+2][col+1] = 1;
		matrixLed[row+2][col+2] = 1;

		matrixLed[row+3][col] 	= 1;
		matrixLed[row+3][col+1] = 0;
		matrixLed[row+3][col+2] = 0;

		matrixLed[row+4][col] 	= 1;
		matrixLed[row+4][col+1] = 1;
		matrixLed[row+4][col+2] = 1;
	}
	if(number == 3){
		//insertarMat(TRES, row, col);
		matrixLed[row][col] 	= 1;
		matrixLed[row][col+1] 	= 1;
		matrixLed[row][col+2] 	= 1;

		matrixLed[row+1][col] 	= 0;
		matrixLed[row+1][col+1] = 0;
		matrixLed[row+1][col+2] = 1;

		matrixLed[row+2][col] 	= 1;
		matrixLed[row+2][col+1] = 1;
		matrixLed[row+2][col+2] = 1;

		matrixLed[row+3][col] 	= 0;
		matrixLed[row+3][col+1] = 0;
		matrixLed[row+3][col+2] = 1;

		matrixLed[row+4][col] 	= 1;
		matrixLed[row+4][col+1] = 1;
		matrixLed[row+4][col+2] = 1;
	}
	if(number == 4){
		//insertarMat(CUATRO, row, col);
		matrixLed[row][col] 	= 1;
		matrixLed[row][col+1] 	= 0;
		matrixLed[row][col+2] 	= 1;

		matrixLed[row+1][col] 	= 1;
		matrixLed[row+1][col+1] = 0;
		matrixLed[row+1][col+2] = 1;

		matrixLed[row+2][col] 	= 1;
		matrixLed[row+2][col+1] = 1;
		matrixLed[row+2][col+2] = 1;

		matrixLed[row+3][col] 	= 0;
		matrixLed[row+3][col+1] = 0;
		matrixLed[row+3][col+2] = 1;

		matrixLed[row+4][col] 	= 0;
		matrixLed[row+4][col+1] = 0;
		matrixLed[row+4][col+2] = 1;
	}
	if(number == 5){
		//insertarMat(CINCO, row, col);
		matrixLed[row][col] 	= 1;
		matrixLed[row][col+1] 	= 1;
		matrixLed[row][col+2] 	= 1;

		matrixLed[row+1][col] 	= 1;
		matrixLed[row+1][col+1] = 0;
		matrixLed[row+1][col+2] = 0;

		matrixLed[row+2][col] 	= 1;
		matrixLed[row+2][col+1] = 1;
		matrixLed[row+2][col+2] = 1;

		matrixLed[row+3][col] 	= 0;
		matrixLed[row+3][col+1] = 0;
		matrixLed[row+3][col+2] = 1;

		matrixLed[row+4][col] 	= 1;
		matrixLed[row+4][col+1] = 1;
		matrixLed[row+4][col+2] = 1;
	}
	if(number == 6){
		//insertarMat(SEIS, row, col);
		matrixLed[row][col] 	= 1;
		matrixLed[row][col+1] 	= 1;
		matrixLed[row][col+2] 	= 1;

		matrixLed[row+1][col] 	= 1;
		matrixLed[row+1][col+1] = 0;
		matrixLed[row+1][col+2] = 0;

		matrixLed[row+2][col] 	= 1;
		matrixLed[row+2][col+1] = 1;
		matrixLed[row+2][col+2] = 1;

		matrixLed[row+3][col] 	= 1;
		matrixLed[row+3][col+1] = 0;
		matrixLed[row+3][col+2] = 1;

		matrixLed[row+4][col] 	= 1;
		matrixLed[row+4][col+1] = 1;
		matrixLed[row+4][col+2] = 1;
	}
	if(number == 7){
		//insertarMat(SIETE, row, col);
		matrixLed[row][col] 	= 1;
		matrixLed[row][col+1] 	= 1;
		matrixLed[row][col+2] 	= 1;

		matrixLed[row+1][col] 	= 0;
		matrixLed[row+1][col+1] = 0;
		matrixLed[row+1][col+2] = 1;

		matrixLed[row+2][col] 	= 0;
		matrixLed[row+2][col+1] = 1;
		matrixLed[row+2][col+2] = 1;

		matrixLed[row+3][col] 	= 0;
		matrixLed[row+3][col+1] = 0;
		matrixLed[row+3][col+2] = 1;

		matrixLed[row+4][col] 	= 0;
		matrixLed[row+4][col+1] = 0;
		matrixLed[row+4][col+2] = 1;
	}
	if(number == 8){
		//insertarMat(OCHO, row, col);
		matrixLed[row][col] 	= 1;
		matrixLed[row][col+1] 	= 1;
		matrixLed[row][col+2] 	= 1;

		matrixLed[row+1][col] 	= 1;
		matrixLed[row+1][col+1] = 0;
		matrixLed[row+1][col+2] = 1;

		matrixLed[row+2][col] 	= 1;
		matrixLed[row+2][col+1] = 1;
		matrixLed[row+2][col+2] = 1;

		matrixLed[row+3][col] 	= 1;
		matrixLed[row+3][col+1] = 0;
		matrixLed[row+3][col+2] = 1;

		matrixLed[row+4][col] 	= 1;
		matrixLed[row+4][col+1] = 1;
		matrixLed[row+4][col+2] = 1;
	}
	if(number == 9){
		//insertarMat(NUEVE, row, col);
		matrixLed[row][col] 	= 1;
		matrixLed[row][col+1] 	= 1;
		matrixLed[row][col+2] 	= 1;

		matrixLed[row+1][col] 	= 1;
		matrixLed[row+1][col+1] = 0;
		matrixLed[row+1][col+2] = 1;

		matrixLed[row+2][col] 	= 1;
		matrixLed[row+2][col+1] = 1;
		matrixLed[row+2][col+2] = 1;

		matrixLed[row+3][col] 	= 0;
		matrixLed[row+3][col+1] = 0;
		matrixLed[row+3][col+2] = 1;

		matrixLed[row+4][col] 	= 0;
		matrixLed[row+4][col+1] = 0;
		matrixLed[row+4][col+2] = 1;
	}
	
}
void InicializePoints(){
	char row, col, c=0;
	row = 19; col = 8;
	Dnumber(c, row, col);
	row = 19; col = 4;
	Dnumber(c, row, col);
	row = 19; col = 0;
	Dnumber(c, row, col);

	row = 0; col = 8;
	Dnumber(c, row, col);
	row = 0; col = 4;
	Dnumber(c, row, col);
	row = 0; col = 0;
	Dnumber(c, row, col);

	row = 0; col = 37;
	Dnumber(c, row, col);
	row = 0; col = 33;
	Dnumber(c, row, col);
	row = 0; col = 29;
	Dnumber(c, row, col);

	row = 19; col = 37;
	Dnumber(c, row, col);
	row = 19; col = 33;
	Dnumber(c, row, col);
	row = 19; col = 29;
	Dnumber(c, row, col);
}
void putPoints(char jugadorJ){
	char row, col, c=-1;
	//Para Jugador 1
	if(jugadorJ == 0 && numberLose[0]==0){
		if((tam[0]-tamSnake)<10){
			char aux = tam[0]-tamSnake;
			row = 19; col = 8;
			Dnumber(c, row, col);//clean space
			Dnumber(aux, row, col);//unidades
		}
		else if((tam[0]-tamSnake)<100){
			row = 19; col = 8;
			Dnumber(c, row, col);//clean space
			Dnumber((tam[0]-tamSnake)%10, row, col);//unidades
			row = 19; col = 4;
			Dnumber(c, row, col);//clean space
			Dnumber((tam[0]-tamSnake)/10, row, col);//decenas
		}
		else{
			row = 19; col = 8;
			Dnumber(c, row, col);//clean space
			Dnumber((tam[0]-tamSnake)%100%10, row, col);//unidades
			row = 19; col = 4;
			Dnumber(c, row, col);//clean space
			Dnumber((tam[0]-tamSnake)%100/10, row, col);//decenas
			row = 19; col = 0;
			Dnumber(c, row, col);//clean space
			Dnumber((tam[0]-tamSnake)/100, row, col);//centenas
		}
	}
	//Para Jugador 2
	if(jugadorJ == 1 && numberLose[1]==0){
		
		if((tam[1]-tamSnake)<10){
			row = 0; col = 8;
			Dnumber(c, row, col);//clean space
			Dnumber(tam[1]-tamSnake, row, col);//unidades
		}
		else if((tam[1]-tamSnake)<100){
			row = 0; col = 8;
			Dnumber(c, row, col);//clean space
			Dnumber((tam[1]-tamSnake)%10, row, col);//unidades
			row = 0; col = 4;
			Dnumber(c, row, col);//clean space
			Dnumber((tam[1]-tamSnake)/10, row, col);//decenas
		}
		else{
			row = 0; col = 8;
			Dnumber(c, row, col);//clean space
			Dnumber((tam[1]-tamSnake)%100%10, row, col);//unidades
			row = 0; col = 4;
			Dnumber(c, row, col);//clean space
			Dnumber((tam[1]-tamSnake)%100/10, row, col);//decenas
			row = 0; col = 0;
			Dnumber(c, row, col);//clean space
			Dnumber((tam[1]-tamSnake)/100, row, col);//centenas
		}
	}
	//Para Jugador 3
	if(jugadorJ == 2 && numberLose[2]==0){
		if((tam[2]-tamSnake)<10){
			row = 0; col = 37;
			Dnumber(c, row, col);//clean space
			Dnumber(tam[2]-tamSnake, row, col);//unidades
		}
		else if((tam[0]-tamSnake)<100){
			row = 0; col = 37;
			Dnumber(c, row, col);//clean space
			Dnumber((tam[2]-tamSnake)%10, row, col);//unidades
			row = 0; col = 33;
			Dnumber(c, row, col);//clean space
			Dnumber((tam[2]-tamSnake)/10, row, col);//decenas
		}
		else{
			row = 0; col = 37;
			Dnumber(c, row, col);//clean space
			Dnumber((tam[2]-tamSnake)%100%10, row, col);//unidades
			row = 0; col = 33;
			Dnumber(c, row, col);//clean space
			Dnumber((tam[2]-tamSnake)%100/10, row, col);//decenas
			row = 0; col = 29;
			Dnumber(c, row, col);//clean space
			Dnumber((tam[2]-tamSnake)/100, row, col);//centenas
		}
	}
	//Para Jugador 4
	if(jugadorJ == 3 && numberLose[3]==0){
		if((tam[3]-tamSnake)<10){
			row = 19; col = 37;
			Dnumber(c, row, col);//clean space
			Dnumber(tam[3]-tamSnake, row, col);//unidades
		}
		else if((tam[3]-tamSnake)<100){
			row = 19; col = 37;
			Dnumber(c, row, col);//clean space
			Dnumber((tam[3]-tamSnake)%10, row, col);//unidades
			row = 19; col = 33;
			Dnumber(c, row, col);//clean space
			Dnumber((tam[3]-tamSnake)/10, row, col);//decenas
		}
		else{
			row = 19; col = 37;
			Dnumber(c, row, col);//clean space
			Dnumber((tam[3]-tamSnake)%100%10, row, col);//unidades
			row = 19; col = 33;
			Dnumber(c, row, col);//clean space
			Dnumber((tam[3]-tamSnake)%100/10, row, col);//decenas
			row = 19; col = 29;
			Dnumber(c, row, col);//clean space
			Dnumber((tam[3]-tamSnake)/100, row, col);//centenas
		}
	}
}
void pintaMuro(){
	for(i=0; i<=12;i++){
		matrixLed[6][i] 	= 1;	
		matrixLed[6][i+27] 	= 1;
		matrixLed[17][i] 	= 1;
		matrixLed[17][i+27] = 1;
	}
	for(i=12;i<28;i++){
		matrixLed[0][i] 	= 1;
		matrixLed[23][i] 	= 1;
	}
	for(i=0; i<=6;i++){
		matrixLed[i][12] 	= 1;
		matrixLed[i][27] 	= 1;
		matrixLed[i+17][12] = 1;
		matrixLed[i+17][27]	= 1;
	}
	for(i=6;i<18;i++){
		matrixLed[i][0] 	= 1;
		matrixLed[i][39] 	= 1;
	}
}
void pintaSnake(char Njugador){ 
	//Inicializa jugadores 
	for(i=0; i<Njugador; i++)
		numberLose[i] = 0;
	if(Njugador-1>=0){
		tam[0]=tamSnake;
		j = tam[0]-1;
		for(i=21; i>21-tamSnake;i--){
			matrixLed[i][14]=1;
			
			x[0][j] = 14;
			y[0][j] = i;
			j = j-1;
		}
		dir[0] = 1; //arriba
	}
	if(Njugador-2>=0){
		tam[1]=tamSnake;
		j = tam[1]-1;
		for(i=2; i<2+tamSnake;i++){
			matrixLed[15][i]=1;
			
			x[1][j] = i;
			y[1][j] = 15;
			j = j-1;
		}
		dir[1] = 4; //derecha
	}
	if(Njugador-3>=0){
		tam[2]=tamSnake;
		j = tam[2]-1;
		for(i=2; i<2+tamSnake;i++){
			matrixLed[i][25]=1;
			
			x[2][j] = 25;
			y[2][j] = i;
			j = j-1;
		}
		dir[2] = 2; //abajo
	}
	if(Njugador-4>=0){
		tam[3]=tamSnake;
		j = tam[3]-1;
		for(i=37; i>37-tamSnake;i--){
			matrixLed[8][i]=1;
			
			x[3][j] = i;
			y[3][j] = 8;
			j = j-1;
		}
		dir[3] = 3; //izquierda
	}
}
void makeFruit(){
	char xf, yf;
    //inserta nueva semilla dada por las lecturas analogicas
	srand(TMR0L);
  	xf = rand()%40;
  	yf = rand()%24;
  	//char aux = matrixLed[yf][xf];
  	//Checa si ya esta ocupada la casilla o si esta fuera del muro   led fundido || xf ==  || yf == 
  	while(matrixLed[yf][xf] == 1 || (xf<12 && (yf<6 || yf>17)) || (xf>27 && (yf<6 || yf>17)) ){
    	xf = rand()%40;
  		yf = rand()%24;
  	}
  	matrixLed[yf][xf] = 1;
  	fruitX = xf;
  	fruitY = yf;
  	//printf(" Fruta %d %d\n", fruitY, fruitX);
}
void nextstep(char numJ){
	char auxX, auxY, auxX2,auxY2, auxX3, auxY3, aux; 
	char tailX[4], tailY[4];
	char headX, headY;
	char auxLosers[4];
	//Borra las snakes
	for(j=0; j<numJ; j++){
		//Saltar en caso de que ya halla perdido
		if(numberLose[j]==1)
			continue;
		for(i=0; i<tam[j]; i++){
    		auxX2 = x[j][i];
  			auxY2 = y[j][i];
  			matrixLed[auxY2][auxX2] = 0;
  		}
	}
	//Determinar proximas coordenadas
	for(j=0; j<numJ; j++){
		//Saltar en caso de que ya halla perdido
		if(numberLose[j]==1)
			continue;
		
  		//printf("posicion guarda cola %d en %d %d\n", tam[j]-1, tailY[j], tailX[j]);
		//Determina nuevos pares de coordenadas del snake del jugador en turno
		for(i=tam[j]-1; i>0; i--){
    		x[j][i] = x[j][i-1];
    		y[j][i] = y[j][i-1];
    		//printf("valor actualizado %d %d\n",y[j][i], x[j][i]);
  		}
  		//Guarda coordenadas pasadas de la cola de snake antes de actualizar
  		tailX[j] = x[j][tam[j]-1];
  		tailY[j] = y[j][tam[j]-1];
  		//Ubica la cabeza del snake
  		switch(dir[j]){
    		case 1://arriba
      			y[j][0] = y[j][0]-1;
      		break;
    		case 2://abajo
    			y[j][0] = y[j][0]+1;
		    break;
    		case 3://izquierda
      			x[j][0] = x[j][0]-1;
      		break;
    		case 4://derecha
      			x[j][0] = x[j][0]+1;
      		break;
  		}
  		//Guarda nuevas coordenadas de la cabeza de la snake
  		headX = x[j][0];
  		headY = y[j][0];
  		//printf("cabeza en %d %d\n", headY, headX);

  		//Comida
  		if(headX == fruitX && headY == fruitY){
  			tam[j]=tam[j]+1;

  			x[j][tam[j]-1] = tailX[j];
  			y[j][tam[j]-1] = tailY[j];

  			fruitFlag = 1;
  			//printf("put point jugador %d\n", j+1);
  			putPoints(j);
    		
    		if(tam[j] == MAX_SNAKE_LENGTH){     
    			//Guarda datos del ganador
      			win = 1;
      			numberWin = j;
      			break;
    		}
  		}
	}
	if(win != 1){
		//Guarda lista jugadores activos hasta el momento
		auxLosers[0] = numberLose[0]; auxLosers[1] = numberLose[1]; auxLosers[2] = numberLose[2]; auxLosers[3]=numberLose[3];
		//Pinta las snakes a partir de jugador 1 ascendiendo
		for(j=0; j<numJ; j++){
			//Saltar en caso de que ya halla perdido
			if(auxLosers[j]==1)
				continue;
			//Cuando crece la cola permanece en el lugar que estaba antes
			if(y[j][0] == fruitY && x[j][0] == fruitX)
  				aux = tam[j]-1;
  			else
  				aux = tam[j];
  			//pinta snake en curso
			for(i=0; i<aux; i++){
   				auxX2 = x[j][i];
				auxY2 = y[j][i];
				//verifica ademas que no sea la fruta
				if(matrixLed[auxY2][auxX2] == 1 && auxX2!=fruitX && auxY2 != fruitY){
					numberLose[j] = 1;
					break;
				}
				else
 					matrixLed[auxY2][auxX2] = 1;
			}
		}
		//Borra las snakes
		for(j=0; j<numJ; j++){
			//Saltar en caso de que ya halla perdido
			if(auxLosers[j]==1)
				continue;
			for(i=0; i<tam[j]; i++){
    			auxX2 = x[j][i];
  				auxY2 = y[j][i];
  				matrixLed[auxY2][auxX2] = 0;
  			}
		}
		//Pinta las snakes a partir de jugador 4 o el ultimo descendiendo
		j = numJ-1;
        while(j>=0){
            if(j == 0)
                break;
            else
                j = j-1;
            
            //while(Busy1USART());
            //sprintf(buffer,"%d muero\n",j);
            //puts1USART(buffer);
        
			//Saltar en caso de que ya halla perdido
			if(auxLosers[j]==1)
				continue;
			//Cuando crece la cola permanece en el lugar que estaba antes
			if(y[j][0] == fruitY && x[j][0] == fruitX)
  				aux = tam[j]-1;
  			else
  				aux = tam[j];

  			//pinta snake en curso
			for(i=0; i<aux; i++){
    			auxX2 = x[j][i];
  				auxY2 = y[j][i];
  				//verifica ademas que no sea la fruta
  				if(matrixLed[auxY2][auxX2] == 1 && auxX2!=fruitX && auxY2 != fruitY){
  					numberLose[j] = 1;
  					break;
  				}
  				else
	  				matrixLed[auxY2][auxX2] = 1;
  			}
		}
		//Borra las snakes
		for(j=0; j<numJ; j++){
			//Saltar en caso de que ya halla perdido
			if(auxLosers[j]==1)
				continue;
			for(i=0; i<tam[j]; i++){
    			auxX2 = x[j][i];
  				auxY2 = y[j][i];
  				matrixLed[auxY2][auxX2] = 0;
  			}
		}
		//pinta snakes finales
		for(j=0; j<numJ; j++){
			//Saltar en caso de que ya halla perdido
			if(numberLose[j]==1)
				continue;
			//Cuando crece la cola permanece en el lugar que estaba antes
			if(y[j][0] == fruitY && x[j][0] == fruitX)
  				aux = tam[j]-1;
  			else
  				aux = tam[j];
  			//pinta snake en curso
			for(i=0; i<aux; i++){
    			auxX2 = x[j][i];
  				auxY2 = y[j][i];
  				matrixLed[auxY2][auxX2] = 1;
  			}
		}
		pintaMuro();
		if(numberLose[0] == 1 && numberLose[1] == 1 && numberLose[2] == 1 && numberLose[3] == 1){
			gameover = 1;
		}
		if(fruitFlag==1){
			makeFruit();
			fruitFlag = 0;
		}

	}
}
void checkDir(char Njugador){
	for(j=0; j<Njugador; j++){
		if(dir[j] == 1 && dirC[j] != 2 && dirC[j] != 0){
			dir[j] = dirC[j];
		}
		if(dir[j] == 2 && dirC[j] != 1 && dirC[j] != 0){
			dir[j] = dirC[j];
		}
		if(dir[j] == 3 && dirC[j] != 4 && dirC[j] != 0){
			dir[j] = dirC[j];
		}
		if(dir[j] == 4 && dirC[j] != 3 && dirC[j] != 0){
			dir[j] = dirC[j];
		}
	}
}
void GameOverMat(){
	resetVariables();
	matrixLed[4][10] = 1; matrixLed[5][10] = 1; matrixLed[6][10] = 1; matrixLed[7][10] = 1; matrixLed[8][10] = 1; matrixLed[9][10] = 1; matrixLed[10][10] = 1;
	matrixLed[12][10] = 1; matrixLed[13][10] = 1; matrixLed[14][10] = 1; matrixLed[15][10] = 1; matrixLed[16][10] = 1; matrixLed[17][10] = 1; matrixLed[18][10] = 1;

	matrixLed[4][11] = 1; matrixLed[10][11] = 1; matrixLed[12][11] = 1; matrixLed[18][11] = 1; 

	matrixLed[4][12] = 1; matrixLed[7][12] = 1; matrixLed[10][12] = 1; matrixLed[12][12] = 1; matrixLed[18][12] = 1;

	matrixLed[4][13] = 1; matrixLed[7][13] = 1; matrixLed[8][13] = 1; matrixLed[9][13] = 1; matrixLed[10][13] = 1; matrixLed[12][13] = 1; matrixLed[13][13] = 1;
	matrixLed[14][13] = 1; matrixLed[15][13] = 1; matrixLed[16][13] = 1; matrixLed[17][13] = 1; matrixLed[18][13] = 1;

	matrixLed[4][15] = 1; matrixLed[5][15] = 1; matrixLed[6][15] = 1; matrixLed[7][15] = 1; matrixLed[8][15] = 1; matrixLed[9][15] = 1; matrixLed[10][15] = 1;
	matrixLed[12][15] = 1; matrixLed[13][15] = 1; matrixLed[14][15] = 1; matrixLed[15][15] = 1; matrixLed[16][15] = 1; matrixLed[17][15] = 1; matrixLed[18][15] = 1;

	matrixLed[4][16] = 1; matrixLed[7][16] = 1; matrixLed[18][16] = 1;

	matrixLed[4][17] = 1; matrixLed[7][17] = 1; matrixLed[18][17] = 1;

	matrixLed[4][18] = 1; matrixLed[5][18] = 1; matrixLed[6][18] = 1; matrixLed[7][18] = 1; matrixLed[8][18] = 1; matrixLed[9][18] = 1; matrixLed[10][18] = 1;
	matrixLed[12][18] = 1; matrixLed[13][18] = 1; matrixLed[14][18] = 1; matrixLed[15][18] = 1; matrixLed[16][18] = 1; matrixLed[17][18] = 1; matrixLed[18][18] = 1;

	matrixLed[4][20] = 1; matrixLed[5][20] = 1; matrixLed[6][20] = 1; matrixLed[7][20] = 1; matrixLed[8][20] = 1; matrixLed[9][20] = 1; matrixLed[10][20] = 1;
	matrixLed[12][20] = 1; matrixLed[13][20] = 1; matrixLed[14][20] = 1; matrixLed[15][20] = 1; matrixLed[16][20] = 1; matrixLed[17][20] = 1; matrixLed[18][20] = 1;

	matrixLed[4][21] = 1; matrixLed[12][21] = 1; matrixLed[15][21] = 1; matrixLed[18][21] = 1;

	matrixLed[4][22] = 1; matrixLed[5][22] = 1; matrixLed[6][22] = 1; matrixLed[7][22] = 1; matrixLed[8][22] = 1; matrixLed[9][22] = 1; matrixLed[10][22] = 1;
	matrixLed[12][22] = 1; matrixLed[15][22] = 1; matrixLed[18][22] = 1;

	matrixLed[4][23] = 1; matrixLed[12][23] = 1; matrixLed[15][23] = 1; matrixLed[18][23] = 1;

	matrixLed[4][24] = 1; matrixLed[5][24] = 1; matrixLed[6][24] = 1; matrixLed[7][24] = 1; matrixLed[8][24] = 1; matrixLed[9][24] = 1; matrixLed[10][24] = 1;

	matrixLed[4][26] = 1; matrixLed[5][26] = 1; matrixLed[6][26] = 1; matrixLed[7][26] = 1; matrixLed[8][26] = 1; matrixLed[9][26] = 1; matrixLed[10][26] = 1;
	matrixLed[12][26] = 1; matrixLed[13][26] = 1; matrixLed[14][26] = 1; matrixLed[15][26] = 1; matrixLed[16][26] = 1; matrixLed[17][26] = 1; matrixLed[18][26] = 1;

	matrixLed[4][27] = 1; matrixLed[7][27] = 1; matrixLed[10][27] = 1; matrixLed[12][27] = 1; matrixLed[15][27] = 1;

	matrixLed[4][28] = 1; matrixLed[7][28] = 1; matrixLed[10][28] = 1; matrixLed[12][28] = 1; matrixLed[13][28] = 1; matrixLed[15][28] = 1; 

	matrixLed[4][29] = 1; matrixLed[7][29] = 1; matrixLed[10][29] = 1; matrixLed[13][29] = 1; matrixLed[14][29] = 1; matrixLed[15][29] = 1; matrixLed[16][29] = 1;
	matrixLed[17][29] = 1; matrixLed[18][29] = 1;
}
void selecNjugMat(){
	resetVariables();
	for(i=0; i<40; i++){
		matrixLed[0][i] = 1;
		matrixLed[23][i] = 1;
		if(i<24){
			matrixLed[i][0] = 1;
			matrixLed[i][39] = 1;
		}
	}

	matrixLed[3][9] = 1; matrixLed[9][9] = 1; matrixLed[13][9] = 1; matrixLed[16][9] = 1; matrixLed[19][9] = 1;

	matrixLed[3][10] = 1; matrixLed[9][10] = 1; matrixLed[13][10] = 1; matrixLed[16][10] = 1; matrixLed[19][10] = 1;

	matrixLed[3][11] = 1; matrixLed[4][11] = 1; matrixLed[5][11] = 1; matrixLed[6][11] = 1; matrixLed[7][11] = 1; matrixLed[8][11] = 1; matrixLed[9][11] = 1;
	matrixLed[13][11] = 1; matrixLed[16][11] = 1; matrixLed[19][11] = 1;

	matrixLed[9][12] = 1; matrixLed[13][12] = 1; matrixLed[14][12] = 1; matrixLed[15][12] = 1; matrixLed[16][12] = 1; matrixLed[17][12] = 1;
	matrixLed[18][12] = 1; matrixLed[19][12] = 1;

	matrixLed[3][25] = 1; matrixLed[6][25] = 1; matrixLed[7][25] = 1; matrixLed[8][25] = 1; matrixLed[9][25] = 1; matrixLed[13][25] = 1; matrixLed[14][25] = 1;
	matrixLed[15][25] = 1; matrixLed[16][25] = 1;

	matrixLed[3][26] = 1; matrixLed[6][26] = 1; matrixLed[9][26] = 1; matrixLed[16][26] = 1;

	matrixLed[3][27] = 1; matrixLed[6][27] = 1; matrixLed[9][27] = 1; matrixLed[16][27] = 1;

	matrixLed[3][28] = 1; matrixLed[4][28] = 1; matrixLed[5][28] = 1; matrixLed[6][28] = 1; matrixLed[9][28] = 1; matrixLed[13][28] = 1; matrixLed[14][28] = 1;
	matrixLed[15][28] = 1; matrixLed[16][28] = 1; matrixLed[17][28] = 1; matrixLed[18][28] = 1; matrixLed[19][28] = 1;
}
char selecNjug(){
	char Njugador = 1;
	selecNjugMat();
	matrixLed[11][8] = 1; matrixLed[11][9] = 1; matrixLed[11][10] = 1; matrixLed[11][11] = 1; matrixLed[11][12] = 1; matrixLed[11][13] = 1;
	
    while(boton == 0){
        if(PORTCbits.RC7 == 1){ //boton de seleccion
                boton = 1;
        }
		if(boton == 1){
			break;
		}
        
        PORTCbits.RC0 = 0;
        PORTCbits.RC1 = 0;
        lectAX0 = ADC(14);
        
        PORTCbits.RC0 = 1;
        PORTCbits.RC1 = 0;
        lectAY1 = ADC(14);
        
        //1     
        int a  = 20;
        int b = 700;
        
        if(lectAX0 <= a && lectAY1 > a && lectAY1 < b) //derecha
            dirC[0]=4;
        if(lectAX0 >= b && lectAY1 > a && lectAY1 < b )//izq
            dirC[0]=3;
        if(lectAY1 <= a && lectAX0 > a && lectAX0 < b )//arriba
            dirC[0]=1;
        if(lectAY1 >= b && lectAX0 > a && lectAX0 < b )//abajo
            dirC[0]=2;
        
        
        
		if(Njugador == 1 && dirC[0] == 4){
			matrixLed[11][8] = 0; matrixLed[11][9] = 0; matrixLed[11][10] = 0; matrixLed[11][11] = 0; matrixLed[11][12] = 0; matrixLed[11][13] = 0; //1
			matrixLed[11][24] = 1; matrixLed[11][25] = 1; matrixLed[11][26] = 1; matrixLed[11][27] = 1; matrixLed[11][28] = 1; matrixLed[11][29] = 1; //2
			Njugador = 2;
		}
		else if(Njugador == 3 && dirC[0] == 4){
			matrixLed[21][8] = 0; matrixLed[21][9] = 0; matrixLed[21][10] = 0; matrixLed[21][11] = 0; matrixLed[21][12] = 0; matrixLed[21][13] = 0; //3
			matrixLed[21][24] = 1; matrixLed[21][25] = 1; matrixLed[21][26] = 1; matrixLed[21][27] = 1; matrixLed[21][28] = 1; matrixLed[21][29] = 1; //4
			Njugador = 4;
		}
		else if(Njugador == 1 && dirC[0] == 2){
			matrixLed[11][8] = 0; matrixLed[11][9] = 0; matrixLed[11][10] = 0; matrixLed[11][11] = 0; matrixLed[11][12] = 0; matrixLed[11][13] = 0;
			matrixLed[21][8] = 1; matrixLed[21][9] = 1; matrixLed[21][10] = 1; matrixLed[21][11] = 1; matrixLed[21][12] = 1; matrixLed[21][13] = 1;
			Njugador = 3;
		}
		else if(Njugador == 2 && dirC[0] == 2){
			matrixLed[11][24] = 0; matrixLed[11][25] = 0; matrixLed[11][26] = 0; matrixLed[11][27] = 0; matrixLed[11][28] = 0; matrixLed[11][29] = 0;
			matrixLed[21][24] = 1; matrixLed[21][25] = 1; matrixLed[21][26] = 1; matrixLed[21][27] = 1; matrixLed[21][28] = 1; matrixLed[21][29] = 1;
			Njugador = 4;
		}
		else if(Njugador == 2 && dirC[0] == 3){
			matrixLed[11][24] = 0; matrixLed[11][25] = 0; matrixLed[11][26] = 0; matrixLed[11][27] = 0; matrixLed[11][28] = 0; matrixLed[11][29] = 0;
			matrixLed[11][8] = 1; matrixLed[11][9] = 1; matrixLed[11][10] = 1; matrixLed[11][11] = 1; matrixLed[11][12] = 1; matrixLed[11][13] = 1; //1
			Njugador = 1;
		}
		else if(Njugador == 3 && dirC[0] == 1){
			matrixLed[21][8] = 0; matrixLed[21][9] = 0; matrixLed[21][10] = 0; matrixLed[21][11] = 0; matrixLed[21][12] = 0; matrixLed[21][13] = 0; //3
			matrixLed[11][8] = 1; matrixLed[11][9] = 1; matrixLed[11][10] = 1; matrixLed[11][11] = 1; matrixLed[11][12] = 1; matrixLed[11][13] = 1; //1
			Njugador = 1;
		}
		else if(Njugador == 4 && dirC[0] == 1){
			matrixLed[21][24] = 0; matrixLed[21][25] = 0; matrixLed[21][26] = 0; matrixLed[21][27] = 0; matrixLed[21][28] = 0; matrixLed[21][29] = 0; //4
			matrixLed[11][24] = 1; matrixLed[11][25] = 1; matrixLed[11][26] = 1; matrixLed[11][27] = 1; matrixLed[11][28] = 1; matrixLed[11][29] = 1; //2
			Njugador = 2;
		}
		else if(Njugador == 4 && dirC[0] == 3){
			matrixLed[21][24] = 0; matrixLed[21][25] = 0; matrixLed[21][26] = 0; matrixLed[21][27] = 0; matrixLed[21][28] = 0; matrixLed[21][29] = 0; //4
			matrixLed[21][8] = 1; matrixLed[21][9] = 1; matrixLed[21][10] = 1; matrixLed[21][11] = 1; matrixLed[21][12] = 1; matrixLed[21][13] = 1;
			Njugador = 3;
		}
		else{
			Njugador = Njugador;
		}

		//imprime la matriz
    	
        createStringMat();
    
        //while(Busy1USART());
        //puts1USART(printing);         
	}
    //createStringMat();
	return Njugador;
}

void InicializeSnake(char Njugador){

	resetVariables();
	pintaMuro();
	pintaSnake(Njugador);	
	makeFruit();
	InicializePoints();
}
void RunSanke(char Njugador){

	if(win==0 && gameover==0){
		checkDir(Njugador);
		nextstep(Njugador);
	}
	else{
		if(win==1){
			//printf("You win\n");
		}
		if(gameover==1){
			//printf("Gameover\n");
            //while(Busy1USART());
            //sprintf(buffer,"You lose\n");
            //puts1USART(buffer);
			
            GameOverMat();
		}
	}
}

void matDedo(){


	  resetVariables();

	  matrixLed[13][5] = 1; matrixLed[14][5] = 1; matrixLed[15][5] = 1; matrixLed[16][5] = 1; matrixLed[17][5] = 1; matrixLed[18][5] = 1;

	  matrixLed[13][6] = 1; matrixLed[14][6] = 1; matrixLed[15][6] = 1; matrixLed[16][6] = 1; matrixLed[17][6] = 1; matrixLed[18][6] = 1; matrixLed[19][6] = 1; 

	  matrixLed[13][7] = 1; matrixLed[14][7] = 1; matrixLed[15][7] = 1; matrixLed[16][7] = 1; matrixLed[17][7] = 1; matrixLed[18][7] = 1; matrixLed[19][7] = 1;

	  
	  gif = gif+1;

	  if(gif < 5){	
	  	matrixLed[6][8] = 1; matrixLed[7][8] = 1; matrixLed[8][8] = 1; matrixLed[9][8] = 1; matrixLed[10][8] = 1; matrixLed[11][8] = 1; matrixLed[12][8] = 1; 
	  	matrixLed[6][9] = 1; matrixLed[7][9] = 1; matrixLed[8][9] = 1; matrixLed[9][9] = 1; matrixLed[10][9] = 1; matrixLed[11][9] = 1; matrixLed[12][9] = 1; 
	  }
	  if(gif >= 5 && gif <10){	
	  	matrixLed[9][8] = 1; matrixLed[10][8] = 1; matrixLed[11][8] = 1; matrixLed[12][8] = 1; 
	  	matrixLed[9][9] = 1; matrixLed[10][9] = 1; matrixLed[11][9] = 1; matrixLed[12][9] = 1; 
	  }
	  if(gif == 15 ){	
	  	gif = 0;
	  }

	  matrixLed[13][8] = 1; matrixLed[14][8] = 1; matrixLed[15][8] = 1; matrixLed[16][8] = 1; matrixLed[17][8] = 1; matrixLed[18][8] = 1; matrixLed[19][8] = 1; 

	  matrixLed[13][9] = 1; matrixLed[14][9] = 1; matrixLed[15][9] = 1; matrixLed[16][9] = 1; matrixLed[17][9] = 1; matrixLed[18][9] = 1; matrixLed[19][9] = 1; 

	  matrixLed[13][10] = 1; matrixLed[14][10] = 1; matrixLed[15][10] = 1; matrixLed[16][10] = 1; matrixLed[17][10] = 1; matrixLed[18][10] = 1; matrixLed[19][10] = 1;

	  matrixLed[13][11] = 1; matrixLed[14][11] = 1; matrixLed[15][11] = 1; matrixLed[16][11] = 1; matrixLed[17][11] = 1; matrixLed[18][11] = 1; matrixLed[19][11] = 1;

	  matrixLed[13][12] = 1; matrixLed[14][12] = 1; matrixLed[15][12] = 1; matrixLed[16][12] = 1; matrixLed[17][12] = 1; matrixLed[18][12] = 1;

}
//col maximo 40, fil maximo 3
unsigned char convertByte(char fil, char col){
	unsigned char byteCon = 0;
	//byteCon = matrixLed[fil*8][col]*128 + matrixLed[fil*8+1][col]*64 + matrixLed[fil*8+2][col]*32 + matrixLed[fil*8+3][col]*16 + matrixLed[fil*8+4][col]*8 + matrixLed[fil*8+5][col]*4 + matrixLed[fil*8+6][col]*2 + matrixLed[fil*8+7][col];
    byteCon = matrixLed[fil*8][col] + matrixLed[fil*8+1][col]*2 + matrixLed[fil*8+2][col]*4 + matrixLed[fil*8+3][col]*8 + matrixLed[fil*8+4][col]*16 + matrixLed[fil*8+5][col]*32 + matrixLed[fil*8+6][col]*64 + matrixLed[fil*8+7][col]*128;
	return byteCon;
}
void createStringMat(){
	for(i = 0; i<3; i++){
		for(j = 0; j<40; j++){
			MatrizDisplay[i][j] = convertByte(i, j);
		}
	}
    /*//desplaza a la izquierda toda la matriz
    i = 2;
    while(i>=0){
        j = 40;
        while(j>0){
			MatrizDisplay[i][j] = MatrizDisplay[i][j-1];
            j = j-1;
		}
        i = i-1;
	}*/  
}

void main(void)
{
    SYSTEM_Initialize();   
    
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    
    //resetVariables(); 
    //matDedo();
    //GameOverMat();
    //selecNjugMat();
    //createStringMat();

    dirC[0] = 0;
    dirC[1] = 0;
    dirC[2] = 0;
    dirC[3] = 0;
    
    char Njugador=1;
	Njugador = selecNjug();   
	InicializeSnake(Njugador);
	/*
     envia la matriz via uart
	*/
    createStringMat();
    //while(Busy1USART());
    //puts1USART(printing);
    
	while(1){
        
        //if(boton == 1){
            GenerateDir();
        
            RunSanke(Njugador); //NOTA: hay que implementar random para fruit
            /*
            envia la matriz via uart
            */
            createStringMat();
            //resetVariables();
            //matDedo();
            //selecNjugMat();
            //createStringMat();
        //}
        
        while(Busy1USART());
        sprintf(buffer,"%x %x %x %x %x\n",MatrizDisplay[0][0], MatrizDisplay[0][1], MatrizDisplay[0][2], MatrizDisplay[0][3], MatrizDisplay[0][4]);
        puts1USART(buffer);
        
        for(int i = 0; i< 25; i++) buffer[i] = 0;
        
        //while(Busy1USART());
        //puts1USART(" ");
        //printing[120] = '\n';

		//delay de velocidad del snake
       
        //while(Busy1USART());
        //puts1USART("***ABCDABCDABCDABCDABCDABCDABCDABCDABCDABCDABCDABCDABCDABCDABCDABCDABCDABCDABCDABCDABCDABCDABCDABCDABCDABCDABCDABCDABCDABCD");
        //10
        __delay_ms(100);
	}
}
/**
 End of File
*/