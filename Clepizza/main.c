#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Elemento.h"

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

	//int opcion2;
	//char op2[3];
	//char seguir[3];
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

	Elemento** arrayElementos;
	arrayElementos = (Elemento**)malloc(sizeof(Elemento*)*10);
	arrayElementos[0] = (Elemento*)malloc(sizeof(Elemento)*50);
	arrayElementos[1] = (Elemento*)malloc(sizeof(Elemento)*50);
	arrayElementos[2] = (Elemento*)malloc(sizeof(Elemento)*50);
	arrayElementos[3] = (Elemento*)malloc(sizeof(Elemento)*50);
	arrayElementos[4] = (Elemento*)malloc(sizeof(Elemento)*50);
	arrayElementos[5] = (Elemento*)malloc(sizeof(Elemento)*50);
	printf("Bienvenido a ClePizza.\n\n");
	printf("¿Qué desea hacer?\n");
	printf("1.- Realizar un pedido.\n");
	printf("q.- Salir\n");
	fflush(stdout);

	arrayElementos = iniciarElementos(arrayElementos,10);

	mostrarElemento(arrayElementos[0][0]);
	mostrarElemento(arrayElementos[1][2]);
	mostrarElemento(arrayElementos[2][2]);
	mostrarElemento(arrayElementos[3][2]);
	mostrarElemento(arrayElementos[4][2]);
	mostrarElemento(arrayElementos[5][2]);
return 0;
}
