#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MASK_ATTACK 0x70
#define MASK_SENSOR 0x80
#define MASK_RELEASE 0x0E
#define MASK_OUT 0x01
#define INITIAL_VALUE 01100100
#define LIGHT_ON 0x01
#define LIGHT_OFF 0x00

/*IN(sensor) ATTACK RELEASE OUT(prende)*/ /*1 3 3 1*/
/*OSCURO 100ms LUZ 15ms*/ 

typedef enum{OK, ERR_NULL_POINTER} status_t;

/*Prototypes============================*/
unsigned char verify_sunlight(const unsigned char);
/*======================================*/

int main(void){
	unsigned char reg=INITIAL_VALUE;
	
	while(MOTOR ON){
		if((verify_sunlight()==1)&&(LIGHT_ON==(MASK_OUT&reg))){ /*si hay luz natural y la luz esta prendida*/
			delay(15); /*esperar 15ms*/
			if((verify_sunlight()==1)&&(LIGHT_ON==(MASK_OUT&reg))){ /*volver a verificar*/
				reg=reg&(~MASK_OUT); /*apagar*/
			}
		}
		if((verify_sunlight()==0)&&(LIGHT_OFF==(MASK_OUT&reg))){ /*si NO hay luz natural y la luz esta apagada*/
			delay(100); /*esperar 100ms*/
			if((verify_sunlight()==0)&&(LIGHT_OFF==(MASK_OUT&reg))){ /*volver a verificar*/
				reg=reg|MASK_OUT; /*prender*/
			}
		}
	}
}

unsigned char verify_sunlight(const unsigned char reg){
	unsigned char light=0x00;
	if(reg&MASK_SENSOR)==LIGHT_ON) light=0x01;
	return light;
}

