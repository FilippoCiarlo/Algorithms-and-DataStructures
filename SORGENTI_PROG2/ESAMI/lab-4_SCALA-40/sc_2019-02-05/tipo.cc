/**
 * @file tipo.cc
 * @author filippo
 * @brief definizione del modulo "tipo"
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
    return (t1.seme - t2.seme) + (t1.valore - t2.valore);
}
void copy(tipo_inf& dest, tipo_inf source)
{
    dest = source;
}
void print(tipo_inf t)
{
    cout<<t.valore<<t.seme;
}