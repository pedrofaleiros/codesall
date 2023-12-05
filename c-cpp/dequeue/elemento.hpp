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
	Elemento(int num);

	Elemento();

	int getValor();

	Elemento *getProx();

	Elemento *getAnt();

	void setProx(Elemento *el);

	void setAnt(Elemento *el);
};

#endif