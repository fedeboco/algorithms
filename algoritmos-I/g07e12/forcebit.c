#include <stdio.h>
#define MASK_BIT 1
#define RND_DATA 0xFE
#define RND_LINE 0

/*PROTOTYPES=====================*/
unsigned char set_bit(unsigned char, short);
unsigned char clear_bit(unsigned char, short);
/*===============================*/

unsigned char set_bit(unsigned char data, short line){
	data=data|(MASK_BIT<<line);
	return data;
}
unsigned char clear_bit(unsigned char data, short line){
        data=data&(~(MASK_BIT<<line));
        return data;
}
int main(void){
	unsigned char data=RND_DATA;
	short line=RND_LINE;
	fprintf(stdout, "%X\n%X\n", set_bit(data,line), clear_bit(data,line));
	return 0;
}
