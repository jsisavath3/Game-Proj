 #include "Deck.h"

Deck::Deck()
{
	buildDeck();
}

void Deck::buildDeck()
{
	int number;
	for (number = 1; number <= SIZE / 4; number++)
	{
		for (int suit = 0; suit < 4; suit++)
		{
			this->myDeck.emplace_back(Card(number, Card::Suit(suit)));
		}
	}
}

void Deck::shuffle()
{
	srand(time(NULL));
	for (int i = 0; i < 1000; i++)
	{
		int swap = rand() % 52;
		Card c_one = myDeck[swap];
		Card c_two = myDeck[0];
		this->myDeck[swap] = c_two;
		this->myDeck[0] = c_one;
	}
}

Card Deck::getCard()
{
	Card c = this->myDeck.front();
	this->myDeck.erase(myDeck.begin());
	return c;
}

int Deck::deckSize()
{
	return SIZE - myIndex;
}

void Deck::printDeck()
{
	for (int i = 0; i < myDeck.size(); i++)
	{
		std::cout << myDeck[i].toString() << "\n";
	}
}



