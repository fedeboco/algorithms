#include <stdio.h>
#include <stdlib.h>
#define MAX_STREET 14

typedef enum {ERROR_NULL_POINTER=0,OK=1} status_t;

typedef struct
{
	char street[MAX_STREET];
	size_t street_number;
	int floor;
}adress_t;

typedef struct
{
	size_t number;
	adress_t * adress; 
}client_t;

/*PROTOTYPES============================*/
status_t print_user(const client_t *);
status_t print_adress(const adress_t *);
/*======================================*/

int main(void){
	adress_t dir_jorge={"YRIGOYEN",234,2};
	client_t cl_jorge={546,&dir_jorge};
	
	if((print_user(&cl_jorge))!=OK) return EXIT_FAILURE;
	/*print_adress(&dir_jorge);*/
	
	return OK;
}

status_t print_user(const client_t * p){
	if(p==NULL) return ERROR_NULL_POINTER;
	fprintf(stdout,"%lu\n",p->number);
	print_adress(p->adress);
	return OK;
}

status_t print_adress(const adress_t * p){
	if(p==NULL) return ERROR_NULL_POINTER;
	fprintf(stdout,"%lu\n",p->street_number);
	fprintf(stdout,"%s\n",p->street);
	fprintf(stdout,"%i\n",p->floor);
	return OK;
}