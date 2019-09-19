#pragma once
#include "State.h"
#include "CircleButton.h"

class GameState :
	public State
{
private:
	sf::Sprite background;
	sf::Texture temp;
	sf::Font font;


	std::map<std::string, CircleButton*> buttons;
public:
	GameState(sf::RenderWindow* window, std::stack<State*>* states);
	virtual ~GameState();
	void initBackground();
	void initButtons();
	void initFont();
	void endState();
	void update(const float& dt);
	void render(sf::RenderTarget* target);
};

