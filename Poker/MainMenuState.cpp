#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow* window) : State(window)
{
	this->initBackground();
	this->initFont();
	this->initButtons();
}

MainMenuState::~MainMenuState()
{
	auto in = this->buttons.begin();
	for (in = this->buttons.begin(); in != this->buttons.end(); ++in)
	{
		delete in->second;
	}
}

void MainMenuState::initBackground()
{
	bool check = this->temp.loadFromFile("Sprites/Menu.png");
	if (!check)
		EXIT_FAILURE;
	this->background.setTexture(temp);
	this->background.setColor(sf::Color::Blue);
}

void MainMenuState::initButtons()
{
	this->buttons["quit_button"] = new Button(325, 500, 150, 50, &this->font, int(28), "Quit", sf::Color::Black, sf::Color(128, 128, 128), sf::Color::Yellow);
	this->buttons["blackjack_button"] = new Button(325, 350, 150, 50, &this->font, int(28), "Blackjack", sf::Color::Black, sf::Color(128, 128, 128), sf::Color::Yellow);

}

void MainMenuState::initFont()
{
	if (!this->font.loadFromFile("Fonts/comic.ttf"))
	{
		EXIT_FAILURE;
	}
}

void MainMenuState::endState()
{
}

void MainMenuState::update(const float& dt)
{
	this->updateMousePosition();
	for (auto& in : this->buttons)
	{
		in.second->update(this->mousePosView);
	}
	if (buttons["quit_button"]->isPressed())
	{
		this->end = true;
	}
}

void MainMenuState::render(sf::RenderTarget* target)
{
	target->draw(this->background);
	for (auto& in : this->buttons)
	{
		in.second->render(target);
	}
}