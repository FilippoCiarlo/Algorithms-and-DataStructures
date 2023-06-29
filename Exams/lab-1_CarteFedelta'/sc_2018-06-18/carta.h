/**
 * @file carta.h
 * @author filippo
 * @brief Header File "carta"
 * @version 0.1
 * @date 2022-09-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef CARTA_H_
#define CARTA_H_

struct carta
{
	char nome[40];
	int punti;
};

typedef carta tipo_inf;

int compare(tipo_inf,tipo_inf);
void copy(tipo_inf&,tipo_inf);
void print(tipo_inf);

#endif /* CARTA_H_ */