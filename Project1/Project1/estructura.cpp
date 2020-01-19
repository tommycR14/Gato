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
		if (turno == 1) {
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

void estructura::validacion(int x, int y, Jugador* J1) {
	std::cout << " Turno de " << J1->nombre << ". " << std::endl;
	if ((x == 0 && y == 0) && tablero.at(0).at(0) == ' ') {
		insertarFicha(J1, x, y);
		mostrar();
	}
	else if ((x == 0 && y == 1) && (tablero.at(0).at(1) == ' ')) {
		insertarFicha(J1, x, y);
		mostrar();
	}
	else if ((x == 0 && y == 2) && (tablero.at(0).at(2) == ' ')) {
		insertarFicha(J1, x, y);
		mostrar();
	}
	else if ((x == 1 && y == 0) && (tablero.at(1).at(0) == ' ')) {
		insertarFicha(J1, x, y);
		mostrar();
	}
	else if ((x == 1 && y == 1) && (tablero.at(1).at(1) == ' ')) {
		insertarFicha(J1, x, y);
		mostrar();
	}
	else if ((x == 1 && y == 2) && (tablero.at(1).at(1) == ' ')) {
		insertarFicha(J1, x, y);
		mostrar();
	}
	else if ((x == 2 && y == 0) && (tablero.at(2).at(0) == ' ')) {
		insertarFicha(J1, x, y);
		mostrar();
	}
	else if ((x == 2 && y == 1) && (tablero.at(2).at(1) == ' ')) {
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
int estructura::WinCondition2(Jugador* pj) {
	int lleno = 0;
	for (int i = 0; i < tablero.size(); i++) {
		bool fila = true;
		bool colm = true;
		for (int j = 0; j < tablero.at(i).size(); j++) {
			if (!(tablero.at(i).at(j) == pj->ficha))
				fila = false;
			if (!(tablero.at(j).at(i) == pj->ficha))
				colm = false;
			if (!(tablero.at(i).at(j) == ' '))
				++lleno;
		}
		if (fila || colm){
			if (pj->ficha == 'x')
				return 1;
			else
				return -1;
		}
		if (lleno == 9) {
			return 0;
		}

	}


	if (tablero.at(0).at(0) == pj->ficha && tablero.at(1).at(1) == pj->ficha && tablero.at(2).at(2) == pj->ficha)
	 {
		if (pj->ficha == 'x')
			return 1;
		else
			return -1;
	}
	if (tablero.at(0).at(2) == pj->ficha && tablero.at(1).at(1) == pj->ficha && tablero.at(2).at(0) == pj->ficha)
	{
		if (pj->ficha == 'x')
			return 1;
		else
			return -1;
	}

	
}

int estructura::WinCondition(Jugador* pj) {
	int lleno = 0;
	for (int i = 0; i < tablero.size(); i++) {
		bool fila = true;
		bool colm = true;
		for (int j = 0; j < tablero.at(i).size(); j++) {
			if (!(tablero.at(i).at(j) == pj->ficha))
				fila = false;
			if (!(tablero.at(j).at(i) == pj->ficha))
				colm = false;
			if (!(tablero.at(i).at(j) == ' '))
				++lleno;
		}
		if (fila || colm)
			gano = true;
		if (lleno == 9) {
			gano = true;
			return 0;
		}

	}


	if (tablero.at(0).at(0) == pj->ficha && tablero.at(1).at(1) == pj->ficha && tablero.at(2).at(2) == pj->ficha)
		gano = true;// check diagonal principal
	if (tablero.at(0).at(2) == pj->ficha && tablero.at(1).at(1) == pj->ficha && tablero.at(2).at(0) == pj->ficha)
		gano = true; // check diagonal principal

	if (pj->ficha == 'x')
		return 1;
	else
		return -1;
}


void estructura::PVE() {
	int turno = 1;
	Jugador* CPU = new Jugador();
	CPU->ficha = 'x';
	CPU->nombre = "CPU";
	std::string nombP1, nombP2;
	std::cout << "Digite su nombre" << "\n";
	std::cin >> nombP1;
	J1->nombre = nombP1;
	J1->ficha = 'o';
	std::cout << '\n';
	int posX; int posY;
	
	while (!gano) {
		system("cls");

		if (turno == 1) {
			int bestScore = -INFINITY;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					// Is the spot available?
					if (tablero[i][j] == ' ') {
						tablero[i][j] = 'x';
						int score = minimax(tablero, 0, false, CPU->ficha);
						tablero[i][j] = ' ';
						if (score > bestScore) {
							bestScore = score;
							posX = i;
							posY = j;
						}
					}
				}
			}
			tablero[posX][posY] = 'x';
			mostrar();
			turno = 2;
			WinCondition(CPU);
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
				WinCondition(J1);
				turno = 1;
				system("pause");
		}
		
	}
}

int estructura::minimax(std::vector<std::vector<char>> tablero, int profundidad, bool estaMax,char ficha) {
	Jugador* pj = new Jugador();
	pj->ficha = ficha;

	int result = WinCondition2(pj);
	if (!gano) {
		return result;
	}

	if (estaMax) {
		int bestScore = -INFINITY;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				// Is the spot available?
				if (tablero[i][j] == ' ') {
					tablero[i][j] = 'x';
					int score = minimax(tablero, profundidad + 1, false, pj->ficha);
					tablero[i][j] = ' ';
					if (score > bestScore)
						bestScore = score;
				}
			}
		}
		return bestScore;
	}
	else {
		int bestScore = INFINITY;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				// Is the spot available?
				if (tablero[i][j] == ' ') {
					tablero[i][j] = 'o';
					int score = minimax(tablero, profundidad + 1, true, pj->ficha);
					tablero[i][j] = ' ';
					if (score < bestScore)
						bestScore = score;
				}
			}
		}
		return bestScore;
	}
}



