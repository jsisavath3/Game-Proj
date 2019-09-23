#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <thread>
#include <chrono>

#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include "SFML\Audio.hpp"
#include "SFML\Graphics.hpp"

enum circlebutton_states { CBTN_IDLE = 0, CBTN_HOVER, CBTN_PRESSED };

class CircleButton
{
private:
	short unsigned buttonState;

	sf::CircleShape shape;
	sf::Font* font;
	sf::Text text;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;

public:
	CircleButton(float x, float y, float radius, sf::Font* font, int fontSize, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
	~CircleButton();


	const bool isPressed() const;

	void render(sf::RenderTarget* target);
	void update(sf::Vector2f mousePos);

};
