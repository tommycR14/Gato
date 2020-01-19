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

bool estructura::getGano() {
	return gano;
}
void estructura::insertarFicha(Jugador* j, int x, int y) {
			tablero.at(x).at(y) = j->ficha;
}

void estructura::regUser(){
	std::string nombP1, nombP2;
	std::cout << " Jugador 1. Digite su nombre" << "\n";
	std::cin >> nombP1;
	J1->nombre = nombP1;
	J1->ficha = 'x';

	std::cout << '\n';

	std::cout << " Jugador 2. Digite su nombre" << "\n";
	std::cin >> nombP1;
	J2->nombre = nombP1;
	J2->ficha = 'o';
}

void estructura::PvP() {
	int turno = 1;
	regUser();
	mostrar();
	system("pause");

	while (!getGano()) {
		system("cls");
		int x = 0, y = 0;
		int eleccion = 0;
		std::cout << "\nPor favor inserte una posicion (x,y): ";
		std::cout << "\n\t=>Posicion x:";  std::cin >> x;
		std::cout << "\n\t=>Posicion y:";  std::cin >> y;
		if (turno ==1) {
			validacion(x, y, J1); 
			WinCondition(J1);
			turno = 2;
		}
		else {
			validacion(x, y, J2);
			WinCondition(J1);
			turno = 1;
		}
		system("pause");

	}
}

void estructura::validacion(int x, int y,Jugador* J1) { 
		std::cout << " Turno de " << J1->nombre << ". " << std::endl;
		if ((x == 0 && y == 0)&& tablero.at(0).at(0) == ' ') {
				insertarFicha(J1, x, y);
				mostrar();
		}
		else if ((x == 0 && y == 1)&& (tablero.at(0).at(1) == ' ')) {
				insertarFicha(J1, x, y);
				mostrar();
		}
		else if ((x == 0 && y == 2) && (tablero.at(0).at(2) == ' ')) {
				insertarFicha(J1, x, y);
				mostrar();
		}
		else if ((x == 1 && y == 0)&& (tablero.at(1).at(0) == ' ')) {
				insertarFicha(J1, x, y);
				mostrar();
		}
		else if ((x == 1 && y == 1)&& (tablero.at(1).at(1) == ' ')) {
				insertarFicha(J1, x, y);
				mostrar();
		}
		else if ((x == 1 && y == 2)&& (tablero.at(1).at(1) == ' ')) {
				insertarFicha(J1, x, y);
				mostrar();
		}
		else if ((x == 2 && y == 0)&&(tablero.at(2).at(0) == ' ')) {
				insertarFicha(J1, x, y);
				mostrar();
		}
		else if ((x == 2 && y == 1)&& (tablero.at(2).at(1) == ' ')) {	
				insertarFicha(J1, x, y);
				mostrar();
		}
		else if ((x == 2 && y == 2) && (tablero.at(2).at(2) == ' ')) {
			insertarFicha(J1, x, y);
			mostrar();
		}
		else {
			int x2, y2;
			std::cout << "\nMovimiento Invalido...!! " << std::endl;
			std::cout << "\nPor favor inserte una posicion (x,y): ";
			std::cout << "\n\t=> Posicion x:";  std::cin >> x2;
			std::cout << "\n\t=> Posicion y:";  std::cin >> y2;
			validacion(x2, y2, J1);
		}
			
	
}
void estructura::WinCondition(Jugador* pj){

	for (int i = 0; i < tablero.size(); i++) {
		bool fila = true;
		bool colm = true;
		for (int j = 0; j < tablero.at(i).size(); j++) {
			if (!(tablero.at(i).at(j) == pj->ficha))
				fila = false;
			if (!(tablero.at(j).at(i) == pj->ficha))
				colm = false;
		}
		if (fila || colm)
			gano = true;
	}


	if (tablero.at(0).at(0) == pj->ficha && tablero.at(1).at(1) == pj->ficha && tablero.at(2).at(2) == pj->ficha)
		gano = true;// check diagonal principal
	if (tablero.at(0).at(2) == pj->ficha && tablero.at(1).at(1) == pj->ficha && tablero.at(2).at(0) == pj->ficha)
		gano = true; // check diagonal principal
}


