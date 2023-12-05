#include "pilha.cpp"
#include "fila.cpp"
#include <iostream>

using namespace std;

int main()
{
	Pilha stack = Pilha(5);

	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);

	stack.mostrar();

	return 0;
}
