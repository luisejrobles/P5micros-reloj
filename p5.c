#include "Timer.h"
#define BYTE unsigned char

void Delay( BYTE );
void DisplayClock( void );
extern void pokeb(unsigned int segment,unsigned int offset, unsigned int data);
extern void putchar(char dato);
void PrintDec2d( BYTE );
void SetClock(BYTE hora, BYTE minutos, BYTE segundos);
void UpdateClock( void );

BYTE seg=0; /* para el manejo de los segundos */
BYTE min=0; /*minutos*/
BYTE horas=0; /*horas*/

void main(){
	Timer_Ini(); /* inicialzaTimer de 1 segundo */
	pokeb(0,0xFFFF,0);
	SetClock(23,59,0);
	while(1){
		/* Verificación para actualizar el reloj */
		if(TimerSecFlag() ==1){ /* Ha pasado un segundo? */
			UpdateClock(); /* actualiza y muestra el reloj */
			DisplayClock(); /* desplegar reloj en 0,0 */
			/* indicar en puerto */
			putchar('.'); /* Imprime */
			Delay(100);
		}
			/* otras cosas por hacer */
			pokeb(0,0xFFFF,seg);
	};
} 

void SetClock(BYTE hora, BYTE minutos, BYTE segundos)
{
	seg=segundos;
	min=minutos;
	horas=hora;

}

void UpdateClock( void ){
	seg=(++seg%60);
	if(seg == 0)
	{
		min=(++min%60);
		if(min == 0)
		{
			horas=(++horas%24);
		}
	}
}

void DisplayClock( void ){
	/* imprimir reloj en formato "hh:mm:ss" */;
	putchar(10);
	putchar(13);
	PrintDec2d(horas);
	putchar(':');
	PrintDec2d(min);
	putchar(':');
	PrintDec2d(seg); 
}

void Delay( BYTE i){
	while(--i);
}

void PrintDec2d( BYTE dato){
	putchar( dato/10 +'0'); /* Imprime decenas */
	putchar( dato%10 +'0'); /* Imprime unidades */
}

