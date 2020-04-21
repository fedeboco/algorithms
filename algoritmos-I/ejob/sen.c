#include <stdio.h>
#include <math.h>
#include "setup_sen.h"

int main(void)
{
	int i;
	float val = 0;

	for(i = 0; i<MAX_POINTS; i++)
	{
		/*printf("%f\t", SEN_INPUT);*/
		val = A*sin(SEN_INPUT);
		printf("%f\n", val);
		
	}
	return EXIT_SUCCESS;
}
