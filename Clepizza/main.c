#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Elemento.h"

static float precioTotal = 0;

/*??*/ void mostrarPedido(){

}

void elegirTamanyo(int tipo){
	char op[3];
	if(tipo == 4){ precioTotal+=1.5;} else {
		printf("Introduce el tamaño: (s, m, b)\n");
		fflush(stdout);
		scanf("%s", &op);
		switch (op[0]) {
		case 's':
			if(tipo == 1) precioTotal+=7;
			if(tipo == 2) precioTotal+=3;
			if(tipo == 4) precioTotal+=1.5;
			if(tipo == 5) precioTotal+=3;
			if(tipo == 6) precioTotal+=10;
			break;
		case 'm':
			if(tipo == 1) precioTotal+=10;
			if(tipo == 2) precioTotal+=4;
			if(tipo == 4) precioTotal+=2;
			if(tipo == 5) precioTotal+=3.5;
			if(tipo == 6) precioTotal+=15;
			break;
		case 'b':
			if(tipo == 1) precioTotal+=13;
			if(tipo == 2) precioTotal+=5;
			if(tipo == 4) precioTotal+=3.5;
			if(tipo == 5) precioTotal+=4.5;
			if(tipo == 6) precioTotal+=20;
			break;
		default:
			break;
		}
	}
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
	scanf("%i", &opcion);
	return opcion;
}



char iniciarPedido(Elemento** arrayelementos, int opcion, Elemento* pedido)
{
	FILE * fp;
	int numero=0;
	int numeroPedido = 0;
	int opcion2;
	char op2[3];
	char seguir[3];
	char codigo[7];
	int i;
	switch(opcion){
	//Menu
	case 1:
		printf("Menu\n___________________\n");
		for (i = 0; i < 6; ++i) {
			printf("%s",arrayelementos[5][i].nombre);
		}
		printf("\n");
		fflush(stdout);
		scanf("%s",&op2);
		numero = (int)op2[0];
		numero-=48;
		printf("%s", arrayelementos[5][numero-1].nombre);
		elegirTamanyo(6);

		//AÑADIR AL PEDIDO
		pedido[numeroPedido] = arrayelementos[0][numero-1];
		numeroPedido++;

		printf("¿Desea hacer alguna operación más?(s/n)\n");//CONTROL DESPUES DE COMPRAR CUALQUIER COSA.
		do{
			fflush(stdout);
			scanf("%s",&op2);
			if(op2[0]=='s'){
				return 's';
			}
			else if(op2[0]=='n'){
				return 'n';
			}
			else{
				printf("Error en el caracter introducido, introduzca 's' para Si y 'n' para No");
			}
		}while(op2[0]!='s' || op2[0]!='n');
		break;
		//Pizza
	case 2:
		printf("Pizza\n___________________\n");
		printf("1.- Especialidad.\n");
		printf("2.- Ingredientes.\n");
		fflush(stdout);
		scanf("%s", &op2);
		if(op2[0] == '1'){ //Especialidad
			for (i = 0; i < 10; ++i) {
				printf("%s",arrayelementos[0][i].nombre);
			}
			fflush(stdout);
			scanf("%s",&op2);
			numero = (int)op2[0];
			numero-=48;
			printf("%s", arrayelementos[0][numero-1].nombre);

			//AÑADIR AL PEDIDO
			pedido[numeroPedido] = arrayelementos[0][numero-1];
			numeroPedido++;

		} else if(op2[0] == '2'){//Ingredientes
			do{
				printf("Elija ingrediente: \n");
				for (i = 0; i < 10; ++i) {
					printf("%s",arrayelementos[4][i].nombre);
				}
				fflush(stdout);
				scanf("%i", &opcion2);
				printf("%s",arrayelementos[4][opcion2-1].nombre);
				printf("¿Más ingredientes? (s/n)\n ");
				fflush(stdout);
				scanf("%s", &seguir);
			} while(seguir[0] != 'n');
		}
		elegirTamanyo(1);
		//TODO meter al archivo
		printf("¿Desea hacer alguna operación más?(s/n)\n");//CONTROL DESPUES DE COMPRAR CUALQUIER COSA.
		do{
			fflush(stdout);
			scanf("%s",&op2);
			if(op2[0]=='s'){
				return 's';
			}
			else if(op2[0]=='n'){
				return 'n';			}
			else{
				printf("Error en el caracter introducido, introduzca 's' para Si y 'n' para No");
			}
		}while(op2[0]!='s' || op2[0]!='n');
		break;
		//Entrante
	case 3:
		printf("Entrantes\n___________________\n");
		for (i = 0; i < 6; ++i) {
			printf("%s",arrayelementos[1][i].nombre);
		}
		fflush(stdout);
		scanf("%s",&op2);
		numero = (int)op2[0];
		numero-=48;
		printf("%s", arrayelementos[1][numero-1].nombre);
		elegirTamanyo(2);
		//AÑADIR AL PEDIDO
		pedido[numeroPedido] = arrayelementos[1][numero-1];
		numeroPedido++;

		printf("¿Desea hacer alguna operación más?(s/n)\n");//CONTROL DESPUES DE COMPRAR CUALQUIER COSA.
		do{
			fflush(stdout);
			scanf("%s",&op2);
			if(op2[0]=='s'){
				return 's';
			}
			else if(op2[0]=='n'){
				return 'n';			}
			else{
				printf("Error en el caracter introducido, introduzca 's' para Si y 'n' para No");
			}
		}while(op2[0]!='s' || op2[0]!='n');
		break;
		//Bebida
	case 4:
		printf("Bebidas\n___________________\n");
		for (i = 0; i < 6; ++i) {
			printf("%s",arrayelementos[2][i].nombre);
		}
		fflush(stdout);
		scanf("%s",&op2);
		numero = (int)op2[0];
		numero-=48;
		printf("%s", arrayelementos[2][numero-1].nombre);

		//AÑADIR AL PEDIDO
		pedido[numeroPedido] = arrayelementos[2][numero-1];
		numeroPedido++;


		printf("¿Desea hacer alguna operación más?(s/n)\n");//CONTROL DESPUES DE COMPRAR CUALQUIER COSA.
		do{
			fflush(stdout);
			scanf("%s",&op2);
			if(op2[0]=='s'){
				return 's';
			}
			else if(op2[0]=='n'){
				return 'n';			}
			else{
				printf("Error en el caracter introducido, introduzca 's' para Si y 'n' para No");
			}
		}while(op2[0]!='s' || op2[0]!='n');
		break;
		//Postre
	case 5:
		printf("Postres\n___________________\n");
		for (i = 0; i < 6; ++i) {
			printf("%s",arrayelementos[3][i].nombre);
		}
		fflush(stdout);
		scanf("%s",&op2);
		numero = (int)op2[0];
		numero-=48;
		printf("%s", arrayelementos[3][numero-1].nombre);
		elegirTamanyo(4);
		//AÑADIR AL PEDIDO
		pedido[numeroPedido] = arrayelementos[3][numero-1];
		printf("%s",pedido[numeroPedido].nombre);
		numeroPedido++;

		printf("¿Desea hacer alguna operación más?(s/n)\n");//CONTROL DESPUES DE COMPRAR CUALQUIER COSA.
		do{
			fflush(stdout);
			scanf("%s",&op2);
			if(op2[0]=='s'){
				return 's';
			}
			else if(op2[0]=='n'){
				return 'n';
			}
			else{
				printf("Error en el caracter introducido, introduzca 's' para Si y 'n' para No");
			}
		}while(op2[0]!='s' || op2[0]!='n');
		break;
		//Descuento
	case 6:
		printf("Introduce un codigo de descuento(5 caracteres):");
		fflush(stdout);
		scanf("%s",&codigo);
		if(codigo=="GBR95"){
			printf("Descuento del 20% aplicado con exito");
			precioTotal*=0.8;
		}else{
			printf("Codigo de descuento erroneo");
		}

		return 's';
		break;
		//Consultar Pedido
	case 7:
		printf("Tu pedido actual es : \n");
		for(i = 0; i <5; i++)
		{
			printf("%s",pedido[i].nombre);
		}
		return 's';
		break;
		//Terminar y pagar
	case 8:

		fp = fopen ("Factura.txt", "w");
		fprintf(fp, "\t Clepizza++ \n");
		fprintf(fp, "\t __________ \n");
		int i;
		for(i = 0 ; i<numeroPedido; i++)
		{
			fprintf(fp, pedido[numeroPedido].nombre);
		}

		fprintf(fp, "\n\n Precio final: %f", precioTotal);

		fclose(fp);
		return 'n';
		break;
	}
}


int main(void){
	int x;
	char seguir;
	Elemento* pedido;
	pedido = (Elemento*)malloc(sizeof(Elemento)*50);
	for (x = 0; x < 50; ++x) {
		pedido[x].nombre=malloc(sizeof(char)*50);
	}
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
	char op[3];
	fgets(op,3,stdin);
	if (op[0]=='1') {
		do{
			seguir = iniciarPedido(arrayElementos,mostrarMenu(), pedido);
		}while(seguir=='s');
		iniciarPedido(arrayElementos,8,pedido);
	}

	//Liberar memoria
	int i;
	int j;
	for(i = 0; i<=6; i++)
	{
		for(j = 0; j<50; j++)
		{
			//free(arrayElementos[i][j].nombre);
			//da error
		}
		free(arrayElementos[i]);
	}
	free(arrayElementos);

	return 0;
}

