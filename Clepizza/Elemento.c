/*
 * Elemento.c
 *
 *  Created on: 25/4/2015
 *      Author: gorka
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Elemento.h"

void handle_line(char *line, Elemento e) {
	strcpy(e.nombre, line);


int readFile(FILE* f, char* e) {
	int size = 1024, pos;
	int c;
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
			// line is now in buffer
			handle_line(buffer, e);
		} while(c != EOF);
		fclose(f);
	}
	free(buffer);
	return 0;
}

void iniciarElementos (Elemento **arrayElementos, int size )
{
	int i;
	int contadorTipo = 1;
	for(i = 0;i<size;i++)
	{
		if(contadorTipo == 1)
		{
			readFile(fopen("Pizzas.txt", "r"),arrayElementos[0]->nombre);
			arrayElementos[0]++;
		}
	}
}

void mostrarElemento(Elemento e)
{
	switch (e.tipo) {
	case 1:
		printf("Pizza ");
		break;
	case 2:
		printf("Entrante ");
		break;
	case 3:
		printf("Bebida ");
		break;
	case 4:
		printf("Postre ");
		break;
	case 5:
		printf("Ingrediente ");
		break;
	default:
		break;
	}
	switch (e.size) {
	case 'p':
		printf("pequeñ@: ");
		break;
	case 'm':
		printf("median@: ");
		break;
	case 'g':
		printf("grande: ");
		break;
	default:
		break;
	}
	printf("%s. Precio: %f€.",e.nombre,e.precio);

}
