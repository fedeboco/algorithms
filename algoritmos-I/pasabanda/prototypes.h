/*Prototipos*/
status_t leer_valor_resistor(const char *, double *);
status_t leer_valor_frecuencia(const char *, double *);
status_t leer_valor_capacidad(const char *, double *);
double calcular_frecuencia(double,double,double,double);
double calcular_resistor_1(double,double,double,double);
double calcular_resistor_2(double,double,double,double);
double calcular_resistor_3(double,double,double,double);
double calcular_capacidad(double,double,double,double);
double calcular_factor_calidad(double,double,double);
status_t imprimir_menu_ppal(void);
status_t imprimir_menu_frecuencia(void);
status_t imprimir_menu_factor_calidad(void);
factor_menu_option_t obtener_opcion_menu_factor(void);
main_menu_option_t obtener_opcion_main_menu(void);
freq_menu_option_t obtener_opcion_menu_frecuencia(void);