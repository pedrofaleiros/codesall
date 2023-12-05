#ifndef PILHA_H
#define PILHA_H

#include <iostream>
#include "dequeue.hpp"

class Pilha : public Dequeue
{
public:
	Pilha(int qtd_max)
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

	bool push(int num)
	{
		if (!listaCheia())
		{
			incluiFinal(num);
			return true; // elemento incluido
		}
		return false; // falha ao incluir
	}

	int pop()
	{
		return removeFinal();
	}

	int getQtd()
	{
		return this->qtd;
	}

	int getTopo()
	{
		if (hasElements())
		{
			return fim->getValor();
		}
		return -1;
	}

	bool hasElements()
	{
		return qtd > 0;
	}
};

#endif