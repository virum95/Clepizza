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
}


int readLine(FILE* f, Elemento* e) {
	int pos=0;
	int i;
	char c;

	for(i = 0; i<10; i++)
	{
	    while(c != EOF && c != (char)(2+i))
	    {
	         c = fgetc(f);
	         if(c != EOF)
	         {
	        	 e[i].nombre[pos] = c;
	        	 //printf("LETRA: %i, %c",c, i+2);
	        	 fflush(stdout);
	          	 pos++;
	         }
	     }
	    pos = 0;
	    }
	    fclose(f);

	    return 0;
}

void iniciarElementos (Elemento** arrayElementos, int size )
{
	int i;
	int j;
	for(i = 1; i<=size; i++)
	{
		for(j = 0; j<10; j++)
		{
			arrayElementos[i][j].tipo = i;
			arrayElementos[i][j].nombre = (char*) malloc(sizeof(char)*20);

		}
	}
	readLine(fopen("Pizzas.txt","r"), arrayElementos[0]);
	//arrayElementos[0][0].nombre="ASDASD";
}

void mostrarElemento(Elemento e)
{
	printf("%s",e.nombre);
	fflush(stdout);
}
