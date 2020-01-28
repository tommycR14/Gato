#include "grafico.h"
#include <windows.h>
grafico::grafico() {
	window = new sf::RenderWindow(sf::VideoMode(1200, 950), "TIC - TAC - TOE");
	//imganes
	espadaT.loadFromFile("imagenes/espada.png");
	espadaS.setTexture(espadaT);

	escudoT.loadFromFile("imagenes/escudo.png");
	escudoS.setTexture(escudoT);

	gatoT.loadFromFile("imagenes/gato.png");
	gatoS.setTexture(gatoT);

	paisajeT.loadFromFile("imagenes/paisaje.jpg");
	paisajeS.setTexture(paisajeT);
	
	menuT.loadFromFile("imagenes/paisaje.jpg");
	menuS.setTexture(menuT);

	marcoT.loadFromFile("imagenes/marco.png");
	marcoS.setTexture(marcoT);

	marcoT.loadFromFile("imagenes/marco.png");
	marcoS.setTexture(marcoT);

	win.loadFromFile("imagenes/final.png");
	winS.setTexture(win);

	texturaEspada.loadFromFile("imagenes/espadauni.png");
	imagenEspada.setTexture(texturaEspada);
	Iespada.setTexture(texturaEspada);

	escudoTextura.loadFromFile("imagenes/granEscudo.png");
	escudoSprite.setTexture(escudoTextura);

	//posiciones
	marcoS.setPosition(87, 53);
	gatoS.setPosition(80, 50);
	paisajeS.setPosition(0, 0);

	//sonidos
	espadaB.loadFromFile("sonidos/espada.wav");
	espadaSound.setBuffer(espadaB);

	golpeB.loadFromFile("sonidos/golpeSeco.wav");
	golpeS.setBuffer(golpeB);

	lataB.loadFromFile("sonidos/lata.wav");
	lataS.setBuffer(lataB);
	vacioB.loadFromFile("sonidos/vacio.wav");
	vacioS.setBuffer(vacioB);
	
	//TEXTO
	fuente.loadFromFile("fuentes/Triforce.ttf");
	texto.setFont(fuente);
	texto3.setFont(fuente);

}
void grafico::dibujoGaneEscudo() {
	window->draw(winS);
	window->draw(escudoSprite);
	window->draw(texto);
	window->draw(texto3);
}

void grafico::dibujoGaneEspada() {
	window->clear();
	window->draw(winS);
	window->draw(imagenEspada);
	window->draw(Iespada);
	window->draw(texto);
	window->draw(texto3);
}
void  grafico::dibujoGaneEmpate() {
	window->clear();
	window->draw(winS);
	window->draw(escudoSprite);
	window->draw(imagenEspada);
	window->draw(Iespada);
	window->draw(texto);
	window->draw(texto3);
}
void  grafico::dibujaGanarEmpate() {

	imagenEspada.setRotation(180);

	int x = -100;
	texto.setString("GAME OVER");
	texto.setCharacterSize(100);
	texto.setPosition(x, 180);
	texto.setFillColor(sf::Color::Black);
	while (x < 300) {
		x += 10;
		texto.setPosition(x, 140);
		window->clear();
		window->draw(winS);
		window->draw(texto);
		window->display();
	}
	golpeS.play();
	int xEspada = -100;
	imagenEspada.setPosition(xEspada, 300);

	while (xEspada < 950) {
		xEspada += 10;
		imagenEspada.setPosition(xEspada, 300);
		window->clear();
		window->draw(winS);
		window->draw(imagenEspada);
		window->draw(texto);
		window->display();
	}
	espadaSound.play();
	//el otro texto
	int x2 = 1700;
	texto3.setString("EMPATE");
	texto3.setCharacterSize(100);
	texto3.setPosition(x, 600);
	texto3.setFillColor(sf::Color::Black);
	while (x2 > 400) {
		x2 -= 10;
		texto3.setPosition(x2, 630);
		window->clear();
		window->draw(winS);
		window->draw(imagenEspada);
		window->draw(texto);
		window->draw(texto3);
		window->display();
	}
	golpeS.play();
	int xEsp = 1700;

	Iespada.setPosition(xEsp, 600);

	while (xEsp > 200) {
		xEsp -= 10;
		Iespada.setPosition(xEsp, 600);
		window->clear();
		window->draw(winS);
		window->draw(imagenEspada);
		window->draw(texto);
		window->draw(Iespada);
		window->draw(texto3);
		window->display();
	}
	espadaSound.play();

	escudoSprite.setOrigin(sf::Vector2f(350, 432));
	escudoSprite.setPosition(600, 475);
	float r1 = 0.005;
	while (r1 < 1) {
		r1 += 0.005;
		escudoSprite.setScale(r1, r1);
		window->clear();
		window->draw(winS);
		window->draw(escudoSprite);
		window->draw(imagenEspada);
		window->draw(Iespada);
		window->draw(texto);
		window->draw(texto3);
		window->display();
	}
	lataS.play();
	vacioS.play();
}

void grafico::dibujaGanarEscudos() {

	int x = -100, xEspada = -100;

	texto.setString("LOS ESCUDOS");
	texto.setCharacterSize(120);
	texto.setPosition(x, 180);
	texto.setFillColor(sf::Color::Black);

	while (x < 200) {
		x += 10;
		texto.setPosition(x, 140);
		window->clear();
		window->draw(winS);
		window->draw(texto);
		window->display();
	}
	golpeS.play();
	
	
	//el otro texto
	int x2 = 1700;
	texto3.setString("GANARON");
	texto3.setCharacterSize(120);
	texto3.setPosition(x, 600);
	texto3.setFillColor(sf::Color::Black);
	while (x2 > 300) {
		x2 -= 10;
		texto3.setPosition(x2, 630);
		window->clear();
		window->draw(winS);
		window->draw(texto);
		window->draw(texto3);
		window->display();
	}
	golpeS.play();


	escudoSprite.setOrigin(sf::Vector2f(350,432));
	escudoSprite.setPosition(600,475);
	float r1 = 0.05;
	while (r1<1) {
		r1 += 0.005;
		escudoSprite.setScale(r1, r1);
		window->clear();
		window->draw(winS);
		window->draw(escudoSprite);
		window->draw(texto);
		window->draw(texto3);
		window->display();

	}
	lataS.play();
	vacioS.play();
}
void grafico::dibujaGanarEspadas() {

	imagenEspada.setRotation(180);

	int x = -100;
	texto.setString("LAS ESPADAS");
	texto.setCharacterSize(100);
	texto.setPosition(x,180);
	texto.setFillColor(sf::Color::Black);
	while (x < 300) {
		x += 10;
		texto.setPosition(x, 140);
		window->clear();
		window->draw(winS);
		window->draw(texto);
		window->display();
	}
	golpeS.play();
	int xEspada = -100;
	imagenEspada.setPosition(xEspada,300);

	while (xEspada<950) {
		xEspada += 10;
		imagenEspada.setPosition(xEspada, 300);
		window->clear();
		window->draw(winS);
		window->draw(imagenEspada);
		window->draw(texto);
		window->display();
	}
	espadaSound.play();
	//el otro texto
	 int x2 = 1700;
	texto3.setString("GANARON");
	texto3.setCharacterSize(100);
	texto3.setPosition(x, 600);
	texto3.setFillColor(sf::Color::Black);
	while (x2 > 300) {
		x2 -= 10;
		texto3.setPosition(x2, 630);
		window->clear();
		window->draw(winS);
		window->draw(imagenEspada);
		window->draw(texto);
		window->draw(texto3);
		window->display();
	}
	golpeS.play();
	int xEsp = 1700;

	Iespada.setPosition(xEsp, 600);

	while (xEsp > 200) {
		xEsp -= 10;
		Iespada.setPosition(xEsp, 600);
		window->clear();
		window->draw(winS);
		window->draw(imagenEspada);
		window->draw(texto);
		window->draw(Iespada);
		window->draw(texto3);
		window->display();
	}
	espadaSound.play();

}
void grafico::setMarcoS(int x, int y) {
	this->marcoS.setPosition(x,y);
}

void grafico::drawTablero(std::vector<std::vector<char>>& tab) {
	int x = 130, y = 84;
	window->clear();
	window->draw(paisajeS);
	window->draw(gatoS);
    window->draw(marcoS);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (tab[i][j] == 'x') {
				espadaS.setPosition(x, y);
				window->draw(espadaS);
				x += 340;
			}
			else if (tab[i][j] == 'o') {
				escudoS.setPosition(x, y);
				window->draw(escudoS);
				x += 340;
			}
			else if (tab[i][j] == ' ')
				x += 340;
		}
		x = 130;
		y += 290;
	}
	window->display();
}

