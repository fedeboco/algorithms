#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include "setup.h"
#include "mensajes.h"
#include "types.h"
#include "prototypes.h"

int main (void){
	char msj_resistor_1[MAX_MSJ]=MSJ_RESISTOR_1;
	char msj_resistor_2[MAX_MSJ]=MSJ_RESISTOR_2;
	char msj_resistor_3[MAX_MSJ]=MSJ_RESISTOR_3;
	char msj_capacidad[MAX_MSJ]=MSJ_CAPACIDAD;
	char msj_frecuencia[MAX_MSJ]=MSJ_FRECUENCIA;
	double val_r1, val_r2, val_r3, val_frec, val_cap;
	main_menu_status_t st=0;
	main_menu_option_t opc_menu_ppal;
	freq_menu_option_t opc_menu_frecuencia;
	factor_menu_option_t opc_menu_factor_calidad;
	
	while(st!=ST_END){
		switch(st){
			case ST_IDLE:
				st=ST_MAIN_MENU; 
				break;
			case ST_MAIN_MENU:
				imprimir_menu_ppal();
				opc_menu_ppal=obtener_opcion_main_menu();
				switch(opc_menu_ppal){
					case OPC_MENU_FREQ:
						st=ST_MENU_FREQUENCY;
						break;
					case OPC_MENU_Q_FACTOR:
						st=ST_MENU_Q_FACTOR;
						break;
					case OPC_END:
						st=ST_END;
						break;
					case ERR_OPCION_INVALIDA_MENU_PPAL:
						fprintf(stderr,"\n%s\n",ERROR_OPCION);
						st=ST_MAIN_MENU;
						break;
					default: EXIT_FAILURE;
						break;
				}
				break;
			case ST_MENU_FREQUENCY:
				imprimir_menu_frecuencia();
				opc_menu_frecuencia=obtener_opcion_menu_frecuencia();
				switch(opc_menu_frecuencia){
					case OPC_CALCULAR_FRECUENCIA:
						leer_valor_resistor(msj_resistor_1,&val_r1);
						leer_valor_resistor(msj_resistor_2,&val_r2);
						leer_valor_resistor(msj_resistor_3,&val_r3);
						leer_valor_capacidad(msj_capacidad,&val_cap);
						fprintf(stdout,
								"\n%f",
								calcular_frecuencia(val_r1,
													val_r2,
													val_r3,
													val_cap)
								);
						st=ST_MAIN_MENU;
						break;
					case OPC_CALCULAR_R1:
						leer_valor_frecuencia(msj_frecuencia,&val_frec);
						leer_valor_resistor(msj_resistor_2,&val_r2);
						leer_valor_resistor(msj_resistor_3,&val_r3);
						leer_valor_capacidad(msj_capacidad,&val_cap);
						fprintf(stdout,
								"\n%f",
								calcular_resistor_1(val_frec,
													val_r2,
													val_r3,
													val_cap)
								);
						st=ST_MAIN_MENU;
						break;
					case OPC_CALCULAR_R2:
						leer_valor_frecuencia(msj_frecuencia,&val_frec);
						leer_valor_resistor(msj_resistor_1,&val_r1);
						leer_valor_resistor(msj_resistor_3,&val_r3);
						leer_valor_capacidad(msj_capacidad,&val_cap);
						fprintf(stdout,
								"\n%f",
								calcular_resistor_2(val_frec,
													val_r1,
													val_r3,
													val_cap)
								);
						st=ST_MAIN_MENU;
						break;
					case OPC_CALCULAR_R3:
						leer_valor_frecuencia(msj_frecuencia,&val_frec);
						leer_valor_resistor(msj_resistor_1,&val_r1);
						leer_valor_resistor(msj_resistor_2,&val_r2);
						leer_valor_capacidad(msj_capacidad,&val_cap);
						fprintf(stdout,
								"\n%f",
								calcular_resistor_3(val_frec,
													val_r1,
													val_r2,
													val_cap)
								);
						st=ST_MAIN_MENU;
						break;
					case OPC_CALCULAR_CAPACIDAD:
						leer_valor_frecuencia(msj_frecuencia,&val_frec);
						leer_valor_resistor(msj_resistor_1,&val_r1);
						leer_valor_resistor(msj_resistor_2,&val_r2);
						leer_valor_resistor(msj_resistor_3,&val_r3);
						fprintf(stdout,
								"\n%f",
								calcular_capacidad(val_frec,
												   val_r1,
												   val_r2,
												   val_r3)
								);
						st=ST_MAIN_MENU;
						break;
					case ERR_OPCION_INVALIDA_FREQ:
						fprintf(stderr,"\n%s\n",ERROR_OPCION);
						break;
					case OPC_VOLVER_MENU_PPAL:
						st=ST_MAIN_MENU;
						break;
					default: return EXIT_FAILURE;
				}
				break;
			case ST_MENU_Q_FACTOR:
				imprimir_menu_factor_calidad();
				opc_menu_factor_calidad=obtener_opcion_menu_factor();
				switch(opc_menu_factor_calidad){
					case OPC_CALCULAR_FACTOR:
						leer_valor_resistor(msj_resistor_1,&val_r1);
						leer_valor_resistor(msj_resistor_2,&val_r2);
						leer_valor_resistor(msj_resistor_3,&val_r3);
						fprintf(stdout,
								"\n%f",
								calcular_factor_calidad(val_r1,
														val_r2,
														val_r3)
								);
						break;
					case OPC_MENU_PPAL:
						st=ST_MAIN_MENU;
						break;
					case ERR_OPCION_INVALIDA_FACTOR:
						fprintf(stderr,"\n%s\n",ERROR_OPCION);
						break;
					default: return EXIT_FAILURE;
				}
				break;
			default: EXIT_FAILURE;
		}
	}
	return EXIT_SUCCESS;
}				

main_menu_option_t obtener_opcion_main_menu(void){
	char line[MAX_STR];
	size_t i;
	main_menu_option_t opcion_seleccionada;
	
	fgets(line,MAX_DIG_OPC_MAIN_MENU+2,stdin);
	for(i=0;i<MAX_DIG_OPC_MAIN_MENU;i++){
		if(!isdigit(line[i])){
			return ERR_OPCION_INVALIDA_MENU_PPAL;
		}
	}
	opcion_seleccionada=atoi(line);
	if((opcion_seleccionada<=0)||(opcion_seleccionada>CANTIDAD_OPCIONES_MAIN_MENU)){
		return ERR_OPCION_INVALIDA_MENU_PPAL;
	}
	return opcion_seleccionada;
}

freq_menu_option_t obtener_opcion_menu_frecuencia(void){
	char line[MAX_STR];
	size_t i;
	freq_menu_option_t opcion_seleccionada;
	
	fgets(line,MAX_DIG_OPC_FREQ_MENU+2,stdin);
	for(i=0;i<MAX_DIG_OPC_FREQ_MENU;i++){
		if(!isdigit(line[i])){
			return ERR_OPCION_INVALIDA_FREQ;
		}
	}
	opcion_seleccionada=atoi(line);
	if((opcion_seleccionada<=0)||(opcion_seleccionada>CANTIDAD_OPCIONES_MENU_FREC)){
		return ERR_OPCION_INVALIDA_FREQ;
	}
	return opcion_seleccionada;
}

factor_menu_option_t obtener_opcion_menu_factor(void){
	char line[MAX_STR];
	size_t i;
	factor_menu_option_t opcion_seleccionada;
	
	fgets(line,MAX_DIG_OPC_FACTOR_MENU+2,stdin);
	for(i=0;i<MAX_DIG_OPC_FACTOR_MENU;i++){
		if(!isdigit(line[i])){
			return ERR_OPCION_INVALIDA_FACTOR;
		}
	}
	opcion_seleccionada=atoi(line);
	if((opcion_seleccionada<=0)||(opcion_seleccionada>CANTIDAD_OPCIONES_MENU_FACTOR_CAL)){
		return ERR_OPCION_INVALIDA_FACTOR;
	}
	return opcion_seleccionada;
}

status_t imprimir_menu_ppal(void){
	fprintf(stdout,"\n%s",MSJE_MENU_PPAL);
	fprintf(stdout,"\n%s",MSJE_FREC_MENU_PPAL);
	fprintf(stdout,"\n%s",MSJE_FACT_CALIDAD_MENU_PPAL);
	fprintf(stdout,"\n%s",MSJE_SALIR);
	puts("");
	return OK;
}

status_t imprimir_menu_frecuencia(void){
	fprintf(stdout,"\n%s",MSJE_CALCULAR_FREC);
	fprintf(stdout,"\n%s",MSJE_CALCULAR_RESISTOR_1);
	fprintf(stdout,"\n%s",MSJE_CALCULAR_RESISTOR_2);
	fprintf(stdout,"\n%s",MSJE_CALCULAR_RESISTOR_3);
	fprintf(stdout,"\n%s",MSJE_CALCULAR_CAPACIDAD);
	fprintf(stdout,"\n%s",MSJE_VOLVER_MENU_PPAL_FREC);
	puts("");
	return OK;
}

status_t imprimir_menu_factor_calidad(void){
	fprintf(stdout,"\n%s",MSJE_CALCULAR_FACTOR_CALIDAD);
	fprintf(stdout,"\n%s",MSJE_VOLVER_MENU_PPAL_FACTOR);
	puts("");
	return OK;
}
	
status_t leer_valor_resistor(const char * msj, double * val){
	char str[MAX_STR]; char * temp;
	
	if (msj==NULL||val==NULL);
	puts(msj);
	if(fgets(str, MAX_STR, stdin)==NULL) 
		return ERR_DATO_INVALIDO;
	*val=strtod(str,&temp);
	if(*temp&&*temp!='\n')
		return ERR_DATO_INVALIDO;
	if(*val<MIN_VALOR_RESISTENCIA)
		return ERR_RESISTOR_INVALIDO;
	if(*val>MAX_VALOR_RESISTENCIA)
		return ERR_RESISTOR_INVALIDO;
	return OK;
}

status_t leer_valor_frecuencia(const char * msj, double * val){
	char str[MAX_STR]; char * temp;
	
	if (msj==NULL||val==NULL);
	puts(msj);
	if(fgets(str, MAX_STR, stdin)==NULL) 
		return ERR_DATO_INVALIDO;
	*val=strtod(str,&temp);
	if(*temp&&*temp!='\n')
		return ERR_DATO_INVALIDO;
	if(*val<MIN_VALOR_FRECUENCIA)
		return ERR_FRECUENCIA_INVALIDA;
	if(*val>MAX_VALOR_FRECUENCIA)
		return ERR_FRECUENCIA_INVALIDA;
	return OK;
}

status_t leer_valor_capacidad(const char * msj, double * val){
	char str[MAX_STR]; char * temp;
	
	if (msj==NULL||val==NULL);
	puts(msj);
	if(fgets(str, MAX_STR, stdin)==NULL) 
		return ERR_DATO_INVALIDO;
	*val=strtod(str,&temp);
	if(*temp&&*temp!='\n')
		return ERR_DATO_INVALIDO;
	if(*val<MIN_VALOR_CAPACIDAD)
		return ERR_CAPACIDAD_INVALIDA;
	if(*val>MAX_VALOR_CAPACIDAD)
		return ERR_CAPACIDAD_INVALIDA;
	*val=(*val)*1000000000; /*conv. de nF a F*/
	return OK;
}

double calcular_frecuencia(	double resistor_1, 
							double resistor_2,
							double resistor_3,
							double capacidad){
	double frecuencia=0;
	frecuencia = (sqrt(1+resistor_1/resistor_3))/
				 (CTE_2PI*capacidad*sqrt(resistor_1*resistor_2));
	return frecuencia;
}

double calcular_capacidad(	double frecuencia, 
							double resistor_1, 
							double resistor_2,
							double resistor_3){
	double capacidad=0;
     
	capacidad = (sqrt(1+resistor_1/resistor_3))/
                (CTE_2PI*frecuencia*sqrt(resistor_1*resistor_2));
    return capacidad;
}

double calcular_resistor_1(	double frecuencia, 
							double resistor_2,
							double resistor_3,
							double capacidad){
	double resistor_1=0;
	
	resistor_1 = 1/(CTE_2PI*CTE_2PI*capacidad*capacidad*frecuencia*
		 frecuencia*resistor_2-1/resistor_3);
	return resistor_1;
}

double calcular_resistor_2(	double frecuencia, 
							double resistor_1, 
							double resistor_3,
							double capacidad){
	double resistor_2=0;
	
	resistor_2 = (1+resistor_1/resistor_3)/(resistor_1*CTE_2PI*CTE_2PI*
		 capacidad*capacidad*frecuencia*frecuencia);
	return resistor_2;
}

double calcular_resistor_3(	double frecuencia, 
							double resistor_1, 
							double resistor_2,
							double capacidad){
    double resistor_3=0;
 
	resistor_3 = resistor_1*resistor_2/(CTE_2PI*CTE_2PI*capacidad*capacidad*frecuencia*
         frecuencia*resistor_1-resistor_2);
        return resistor_3;
}

double calcular_factor_calidad(	double resistor_1, 
								double resistor_2,
								double resistor_3){
	double factor_q=0;

	factor_q = sqrt(resistor_2/resistor_1*
			   (1+resistor_1/resistor_3))/2;
	return factor_q;
}