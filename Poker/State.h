#pragma once
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>

#include "Button.h"
#include "SFML\System.hpp"
#include "SFML\Audio.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\Network.hpp"

class State
{
private:

protected:
	sf::RenderWindow* window;
	std::vector<sf::Texture> textures;
	std::stack<State*>* states;
	bool end;

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

public:
	State(sf::RenderWindow* window, std::stack<State*>* states);
	virtual ~State();

	void updateMousePosition();

	bool checkForEnd();

	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target) = 0;

};

