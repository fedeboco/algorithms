#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_INPUT_LINE 32
#define MAX_ID 12
#define MAX_PHONE 12
#define MAX_BILL 11
#define MAX_ZONE 3
#define VALUE "100023000111434308910000.2200R"
#define SPAN_ID 10
#define SPAN_PHONE 10
#define SPAN_BILLING 9
#define SPAN_ZONE 1
#define START_PHONE 10
#define START_BILLING 20
#define START_ZONE 29

/*PROTOTYPES===============*/
unsigned int get_id(unsigned char*);
unsigned int get_phone(unsigned char*);
float get_bill(unsigned char*);
unsigned char * get_zone(unsigned char*, unsigned char*);
/*=========================*/

unsigned int get_id(unsigned char * line){
	unsigned char aux[MAX_ID];unsigned int id=0;

	if(line==NULL) return 0;
	memcpy(aux,line,SPAN_ID);
	aux[SPAN_ID]='\0';
	id=atoi(aux);
	return id;
}
unsigned int get_phone(unsigned char * line){
        unsigned char aux[MAX_PHONE];unsigned int phone=0;

        if(line==NULL) return 0;
	memcpy(aux,line+START_PHONE,SPAN_PHONE);
        aux[SPAN_PHONE]='\0';
        phone=atoi(aux);
        return phone;
}
float get_bill(unsigned char * line){
        unsigned char aux[MAX_BILL];float bill=0;
    
        if(line==NULL) return 0;
        memcpy(aux,line+START_BILLING,SPAN_BILLING);
        aux[SPAN_BILLING]='\0';
        bill=atof(aux);
        return bill;
}
unsigned char * get_zone(unsigned char * line, unsigned char * aux){
        
        if(line==NULL) return 0;
        memcpy(aux,line+START_ZONE,SPAN_ZONE);
        aux[SPAN_BILLING]='\0';
        return 0;
}
int main(void){
	unsigned char line[MAX_INPUT_LINE]=VALUE;
	unsigned char aux[MAX_ZONE];
	
	get_zone(line,aux);
	fprintf(stdout,"%i\n",get_id(line));
	fprintf(stdout,"%i\n",get_phone(line));
	fprintf(stdout,"%f\n",get_bill(line));
	fprintf(stdout,"%s\n",aux);
	return 0;
}

/*Devuelve los valores esperados pero compila con warnings como estos:

tel.c:49:9: warning: pointer targets in passing argument 1 of ‘atof’ differ in signedness [-Wpointer-sign]
         bill=atof(aux);
         ^
In file included from tel.c:3:0:
/usr/include/stdlib.h:144:15: note: expected ‘const char *’ but argument is of type ‘unsigned char *’
 extern double atof (const char *__nptr)

*/
