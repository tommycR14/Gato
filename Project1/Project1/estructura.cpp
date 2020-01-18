#include "estructura.h"
#include <iostream>
estructura::estructura(Jugador* a, Jugador* b) {
	 J1 = a; 
	 J2 = b; 
	 for (int i = 0; i < 3; i++) {
		 std::vector<char> linea;
		 for (int j = 0; j < 3; j++) {
			 linea.push_back(' ');
		 }
		 tablero.push_back(linea);
	 }
	 gano = false;
}

void estructura::mostrar() {
	for (int i = 0; i < tablero.size(); i++) {
		for (int j = 0; j < tablero.at(i).size() ; j++) {
			std::cout<<tablero.at(i).at(j)<<" | ";
		}
		std::cout << "\n";
	}
}

void estructura::verificaGane() {
	for (int i = 0; i < tablero.size(); i++) {
		for (int j = 0; j < tablero.at(i).size(); j++) {
			tablero.at(i).at(j);
		}
	}
}

bool estructura::getGano() {
	return gano;
}
void estructura::insertarFicha(Jugador* j, int x, int y) {
	tablero.at(x).at(y) = j->ficha;
}
