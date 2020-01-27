#include "juego.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics.hpp>
juego::juego() {
	J1 = new Jugador;
	J2 = new Jugador;
	tab = new estructura();

	coorMarcoX = 87;
	coorMarcoY = 53;
	posTableroi = 0;
	posTableroJ = 0;

	//carga sonidos
	pasaNivelB.loadFromFile("sonidos/opcion.wav");
	pasaNivel.setBuffer(pasaNivelB);
	cancion.openFromFile("sonidos/menu.wav");
	opcionB.loadFromFile("sonidos/opcion.wav");
	opcion.setBuffer(opcionB);

}


void juego::registroUnico() {
	J1->ficha = 'x';
	J1->nombre = "CPU";

	std::string nombP1;
	std::cout << " Jugador 1. Digite su nombre" << "\n";
	std::cin >> nombP1;
	J2->nombre = nombP1;
	J2->ficha = 'o';

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
	g.drawTablero(tab->getTablero());
	registroUnico();

	srand(time(NULL));//inicializa la semilla con la hora de la compu
	 turno = 1 + rand() % (3 - 1);//turno al azar

	while (!gano) {
		if (turno == 1) {
			//Se valida y se inserta la jugada
			tab->juegaAleatorio();
			//Se cambia de turno
			turno = 2;
			g.drawTablero(tab->getTablero());
		}
		else {
			//movimiento del jugador
			eventos();
		}
		if (tab->winCondition(J1) != 3 || tab->winCondition(J2) != 3)//verifica si alguno ha ganado.
			gano = true;
	}

}

void juego::PCvsJugadorIntermedio() {
	g.drawTablero(tab->getTablero());

	registroUnico();
		int posX = 0; int posY = 0;
		srand(time(NULL));//se inicializa la semilla con respecto a la hora de la compu

		 turno =1+ rand() % (3-1);//se da el turno de un modo aleatorio

		while (!gano) {
			if (turno == 1) {
				if (!(tab->juegoOfensivo())) //primero verifica si existe posibilidad de ganar
					if (!(tab->juegoDefensivo())) //luego se serciora de que bloquear al jugador
						(tab->juegaAleatorio());//selecciona una posicion aleatoria para jugar.
				turno = 2;
				g.drawTablero(tab->getTablero());
			}
			else {
				//turno del jugador en el que se inserta la ficha 'o'
				eventos();
			}
			if (tab->winCondition(J1) != 3 || tab->winCondition(J2) != 3)//verifica si alguno ha ganado.
				gano = true;
		}

}

void juego::PCvsJugadorDificil() {
	menu();
	g.drawTablero(tab->getTablero());
	registroUnico();
	
	int posX = 0; int posY = 0;
	srand(time(NULL));//inicializa la semilla con la hora de la compu
	turno = 2;//1 + rand() % (3 - 1);//inicia el turno de manera aleatoria

	while (!gano) {
		//turno de la computadora
		if (turno == 1) {
			tab->pcDificil();
			g.drawTablero(tab->getTablero());
			turno = 2;//pasa el turno
		}
		else {//movimiento del jugador
			eventos();
		}
		if (tab->winCondition(J1) != 3 || tab->winCondition(J2) != 3)//verifica si alguno ha ganado.
			gano = true;
	}
}

void juego::menu() {
	cancion.setLoop(true);
	cancion.setVolume(2);
	cancion.play();
	sf::Texture top;
	sf::Sprite topS;
	top.loadFromFile("imagenes/menu.png");
	topS.setTexture(top);
	topS.setPosition(-100, 0);

	sf::Font fuente;
	sf::Text texto;

	fuente.loadFromFile("fuentes/Pixelmania.ttf");
	texto.setFont(fuente);

	texto.setString("TIC=TAC=TOE");
	texto.setCharacterSize(60);
	texto.setPosition(60, 50);
	texto.setFillColor(sf::Color::Black);

	sf::Font fuente2;
	sf::Text texto2;
	fuente2.loadFromFile("fuentes/Triforce.ttf");
	texto2.setFont(fuente2);

	std::string menu = "1. PVE ^\n\n\t2. PVP %\n\n\t\t3. SALIR @";
	texto2.setString(menu);
	texto2.setCharacterSize(80);
	texto2.setPosition(250, 250);
	texto2.setStyle(texto2.Bold);
	texto2.setFillColor(sf::Color::Black);


	sf::Event evt;
	while (g.getWindow()->isOpen()) {
		g.getWindow()->clear();
		g.getWindow()->draw(topS);
		g.getWindow()->draw(texto);
		g.getWindow()->draw(texto2);
		g.getWindow()->display();

		while (g.getWindow()->pollEvent(evt)) {
			switch (evt.type) {

			case sf::Event::Closed:
				g.getWindow()->close();
				exit(1);
				break;

			case sf::Event::KeyPressed:
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
					opcion.play();
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
					opcion.play();

				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
					//en caso de que se desee salir del programa
					opcion.play();
					exit(1);
				}
			}
			break;
			}
		}
	}

}
void juego::jugadorVSjugador() {
	g.drawTablero(tab->getTablero());

	registroPVP();
	//inicializa el turno de manera random
	srand(time(NULL));
	 turno = 1 + rand() % (3 - 1);

	//crea el hilo del juego 
	while (!gano) {
		int x = 0, y = 0;
		//JUEGA J1
		if (turno == 1) {
				eventos();
				if (tab->winCondition(J1) != 3)//Verica si alguien ha ganado o empatado
					gano = true;
		}//JUEGA J2
		else {
			eventos();
			if (tab->winCondition(J2) != 3)//Verica si alguien ha ganado o empatado
				gano = true;
		}
	}
}


void juego::insertar(int x, int y) {
	if (turno == 1) {
		if (tab->validacion(x, y, J1)) {
			g.drawTablero(tab->getTablero());
			coorMarcoX = 87;
			coorMarcoY = 53;
			posTableroi = 0;
			posTableroJ = 0;
			 g.setMarcoS(coorMarcoX, coorMarcoY);
			turno = 2;
		}
	}
	else {
		if (tab->validacion(x, y, J2)) {
			g.drawTablero(tab->getTablero());
			coorMarcoX = 87;
			coorMarcoY = 53;
		    posTableroi = 0;
	        posTableroJ = 0;
			g.setMarcoS(coorMarcoX, coorMarcoY);
			turno = 1;
		}
	}
}

void juego::eventos(){
		while (g.getWindow()->pollEvent(evento))
		{
			switch (evento.type) {
			case sf::Event::Closed: {
				g.getWindow()->close();
				exit(1);
				break;
			}
			case sf::Event::KeyPressed: {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
					if ((posTableroJ < 2)) {
						++posTableroJ;
						coorMarcoX += 340;
						g.setMarcoS(coorMarcoX, coorMarcoY);
						g.drawTablero(tab->getTablero());

					}
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
					if (posTableroJ > 0) {
						--posTableroJ;
						coorMarcoX -= 340;
						g.setMarcoS(coorMarcoX, coorMarcoY);
						g.drawTablero(tab->getTablero());
					}
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
					if (posTableroi > 0) {
						--posTableroi;
						g.setMarcoS(coorMarcoX, coorMarcoY -= 300);
						g.drawTablero(tab->getTablero());

					}
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
					if (posTableroi < 2) {
						++posTableroi;
						g.setMarcoS(coorMarcoX, coorMarcoY += 300);
						g.drawTablero(tab->getTablero());
					}
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
					insertar(posTableroi, posTableroJ);
					g.drawTablero(tab->getTablero());
				}
				break;
			}
			}
		}
	}
			
		
