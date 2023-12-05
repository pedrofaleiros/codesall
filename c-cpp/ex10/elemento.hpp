#ifndef ELEMENTO_H
#define ELEMENTO_H

#include <iostream>

using namespace std;

class Elemento
{
private:
	int valor;
	Elemento *prox;
	Elemento *ant;

public:
	Elemento(int num)
	{
		this->valor = num;
		this->ant = NULL;
		this->prox = NULL;
	}

	Elemento()
	{
		this->valor = 0;
		this->ant = NULL;
		this->prox = NULL;
	}

	int getValor()
	{
		return this->valor;
	}

	Elemento *getProx()
	{
		return prox;
	}

	Elemento *getAnt()
	{
		return ant;
	}

	void setProx(Elemento *el)
	{
		this->prox = el;
	}
	void setAnt(Elemento *el)
	{
		this->ant = el;
	}
};

#endif