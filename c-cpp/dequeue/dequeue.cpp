#include "dequeue.hpp"

void Dequeue::incluiFinal(int num)
{
	if (listaCheia())
	{
		return;
	}

	Elemento *novo;
	novo = new Elemento(num);

	if (inicio != NULL)
	{
		Elemento *aux;
		aux = fim;

		aux->setProx(novo);
		novo->setAnt(aux);
		fim = novo;
	}
	else
	{
		inicio = novo;
		fim = novo;
	}
	qtd++;
}

void Dequeue::incluiInicio(int num)
{
	if (listaCheia())
	{
		return;
	}

	Elemento *novo;
	novo = new Elemento(num);

	if (inicio != NULL)
	{
		Elemento *aux;
		aux = inicio;

		aux->setAnt(novo);
		novo->setProx(aux);
		inicio = novo;
	}
	else
	{
		inicio = novo;
		fim = novo;
	}
	qtd++;
}

int Dequeue::removeInicio()
{
	if (inicio != NULL)
	{
		Elemento *aux = inicio;
		int num = aux->getValor();

		if (qtd > 1)
		{
			inicio->getProx()->setAnt(NULL);
			inicio = inicio->getProx();
		}
		else
		{
			fim = NULL;
			inicio = NULL;
		}

		qtd--;
		free(aux);
		return num;
	}
	else
	{
		return -1;
	}
}

int Dequeue::removeFinal()
{
	if (fim != NULL)
	{
		Elemento *aux = fim;
		int num = aux->getValor();
		if (qtd > 1)
		{
			fim->getAnt()->setProx(NULL);
			fim = fim->getAnt();
		}
		else
		{
			fim = NULL;
			inicio = NULL;
		}
		qtd--;
		free(aux);
		return num;
	}
	else
	{
		return -1;
	}
}

Dequeue::Dequeue()
{
	this->qtd_max = 0;
	this->qtd = 0;
	this->inicio = NULL;
	this->fim = NULL;
}

Dequeue::Dequeue(int qtd_max)
{
	if (qtd_max > 0)
	{
		this->qtd_max = qtd_max;
	}
	else
	{
		this->qtd_max = 0;
	}
	this->qtd = 0;
	this->inicio = NULL;
	this->fim = NULL;
}

bool Dequeue::listaCheia()
{
	if (qtd == qtd_max)
	{
		return true;
	}
	return false;
}

void Dequeue::mostrar()
{
	if (inicio == NULL)
	{
		printf("\n Lista vazia");
		return;
	}
	Elemento *aux;
	aux = this->inicio;

	printf("\n");
	while (aux != NULL)
	{
		printf(" %d", aux->getValor());
		aux = aux->getProx();
	}
}
