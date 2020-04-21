#include <stdio.h>
#define STRING_MSG "HOLA"
#define MAX_STRING 20

typedef enum {ERROR_NULL_POINTER=0,OK=1} status_t;

/*PROTOTYPES====================*/
status_t strlwr(char *);
/*==============================*/

status_t strlwr(char * s){
	size_t i;
	if(s==NULL) return ERROR_NULL_POINTER;
	for(i=0;*(s+i)!='\0';i++){
		if(65<=*(s+i)&&*(s+i)<=90) *(s+i)=*(s+i)+32;
	}
	return OK;
}

int main(void){
	char s[MAX_STRING]=STRING_MSG;
	strlwr(s);
	fprintf(stdout,"%s\n",s);
	return 0;
}
