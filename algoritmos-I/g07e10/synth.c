#include <stdio.h>
#include <math.h>
#define DATA 0xFA
#define RAND_FDIV 0x24
#define MASK_DIV 0x3E
#define MASK_BIT 0x01
#define MASK_BAND 0x40
#define SHIFT_DIV 0x01
#define SHIFT_BAND 6
#define MAX_DIV_VAL 5

typedef enum {BAND_AM=1, BAND_FM=0} band_t;
typedef enum {ERROR=1, OK=0} status_t;

/*PROTOTYPES=====================*/
unsigned char get_synthesizer_divider(unsigned char);
status_t set_synthesizer_divider(unsigned char, unsigned char*);
band_t get_band(unsigned char);
unsigned char set_band(unsigned char, band_t);
/*===============================*/

unsigned char get_synthesizer_divider(unsigned char data){
	unsigned char divider=0;size_t i;
	data=(data&MASK_DIV)>>SHIFT_DIV;
	for(i=0; i<MAX_DIV_VAL; i++) 
		divider+=((data&(MASK_BIT<<i)>>i)*pow(2,i));
	divider++;
	return divider;		
}
status_t set_synthesizer_divider(unsigned char fdiv, unsigned char * control){
	if(control==NULL) return ERROR;
	*control=*control&(~MASK_DIV); /*Pone todo DIV a 0*/
	*control=*control|(fdiv<<SHIFT_DIV);
	return OK;
}
band_t get_band(unsigned char data){
	band_t band;
	band=(data&MASK_BAND)?BAND_FM:BAND_AM;
	return band;
}
unsigned char set_band(unsigned char control, band_t new_band){
	control=control&(~MASK_BAND);
	switch(new_band){
		case BAND_FM: control=control&(~MASK_BAND);
			break;
		case BAND_AM: control=control|MASK_BAND;
			break;
		default: return 0;
	}
	return control;
}
int main(void){
	band_t new_band=0;
	unsigned char data=DATA;
	unsigned char fdiv=RAND_FDIV;
	unsigned char * control; control=&data;
	
	fprintf(stdout, "%d\n", get_synthesizer_divider(data));/*Imprime 32*/
	fprintf(stderr, "%d\n", set_synthesizer_divider(fdiv,control));/*Imprime 0 (OK)*/
	fprintf(stdout, "%X\n", *control);/*Imprime C8 (modificó FA)*/
	fprintf(stdout, "%X\n", get_band(data));/*Imprime 1 (AM)*/ 
	fprintf(stdout, "%X\n", set_band(data,new_band));/*Imprime 88 (modificó C8)*/
	return 0;
}
