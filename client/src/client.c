#include "client.h"
#include <readline/readline.h>

int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/

	int conexion;
	char* ip;
	char* puerto;
	char* valor;

	t_log* logger;
	t_config* config;

	/* ---------------- LOGGING ---------------- */

	logger = iniciar_logger();

	// Usando el logger creado previamente
	// Escribi: "Hola! Soy un log"

	logger = log_create("tp0.log", "TP0", true, LOG_LEVEL_INFO);
	log_info(logger, "Hola! Soy un log");
	log_destroy(logger);

	/* ---------------- ARCHIVOS DE CONFIGURACION ---------------- */

	config = iniciar_config();

	// Usando el config creado previamente, leemos los valores del config y los 
	// dejamos en las variables 'ip', 'puerto' y 'valor'

	config = config_create("/home/utnso/Documents/tp0/client/cliente.config");

	if (config == NULL) {
		printf("¡No se pudo crear el config!");
		exit(3);
	}

	valor = config_get_string_value(config, "CLAVE");
	ip = config_get_string_value(config, "IP");
	puerto = config_get_string_value(config, "PUERTO");

	// Loggeamos el valor de config

	logger = iniciar_logger();
	logger = log_create("tp0.log", "TP0", true, LOG_LEVEL_INFO);
	log_info(logger, "VALOR: %s\nIP: %s\nPUERTO: %s", valor, ip, puerto);
	log_destroy(logger);

	config_destroy(config);

	/* ---------------- LEER DE CONSOLA ---------------- */

	logger = iniciar_logger();
	leer_consola(logger);
	logger = log_create("tp0.log", "TP0", true, LOG_LEVEL_INFO);
	log_info(logger,"Termino la lectura.");
	log_destroy(logger);

	/*---------------------------------------------------PARTE 3-------------------------------------------------------------*/

	// ADVERTENCIA: Antes de continuar, tenemos que asegurarnos que el servidor esté corriendo para poder conectarnos a él

	// Creamos una conexión hacia el servidor
	conexion = crear_conexion(ip, puerto);

	err = connect(fd_conexion, server_info->ai_addr, server_info->ai_addrlen);

	// Enviamos al servidor el valor de CLAVE como mensaje
	

	// Armamos y enviamos el paquete
	paquete(conexion);

	terminar_programa(conexion, logger, config);

	/*---------------------------------------------------PARTE 5-------------------------------------------------------------*/
	// Proximamente
}

t_log* iniciar_logger(void)
{
	t_log* nuevo_logger;

	return nuevo_logger;
}

t_config* iniciar_config(void)
{
	t_config* nuevo_config;

	return nuevo_config;
}

void leer_consola(t_log* logger)
{
	char* leido;

	while(true){
		// La primera te la dejo de yapa
		leido = readline("> ");
		// El resto, las vamos leyendo y logueando hasta recibir un string vacío
		if(!strcmp(leido, "")){
			free(leido);
			break;
		}
		log_info(logger,leido);
		// ¡No te olvides de liberar las lineas antes de regresar!
		free(leido);
	}	
}

void paquete(int conexion)
{
	// Ahora toca lo divertido!
	char* leido;
	t_paquete* paquete;

	// Leemos y esta vez agregamos las lineas al paquete


	// ¡No te olvides de liberar las líneas y el paquete antes de regresar!
	
}

void terminar_programa(int conexion, t_log* logger, t_config* config)
{
	/* Y por ultimo, hay que liberar lo que utilizamos (conexion, log y config) 
	  con las funciones de las commons y del TP mencionadas en el enunciado */
}
