/*
Ej.2, Guía 5.
----------------------------------------------------------- 
a) Definir un tipo enumerativo temperature_t que contenga los
símbolos TEMP_CELSIUS y TEMP_FARENHEIT.

b) Escribir una función que reciba un valor de temperatura y 
la escala de temperatura de destino, y realice la conversión 
del valor recibido (devolución por el nombre o por la interfaz).
*/

#include <stdio.h>
#include <string.h>
#define ERROR_MSG "ERROR."
#define USR_INPUT_MSG "Please, enter the input and output scales, once a time (C, for Celsius | F, for Farenheit):"
#define USR_OUTPUT_MSG "The conversion is: "
#define MAX_STRING 4
#define TEMP_INITIAL_VALUE 50

typedef enum {TEMP_CELSIUS=0, TEMP_FARENHEIT=1} temp_scale_t;
typedef float temp_data_t;
typedef char input_letter;

temp_data_t temp_conversion(temp_data_t, temp_scale_t,temp_scale_t); /*Prototype*/
temp_scale_t scale_assignment(input_letter);                      /*Prototype*/
        
int main(void){
	char string[MAX_STRING];
	char * s=string;
	unsigned short int i=0;
	temp_scale_t input_scale;
	temp_scale_t output_scale;
	temp_data_t user_temp=TEMP_INITIAL_VALUE;

	fprintf(stdout, "%s\n", USR_INPUT_MSG);
	for(i=0;i<=2;i++){
		string[i]=getchar();
	}
	input_scale=scale_assignment(*s);
        output_scale=scale_assignment(*(s+1));

	user_temp=temp_conversion(user_temp, input_scale, output_scale);
	fprintf(stdout, "%s%f\n", USR_OUTPUT_MSG, user_temp);
	return 0;
}
temp_scale_t scale_assignment(input_letter letter){
	temp_scale_t scale_assigned;
	
	if(letter==67){
		scale_assigned=TEMP_CELSIUS;
	}else{
                scale_assigned=TEMP_FARENHEIT;
	}
	return scale_assigned;
}
temp_data_t temp_conversion(temp_data_t temp,temp_scale_t input_scale,temp_scale_t output_scale){
	if (input_scale==output_scale){
		return temp;
	}else{
		switch(input_scale){
			case TEMP_CELSIUS: temp=32+(float)9/5*temp; break;
			case TEMP_FARENHEIT: temp=(float)5/9*(temp-32); break;
			default: fprintf(stderr, "%s", ERROR_MSG);
		}	
	}
	return temp;
}
