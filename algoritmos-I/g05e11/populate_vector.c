#include <stdio.h>
#include <stdlib.h>
#define MAX_ARRAY 5
#define MAX_RAND 1.0

/*PROTOTYPES==============*/
int populate_vector(float [],size_t);
/*========================*/

int populate_vector(float v[],size_t length){
	size_t i;
	if(v==NULL) return 0;
	for(i=0;i<length;i++) v[i]=(rand()/(float)RAND_MAX)*MAX_RAND;
	return 0;
}

int main(void){
	size_t i;
	float v[MAX_ARRAY];
	size_t length=MAX_ARRAY;
	populate_vector(v,length);
	for(i=0;i<MAX_ARRAY;i++) fprintf(stdout,"%f\n",v[i]);
	return 0;
}
