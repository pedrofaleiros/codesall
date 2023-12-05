#ifndef FILA_H
#define FILA_H

#include <iostream>
#include "dequeue.hpp"

class Fila : public Dequeue
{

public:
	Fila(int qtd_max)
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

	bool insert(int num)
	{
		if (!listaCheia())
		{
			incluiFinal(num);
			return true; // elemento incluido
		}
		return false; // falha ao incluir
	}

	int remove()
	{
		return removeInicio();
	}

	int getQtd()
	{
		return this->qtd;
	}

	int getFirst()
	{
		if (hasElements())
		{
			return inicio->getValor();
		}
		return -1;
	}

	int getLast()
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