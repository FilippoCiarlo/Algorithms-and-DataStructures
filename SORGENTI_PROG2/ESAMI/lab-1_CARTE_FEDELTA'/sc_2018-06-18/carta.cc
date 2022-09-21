/**
 * @file carta.cc
 * @author filippo
 * @brief definizione del modulo "carta"
 * @version 0.1
 * @date 2022-09-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <cstring>
#include "carta.h"

using namespace std;

/**
 * @brief compara i due parametri in ingresso
 * 
 * @param t1 primo parametro
 * @param t2 secondo parametro
 * @return int (t1<t2) <0, (t1==t2) =0, (t1>t2) >0
 */
int compare(tipo_inf t1,tipo_inf t2)
{
	return strcmp(t1.nome,t2.nome);
}

/**
 * @brief copia il contenuto si source in dest
 * 
 * @param dest variabile di destinazione
 * @param source variabile sorgente
 */
void copy(tipo_inf& dest,tipo_inf source)
{
	dest = source;
}

/**
 * @brief stampa il campo informazione del parametro 
 * 
 * @param t
 */
void print(tipo_inf t)
{
	cout<<t.nome<<" "<<t.punti<<endl;
}
