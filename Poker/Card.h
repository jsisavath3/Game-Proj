#pragma once

#include <iostream>
#include <string>

#include "SFML\System.hpp"
#include "SFML\Audio.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\Network.hpp"

class Card
{
public:
	enum Suit { Hearts, Diamonds, Clubs, Spades };
	void setCard(int n, Suit s);
	Card();
	Card(int num, Suit s);
	std::string suitString(Suit s);
	std::string toString();
	int getNum();
	int getValue();
	sf::Texture* getTexture();
	Suit getSuit();
	void initTexture();
private:
	int myNum;
	Suit mySuit;
	std::string rankString(int n);
	sf::Texture temp;
};
