#include "juego.h"
#include <iostream>

juego::juego() {
	J1 = new Jugador;
	J2 = new Jugador;
	estruct = new estructura();
}
//registros
void juego::registroUnico() {
	std::string nombP1;
	std::cout << " Jugador 1. Digite su nombre" << "\n";
	std::cin >> nombP1;
	J1->nombre = nombP1;
	J1->ficha = 'o';

	J2->ficha = 'x';
	J2->nombre = "CPU";
}

void juego::registroPVP() {
	std::string nombP1;
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

//Modos de juego
void juego::PCvsJugadorFacil() {
	registroUnico();
	estruct->PVEfacil(J1,J2);
}

void juego::PCvsJugadorIntermedio() {
	registroUnico();
	estruct->PVEintermedio(J1,J2);
}

void juego::PCvsJugadorDificil() {
	registroUnico();
	estruct->PVEdificil(J1, J2);
}

void juego::jugadorVSjugador() {
	registroPVP();
	estruct->PvP(J1, J2);
}