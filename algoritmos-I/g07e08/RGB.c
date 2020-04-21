#include <stdio.h>
#define MASK_RED 0x00FF0000
#define MASK_GREEN 0x0000FF00
#define MASK_BLUE 0X000000FF
#define SHIFT_16 16
#define SHIFT_8 8
#define MSG_ORIGINAL_COLOR "The original color is:"
#define MSG_RED "RED component:"
#define MSG_GREEN "GREEN component:"
#define MSG_BLUE "BLUE component:"
#define MSG_ALL_COMPONENTS "R G B components are:"
#define RANDOM_COLOR 0x00EECD44
#define RANDOM_COLOR_B 0x00111111
#define MAX_2DIGITS_HEX 0x000000FF
#define MSG_COMPLEMENTARY_CLR "The complementary color is:"
#define PERCENT_MOD 100
#define RANDOM_PERCENTAGE 50
#define MSG_MOD_CLR "The new color with modified brightness is:"
#define MSG_MIX_CLR "The mix with Color B results in:"
#define R 0
#define G 1
#define B 2

typedef unsigned char primary;
typedef unsigned int color; /*component*/
typedef enum {OK=0,ERROR_NULL_POINTER=1} status_t;

/*PROTOTIPOS=========================================*/
primary red(color);
primary green(color);
primary blue(color);
status_t rgb_components(const color,primary *,primary *,primary *);
color mix_colors(color, color);
color modify_brightness(color,unsigned short int);
color complementary_color(color);
/*===================================================*/

primary red(color original_color){
	color red;
	red = (original_color&MASK_RED)>>SHIFT_16;
	return red;
}
primary green(color original_color){
        color green;
        green = (original_color&MASK_GREEN)>>SHIFT_8;
        return green;
}
primary blue(color original_color){
        color blue;
	blue = (original_color&MASK_BLUE);
        return blue;
}
status_t rgb_components(const unsigned int color, primary *r_comp, primary *g_comp, primary *b_comp){
	if(((r_comp==NULL)||(g_comp==NULL))||(b_comp==NULL)) return ERROR_NULL_POINTER;
	*r_comp = (color&MASK_RED)>>SHIFT_16;	
	*g_comp = (color&MASK_GREEN)>>SHIFT_8;
	*b_comp = (color&MASK_BLUE);
	return OK;
}

color mix_colors(color color_a,color color_b){
	color red; color green; color blue; color mixed_color;
	red   = (((color_a&MASK_RED)>>SHIFT_16)+((color_b&MASK_RED)>>SHIFT_16))<<SHIFT_16;
	green = (((color_a&MASK_GREEN)>>SHIFT_8)+((color_b&MASK_GREEN)>>SHIFT_8))<<SHIFT_8;
	blue  = (color_a&MASK_BLUE)+(color_b&MASK_BLUE);
	mixed_color = (red|green)|blue;
	return mixed_color;
}
color modify_brightness(color original_color, unsigned short int percent){
	color red; color green; color blue; color mod_color;
	red   = (((original_color&MASK_RED)>>SHIFT_16)/PERCENT_MOD*percent)<<SHIFT_16;
       	green = (((original_color&MASK_GREEN)>>SHIFT_8)/PERCENT_MOD*percent)<<SHIFT_8;
        blue  = (original_color&MASK_BLUE)/PERCENT_MOD*percent;
        mod_color = (red|green)|blue;
        return mod_color;
}
color complementary_color(color original_color){
	color red; color green; color blue; color complemented_color;
	red   = (MAX_2DIGITS_HEX-((original_color&MASK_RED)>>SHIFT_16))<<SHIFT_16;
	green = (MAX_2DIGITS_HEX-((original_color&MASK_GREEN)>>SHIFT_8))<<SHIFT_8;
	blue  = MAX_2DIGITS_HEX-(original_color&MASK_BLUE);
	complemented_color = (red|green)|blue;
	return complemented_color;
}
int main(void){
	unsigned int color=RANDOM_COLOR;
	unsigned int color_b=RANDOM_COLOR_B;
	unsigned char component[B];
	rgb_components(color,&component[R],&component[G],&component[B]);
	fprintf(stdout,"%s%X\n%s%X\n%s%X\n%s%X\n%s%X-%X-%X\n%s%X\n%s%X\n%s%X\n",
		MSG_ORIGINAL_COLOR,color,
		MSG_RED,red(color),
		MSG_GREEN,green(color),
		MSG_BLUE,blue(color),
		MSG_ALL_COMPONENTS,component[R],component[G],component[B],
		MSG_COMPLEMENTARY_CLR,complementary_color(color),
		MSG_MOD_CLR,modify_brightness(color,RANDOM_PERCENTAGE),
		MSG_MIX_CLR,mix_colors(color,color_b)		
	);
	return 0;
}
