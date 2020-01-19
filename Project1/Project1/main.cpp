#include <iostream>
#include <Windows.h>
#include "estructura.h"

int main() {
	Jugador* a = new Jugador;
	Jugador* b = new Jugador;
	a->ficha = 'x';
	estructura s(a, b);
	s.PVE(); 

	return 0;
}