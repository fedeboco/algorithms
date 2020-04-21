#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "setup_mu.h"

int main(void)
{
	float x;
	float y = 0;
	int sign = 0;

	while(scanf("%f", &x)==1)
	{
		if(x>=0){
			sign = 1;
		}else{
			sign = -1;
		}
		
		y = (log (1+MU * (x*sign) / X_MAX) )*sign/log(1+MU);

		printf("%f\n",y);
	}
	return EXIT_SUCCESS;
}
