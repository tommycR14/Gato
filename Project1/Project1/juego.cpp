#include "juego.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics.hpp>
#include "windows.h"

juego::juego() {
	J1 = new Jugador;
	J2 = new Jugador;
	tab = new estructura();

	coorMarcoX = 87;
	coorMarcoY = 53;
	posTableroi = 0;
	posTableroJ = 0;

	//carga sonidos
	espadaB.loadFromFile("sonidos/espada.wav");
	escudoB.loadFromFile("sonidos/escudo.wav");
	escudoS.setBuffer(escudoB);
	espadaS.setBuffer(espadaB);

	cancion.openFromFile("sonidos/menu.wav");
	opcionB.loadFromFile("sonidos/opcion.wav");
	opcion.setBuffer(opcionB);
	facil.openFromFile("sonidos/facil.wav");
	intermedio.openFromFile("sonidos/intermedio.wav");
	dificil.openFromFile("sonidos/dificil.wav");
	pvpSong.openFromFile("sonidos/pvp.wav");
	ganar.openFromFile("sonidos/gane.wav");



	fuente2.loadFromFile("fuentes/intermitente.ttf");
	texto2.setFont(fuente2);

}

void juego::ganarEspadas() {

	ganar.setVolume(30);
	ganar.play();
	g.dibujaGanarEspadas();

	int intermitente = 1;
	texto2.setString("! PRESS ESC TO EXIT  !");
	texto2.setCharacterSize(60);
	texto2.setPosition(300, 400);
	texto2.setFillColor(sf::Color::Yellow);
	while (g.getWindow()->isOpen()) {
		if (intermitente >= 301)
			intermitente = 1;//se hace para que nunca se alcance el numero maximo de bytes que puede tomar un int

		g.getWindow()->clear();
		g.dibujoGaneEspada();

		if (intermitente % 2 == 0)
			g.getWindow()->draw(texto2);
		intermitente++;
		g.getWindow()->display();
	
		while (g.getWindow()->pollEvent(evento)) {

			if (evento.type == sf::Event::Closed) {
				g.getWindow()->close();
				exit(1);
				break;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				ganar.stop();
				cancion.play();
				menu();
			}
		}
		Sleep(150);
	}
}
void juego::dibujaEmpate() {


	ganar.setVolume(30);
	ganar.play();
	g.dibujaGanarEmpate();

	int intermitente = 1;
	texto2.setString("! PRESS ESC TO EXIT  !");
	texto2.setCharacterSize(60);
	texto2.setPosition(300, 400);
	texto2.setFillColor(sf::Color::Yellow);
	while (g.getWindow()->isOpen()) {
		if (intermitente >= 301)
			intermitente = 1;//se hace para que nunca se alcance el numero maximo de bytes que puede tomar un int

		g.getWindow()->clear();
		g.dibujoGaneEmpate();

		if (intermitente % 2 == 0)
			g.getWindow()->draw(texto2);
		intermitente++;
		g.getWindow()->display();

		while (g.getWindow()->pollEvent(evento)) {

			if (evento.type == sf::Event::Closed) {
				g.getWindow()->close();
				exit(1);
				break;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				ganar.stop();
				cancion.play();
				menu();
			}
		}
		Sleep(150);
	}
}

void juego::ganarEscudo() {


	ganar.setVolume(30);
	ganar.play();
	g.dibujaGanarEscudos();

	int intermitente = 1;
	texto2.setString("! PRESS ESC TO EXIT  !");
	texto2.setCharacterSize(60);
	texto2.setPosition(300, 400);
	texto2.setFillColor(sf::Color::Yellow);
	while (g.getWindow()->isOpen()) {
		if (intermitente >= 301)
			intermitente = 1;//se hace para que nunca se alcance el numero maximo de bytes que puede tomar un int

		g.getWindow()->clear();
		g.dibujoGaneEscudo();

		if (intermitente % 2 == 0)
			g.getWindow()->draw(texto2);
		intermitente++;
		g.getWindow()->display();

		while (g.getWindow()->pollEvent(evento)) {

			if (evento.type == sf::Event::Closed) {
				g.getWindow()->close();
				exit(1);
				break;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				ganar.stop();
				cancion.play();
				menu();
			}
		}
		Sleep(150);
	}
}

void juego::registroUnico() {
	J1->ficha = 'x';
	J1->nombre = "CPU";

	J2->nombre = "Jugador Humano";
	J2->ficha = 'o';

}

void juego::registroPVP() {
	J1->nombre = "Jugador 1";
	J1->ficha = 'x';

	J2->nombre = "Jugador 2";
	J2->ficha = 'o';
}

//Modos de juego
void juego::PVEfacil() {
	g.drawTablero(tab->getTablero());
	registroUnico();

	srand(time(NULL));//inicializa la semilla con la hora de la compu
	turno = 1 + rand() % (3 - 1);//turno al azar
	gano = false;

	while (!gano) {
		if (turno == 1) {
			//Se valida y se inserta la jugada
			tab->juegaAleatorio();
			//Se cambia de turno
			espadaS.play();
			turno = 2;
			Sleep(100);
			g.drawTablero(tab->getTablero());
		}
		else {
			//movimiento del jugador
			eventos();
		}

		if (tab->winCondition(J1) == 10 ) {//verifica si x ha ganado.
			gano = true;
			facil.stop();
			tab->reiniciar();
			this->ganarEspadas();
		}else if (tab->winCondition(J2) == -10) {//verifica si o ha ganado.
			gano = true;
			facil.stop();
			tab->reiniciar();
			this->ganarEscudo();
		}
		else if (tab->winCondition(J2) == 0) {
			gano = true;
			facil.stop();
			tab->reiniciar();
			this->dibujaEmpate();
		}
	}
}

void juego::PVEintermedio() {
	g.drawTablero(tab->getTablero());

	registroUnico();
	int posX = 0; int posY = 0;
	srand(time(NULL));//se inicializa la semilla con respecto a la hora de la compu

	turno = 1 + rand() % (3 - 1);//se da el turno de un modo aleatorio
	gano = false;
	while (!gano) {
		if (turno == 1) {
			if (!(tab->juegoOfensivo())) //primero verifica si existe posibilidad de ganar
				if (!(tab->juegoDefensivo())) //luego se serciora de que bloquear al jugador
					(tab->juegaAleatorio());//selecciona una posicion aleatoria para jugar.
			espadaS.play();
			turno = 2;
			Sleep(100);
			g.drawTablero(tab->getTablero());
		}
		else {
			//turno del jugador en el que se inserta la ficha 'o'
			eventos();
		}
		if (tab->winCondition(J1) == 10) {//verifica si x ha ganado.
			gano = true;
			intermedio.stop();
			tab->reiniciar();
			this->ganarEspadas();
		}
		else if (tab->winCondition(J2) == -10) {//verifica si o ha ganado.
			gano = true;
			intermedio.stop();
			tab->reiniciar();
			this->ganarEscudo();
		}
		else if (tab->winCondition(J2) == 0) {
			gano = true;
			intermedio.stop();
			tab->reiniciar();
			this->dibujaEmpate();
		}
	}

	gano = false;
	menu();

}

void juego::PVEdificil() {
	g.drawTablero(tab->getTablero());
	registroUnico();

	int posX = 0; int posY = 0;
	srand(time(NULL));//inicializa la semilla con la hora de la compu
	turno = 1 + rand() % (3 - 1);//inicia el turno de manera aleatoria
	gano = false;
	while (!gano) {
		//turno de la computadora
		if (turno == 1) {
			tab->pcDificil();
			Sleep(100);
			g.drawTablero(tab->getTablero());
			espadaS.play();
			turno = 2;//pasa el turno
		}
		else {//movimiento del jugador
			eventos();
		}
		if (tab->winCondition(J1) == 10) {//verifica si x ha ganado.
			gano = true;
			dificil.stop();
			tab->reiniciar();
			this->ganarEspadas();
		}
		else if (tab->winCondition(J2) == -10) {//verifica si o ha ganado.
			gano = true;
			dificil.stop();
			tab->reiniciar();
			this->ganarEscudo();
		}
		else if (tab->winCondition(J2) == 0) {
			gano = true;
			dificil.stop();
			tab->reiniciar();
			this->dibujaEmpate();
		}
	}
	gano = false;
	menu();

}

void juego::menu() {
	cancion.setLoop(true);
	cancion.setVolume(20);
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
					menuPVE();
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
					opcion.play();
					PVP();
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

void juego::menuPVE() {

	sf::Texture top;
	sf::Sprite topS;
	top.loadFromFile("imagenes/menuPVE.jpg");
	topS.setTexture(top);
	topS.setPosition(-100, 0);

	sf::Font fuente;
	sf::Text texto;

	fuente.loadFromFile("fuentes/Pixelmania.ttf");
	texto.setFont(fuente);

	texto.setString("COMPUTADORA\n\t\t\t\tVS\n\t\tJUGADOR");
	texto.setCharacterSize(40);
	texto.setPosition(230, 50);
	texto.setFillColor(sf::Color::Black);

	sf::Font fuente2;
	sf::Text texto2;
	fuente2.loadFromFile("fuentes/Triforce.ttf");
	texto2.setFont(fuente2);

	std::string menuText = "1. Facil ^\n\n2. Intermedio %\n\n3. Dificil @ \n\n 4. MENU PRINCIPAL";
	texto2.setString(menuText);
	texto2.setCharacterSize(50);
	texto2.setPosition(250, 330);
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
					cancion.stop();
					facil.setLoop(true);
					facil.play();
					facil.setVolume(30);
					this->PVEfacil();
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
					opcion.play();
					cancion.stop();
					intermedio.setLoop(true);
					intermedio.setVolume(30);
					intermedio.play();

					this->PVEintermedio();
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
					opcion.play();
					cancion.stop();
					dificil.setLoop(true);
					dificil.setVolume(30);
					dificil.play();
					this->PVEdificil();
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
					//en caso de que se desee volver al menu principal
					opcion.play();
					cancion.play();
					menu();
				}
			}
			break;
			}
		}
	}
}


void juego::PVP() {
	g.drawTablero(tab->getTablero());
	cancion.stop();
	pvpSong.setLoop(true);
	pvpSong.setVolume(80);
	pvpSong.play();
	registroPVP();
	//inicializa el turno de manera random
	srand(time(NULL));
	turno = 1 + rand() % (3 - 1);
	gano = false;
	//crea el hilo del juego 
	while (!gano) {
		int x = 0, y = 0;
		//JUEGA J1
		if (turno == 1) {
			eventos();
		}//JUEGA J2
		else {
			eventos();
		}
		if (tab->winCondition(J1) == 10) {//verifica si x ha ganado.
			gano = true;
			facil.stop();
			tab->reiniciar();
			this->ganarEspadas();
		}
		else if (tab->winCondition(J2) == -10) {//verifica si o ha ganado.
			gano = true;
			pvpSong.stop();
			tab->reiniciar();
			this->ganarEscudo();
		}
		else if (tab->winCondition(J2) == 0) {
			gano = true;
			pvpSong.stop();
			tab->reiniciar();
			this->dibujaEmpate();
		}
	}
	gano = false;
	menu();
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
			espadaS.play();
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
			escudoS.play();
			turno = 1;
		}
	}
}

void juego::eventos() {

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


