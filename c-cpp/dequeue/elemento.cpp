#include "elemento.hpp"

Elemento::Elemento(int num)
{
	this->valor = num;
	this->ant = NULL;
	this->prox = NULL;
}

Elemento::Elemento()
{
	this->valor = 0;
	this->ant = NULL;
	this->prox = NULL;
}

int Elemento::getValor()
{
	return this->valor;
}

Elemento * Elemento::getProx()
{
	return prox;
}

Elemento * Elemento::getAnt()
{
	return ant;
}

void Elemento::setProx(Elemento *el)
{
	this->prox = el;
}
void Elemento::setAnt(Elemento *el)
{
	this->ant = el;
}