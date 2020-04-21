#include <stdio.h>
#include <math.h>

#define A0 1
#define A1 2
#define A2 3
#define A3 4
#define INDEPENDENT_VAR 10
#define MAX_ARRAY 4

/*PROTOTYPES=================*/
double evaluate_poly(const double [], size_t, double );
/*===========================*/

double evaluate_poly(const double coef[], size_t grade, double x){
	size_t power;
	double result=0;
	
	if(coef==NULL) return 0;
	for(power=0;power<=grade;power++) result+=coef[power]*pow(x,power);
	return result;
}

int main(void){
	double coef[MAX_ARRAY]={A0,A1,A2,A3};
	double x=INDEPENDENT_VAR;
	fprintf(stdout,"%lf",evaluate_poly(coef,MAX_ARRAY,x));
	return 0;
}
