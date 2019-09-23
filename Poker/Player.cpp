#include "Player.h"

Player::Player()
{
}

Player::Player(std::string pName, int pBalance, bool type)
{
	setName(pName);
	setBalance(pBalance);
	setType(type);
}

void Player::setBalance(int pBalance)
{
	this->balance = pBalance;
}

void Player::setName(std::string pName)
{
	this->name = pName;
}

void Player::addCard(Card aCard)
{
	this->hand.push_back(aCard);
}

void Player::setType(bool aType)
{
	this->isPlayer = aType;
}

void Player::clearHand()
{
	this->hand.clear();
}

int Player::getBalance()
{
	return this->balance;
}

std::string Player::getName()
{
	return this->name;
}

std::vector<Card> Player::getHand()
{
	return this->hand;
}

bool Player::getType()
{
	return this->isPlayer;
}

int Player::getHandValue()
{
	int handValue = 0;
	for (auto& in : this->getHand())
		handValue = handValue + in.getValue();
	return handValue;
}

bool Player::isBust()
{
	if (this->getHandValue() <= 21)
		return false;
	else
		return true;
}

void Player::withdraw(int num)
{
	this->balance = this->balance - num;
}

void Player::deposit(int num)
{
	this->balance = this->balance + num;
}