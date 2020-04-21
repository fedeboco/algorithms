#include <stdio.h>
#include <stdlib.h>
#define MAX_STRING 200
#define MSG_STRING_A "Elephant"
#define MSG_STRING_B "Elepha"

/*PROTOTYPES=============*/
int strcmp (const char [], const char[]);
/*=======================*/

int strcmp (const char string_a[], const char string_b[]){
	int i;
	if(string_a!=NULL&&string_b!=NULL){
		for(i=0;string_a[i]==string_b[i];i++){
			if (string_a[i]=='\0') return 0;
		}
		return string_a[i]-string_b[i];
	}else{ 
		return EXIT_FAILURE;
	}
}

int main(void){
	char string_a[MAX_STRING]=MSG_STRING_A;
	char string_b[MAX_STRING]=MSG_STRING_B;
	fprintf(stdout,"%i\n",strcmp(string_a,string_b));
	return 0;
}
