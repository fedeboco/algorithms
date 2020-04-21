#include <stdio.h>
#define MASK_INVERTER 0x70 /*0111 0000*/
#define MAX_STRING 8
#define RANDOM_CHAR 'W'

int main(void){
	unsigned char reg=RANDOM_CHAR; /*0x41 equivalente a 0100 0001*/
	
	reg=reg&(~MASK_INVERTER); /*0100 0001 & 1000 1111* = 0000 0001*/
	fprintf(stdout, "%c\n", reg); /*imprime 0x0001*/

	return 0;
}

/*HACER UN CASTEO A INT Y CONVERTIRLO A BINARIO PARA IMPRIMIRLO!*/
