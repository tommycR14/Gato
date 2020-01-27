#pragma once

#include <string>
#include <vector>

class estructura;
class grafico;

struct Jugador {
	std::string nombre;
	char ficha;
};

class estructura
{
private:
	//======== ATRIBUTOS =============
	std::vector<std::vector<char>> tablero;
	//======== # # # # # =============

	

	//posiciona la ficha en un lugar determinado
	void insertarFicha(Jugador* j, int x, int y) { tablero.at(x).at(y) = j->ficha; }
	//cuenta cuantos espacios vacios hay. 
	int verificaEspaciosVacios();
	
	
	
	void mostrar();
	
	~estructura() {}
	
	// Verifica que las fichas sean iguales 
	// y diferentes de espacio.
	bool verificaIgualdad(char, char, char);

public: 
	
	estructura() ;//constructor de la clase
	std::vector<std::vector<char>>& getTablero() { return tablero; }
	
	//auxiliares para el juego intermedio
	bool juegoOfensivo();
	bool juegoDefensivo();
	bool juegaAleatorio();

	//computadora dificil
	void pcDificil();

	//facil
	void PVEfacil(Jugador*,Jugador*);

	//verfica si el movimiento ingresado
	//por el jugador es correcto
	bool validacion(int, int, Jugador*);

	//verifica que alguien gane
	int winCondition(Jugador*);
	
	//crea un arbol de desiciones en el que escoje la opcion 
//que de el puntaje mas alto en el que juega la PC
	int minimax(int, bool, char);
};

