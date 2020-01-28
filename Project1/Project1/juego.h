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

	sf::Music ganar;
	sf::SoundBuffer opcionB;
	sf::Sound opcion;
	sf::Music facil;
	sf::Music intermedio;
	sf::Music dificil;
	sf::SoundBuffer espadaB;
	sf::Sound espadaS;
	sf::SoundBuffer escudoB;
	sf::Sound escudoS;
	sf::Music pvpSong;
	//================= METODOS PRIVADOS =============
	void menuPVE();

	//Insertar en posicion del tablero
	//registro

	//Modos de juego 
	void PVEfacil();
	void PVEintermedio();
	void PVEdificil();
	void PVP();

	void ganarEspadas();
	void ganarEscudo();
	void dibujaEmpate();

	sf::Font fuente2;
	sf::Text texto2;
	//================= METODOS PRIVADOS =============
public: 
	juego();//reserva un espacio en el heap para los atributos de la clase
	~juego() { delete J1, J2, tab; }//libera el espacio

	void menu();
};

