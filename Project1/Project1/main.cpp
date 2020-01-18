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

	estructura s(a, b);
	s.insertarFicha(a, 2, 2);

	int turno = 1;
	while (!s.getGano()) {
		int x = 0;
		int y = 0;
		std::cout << "Por favor inserte una posicion: ";
		std::cin >> x;
		std::cin >> y;
		if (turno == 1) {
			s.insertarFicha(a, x, y);
			turno = 2;
		}
		else
			s.insertarFicha(b, x, y);
		
		s.mostrar();
		s.verificaGane();
		std::cout << "Luego del pequeño susto de tommy";
	}


	s.mostrar();

	return 0;
}