/*
 * Elemento.h
 *
 *  Created on: 25/4/2015
 *      Author: gorka
 */

#ifndef ELEMENTO_H_
#define ELEMENTO_H_

typedef struct{
	int tipo;
	char* nombre;
	char size; /* 'p', 'm' o 'g'*/
	float precio;
} Elemento;

void iniciarElementos ();

void mostrarElemento (Elemento e);

#endif /* ELEMENTO_H_ */
