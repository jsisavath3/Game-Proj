#include "State.h"

State::State(sf::RenderWindow* window, std::stack<State*>* states)
{
	this->window = window;
	this->states = states;
	this->end = false; 
}

State::~State()
{
}

void State::updateMousePosition()
{
	this->mousePosScreen = sf::Mouse::getPosition();    
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}


bool State::checkForEnd()
{
	return this->end;
}

void State::update(const float& dt)
{

}

void State::render(sf::RenderTarget* target)
{
}
