#include "estructura.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
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
		for (int j = 0; j < tablero.at(i).size(); j++) {
			std::cout << tablero.at(i).at(j) << " | ";
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

void estructura::regUser() {
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

		srand(time(NULL));
		int turno = rand() % 2;
		if (turno == 1)
			std::cout << J1->nombre << "empieza con el primer turno.\n ";
		else
			std::cout << J2->nombre << "empieza con el primer turno.\n ";

		system("pause");
		if (turno == 1) {
			validacion(x, y, J1);
			if (WinCondition2(J1) != 3)
				gano = true;
			turno = 2;
		}
		else {
			validacion(x, y, J2);
			if (WinCondition2(J2) != 3)
				gano = true;
			turno = 1;
		}
		system("pause");

	}
}

void estructura::validacion(int x, int y, Jugador* J1) {
	std::cout << " Turno de " << J1->nombre << ". " << std::endl;
	
	 if ((x <= 2 && x >= 0) && (y <= 2 && y >= 0) && (tablero.at(x).at(y) == ' ')) {
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

bool estructura::equals3(char a, char b, char c) {
	return a == b && b == c && a != ' ';
}

int estructura::WinCondition2(Jugador* pj) {
	int winner = 3;

	// horizontal
	for (int i = 0; i < 3; i++) {
		if (equals3(tablero[i][0], tablero[i][1], tablero[i][2])) {
			winner = tablero[i][0];
		}
	}

	// Vertical
	for (int i = 0; i < 3; i++) {
		if (equals3(tablero[0][i], tablero[1][i], tablero[2][i])) {
			winner = tablero[0][i];
		}
	}

	// Diagonal
	if (equals3(tablero[0][0], tablero[1][1], tablero[2][2])) {
		winner = tablero[0][0];
	}
	if (equals3(tablero[2][0], tablero[1][1], tablero[0][2])) {
		winner = tablero[2][0];
	}

	int openSpots = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (tablero[i][j] == ' ') {
				openSpots++;
			}
		}
	}

	if (openSpots == 0) {
		return 0;
	}
	else if (winner == 'x') {
		return 1;
	}
	else if (winner == 'o') {
		return -1;
	}
	else
		return 3;
}


void estructura::PVEintermedio() {
	Jugador* CPU = new Jugador();
	CPU->ficha = 'x';
	CPU->nombre = "CPU";
	std::string nombP1, nombP2;
	std::cout << "Digite su nombre" << "\n";
	std::cin >> nombP1;
	J1->nombre = nombP1;
	J1->ficha = 'o';
	std::cout << '\n';
	int posX = 0; int posY = 0;
	srand(time(NULL));
	int turno =1+ rand() % (2-1);
	if (turno == 1)
		std::cout << "Empieza la computadora: ";
	else
		std::cout << "Empieza el ser humano: ";
	system("pause");


	while (!gano) {
		if (turno == 1) {
			if (!juegoOfensivo()) {
				if (!juegoDefensivo()) 
					if(!espacioVacio())
						juegaAleatorio();
			}
			turno = 2;
			mostrar();
			system("pause");
		}
		else {
			system("cls");
			int x = 0, y = 0;
			int eleccion = 0;
			std::cout << "\nPor favor inserte una posicion (x,y): ";
			std::cout << "\n\t=>Posicion x:";  std::cin >> x;
			std::cout << "\n\t=>Posicion y:";  std::cin >> y;
			validacion(x, y, J1);
			turno = 1;
			system("pause");
		}
		if (WinCondition2(J1) != 3 || WinCondition2(J2) != 3)
			gano = true;
	}
}
bool estructura::espacioVacio() {
	int cont = 0;
	int auxY = 0, auxX = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (tablero[i][j] == ' ') {
				cont++; auxX = i; auxY = j;
			}
		}
	}
	if (cont == 1) {
		tablero[auxX][auxY] = 'x';
		return true;
	}

	return false;
}

bool estructura::juegaAleatorio() {
	srand(time(NULL));
	bool movio = false;

	while (!movio) {
		int posX = rand() % 2;
		int posY = rand() % 2;

		if (tablero[posX][posY] == ' ') {
			tablero[posX][posY] = 'x';
			movio = true; return true;
		}
	}
}
bool estructura::juegoOfensivo() {
	//verificacion de diagonales:
		// caso 1: x |   | x  caso 2:  x |   |      caso 3:   |   | 
		//           |   |               | x |			      | x | 
		//         x |   | x             |   |  		    x |   | 

	if (tablero[0][0] == 'x' && tablero[1][1] == 'x' && tablero[2][2] == ' ') {
		tablero[2][2] = 'x'; //caso 2
		return true;
	}
	else if (tablero[0][2] == 'x' && tablero[1][1] == 'x' && tablero[2][0] == ' ') {
		tablero[2][0] = 'x'; //caso 2 invertido
		return true;
	}
	else if (tablero[2][0] == 'x' && tablero[1][1] == 'x' && tablero[0][2] == ' ') {
		tablero[0][2] = 'x'; //caso 3
		return true;
	}
	else if (tablero[2][2] == 'x' && tablero[1][1] == 'x' && tablero[0][0] == ' ') {
		tablero[0][0] = 'x'; //caso 3 invertido
		return true;
	}
	else if (tablero[0][0] == 'x' && tablero[1][1] == ' ' && tablero[2][2] == 'x') {
		tablero[1][1] = 'x'; //caso 1
		return true;
	}
	else if (tablero[0][2] == 'x' && tablero[1][1] == ' ' && tablero[2][0] == 'x') {
		tablero[1][1] = 'x'; //caso 1
		return true;
	}
	//verificacion de horizontal y vertical: 	
	for (int i = 0; i < 3; i++) {
		//jugadas a la defensiva
		if (tablero[i][0] == 'x' && tablero[i][1] == 'x' && tablero[i][2] == ' ') {
			tablero[i][2] = 'x';//verificacion horizontal x|x|~
			return true; break;
		}
		else if (tablero[i][1] == 'x' && tablero[i][2] == 'x' && tablero[i][0] == ' ') {
			tablero[i][0] = 'x';//verificacion horizontal = ~|x|x
			return true;
		}
		else if (tablero[i][0] == 'x' && tablero[i][2] == 'x' && tablero[i][1] == ' ') {
			tablero[i][1] = 'x';//verificacion horizontal = x|~|x
			return true;
		}
		else if (tablero[0][i] == 'x' && tablero[1][i] == 'x' && tablero[2][i] == ' ') {
			tablero[2][i] = 'x';//verificacion vertical	= x/x/~
			return true;
		}
		else if (tablero[1][i] == 'x' && tablero[2][i] == 'x' && tablero[0][i] == ' ') {
			tablero[2][i] = 'x';//verificacion vertical = ~/x/x
			return true;
		}
		else if (tablero[0][i] == 'x' && tablero[2][i] == 'x' && tablero[1][i] == ' ') {
			tablero[1][i] = 'x';//verificacion vertical = x/~/x
			return true;
		}
	}
	return false;
}
bool estructura::juegoDefensivo() {
	//verificacion de diagonales:
	// caso 1: o |   | o  caso 2:  o |   |      caso 3:   |   | x
	//           | x |               | o |			      | o | 
	//         o |   | o             |   | x		    o |   | 

	if (tablero[0][0] == 'o' && tablero[1][1] == 'o' && tablero[2][2] == ' ') {
		tablero[2][2] = 'x'; //caso 2
		return true;
	}
	else if (tablero[0][2] == 'o' && tablero[1][1] == 'o' && tablero[2][0] == ' ') {
		tablero[2][0] = 'x'; //caso 2 invertido
		return true;
	}
	else if (tablero[2][0] == 'o' && tablero[1][1] == 'o' && tablero[0][2] == ' ') {
		tablero[0][2] = 'x'; //caso 3
		return true;
	}
	else if (tablero[2][2] == 'o' && tablero[1][1] == 'o' && tablero[0][0] == ' ') {
		tablero[0][0] = 'x'; //caso 3 invertido
		return true;
	}
	else if (tablero[0][0] == 'o' && tablero[1][1] == ' ' && tablero[2][2] == 'o') {
		tablero[1][1] = 'x'; //caso 1
		return true;
	}
	else if (tablero[0][2] == 'o' && tablero[1][1] == ' ' && tablero[2][0] == 'o') {
		tablero[1][1] = 'x'; //caso 1
		return true;
	}
		//verificacion de horizontal y vertical: 	
		for (int i = 0; i < 3; i++) {
			//jugadas a la defensiva
			if (tablero[i][0] == 'o' && tablero[i][1] == 'o' && tablero[i][2] == ' ') {
				tablero[i][2] = 'x';//verificacion horizontal o|o|x
				return true; 
			}
			else if (tablero[i][1] == 'o' && tablero[i][2] == 'o' && tablero[i][0] == ' ') {
				tablero[i][0] = 'x';//verificacion horizontal = x|o|o
				return true;
			}
			else if (tablero[i][0] == 'o' && tablero[i][2] == 'o' && tablero[i][1] == ' ') {
				tablero[i][1] = 'x';//verificacion horizontal = o|x|o
				return true;
			}
			else if (tablero[0][i] == 'o' && tablero[1][i] == 'o' && tablero[2][i] == ' ') {
				tablero[2][i] = 'x';//verificacion vertical	= o/o/x
				return true;
			}
			else if (tablero[1][i] == 'o' && tablero[2][i] == 'o' && tablero[0][i] == ' ') {
				tablero[2][i] = 'x';//verificacion vertical = x/o/o
				return true;
			}
			else if (tablero[0][i] == 'o' && tablero[2][i] == 'o' && tablero[1][i] == ' ') {
				tablero[1][i] = 'x';//verificacion vertical = o/x/o
				return true;
			}
		}

		return false;
	}

void estructura::PVE() {
	Jugador* CPU = new Jugador();
	CPU->ficha = 'x';
	CPU->nombre = "CPU";
	std::string nombP1, nombP2;
	std::cout << "Digite su nombre" << "\n";
	std::cin >> nombP1;
	J1->nombre = nombP1;
	J1->ficha = 'o';
	std::cout << '\n';
	int posX = 0; int posY = 0;
	srand(time(NULL));
	int turno = 1+rand() % (2 - 1);
	if (turno == 1)
		std::cout << "Empieza la computadora: ";
	else
		std::cout << "Empieza el ser humano: ";
	system("pause");

	while (!gano) {
		system("cls");

		if (turno == 1) {
			int bestScore = -2;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (tablero[i][j] == ' ') {
						tablero[i][j] = CPU->ficha;
						int score = minimax(false, CPU->ficha);
						tablero.at(i).at(j) = ' ';
						if (score > bestScore) {
							bestScore = score;
							posX = i;
							posY = j;
						}
					}
				}
			}
			tablero.at(posX).at(posY) = CPU->ficha;
			mostrar();
			turno = 2;
			if (WinCondition2(CPU) != 3)
				gano = true;
			system("pause");
		}
		else {
			system("cls");
			int x = 0, y = 0;
			int eleccion = 0;
			std::cout << "\nPor favor inserte una posicion (x,y): ";
			std::cout << "\n\t=>Posicion x:";  std::cin >> x;
			std::cout << "\n\t=>Posicion y:";  std::cin >> y;
			validacion(x, y, J1);
			if (WinCondition2(J1) != 3)
				gano = true;
			turno = 1;
			system("pause");
		}

	}
}

int estructura::minimax(bool estaMax, char ficha) {
	Jugador* pj = new Jugador();
	pj->ficha = ficha;

	int result = WinCondition2(pj);
	if (result != 3) {
		return result;
	}

	if (estaMax) {
		int bestScore = -2;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (tablero.at(i).at(j) == ' ') {
					tablero.at(i).at(j) = 'x';
					int score = minimax(false, 'x');
					tablero.at(i).at(j) = ' ';
					if (score > bestScore)
						bestScore = score;
				}
			}
		}
		return bestScore;
	}
	else {
		int bestScore = 2;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (tablero.at(i).at(j) == ' ') {
					tablero.at(i).at(j) = 'o';
					int score = minimax(true, 'o');
					tablero.at(i).at(j) = ' ';
					if (score < bestScore)
						bestScore = score;
				}
			}
		}
		return bestScore;
	}
}



