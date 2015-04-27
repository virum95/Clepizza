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

void handle_line(char *line, Elemento* e) {
	strcpy(e->nombre, line);
	//Jorca tonto
}

int readFile(FILE* f, Elemento* e) {
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
			e++;
		} while(c != EOF);
		fclose(f);
	}
	free(buffer);
	return 0;
}

void iniciarElementos (Elemento** arrayElementos, int size )
{
	int i;
	int contadorTipo = 1;
	for(contadorTipo = 1;contadorTipo<=size;contadorTipo++)
	{
		if(contadorTipo == 1)
		{
			for(i = 0; i<10; i++)
			{
		//	readFile(fopen("Pizzas.txt", "r"), arrayElementos[0]);
			arrayElementos[contadorTipo-1]->tipo = contadorTipo;
			arrayElementos[contadorTipo-1]++;
			}
		}
		if(contadorTipo == 2)
		{
			for(i = 0; i<10; i++)
			{
		//	readFile(fopen("Entrantes.txt", "r"), arrayElementos[0]);
			arrayElementos[contadorTipo-1]->tipo = contadorTipo;
			arrayElementos[contadorTipo-1]++;
			}
		}
		if(contadorTipo == 3)
		{
			for(i = 0; i<10; i++)
			{
	//	readFile(fopen("Bebidas.txt", "r"), arrayElementos[0]);
			arrayElementos[contadorTipo-1]->tipo = contadorTipo;
			arrayElementos[contadorTipo-1]++;
			}
		}
		if(contadorTipo == 4)
		{
			for(i = 0; i<10; i++)
			{
	//		readFile(fopen("Postres.txt", "r"), arrayElementos[0]);
			arrayElementos[contadorTipo-1]->tipo = contadorTipo;
			arrayElementos[contadorTipo-1]++;
			}
		}
	}
}

void mostrarElemento(Elemento e)
{
	printf("%s",e.nombre);
}
