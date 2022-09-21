/*******************************/
/* HEADER MODULO "tipo" */
/*******************************/
#ifndef TIPO_H_
#define TIPO_H_

struct tipo_inf
{
	char data[7];
	char ora_i[5];
	char ora_f[5];
	char descr[51];
};

int compare(tipo_inf,tipo_inf);
void copy(tipo_inf&,tipo_inf);
void print(tipo_inf);

#endif /* TIPO_H_ */
