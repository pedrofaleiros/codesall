#ifndef FILA_H
#define FILA_H

#include <iostream>
#include "dequeue.cpp"

class Fila : public Dequeue
{

public:
	Fila(int qtd_max);

	bool insert(int num);

	int remove();

	int getQtd();

	int getFirst();

	int getLast();

	bool hasElements();
};

#endif