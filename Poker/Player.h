#pragma once

#include "Deck.h"
class Player
{
private:
	std::vector<Card> hand;
	bool isPlayer;
	int balance;
	std::string name;
public:
	Player();
	Player(std::string pName, int pBalance, bool type);
	
	void setBalance(int pBalance);
	void setName(std::string pName);
	void addCard(Card aCard);
	void setType(bool aType);
	void clearHand();

	int getBalance();
	std::string getName();
	std::vector<Card> getHand();
	bool getType();
	int getHandValue();
	bool isBust();

	void withdraw(int num);
	void deposit(int num);
};

