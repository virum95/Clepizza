/*
 * Elemento.c
 *
 *  Created on: 25/4/2015
 *      Author: gorka
 */

#include <stdio.h>
#include <stdlib.h>
#include "Elemento.h"

void handle_line(char *line) {
	printf("%s", line);
	fflush(stdout);
}

int readFile(FILE* f) {
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
			handle_line(buffer);
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
		}
	}
}

void mostrarElemento()
{

}
