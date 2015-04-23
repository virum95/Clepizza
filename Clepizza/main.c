#include <stdio.h>
#include <stdlib.h>



typedef struct{
	char* nombre;
	char size; /* 'p', 'm' o 'g'*/
	float precio;
} Elemento;

typedef struct{
	Elemento entrante;
	Elemento pizza;
	Elemento bebida;
	Elemento postre;
	float precio;
} Menu;

/*??*/ void mostrarPedido(){

}



int mostrarMenu(){
	int opcion;
	printf("¿Qué desea pedir?\n");
	printf("1.- Menu.\n");
	printf("2.- Pizza.\n");
	printf("3.- Entrantes.\n");
	printf("4.- Bebidas.\n");
	printf("5.- Postres.\n");
	printf("6.- Descuento.\n");
	printf("7.- Consultar pedido.\n");
	printf("8.- Terminar pedido y pagar.\n");
	fflush(stdout);
	scanf("%i", &opcion); //TODO: sscanf
	return opcion;
}

void iniciarPedido(int opcion){
	int opcion2;
	switch(opcion){
	//Menu
	case 1:

		break;
	//Pizza
	case 2:
		printf("Pizza\n___________________\n");
		printf("1.- Especialidad.\n");
		printf("2.- Ingredientes.\n");
		fflush(stdout);
		//sscanf
		scanf("%i", &opcion2);
		break;
	//Entrante
	case 3:
		printf("Entrantes\n___________________\n");

		break;
	//Bebida
	case 4:
		printf("Bebidas\n___________________\n");

		break;
	//Postre
	case 5:
		printf("Postres\n___________________\n");

		break;
	//Descuento
	case 6:

		break;
	//Consultar Pedido
	case 7:

		break;
	//Terminar y pagar
	case 8:

		break;
	}
}

int main(void){
	char opcion;
	printf("Bienvenido a ClePizza.\n\n");
	printf("¿Qué desea hacer?\n");
	printf("1.- Realizar un pedido.\n");
	printf("q.- Salir\n");
	fflush(stdout);
	//TODO: sscanf
	scanf("%c", &opcion);
	if( opcion == '1'){
		iniciarPedido(mostrarMenu());
	}


	return 0;
}
