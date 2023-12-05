#include <iostream>
#include "pilha.hpp"
#include "fila.hpp"

using namespace std;

int main()
{
	Pilha p = Pilha(3);

	p.push(1);
	p.push(2);
	p.push(3);

	p.mostrar();

	return 0;
}