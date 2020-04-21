#include <stdio.h>
#define ARRAY_LENGTH 10

typedef double average_t;
typedef unsigned int length_t;
typedef double vector_t;

/*PROTOTYPES=======================*/
average_t average(vector_t [], length_t);
/*=================================*/

average_t average(vector_t v[],length_t vector_length){
	unsigned int i;
	double average=0;
	
	if(v==NULL) return 0;
	for(i=0;i<ARRAY_LENGTH;i++) average+=v[i];
	average=average/vector_length;
	return average;
}

int main(void){
	unsigned int i;
	length_t length=ARRAY_LENGTH; vector_t v[ARRAY_LENGTH];
	for(i=0;i<ARRAY_LENGTH;i++){
		scanf("%lf",&v[i]);
	}
	fprintf(stdout,"%f",average(v,length));
	return 0;
}
