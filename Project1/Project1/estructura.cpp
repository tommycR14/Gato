#include "estructura.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
estructura::estructura() {
	//Recorre el tablero y lo llena con espacios vacios (' ') en cada posicion

	for (int i = 0; i < 3; i++) {
		std::vector<char> linea;
		for (int j = 0; j < 3; j++) {
			linea.push_back(' ');
		}
		tablero.push_back(linea);
	}
	gano = false;//inicializa la variable en falso
}

void estructura::mostrar() {
	//Se utiliza para recorrer el tablero y mostrarlo en consola
	for (int i = 0; i < tablero.size(); i++) {
		for (int j = 0; j < tablero.at(i).size(); j++) {
			std::cout << tablero.at(i).at(j) << " | ";
		}
		std::cout << "\n";
	}
}

void estructura::PvP(Jugador* J1, Jugador* J2) {
	//inicializa el turno de manera random
	int turno = 1 + rand() % (3 - 1);

	mostrar();
	graph.draw(tablero);
	system("pause");
	//crea el hilo del juego 
	while (!gano) {
		system("cls");
		int x = 0, y = 0;


		srand(time(NULL));
		int turno = rand() % 2;
		if (turno == 1)
			std::cout << J1->nombre << "empieza con el primer turno.\n ";
		else
			std::cout << J2->nombre << "empieza con el primer turno.\n ";

		system("pause");
		//JUEGA J1
		if (turno == 1) {
			std::cout << "\nPor favor inserte una posicion (x,y): ";
			std::cout << "\n\t=>Posicion x:";  std::cin >> x;
			std::cout << "\n\t=>Posicion y:";  std::cin >> y;

			validacion(x, y, J1);//Verica si la posicion es correcta
			if (winCondition(J1) != 3)//Verica si alguien ha ganado o empatado
				gano = true;

			turno = 2;
		}//JUEGA J2
		else {
			std::cout << "\nPor favor inserte una posicion (x,y): ";
			std::cout << "\n\t=>Posicion x:";  std::cin >> x;
			std::cout << "\n\t=>Posicion y:";  std::cin >> y;

			validacion(x, y, J2);//Verica si la posicion es correcta
			if (winCondition(J2) != 3)//Verica si alguien ha ganado o empatado
				gano = true;
			turno = 1;
		}
		system("pause");
	}
}

//Verica si la posicion ingresada es correcta
void estructura::validacion(int x, int y, Jugador* J1) {
	std::cout << " Turno de " << J1->nombre << ". " << std::endl;
	//Primero verifica que las cordenadas esten dentro del rango del tablero
	//luego verifica que el espacio ingresado se encuentre en blanco.
	 if ((x <= 2 && x >= 0) && (y <= 2 && y >= 0) && (tablero.at(x).at(y) == ' ')) {
		insertarFicha(J1, x, y);
		mostrar();
		graph.draw(tablero);
		system("pause");
	}//en caso de que no sea valido vuelve a solicitar la insercion
	else {
		int x2, y2;
		std::cout << "\nMovimiento Invalido...!! " << std::endl;
		std::cout << "\nPor favor inserte una posicion (x,y): ";
		std::cout << "\n\t=> Posicion x:";  std::cin >> x2;
		std::cout << "\n\t=> Posicion y:";  std::cin >> y2;
		validacion(x2, y2, J1);
	}


}


// Verifica que las fichas sean iguales 
// y diferentes de espacio.
bool estructura::verificaIgualdad(char a, char b, char c) {
	return a == b && b == c && a != ' ';
}

//verifica que alguien gana, empata o ninguna de las anteriores
int estructura::winCondition(Jugador* pj) {
	int winner = 3;

	for (int i = 0; i < 3; i++) {
		// Horizontal
		if (verificaIgualdad(tablero[i][0], tablero[i][1], tablero[i][2])) {
			winner = tablero[i][0]; break;
		}
		// Vertical
		else if (verificaIgualdad(tablero[0][i], tablero[1][i], tablero[2][i])) {
			winner = tablero[0][i]; break;
		}
	}

	// Diagonales
	if (verificaIgualdad(tablero[0][0], tablero[1][1], tablero[2][2])) {
		winner = tablero[0][0];
	}
	if (verificaIgualdad(tablero[2][0], tablero[1][1], tablero[0][2])) {
		winner = tablero[2][0];
	}

	if (verificaEspaciosVacios() == 0) {
		return 0;//retorna 0 en caso de que haya un empate
	}
	else if (winner == 'x') {
		return 1;//retorna 1 en caso de que sea 'x' la que gane
	}
	else if (winner == 'o') {
		return -1;//retorna -1 en caso de que 'o' gane
	}
	else
		return 3;//retorna 3 en caso de que nadie gane
}

//cuenta cuantos espacios vacios hay. 
int estructura::verificaEspaciosVacios() {
	int espaciosVacios = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (tablero[i][j] == ' ') {
				espaciosVacios++;
			}
		}
	}
	return espaciosVacios;
}

//Dificultad intermedia que permite ganarle a la compu. 
void estructura::PVEintermedio(Jugador* J1, Jugador* CPU) {
	graph.eventos();
	int posX = 0; int posY = 0;
	srand(time(NULL));//se inicializa la semilla con respecto a la hora de la compu

	int turno =1+ rand() % (3-1);//se da el turno de un modo aleatorio
	if (turno == 1)
		std::cout << "Empieza la computadora: ";
	else
		std::cout << "Empieza el ser humano: ";
	

	while (!gano) {
		graph.eventos();
		if (turno == 1) {
			if (!juegoOfensivo()) {//primero verifica si existe posibilidad de ganar
				if (!juegoDefensivo()) //luego se serciora de que bloquear al jugador
						juegaAleatorio();//selecciona una posicion aleatoria para jugar.
			}
			turno = 2;
			mostrar();
			graph.draw(tablero);
		}
		else {
			//turno del jugador en el que se inserta la ficha 'o'
			system("cls");
			int x = 0, y = 0;
			int eleccion = 0;
			std::cout << "\nPor favor inserte una posicion (x,y): ";
			std::cout << "\n\t=>Posicion x:";  std::cin >> x;
			std::cout << "\n\t=>Posicion y:";  std::cin >> y;
			validacion(x, y, J1);
			turno = 1;
		}
		if (winCondition(J1) != 3 || winCondition(CPU) != 3)//verifica si alguno ha ganado.
			gano = true;
	}
}


//utiliza coordenadas random para jugar 
bool estructura::juegaAleatorio() {
	srand(time(NULL));
	bool movio = false;

	while (!movio) {
		int posX = rand() % 3;
		int posY = rand() % 3;
		std::vector<std::vector<int>> paresDisponibles;
		int x = 0 ;
		if (verificaEspaciosVacios() < 4) {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (tablero[i][j]== ' ') {
						std::vector<int> pares;
						paresDisponibles.push_back(pares);
						paresDisponibles.at(x).push_back(i);
						paresDisponibles.at(x++).push_back(j);
						movio = true;
					}
				}
			}
			x = 0;
			int indiceRand = rand() % paresDisponibles.size();
			tablero[paresDisponibles.at(indiceRand).at(x++)][paresDisponibles.at(indiceRand).at(x)] = 'x';
			return true;
		}
		
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

//Modo dificil de la computadora. Imposible de ganar. 
void estructura::PVEdificil(Jugador* J1, Jugador* CPU) {
	
	int posX = 0; int posY = 0;
	srand(time(NULL));//inicializa la semilla con la hora de la compu
	int turno = 1+rand() % (3 - 1);//inicia el turno de manera aleatoria
	if (turno == 1)
		std::cout << "Empieza la computadora: ";
	else
		std::cout << "Empieza el ser humano: ";
	system("pause");

	while (!gano) {
		system("cls");
		//turno de la computadora
		if (turno == 1) {
			int bestScore = -INFINITY;//inicializa la variable para la fase de minimizar
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (tablero[i][j] == ' ') {
						tablero[i][j] = CPU->ficha;//posicion la 'x' en la primera 
						int score = minimax(0,false, CPU->ficha);//Analiza todas las posibles movidas que tiene con respecto a la situacion actual del tablero.
						tablero.at(i).at(j) = ' ';//vuelve a ponera la posicion en vacio
						if (score > bestScore) {
							bestScore = score;
							posX = i;
							posY = j;
						}
					}
				}
			}
			tablero.at(posX).at(posY) = CPU->ficha;//dado el mayor puntaje se le asigna las coordenadas asociadas a esa mejor puntuacion al tablero. 
			mostrar();//muestra en consola
			graph.draw(tablero);
			turno = 2;//pasa el turno
			if (winCondition(CPU) != 3)//verifica si gano en su turno
				gano = true;
			system("pause");
		}
		else {
			system("cls");
			//inserta y valida las posiciones
			int x = 0, y = 0;
			int eleccion = 0;
			std::cout << "\nPor favor inserte una posicion (x,y): ";
			std::cout << "\n\t=>Posicion x:";  std::cin >> x;
			std::cout << "\n\t=>Posicion y:";  std::cin >> y;
			validacion(x, y, J1);
			if (winCondition(J1) != 3)//verifica si gano en su turno
				gano = true;
			turno = 1;//pasa de tuurno
			system("pause");
		}

	}
}
//Metodo utilizado para obtener la jugada mas obtima por medio de la recreacion de un arbol de desiciones
//En todos los casos en los que se gane se devuelve un valor positivo(Maximizar) 
//En caso de que se pierda se devuelve un valor negativo (Minimizar)
int estructura::minimax(int profundidad, bool estaMax, char ficha) {
	Jugador* pj = new Jugador();
	pj->ficha = ficha;

	int result = winCondition(pj);
	//caso base en el que se verifica si se gano y se devuelve quien fue el ganador
	//como por defecto la computadora es 'x' entonces se retorna un 1 en todos los casos
	//en el que la compu gane. y un -1 en caso de que sea 'o' el ganador
	// en caso de que sea 3 significa que todavia nadie ha ganado, por lo tanto sigue con la recursividad
	if (result != 3) {
		return result;
	}
	//este es el caso en que maximiza (juegan las 'x')
	if (estaMax) {
		int bestScore = -INFINITY;//se inicializa con la peor puntuacion que podria tener. (deberia se infinito)
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (tablero.at(i).at(j) == ' ') {//verifica que la posicion en la que se puede jugar sea un espacio vacio
					tablero.at(i).at(j) = 'x';//si esta vacio posiciona la 'x' en ese lugar y luego le pasa el "turno" al jugador
					int score = profundidad - minimax(profundidad + 1, false, 'x');//optiene la puntuacion mas alta del arbol. y se le resta la profundidad para conseguirlo en la menor cantidad de pasos
					tablero.at(i).at(j) = ' ';//vuelve a poner la posicion jugada en blanco
					
					if ((score > bestScore))//maximiza
						bestScore = score;
				}
			}
		}
		return bestScore;
	}
	//este el caso en que minimiza (juegan las 'o') 
	//hace lo mismo que el de arriba pero busca el minimo
	else {
		int bestScore = INFINITY;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (tablero.at(i).at(j) == ' ') {
					tablero.at(i).at(j) = 'o';
					int score = minimax(profundidad + 1, true, 'o') - profundidad;
					tablero.at(i).at(j) = ' ';
					if (score < bestScore)
						bestScore = score;
				}
			}
		}
		return bestScore;
	}
}

//Jugador vs CPU (Modo facil)
void estructura::PVEfacil(Jugador* J1, Jugador* J2) {

	srand(time(NULL));//inicializa la semilla con la hora de la compu
	int turno = 1 + rand() % (3 - 1);//turno al azar
	system("pause");

	while (!gano) {

		int x = 0, y = 0;
		system("cls");

		if (turno == 1) {
			//Se pide que el usuario digite la jugada
			std::cout << " Turno de " << J1->nombre << ". " << std::endl;
			std::cout << "\nPor favor inserte una posicion (x,y): ";
			std::cout << "\n\t=>Posicion x:";  std::cin >> x;
			std::cout << "\n\t=>Posicion y:";  std::cin >> y;

			//Se valida y se inserta la jugada
			validacion(x, y, J1);
			//Se valida por si gano o si el tablero esta lleno
			if (winCondition(J1) != 3)
				gano = true;
			graph.draw(tablero);
			//Se cambia de turno
			turno = 2;
		}
		else {
			//Se elige al azar un movimiento en el tablero
			x = rand() % 3;
			y = rand() % 3;
			//Se valida y se inserta la jugada
			juegaAleatorio();

			//Se valida por si gano o si el tablero esta lleno
			if (winCondition(J2) != 3)
				gano = true;
			
			//Se cambia de turno
			turno = 1;
			mostrar();
			graph.draw(tablero);
			system("pause");
		}
	}

	//Imprime quien gano (Y)
	if (turno == 2)
		std::cout << "El ganador es " << J1->nombre << "\n";
	else
		if (turno == 1)
			std::cout << "El ganador es el CPU" << "\n";
}





