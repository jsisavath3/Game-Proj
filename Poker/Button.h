#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>

#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include "SFML\Audio.hpp"
#include "SFML\Graphics.hpp"

enum button_states{ BTN_IDLE = 0, BTN_HOVER, BTN_PRESSED};

class Button
{
private:
	short unsigned buttonState;

	sf::RectangleShape shape;
	sf::Font* font;
	sf::Text text;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;

public:
	Button(float x, float y, float width, float height, sf::Font* font, int fontSize, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
	~Button();


	const bool isPressed() const;

	void render(sf::RenderTarget* target);
	void update(sf::Vector2f mousePos);

};  

