/**
 * @file tipo.cc
 * @author filippo
 * @brief definizione modulo "tipo"
 * @version 0.1
 * @date 2022-09-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <cstring>
#include "tipo.h"

using namespace std;

int compare(tipo_inf t1, tipo_inf t2)
{
    return (t1.id - t2.id);
}

void copy(tipo_inf& dest, tipo_inf source)
{
    dest = source;
}

void print(tipo_inf t)
{
    cout<<t.id<<" "<<t.nome<<" "<<t.tipo<<endl;
}