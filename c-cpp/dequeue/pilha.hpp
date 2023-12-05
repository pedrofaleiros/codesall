#ifndef PILHA_H
#define PILHA_H

#include "dequeue.cpp"

using namespace std;

class Pilha : public Dequeue
{
public:
	Pilha(int qtd_max);

	bool push(int num);

	int pop();

	int getQtd();

	int getTopo();

	bool hasElements();
};

#endif