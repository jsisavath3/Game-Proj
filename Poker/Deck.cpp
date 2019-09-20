 #include "Deck.h"

Deck::Deck()
{
	buildDeck();
}

void Deck::buildDeck()
{
	myDeck.resize(52);
	myIndex = 0;
	int number;
	int num = 0;
	for (number = 1; number <= SIZE / 4; number++)
	{
		for (int suit = 0; suit < 4; suit++)
		{
			myDeck[num] = Card(number, Card::Suit(suit));
			num++;
		}
	}
}

void Deck::Shuffle()
{
	myIndex = 0; 
	srand(time(NULL));
	for (int i = 0; i < 1000; i++)
	{
		int swap = rand() % 52;
		Card c_one = myDeck[swap];
		Card c_two = myDeck[0];
		myDeck[swap] = c_two;
		myDeck[0] = c_one;
	}
}

Card Deck::getCard()
{
	Card c = myDeck[0];
	myDeck.erase(myDeck.begin());
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



