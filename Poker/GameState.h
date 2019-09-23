#pragma once
#include "State.h"
#include "CircleButton.h"
#include "Player.h"
#include <thread>
#include <chrono>

class GameState :
	public State
{
private:
	sf::Sprite background;
	sf::Sprite playerCardSprite;
	std::vector<sf::Sprite*> sprites;
	sf::Texture temp;
	sf::Font font;
	std::map<std::string, CircleButton*> buttons;
	
	//Blackjack logic
	sf::Text loseText;
	sf::Text winText;
	std::vector<Player*> players;
	int playerInd;
	int dealerInd;
	Deck deck;
	bool isWin;
	bool isLose;
	bool isPlayingDealer;
public:
	GameState(sf::RenderWindow* window, std::stack<State*>* states, std::vector<Player*> players);
	virtual ~GameState();
	void initBackground();
	void initButtons();
	void initFont();
	void renderPlayers(sf::RenderTarget* target);
	void endState();
	void update(const float& dt);
	void render(sf::RenderTarget* target);
	void renderLoseText(sf::RenderTarget* target);
	void renderWinText(sf::RenderTarget* target);
	
	//Blackjack logic
	void dealCards();
	void checkGame();
	void endGame();
	
};

