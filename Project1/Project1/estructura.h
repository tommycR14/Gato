#pragma once
#include "grafico.h"
#include <string>
#include <vector>

struct Jugador {
	std::string nombre;
	char ficha;
};

class estructura
{
private:
	//======== ATRIBUTOS =============
	std::vector<std::vector<char>> tablero;
	bool gano;
	//======== # # # # # =============

	//auxiliares para el juego intermedio
	bool juegoOfensivo();
	bool juegoDefensivo();
	bool juegaAleatorio();

	//posiciona la ficha en un lugar determinado
	void insertarFicha(Jugador* j, int x, int y) { tablero.at(x).at(y) = j->ficha; }
	//cuenta cuantos espacios vacios hay. 
	int verificaEspaciosVacios();
	
	
	
	void mostrar();
	
	~estructura() {}
	//crea un arbol de desiciones en el que escoje la opcion 
	//que de el puntaje mas alto en el que juega la PC
	int minimax(int,bool, char);
	
	// Verifica que las fichas sean iguales 
	// y diferentes de espacio.
	bool verificaIgualdad(char, char, char);

	grafico ventana;
public: 
	
	estructura() ;//constructor de la clase
	std::vector<std::vector<char>>& getTablero() { return tablero; }
	
	//juego de persona vs persona
	void PvP(Jugador* , Jugador* );

	//computadora dificil
	void PVEdificil(Jugador* ,Jugador*);

	//Contra computadora intermedio
	void PVEintermedio(Jugador*, Jugador*);

	//facil
	void PVEfacil(Jugador*,Jugador*);

	//verfica si el movimiento ingresado
	//por el jugador es correcto
	bool validacion(int, int, Jugador*);

	//verifica que alguien gane
	int winCondition(Jugador*);
};

