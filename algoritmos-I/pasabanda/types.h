typedef enum {	ERR_DATO_INVALIDO=0, 
				ERR_PUNTERO_NULO=1, 
				OK=2,
				ERR_RESISTOR_INVALIDO=3,
				ERR_FRECUENCIA_INVALIDA=4,
				ERR_CAPACIDAD_INVALIDA=5} status_t;
				
typedef enum {	ST_IDLE=0,
				ST_MAIN_MENU=1,
				ST_MENU_FREQUENCY=2,
				ST_MENU_Q_FACTOR=3,
				ST_END=4} main_menu_status_t;
				
typedef enum {	OPC_MENU_FREQ=1,
				OPC_MENU_Q_FACTOR=2,
				OPC_END=3,
				ERR_OPCION_INVALIDA_MENU_PPAL=0
				} main_menu_option_t;
				
typedef enum {	OPC_CALCULAR_FRECUENCIA=1,
				OPC_CALCULAR_R1=2,
				OPC_CALCULAR_R2=3,
				OPC_CALCULAR_R3=4,
				OPC_CALCULAR_CAPACIDAD=5,
				OPC_VOLVER_MENU_PPAL=6,
				ERR_OPCION_INVALIDA_FREQ=0
				} freq_menu_option_t;
				
typedef enum {	OPC_CALCULAR_FACTOR=1,
				OPC_MENU_PPAL=2,
				ERR_OPCION_INVALIDA_FACTOR=0
				} factor_menu_option_t;