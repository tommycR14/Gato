#pragma once
#include <string>
#include <vector>

struct Jugador {
	std::string nombre;
	char ficha;
};

class estructura
{
private:
	 Jugador* J1;
	 Jugador* J2;
	std::vector<std::vector<char>> tablero;
	bool gano;
public: 
	bool getGano();
	estructura(Jugador* , Jugador* ) ;
	~estructura() { delete J1, J2; J1 = J2 = nullptr; }
	void mostrar();
	void insertarFicha(Jugador*,int,int);
	void regUser();
	
	//verfica si el movimiento ingresado
	//por el jugador es correcto
	void validacion(int, int, Jugador* );
	
	//verifica que alguien gane
	int WinCondition2(Jugador*);
	
	//juego de persona vs persona
	void PvP();

	//computadora dificil
	void PVE();
	int minimax(bool, char);
	bool equals3(char, char, char);

	//Contra computadora intermedio
	void PVEintermedio();
	bool juegoOfensivo();
	bool juegoDefensivo();
	bool juegaAleatorio();
	bool espacioVacio();
};

