#include <iostream>
#include <Windows.h>
#include "estructura.h"

int main() {
	Jugador* a = new Jugador;
	Jugador* b = new Jugador;
	a->ficha = 'X';
	estructura s(a, b);
	s.PvP(); 

	return 0;
}