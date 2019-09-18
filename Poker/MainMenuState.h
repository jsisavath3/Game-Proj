#pragma once
#include "GameState.h"
#include "Button.h"

class MainMenuState :
	public State
{
private:
	sf::Sprite background; 
	sf::Texture temp;
	sf::Font font;

	std::map<std::string, Button*> buttons;
public:
	MainMenuState(sf::RenderWindow* window);
	virtual ~MainMenuState();

	void initBackground();
	void initButtons();
	void initFont();
	void endState();
	void update(const float& dt);
	void render(sf::RenderTarget* target);
};

