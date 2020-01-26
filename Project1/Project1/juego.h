#pragma once
#include "estructura.h"
#include "grafico.h"

class juego
{
private:
	estructura* estruct;
	Jugador* J1;
	Jugador* J2;
	//grafico ventana;

public: 
	juego();//reserva un espacio en el heap para los atributos de la clase
	~juego() { delete J1, J2, estruct; }//libera el espacio
	
	//registro
	void registroUnico();
	void registroPVP();

	//Modos de juego 
	void PCvsJugadorFacil();
	void PCvsJugadorIntermedio();
	void PCvsJugadorDificil();
	void jugadorVSjugador();
	void dibujar();
	
};

