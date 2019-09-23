#pragma once

#include "MainMenuState.h"

class Game
{
private:
	sf::ContextSettings context;
	sf::Uint32 style;
	sf::RenderWindow* window;
	sf::Event sfEvent;
	sf::Clock dtClock;
	std::stack<State*> states;
	Player testPlayer;
	std::vector<Player*> players;

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

	int blackjack();
};

