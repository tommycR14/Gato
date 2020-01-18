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
	~estructura() {}
	void mostrar();
	void verificaGane();
	void insertarFicha(Jugador*,int,int);

};

