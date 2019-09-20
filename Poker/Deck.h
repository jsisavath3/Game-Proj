#pragma once

#include "Card.h"
#include <vector>
#include <cstdlib>
#include <ctime>

class Deck
{
public:
	Deck();
	void Shuffle();
	Card getCard();
	int  deckSize();
	void printDeck();
	void buildDeck();
private:
	const int SIZE = 52;
	std::vector<Card> myDeck;
	int myIndex;
};