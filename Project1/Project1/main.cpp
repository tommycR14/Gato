#include <iostream>
#include <Windows.h>
#include "estructura.h"

int main() {
	Jugador* a = new Jugador;
	a->ficha = 'X';
	a->nombre = "David";
	Jugador* b = new Jugador;
	b->ficha = 'O';
	b->nombre = "Tommy";

	estructura s (a,b);
	s.insertarFicha(a,2,2);
	s.mostrar();

	return 0;
}