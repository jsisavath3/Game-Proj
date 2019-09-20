#include "Card.h"

Card::Card()
{

}

Card::Card(int num, Suit s)
{
	setCard(num, s);
	initTexture();
}

void Card::setCard(int n, Suit s)
{
	myNum = n;
	mySuit = s;
}


std::string Card::suitString(Suit s)
{
	if (s == Clubs)
		return "clubs";
	else if (s == Diamonds)
		return "diamonds";
	else if (s == Hearts)
		return "hearts";
	else return "spades";
}

std::string Card::rankString(int n)
{
	if (n == 1)
		return "ace";
	if (n == 2)
		return "two";
	if (n == 3)
		return "three";
	if (n == 4)
		return "four";
	if (n == 5)
		return "five";
	if (n == 6)
		return "six";
	if (n == 7)
		return "seven";
	if (n == 8)
		return "eight";
	if (n == 9)
		return "nine";
	if (n == 10)
		return "ten";
	if (n == 11)
		return "jack";
	if (n == 12)
		return "queen";
	if (n == 13)
		return "king";
}

std::string Card::toString()
{
	if (myNum >= 1 && myNum <= 13)
	{
		return rankString(getNum()) + " of " + suitString(getSuit());
	}
	return "invalid card";
}

int Card::getNum() {
	return myNum;
}

int Card::getValue()
{
	int value1;
	if (myNum > 10) {
		value1 = 10;
	}
	else if (myNum == 1) {
		value1 = 11;
	}
	else {
		value1 = myNum;
	}
	return value1;
}

sf::Texture* Card::getTexture()
{
	return &this->temp;
}

Card::Suit Card::getSuit()
{
	return mySuit;
}

void Card::initTexture()
{
	int num;
	if (getNum() > 1)
	{
		num = getNum() - 2;
	}
	else
	{
		num = 12;
	}
	int suit = getSuit();
	
	if (!this->temp.loadFromFile("Sprites/Cards.png", sf::IntRect(0 + (81 * num) ,0 + (117 * suit),80,117)))
		EXIT_FAILURE;
}
