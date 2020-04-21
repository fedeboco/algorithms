/*--------------------------------------------------------------------
This program receives a CLA as a parameter to count the desired element 
represented by the parameter.
-l stands for lines
-c stands for characters
-w stands for words
-a prints all the previous parameters

The program must be called as follows:
./count <parameter> <relative file path> ; e.g.: ./count -l -ids.txt

Developed by Federico Pérez Boco. 22/12/2015.
----------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "count.h"

typedef enum {	OK=0,
		ERR_NULL_POINTER=1,
		ERR_INVALID_PARAMETER=2,
		ERR_INVALID_NUM_OF_ARGS=3,
		ERR_READING_FILE=4,
		ERR_CLOSING_FILE=5
}status_t;

typedef enum { IN=1, OUT=0} word_t;

/*Prototypes================*/
status_t validate_arguments(int, char *[]);
status_t print_error(status_t *);
status_t count_lines(FILE *, size_t *);
status_t count_chars(FILE *, size_t *);
status_t count_words(FILE *, size_t *);
status_t count_all(FILE *, size_t *, size_t *, size_t *);
/*End of prototypes=========*/

int main(int argc,char * argv[]){
	status_t st; FILE * fi;	size_t nl, nc, nw;

	if((st=validate_arguments(argc,argv))!=OK){
		print_error(&st);
		return EXIT_FAILURE;
	}
	
	if((fi=fopen(argv[CMD_ARG_FILE_PATH]+1,"rt"))==NULL){
		st=ERR_READING_FILE;
		print_error(&st);
		return EXIT_FAILURE;
	}
	
	switch(argv[CMD_ARG_PARAMETER][1]){
		case 'l':
			if((st=count_lines(fi,&nl))!=OK){
				print_error(&st);
				return EXIT_FAILURE;
			}
			fprintf(stdout,"%lu\n",nl);
			break;
		case 'c':
			if((st=count_chars(fi,&nc))!=OK){
				print_error(&st);
				return EXIT_FAILURE;
			}
			fprintf(stdout,"%lu\n",nc);
			break;
		case 'w':
			if((st=count_words(fi,&nw))!=OK){
				print_error(&st);
				return EXIT_FAILURE;
			}
			fprintf(stdout,"%lu\n",nw);
			break;
		case 'a':
			if((st=count_all(fi,&nl,&nc,&nw))!=OK){
				print_error(&st);
				return EXIT_FAILURE;
			}
			fprintf(stdout,"%lu\n%lu\n%lu\n",nl,nc,nw);
			break;
		case 'h':
			fprintf(stdout,"%s",MSG_HELP_CALL);
			break;
		default:
			st=ERR_INVALID_PARAMETER;
			print_error(&st);
			return EXIT_FAILURE;
	}

	if(fclose(fi)==EOF){
		st=ERR_CLOSING_FILE;
		print_error(&st);
		return EXIT_FAILURE;	
	}

	return EXIT_SUCCESS;
}

/*This function counts the number of characters in a file and stores
the count in an external variable nc (previously defined).*/
status_t count_chars(FILE * fi, size_t * nc){
	char c;
	*nc=0;

	if(nc==NULL)
		return ERR_NULL_POINTER;
	while((c=fgetc(fi))!=EOF)
		(*nc)++;
	return OK;
}

/*This function counts the number of lines, words and characters in a file and stores
the count in 3 external variables nl, nw and nc respectively (previously defined).*/
status_t count_all(FILE * fi, size_t * nl, size_t * nc, size_t * nw){
	char c;
	word_t word_status;
	*nl=0;
	*nc=0;
	*nw=0;

	if(nl==NULL||nc==NULL||nw==NULL)
		return ERR_NULL_POINTER;

	while((c=fgetc(fi))!=EOF){
		(*nc)++;
		if (c == '\n')
			(*nl)++;
		if (c == ' ' || c == '\n' || c == '\t')
			word_status = OUT;
		else if (word_status == OUT) {
			word_status = IN;
			(*nw)++;
		}
	}
	return OK;
}

/*This function counts the number of words in a file and stores
the count in an external variable nw (previously defined).*/
status_t count_words(FILE * fi, size_t * nw){
	char c;	
	word_t word_status;
	*nw=0;

	if(nw==NULL)
		return ERR_NULL_POINTER;
	while((c=fgetc(fi))!=EOF){
		if (c == ' ' || c == '\n' || c == '\t')
			word_status = OUT;
		else if (word_status == OUT) {
			word_status = IN;
			(*nw)++;
		}
	}
	return OK;
}

/*This function counts the number of lines in a file and stores
the count in an external variable nl (previously defined).*/
status_t count_lines(FILE * fi, size_t * nl){
	char c;
	*nl=0;
	
	if(nl==NULL)
		return ERR_NULL_POINTER;
	while((c=fgetc(fi))!=EOF){
		if (c == '\n')
			(*nl)++;
	}
	return OK;
}


char * error_dictionary[]={
	MSG_OK,
	MSG_ERR_NULL_POINTER,
	MSG_ERR_INVALID_PARAMETER,
	MSG_ERR_INVALID_NUM_OF_ARGS,
	MSG_ERR_READING_FILE,
	MSG_ERR_CLOSING_FILE
};

/*This function prints why the program failed and some help to call it properly.*/
status_t print_error(status_t * st){
	
	if(st==NULL)
		return ERR_NULL_POINTER;
	fprintf(stdout,"%s\n",error_dictionary[*st]);
	fprintf(stdout,"\n%s\n\n",MSG_HELP_CALL);
	return OK;	
}

/*This function validates the arguments received as CLA.*/
status_t validate_arguments(int argc,char * argv[]){

	if(argv==NULL)
		return ERR_NULL_POINTER;
	if(argc!=MAX_ARGS)
		return ERR_INVALID_NUM_OF_ARGS;
	if(argv[CMD_ARG_PARAMETER][0]!=PARAMETER_INDICATOR)
		return ERR_INVALID_PARAMETER;
	if(argv[CMD_ARG_PARAMETER][1]!=LINE_PARAMETER&&
	   argv[CMD_ARG_PARAMETER][1]!=CHAR_PARAMETER&&
	   argv[CMD_ARG_PARAMETER][1]!=ALL_PARAMETER&&
	   argv[CMD_ARG_PARAMETER][1]!=WORD_PARAMETER&&
	   argv[CMD_ARG_PARAMETER][1]!=HELP_PARAMETER)
		return ERR_INVALID_PARAMETER;
	return OK;
}
