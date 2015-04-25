/*
 * Elemento.c
 *
 *  Created on: 25/4/2015
 *      Author: gorka
 */

#include <stdio.h>
#include <stdlib.h>
#include "Elemento.h"

void iniciarElementos ()
{

}

void mostrarElemento(Elemento e)
{
	switch (e.) {
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
