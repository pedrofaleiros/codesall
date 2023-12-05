#ifndef DEQUEUE_H
#define DEQUEUE_H

#include <iostream>
#include "elemento.cpp"

using namespace std;

class Dequeue
{
protected:
	Elemento *inicio;
	Elemento *fim;
	int qtd;
	int qtd_max;

	void incluiFinal(int num);

	void incluiInicio(int num);

	int removeInicio();

	int removeFinal();
	
public:
	Dequeue();

	Dequeue(int qtd_max);
	
	bool listaCheia();

	void mostrar();
};

#endif