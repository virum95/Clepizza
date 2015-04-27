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
	//pizza = 1, entrante = 2, bebida = 3, postre = 4, ingrediente = 5
	char* nombre;
} Elemento;

Elemento** iniciarElementos (Elemento** arrayElementos, int size );

void mostrarElemento (Elemento e);

#endif /* ELEMENTO_H_ */
