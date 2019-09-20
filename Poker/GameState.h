#pragma once
#include "State.h"
#include "CircleButton.h"
#include "Deck.h"

class GameState :
	public State
{
private:
	sf::Sprite background;
	sf::Sprite playerCardSprite;
	sf::Texture temp;
	sf::Font font;
	std::vector<Card>* playerCard;
	std::vector<Card>* dealerCard;
	std::map<std::string, CircleButton*> buttons;
public:
	GameState(sf::RenderWindow* window, std::stack<State*>* states);
	virtual ~GameState();
	void initCards();
	void initBackground();
	void initButtons();
	void initFont();
	void endState();
	void update(const float& dt);
	void render(sf::RenderTarget* target);
};

