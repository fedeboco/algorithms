#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define UNIDADES_FRECUENCIA "Hz"
#define UNIDADES_RESISTENCIA "Ω"
#define UNIDADES_CAPACIDAD "nF"

#define R_MAX 5000000
#define R_MIN 100
#define C_MAX 10000 
#define C_MIN 1
#define F_MAX 1000000
#define F_MIN 1

#define CTE_2PI 6.28318
#define CONVERSION_FARADIOS 1000000000.0

#define MAX_DATOS 5
#define MAX_CADENA 10000

#define CADENA_REFERENCIA_FREC "frecuencia"
#define CADENA_REFERENCIA_R1 "r1"
#define CADENA_REFERENCIA_R2 "r2"
#define CADENA_REFERENCIA_R3 "r3"
#define CADENA_REFERENCIA_CAPACIDAD "capacidad"
#define CADENA_REFERENCIA_FACTOR_Q "factor de calidad"

#define MSJE_BIENVENIDA ">Calculadora de filtros pasabandas."
#define MSJE_OPCION ">MENU:"
#define MSJE_CALCULAR "- Calcular"
#define MSJE_SALIR "- Salir"
#define MSJE_DECISION "¿Qué desea hacer?"
#define MSJE_RESULTADO "El resultado es: "

#define MSJE_R1_SELECCIONADA ">Ingrese F(en Hz), R2(en Ω), R3(en Ω) y C(en nF) (oprima enter para cada valor):"
#define MSJE_R2_SELECCIONADA ">Ingrese F(en Hz), R1(en Ω), R3(en Ω) y C(en nF) (oprima enter para cada valor):"
#define MSJE_R3_SELECCIONADA ">Ingrese F(en Hz), R1(en Ω), R2(en Ω) y C(en nF) (oprima enter para cada valor):"
#define MSJE_CAPACIDAD_SELECCIONADA ">Ingrese F(en Hz), R1(en Ω), R2(en Ω) y R3(en Ω) (oprima enter para cada valor):"
#define MSJE_F_SELECCIONADA ">Ingrese R1(en Ω), R2(en Ω), R3(en Ω) y C(en nF) (oprima enter para cada valor):"
#define MSJE_Q_SELECCIONADO ">Ingrese R1(en Ω), R2(en Ω) y R3(en Ω); (oprima enter para cada valor):"

#define MSJE_USUARIO_SELECCION ">Puede calcular los siguiente parámetros:"
#define MSJE_USUARIO_FRECUENCIA "- Frecuencia | (1Hz < f < 1MHz)"
#define MSJE_USUARIO_R1 "- R1 |"
#define MSJE_USUARIO_R2 "- R2 | (100Ω < R < 5MΩ)"
#define MSJE_USUARIO_R3 "- R3 |"
#define MSJE_USUARIO_CAPACIDAD "- Capacidad | (1nF < C < 10pF)"
#define MSJE_USUARIO_FACTOR_Q "- Factor de Calidad"
#define MSJE_USUARIO_INGRESAR_INCOGNITA ">Introduzca el parámetro a calcular:"

/*Esquema del vector>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
					|Frecuencia|R1|R2|R3|Capacidad|
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

typedef enum {FRECUENCIA=0, R1=1, R2=2, R3=3, CAPACIDAD=4, FACTOR_Q=5} calculo_t;
typedef enum {ERR_VAL_NO_ADMITIDO=0, ERR_PUNTERO_NULO=1, OK=2} status_t;
typedef enum {SALIR, CALCULAR} opcion_t;

/*PROTOTIPOS============================================================*/
status_t leer(float [], calculo_t);
calculo_t elegir_incognita(void);
float calcular_incognita(float [],calculo_t);
void imprimir_resultado(float [],calculo_t);
void elegir_opcion(float []);
status_t strlwr(char []);
status_t verificar_datos(float []);

float calc_f(float [], calculo_t);
float calc_c(float [], calculo_t);
float calc_r1(float [], calculo_t);
float calc_r2(float [], calculo_t);
float calc_r3(float [], calculo_t);
float calc_q(float [], calculo_t);
/*======================================================================*/

int main(void)
{
	float datos[MAX_DATOS];
		
	elegir_opcion(datos);
	return 0;
}

void elegir_opcion(float datos[]){
	calculo_t tipo;
	opcion_t opcion_elegida=CALCULAR;
	char opcion_calcular[MAX_CADENA]="calcular";
	char opcion_salir[MAX_CADENA]="salir";
	char opcion_usuario[MAX_CADENA];
	
	if(datos==NULL) return;
	while(opcion_elegida==CALCULAR){
		fprintf(stdout, "\n%s\n%s\n\t%s\n\t%s\n\n%s ", 
							  MSJE_BIENVENIDA, 
							  MSJE_OPCION, 
							  MSJE_CALCULAR, 
							  MSJE_SALIR,
							  MSJE_DECISION
							  );
		fgets(opcion_usuario,MAX_CADENA,stdin); strlwr(opcion_usuario);
		if(strncmp(opcion_calcular,opcion_usuario,strlen(opcion_calcular))==0) 
		{
			opcion_elegida=CALCULAR;
			tipo=elegir_incognita();
			imprimir_resultado(datos,tipo);
			fgets(opcion_usuario,MAX_CADENA,stdin);
		}
		if(strncmp(opcion_salir,opcion_usuario,strlen(opcion_salir))==0) 
		{
			opcion_elegida=SALIR;
			break;
		}
	}
	return;
}

calculo_t elegir_incognita(void)
{
	calculo_t incognita;
	char cadena_frec[MAX_CADENA]=CADENA_REFERENCIA_FREC;
	char cadena_r1[MAX_CADENA]=CADENA_REFERENCIA_R1;
	char cadena_r2[MAX_CADENA]=CADENA_REFERENCIA_R2;
	char cadena_r3[MAX_CADENA]=CADENA_REFERENCIA_R3;
	char cadena_cap[MAX_CADENA]=CADENA_REFERENCIA_CAPACIDAD;
	char cadena_q[MAX_CADENA]=CADENA_REFERENCIA_FACTOR_Q;
	char sel_usuario[MAX_CADENA];
	
	fprintf(stdout,"\n%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\n%s ",
				MSJE_USUARIO_SELECCION,
				MSJE_USUARIO_FRECUENCIA,
				MSJE_USUARIO_R1,
				MSJE_USUARIO_R2,
				MSJE_USUARIO_R3,
				MSJE_USUARIO_CAPACIDAD,
				MSJE_USUARIO_FACTOR_Q,
				MSJE_USUARIO_INGRESAR_INCOGNITA
				);
	fgets(sel_usuario,MAX_CADENA,stdin); strlwr(sel_usuario);
	if(strncmp(sel_usuario,cadena_frec,strlen(cadena_frec))==0) incognita=FRECUENCIA;
	if(strncmp(sel_usuario,cadena_r1,strlen(cadena_r1))==0) incognita=R1;
	if(strncmp(sel_usuario,cadena_r2,strlen(cadena_r2))==0) incognita=R2;
	if(strncmp(sel_usuario,cadena_r3,strlen(cadena_r3))==0) incognita=R3;
	if(strncmp(sel_usuario,cadena_cap,strlen(cadena_cap))==0) incognita=CAPACIDAD;
	if(strncmp(sel_usuario,cadena_q,strlen(cadena_q))==0) incognita=FACTOR_Q;
	return incognita;
}

status_t leer(float datos[], calculo_t tipo)
{
	size_t i;
	
	if(datos==NULL) return ERR_PUNTERO_NULO;
		switch(tipo)
		{
			case FRECUENCIA:
				fprintf(stdout,"%s\n\n",MSJE_F_SELECCIONADA);
				for(i=0;i<MAX_DATOS;i++){
					if(i!=FRECUENCIA) scanf("%f", &datos[i]);
				} break;
			case R1:
                fprintf(stdout,"%s\n\n",MSJE_R1_SELECCIONADA);
                for(i=0;i<MAX_DATOS;i++){
                    if(i!=R1) scanf("%f", &datos[i]);
                } break;
			case R2:
                fprintf(stdout,"%s\n\n",MSJE_R2_SELECCIONADA);
                for(i=0;i<MAX_DATOS;i++){
                    if(i!=R2) scanf("%f", &datos[i]);
                } break;
			case R3:
                fprintf(stdout,"%s\n\n",MSJE_R3_SELECCIONADA);
                for(i=0;i<MAX_DATOS;i++){
                    if(i!=R3) scanf("%f", &datos[i]);
                } break;
			case CAPACIDAD:
                fprintf(stdout,"%s\n\n",MSJE_CAPACIDAD_SELECCIONADA);
                for(i=0;i<MAX_DATOS;i++){
                    if(i!=CAPACIDAD) scanf("%f", &datos[i]);
                } break;
			case FACTOR_Q:
                fprintf(stdout,"%s\n\n",MSJE_Q_SELECCIONADO);
                for(i=0;i<MAX_DATOS;i++){
                    if((i!=CAPACIDAD)&&(i!=FRECUENCIA)) scanf("%f", &datos[i]);
                } break;
			default: return 0;	
		}
	datos[C_POS]=datos[C_POS]/CONVERSION_FARADIOS;
	verificar_datos(datos);
	return OK;
}

float calcular_incognita(float datos [],calculo_t tipo)
{
	float resultado=0;
	
	if(datos==NULL) return 0;
	switch(tipo){
		case FRECUENCIA:
			leer(datos,tipo); resultado = calc_f(datos,tipo); break;
		case R1:
			leer(datos,tipo); resultado = calc_r1(datos,tipo); break;
		case R2:
			leer(datos,tipo); resultado = calc_r2(datos,tipo); break;
		case R3:
			leer(datos,tipo); resultado = calc_r3(datos,tipo); break;
		case CAPACIDAD:
			leer(datos,tipo); resultado = calc_c(datos,tipo); break;
		case FACTOR_Q:
			leer(datos,tipo); resultado = calc_q(datos,tipo); break;
		default: return 0;
	}
	return resultado;
}

status_t verificar_datos(float datos []){
	size_t i;
	
	if(datos==NULL) return ERR_PUNTERO_NULO;
	if((datos[F_POS]>F_MAX)||(datos[F_POS])<F_MIN) return ERR_VAL_NO_ADMITIDO;
	for(i=R1_POS;i<=R3_POS;i++){
		if((datos[i]>R_MAX)||(datos[i])<R_MIN) return ERR_VAL_NO_ADMITIDO;
	}
	return OK;
}

void imprimir_resultado(float datos[],calculo_t tipo){
	
	if(datos==NULL) return;
	fprintf(stdout, "\n%s %f", MSJE_RESULTADO, calcular_incognita(datos,tipo)); 
	switch(tipo){
		case FRECUENCIA:
			fprintf(stdout," %s\n",UNIDADES_FRECUENCIA); break;
		case R1:
            fprintf(stdout," %s\n",UNIDADES_RESISTENCIA); break;
        case R2:
            fprintf(stdout," %s\n",UNIDADES_RESISTENCIA); break;
		case R3:
            fprintf(stdout," %s\n",UNIDADES_RESISTENCIA); break;                    
        case CAPACIDAD:
            fprintf(stdout," %s\n",UNIDADES_CAPACIDAD); break; 
        case FACTOR_Q:
            break;
		default: return;
	}
	return;
}

float calc_f(float datos[], calculo_t tipo)
{
	float frecuencia=0;
	
	if(datos==NULL) return 0;
	frecuencia = (sqrt(1+datos[1]/datos[3]))/
				 (CTE_2PI*datos[4]*sqrt(datos[1]*datos[2]));
	return frecuencia;
}

float calc_c(float datos[], calculo_t tipo)
{
	float capacidad=0;
     
	if(datos==NULL) return 0; 
	capacidad = (sqrt(1+datos[1]/datos[3]))/
                (CTE_2PI*datos[0]*sqrt(datos[1]*datos[2]));
    return capacidad;
}

float calc_r1(float datos[], calculo_t tipo)
{
	float r1=0;
	
	if(datos==NULL) return 0;
	r1 = 1/(CTE_2PI*CTE_2PI*datos[4]*datos[4]*datos[0]*
		 datos[0]*datos[2]-1/datos[3]);
	return r1;
}

float calc_r2(float datos[], calculo_t tipo)
{
	float r2=0;
	
	if(datos==NULL) return 0;
	r2 = (1+datos[1]/datos[3])/(datos[1]*CTE_2PI*CTE_2PI*
		 datos[4]*datos[4]*datos[0]*datos[0]);
	return r2;
}

float calc_r3(float datos[], calculo_t tipo)
{
    float r3=0;
    
	if(datos==NULL) return 0;    
	r3 = 1/(CTE_2PI*CTE_2PI*datos[4]*datos[4]*datos[0]*
         datos[0]*datos[2]-1/datos[3]);
        return r3;
}

float calc_q(float datos[], calculo_t tipo)
{
	float factor_q=0;
	
	if(datos==NULL) return 0;
	factor_q = sqrt(datos[2]/datos[1]*
			   (1+datos[1]/datos[3]))/2;
	return factor_q;
}

status_t strlwr(char cadena[]){
	size_t i;
	if(cadena==NULL) return ERR_PUNTERO_NULO;
	for(i=0;cadena[i]!='\0';i++){
		cadena[i]=tolower(cadena[i]);
	}
	return OK;
}