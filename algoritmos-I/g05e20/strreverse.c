#include <stdio.h>
#include <string.h>
#define STRING_MSG "Hola mundo."

typedef enum{ERROR_NULL_POINTER=0, OK=1} status_t;

/*PROTOTYPES=============*/
status_t string_reverse(char *);
/*=======================*/

status_t string_reverse(char * s){
	size_t i,j; char aux;
	if(s==NULL) return ERROR_NULL_POINTER;
	for(i=0,j=strlen(s)-1;i<j;i++,j--){
		aux=*(s+i);
		*(s+i)=*(s+j);
		*(s+j)=aux;
	}return OK;
}
int main(void){
	char s[] = STRING_MSG;
	fprintf(stderr,"%i\n",string_reverse(s));
	fprintf(stdout,"%s\n",s);
	return 0;
}

