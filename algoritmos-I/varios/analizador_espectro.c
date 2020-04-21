#include<stdio.h>
#include<stdlib.h>
#define INIT_CHOP 1000
#define CHOP_SIZE 100

typedef struct{
	double real;
	double imag;
}complex_t;

typedef enum{OK=0,
			ERROR_NULL_POINTER=1,
			ERROR_INVALID_DATA=2,
			ERROR_NO_MEMORY=3} status_t;

/*Prototypes======================*/
status_t load_values(FILE *, complex_t ***, size_t*);
/*================================*/			
			
int main(void){
	return 0;
}

status_t load_values(FILE * fi, complex_t *** registros, size_t *len){
	complex_t ** aux; 
	complex_t * c; 
	size_t alloc_size;
	
	if(registros==NULL||len==NULL||fi==NULL){
		return ERROR_NULL_POINTER;
	}
	if((*registros=(complex_t**)malloc(sizeof(complex_t*)*INIT_CHOP))==NULL){
		*len=0;
		return ERROR_NO_MEMORY;
	}
	alloc_size=INIT_CHOP; 
	*len=0;
	while(fread(&c,sizeof(c),1,fi)){
		if(*len==alloc_size){
			if((aux=(complex_t**)realloc(*registros,sizeof(complex_t*)*(alloc_size+CHOP_SIZE)))==NULL){
				*registros=NULL;
				*len=0;
				free(*registros);
				return ERROR_NO_MEMORY;
			}
			*registros=aux;
			alloc_size+=CHOP_SIZE;
		}
		(*registros)[*len]=c;
		(*len)++;
	}
	return OK;
}