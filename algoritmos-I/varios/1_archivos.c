#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define CMD_ARG_INPUT_FILE 1
#define CMD_ARG_OUTPUT_FILE 2

typedef enum{ERROR_NULL_POINTER,OK} status_t;

/*Prototypes==============================*/
status_t validate_arguments(int, char *[]);
/*========================================*/

int main(int argc, char * argv[]){
	FILE * fi;
	FILE * fo;
	char c;
	
	if((validate_arguments(argc,argv))!=OK)
		return EXIT_FAILURE;
	if((fi=fopen(argv[CMD_ARG_INPUT_FILE],"rt"))==NULL){
		fprintf(stderr,"%s%s%s\n","Error:","no se pudo abrir",argv[CMD_ARG_INPUT_FILE]);
		return EXIT_FAILURE;
	}
	if((fo=fopen(argv[CMD_ARG_OUTPUT_FILE],"wt"))==NULL){
		fprintf(stderr,"%s%s%s\n","Error:","no se pudo abrir el archivo",argv[CMD_ARG_OUTPUT_FILE]);
		fclose(fo);
		return ERROR_NULL_POINTER;
	}
	while((c=fgetc(fi))!=EOF){
		fputc(toupper(c),fo);
	}
	if(fclose(fo)==EOF){
		fprintf(stderr,"%s%s%s\n","Error:","no se pudo generar el archivo",argv[CMD_ARG_OUTPUT_FILE]);
		return EXIT_FAILURE;
	}
	fclose(fi);
	return EXIT_SUCCESS;
}

status_t validate_arguments(int argc, char * argv[]){
	return OK;
}
