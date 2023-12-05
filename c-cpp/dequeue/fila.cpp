#include "fila.hpp"

Fila::Fila(int qtd_max)
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

bool Fila::insert(int num)
{
	if (!listaCheia())
	{
		incluiFinal(num);
		return true; // elemento incluido
	}
	return false; // falha ao incluir
}

int Fila::remove()
{
	return removeInicio();
}

int Fila::getQtd()
{
	return this->qtd;
}

int Fila::getFirst()
{
	if (hasElements())
	{
		return inicio->getValor();
	}
	return -1;
}

int Fila::getLast()
{
	if (hasElements())
	{
		return fim->getValor();
	}
	return -1;
}

bool Fila::hasElements()
{
	return qtd > 0;
}