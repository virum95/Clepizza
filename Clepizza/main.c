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

int readLine(FILE* f, int line) {
	int size = 1024, pos;
	int c;
	int linea = 0;
	char *buffer = (char *)malloc(size);
	if(f) {
		do { // read all lines in file
			pos = 0;
			do{ // read one line
				c = fgetc(f);
				if(c != EOF) buffer[pos++] = (char)c;
				if(pos >= size - 1) { // increase buffer length - leave room for 0
					size *=2;
					buffer = (char*)realloc(buffer, size);
				}
			}while(c != EOF && c != '\n');
			buffer[pos] = 0;
			linea++;
			// line is now in buffer
			if((linea) == line) handle_line(buffer);
		} while(c != EOF);
		fclose(f);
	}
	free(buffer);
	return 0;
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
	char op2[3];
	char seguir[3];
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

		//fgets(op2, 3, stdin);
		//char *opcionf = malloc(3*sizeof(char));
		//sscanf(op2,"%s",opcionf);
		scanf("%s", &op2);
		if(op2[0] == '1'){
			readFile(fopen("Pizzas.txt","r"));
			scanf("%i", &opcion2);
			readLine(fopen("Pizzas.txt","r"), opcion2);
		} else if(op2[0] == '2'){
				readFile(fopen("Ingredientes.txt","r"));
			do{
				printf("Elija ingrediente: \n");
				fflush(stdout);
				scanf("%i", &opcion2);
				readLine(fopen("Ingredientes.txt","r"), opcion2);
				printf("¿Más ingredientes? (s/n)\n ");
				fflush(stdout);
				scanf("%s", &seguir);
			} while(seguir[0] != 'n');
		}
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
	Elemento arrayElementos[5][10];
	printf("Bienvenido a ClePizza.\n\n");
	printf("¿Qué desea hacer?\n");
	printf("1.- Realizar un pedido.\n");
	printf("q.- Salir\n");
	fflush(stdout);

	iniciarElementos(arrayElementos,5);


	return 0;
}
