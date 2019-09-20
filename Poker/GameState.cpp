#include "GameState.h"

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states) : State(window, states)
{
	this->initBackground();
	this->initFont();
	this->initButtons();
	this->initCards();
}

GameState::~GameState()
{
}

void GameState::initCards()
{

/*	Renders one card
	this->card = Card(10, Card::Suit(1));
	this->playerCardSprite.setTexture(*this->card.getTexture());
	this->playerCardSprite.setPosition(sf::Vector2f(50, 50));
*/
}

void GameState::initBackground()
{
	bool check = this->temp.loadFromFile("Sprites/Table.png");
	if (!check)
		EXIT_FAILURE;
	this->background.setTexture(temp);
	this->background.setColor(sf::Color::Red);
}

void GameState::initButtons()
{
	this->buttons["bet_button"] = new CircleButton(450, 450, 50, &this->font, 20, "Bet", sf::Color::Black, sf::Color(210, 210, 210), sf::Color::Yellow);
}

void GameState::initFont()
{
	if (!this->font.loadFromFile("Fonts/comic.ttf"))
		EXIT_FAILURE;
}

void GameState::endState()
{
}

void GameState::update(const float& dt)
{
	this->updateMousePosition();
	for (auto& in : this->buttons)
	{
		in.second->update(this->mousePosView);
	}
}

void GameState::render(sf::RenderTarget* target)
{
	target->draw(this->background);
	for (auto& in : this->buttons)
	{
		in.second->render(target);
	}
	target->draw(this->playerCardSprite);
}
