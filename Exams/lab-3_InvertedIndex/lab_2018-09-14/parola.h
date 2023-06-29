/**
 * @file parola.h
 * @author filippo
 * @brief header file "parola"
 * @version 0.1
 * @date 2022-09-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "liste.h"

struct parola
{
    char p[80]; //parola
    int n_doc;  //numero di documenti che contengono la parola
    lista l;    //lista dei documenti
};