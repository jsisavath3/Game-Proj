#include "Game.h"

void Game::initWindow()
{
	this->style = 7U;
	this->context.antialiasingLevel = 8;
	this->window = new sf::RenderWindow(sf::VideoMode(800,600), "Casino", style , context );

}

void Game::initStates()
{
	this->states.push(new GameState(this->window, &this->states, this->players));
}

Game::Game()
{
	Player* dealer = new Player("Dealer", 10, false);
	this->testPlayer.setName("Jake");
	this->testPlayer.setBalance(10);
	this->testPlayer.setType(true);
	this->players.push_back(&this->testPlayer);
	this->players.push_back(dealer);
	this->initWindow();
	this->initStates();
}

Game::~Game()
{	
	delete this->window;

	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}
}

void Game::updateDt()
{
	this->dt = this->dtClock.restart().asSeconds();
}

void Game::updateSFMLEvents()
{
	while (this->window->pollEvent(this->sfEvent))
	{
		if (this->sfEvent.type == sf::Event::Closed)
		{
			this->window->close();
		}
	}
}

void Game::update(float& deltaTime)
{
	this->updateSFMLEvents(); 

	if (!this->states.empty())
	{
		this->states.top()->update(deltaTime);
		if (states.top()->checkForEnd())
		{
			delete this->states.top();
			this->states.pop();
		}
	}
	else
	{
		this->window->close();
	}
}

void Game::render()
{
	this->window->clear();

	//render
	if (!this->states.empty())
		this->states.top()->render(this->window);

	this->window->display();
}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->updateDt();
		this->update(this->dt);
		this->render();
	}
}

int Game::blackjack()
{
	return 0;
}
