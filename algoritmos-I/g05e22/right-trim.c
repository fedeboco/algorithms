#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define STRING_MAX 20
#define STRING_MSG "AAAAAAA       "

typedef enum {ERROR_NULL_POINTER=0, OK=1} status_t;

/*PROTOTYPES==============*/
status_t right_trim(char *);
/*========================*/

status_t right_trim(char * s){
	size_t i;
	if(s==NULL) return ERROR_NULL_POINTER;
	for(i=strlen(s)-1;isspace(*(s+i));i--);
	memmove(s+i,s,strlen(s)-i+1);
	return OK;
}

int main(void){
	char s[STRING_MAX]=STRING_MSG;
	fprintf(stderr,"%i\n",right_trim(s));
	fprintf(stdout,"%s\n",s);
	return 0;
}
