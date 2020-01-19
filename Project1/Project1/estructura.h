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
	void PvP();
	void validacion(int, int, Jugador* );
	int WinCondition(Jugador*);
	int WinCondition2(Jugador*);

	void PVE();

	int minimax(std::vector<std::vector<char>>, int, bool, char );
};

