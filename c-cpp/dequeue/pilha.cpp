#include "pilha.hpp"

Pilha::Pilha(int qtd_max)
{
	if (qtd_max > 0)
	{
		this->qtd_max = qtd_max;
	}
	else
	{
		this->qtd_max = 0;
	}
}

bool Pilha::push(int num)
{
	if (!listaCheia())
	{
		incluiFinal(num);
		return true; // elemento incluido
	}
	return false; // falha ao incluir
}

int Pilha::pop()
{
	return removeFinal();
}

int Pilha::getQtd()
{
	return this->qtd;
}

int Pilha::getTopo()
{
	if (hasElements())
	{
		return fim->getValor();
	}
	return -1;
}

bool Pilha::hasElements()
{
	return qtd > 0;
}