#pragma once
#include <SFML/Graphics.hpp>

class grafico
{
private: 
	sf::RenderWindow* window;

	sf::Texture paisajeT;
	sf::Sprite paisajeS;
	
	sf::Texture espadaT;
	sf::Sprite espadaS;
	
	sf::Texture escudoT;
	sf::Sprite escudoS;
	
	sf::Texture gatoT;
	sf::Sprite gatoS;
	
	sf::Event evento;
public: 
	grafico();
	~grafico() { delete window; }
	void draw(std::vector<std::vector<char>>&);
	void eventos();
};

