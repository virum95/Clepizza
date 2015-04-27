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
	//strcpy(e->nombre, line);
	int i;

	for(i = 0; i<15; i++)
	{
		e->nombre[i] = line[i];
	}

}

Elemento readFile(FILE* f, Elemento e, int line) {
	int size = 1024, pos;
	int c;
	int lineaActual = 0;
	int fin = 0;
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
			if(line == lineaActual){
				handle_line(buffer, &e);
				fin = 1;
			}
			//mostrarElemento(e);
			lineaActual++;
		} while(c != EOF || fin!=1);
		fclose(f);


	}
	free(buffer);
	return e;
}

Elemento** iniciarElementos (Elemento** arrayElementos, int size )
{
	int i;
	int j;
	int contadorTipo = 1;
	for(i = 0; i<=size; i++)
	{
		if(contadorTipo == 1)
		{
			for(j = 0; j<50; j++)
			{
				arrayElementos[i][j].tipo = contadorTipo;
				arrayElementos[i][j].nombre = (char*) malloc(sizeof(char)*50);
				arrayElementos[i][j] = readFile(fopen("Pizzas.txt", "r"), arrayElementos[i][j],j);
			}
		}
		if(contadorTipo == 5)
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
		if(contadorTipo == 2)
		{
			for(j = 0; j<50; j++)
			{
				arrayElementos[i][j].tipo = contadorTipo;
				arrayElementos[i][j].nombre = (char*) malloc(sizeof(char)*50);
				arrayElementos[i][j] = readFile(fopen("Ingredientes.txt", "r"), arrayElementos[i][j],j);
			}
		}

		contadorTipo++;
	}
	return arrayElementos;
}

void mostrarElemento(Elemento e)
{
	printf("%s",e.nombre);
	fflush(stdout);
}
