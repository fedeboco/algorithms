#include <stdio.h>
#include <math.h>
#define ARRAY_LENGTH 10

typedef double average_t;
typedef unsigned int length_t;
typedef double vector_t;
typedef double std_dev_t;

/*PROTOTYPES=======================*/
average_t average(vector_t [], length_t);
std_dev_t standard_deviation(vector_t [], length_t);
/*=================================*/

average_t average(vector_t v[],length_t vector_length){
	unsigned int i;
	double average=0;
	
	if(v==NULL) return 0;
	for(i=0;i<vector_length;i++) average+=v[i];
	average=average/vector_length;
	return average;
}

std_dev_t standard_deviation(vector_t v[],length_t vector_length){
	unsigned int i;
	double deviation=0;
	double sum=0;
	double average_result=0;
	
	if(v==NULL) return 0;
	average_result=average(v,vector_length);
	for(i=0;i<vector_length;i++) sum+=v[i]*v[i];
	sum=sum/vector_length;
	deviation=sqrt(sum-average_result*average_result);
	return deviation;
}

int main(void){
	unsigned int i;

	length_t length=ARRAY_LENGTH; vector_t v[ARRAY_LENGTH];
	for(i=0;i<ARRAY_LENGTH;i++) scanf("%lf",&v[i]);
	fprintf(stdout,"%f\n%f\n",average(v,length),standard_deviation(v,length));
	return 0;
}
