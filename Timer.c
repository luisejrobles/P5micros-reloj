#define INTR 8 /* Utilizar el vector adecuado */
volatile static unsigned char SecFlag; /*Bandera para indicar el Seg. */
extern void pokeW(unsigned int segment,unsigned int offset, unsigned int data);


/* Manejador de Interrupcion: ocurre 20 veces por segundo */
void interrupt ManejadorISR( void ){
	static unsigned char ContSec = 0;

	ContSec++; /* Conteo de Ticks */
	
	if(ContSec == 20){	/* Validando segundos*/
		SecFlag=1;
		ContSec = 0;
	}	
} 

unsigned char TimerSecFlag(void){
	if( SecFlag == 1 ){
		SecFlag = 0;
		return 1;
	}else
		return 0;
}

void Timer_Ini(void){
	SecFlag=0;
	/* Inicializarvector --faltapokeW(WORD segment, WORD offset, WORD value) -- */
	pokeW(0x0,INTR*4,((unsigned int)&ManejadorISR)+0x100); /* Determinar offset */
	pokeW(0x0,INTR*4+2,_CS);
}


