#include <stdio.h>
#define STRING_MSG "Hola"
#define STRING_MAX 250

/*PROTOTYPE========================*/
size_t strlen(const char []);
/*=================================*/

size_t strlen(const char string[]){
	size_t i=1;
	if(string==NULL) return 0;
	for(i=0;string[i]!='\0';i++);
	return i;
}

int main(void){
	char string[STRING_MAX];
	scanf("%s",string);
	fprintf(stdout,"%lu\n",strlen(string));
	return 0;
}
