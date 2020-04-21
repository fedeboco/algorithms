#include <stdio.h>
#define MAX_STRING_A 200
#define MAX_STRING_B 50
#define MSG_STRING_A "Hola mundo"
#define MSG_STRING_B ", todo bien?"

/*PROTOTYPES==================*/
char * strcat (char[], const char[]);
/*============================*/

char * strcat (char string_a[], const char string_b[]){
	size_t i,j;
	if(string_a==NULL||string_b==NULL) return 0;
	for(i=0;string_a[i]!='\0';i++);
	for(j=0;string_b[j]!='\0';i++,j++) string_a[i]=string_b[j];
	return string_a;
}

int main(void){
	char string_a[MAX_STRING_A]={MSG_STRING_A};
	char string_b[MAX_STRING_B]={MSG_STRING_B};
	fprintf(stdout,"%s\n",strcat(string_a,string_b));
	return 0;
}
