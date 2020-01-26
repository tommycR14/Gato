#include "grafico.h"
grafico::grafico() {
	window = new sf::RenderWindow(sf::VideoMode(1200, 900), "TIC - TAC - TOE");

	espadaT.loadFromFile("imagenes/espada.png");
	espadaS.setTexture(espadaT);

	escudoT.loadFromFile("imagenes/escudo.png");
	escudoS.setTexture(escudoT);

	gatoT.loadFromFile("imagenes/gato.png");
	gatoS.setTexture(gatoT);

	paisajeT.loadFromFile("imagenes/paisaje.jpg");
	paisajeS.setTexture(paisajeT);

	marcoT.loadFromFile("imagenes/marco.png");
	marcoS.setTexture(marcoT);
	gatoS.setPosition(80, 50);
	paisajeS.setPosition(0, 0);
	coorMarcoX = 87;
	coorMarcoY = 53;
	posTableroi = 0;
	posTableroJ = 0;
	marcoS.setPosition(coorMarcoX, coorMarcoY);

}

void grafico::eventos() {

	while (window->pollEvent(evento))
	{
		
		switch (evento.type) {
		case sf::Event::Closed: {
			window->close();
			exit(1);
			break;
		}
		case sf::Event::KeyPressed: {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				if ((posTableroi < 2)) {
					++posTableroi;
					coorMarcoX += 340;
					marcoS.setPosition(coorMarcoX,coorMarcoY);
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				if (posTableroi > 0) {
					--posTableroi;
					coorMarcoX -= 340;
					marcoS.setPosition(coorMarcoX, coorMarcoY);
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				if (posTableroJ > 0) {
					--posTableroJ;
					marcoS.setPosition(coorMarcoX, coorMarcoY -= 300);
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				if (posTableroJ < 2) {
					++posTableroJ;
					marcoS.setPosition(coorMarcoX, coorMarcoY += 300);
				}
			}
			break;
		}
		}


	}


	//if (validacion(x, y, J1))//Verica si la posicion es correcta
	//				turno = true;
	//			if (winCondition(J1) != 3)//Verica si alguien ha ganado o empatado
	//				gano = true;
}
void grafico::draw(std::vector<std::vector<char>>& tab) {
	int x = 130, y = 84;
	eventos();
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

