#pragma once

#include "MainMenuState.h"

class Game
{
private:
	sf::RenderWindow* window;
	sf::Event sfEvent;
	sf::Clock dtClock;
	std::stack<State*> states;

	float dt;
	void initWindow();
	void initStates();
public:
	Game();
	virtual ~Game();

	void updateDt();
	void updateSFMLEvents();
	void update(float& deltaTime);
	void render();
	void run();
};

