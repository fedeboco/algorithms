#include <stdio.h>
#include <stdlib.h>
#define STRING_T "Hola mundo."
#define MAX_STRING 220
#define NULL_POINTER_ERROR_MSG "Error, puntero nulo"
#define OK "Operación completada con éxito."

/*PROTOTYPES====================*/
char * strcpy(char [], char[]);
/*==============================*/

char * strcpy(char s[], char t[]){
	size_t i;
	if(s==NULL||t==NULL) return NULL_POINTER_ERROR_MSG;
	for(i=0;t[i]!='\0';i++) s[i]=t[i];
        i++; s[i]='\0';
	return OK;
}

int main(void){
	char s[MAX_STRING];
	char t[MAX_STRING]=STRING_T;
	fprintf(stderr,"%s\n",strcpy(s,t));
	fprintf(stdout,"%s\n",s);
	return 0;
}
