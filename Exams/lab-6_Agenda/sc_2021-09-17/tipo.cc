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
#include "tipo.h"

using namespace std;

int compare(tipo_inf t1,tipo_inf t2)
{
	if (strcmp(t1.data,t2.data)==0)
		return strcmp(t1.ora_i,t2.ora_i);
    else 
        return strcmp(t1.data,t2.data);
}

void copy(tipo_inf& dest, tipo_inf source)
{
    dest = source;
}

void print(tipo_inf t)
{
    cout<<t.data<<" "<<t.ora_i<<" "<<t.ora_f<<" "<<t.descr<<endl;
}