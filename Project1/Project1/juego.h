#pragma once
#include "estructura.h"
#include "grafico.h"

class juego
{
private:
	estructura* tab;
	Jugador* J1;
	Jugador* J2;
	grafico g;
	bool gano;
	int turno;
	
	//========= Para escoger la posicion ===========
	int coorMarcoX;
	int coorMarcoY;
	int posTableroi;
	int posTableroJ;
	sf::Event evento;
	//===============================================

	//Funciones
	void eventos();
	void insertar(int, int);
	void registroUnico();
	void registroPVP();

	//sonido
	sf::Music cancion;
	sf::SoundBuffer pasaNivelB;
	sf::Sound pasaNivel;
	sf::Music ganar;
	sf::SoundBuffer opcionB;
	sf::Sound opcion;

public: 
	juego();//reserva un espacio en el heap para los atributos de la clase
	~juego() { delete J1, J2, tab; }//libera el espacio
	
	//Insertar en posicion del tablero
	//registro

	//Modos de juego 
	void PCvsJugadorFacil();
	void PCvsJugadorIntermedio();
	void PCvsJugadorDificil();
	void jugadorVSjugador();	

	void menu();

};

