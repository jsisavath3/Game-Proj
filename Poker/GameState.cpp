#include "GameState.h"

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states, std::vector<Player*> players) : State(window, states)
{
	this->loseText.setString("YOU LOSE!");
	this->loseText.setFont(this->font);
	this->loseText.setCharacterSize(30);
	this->loseText.setStyle(sf::Text::Bold);
	this->loseText.setPosition(sf::Vector2f(400, 400));
	this->winText.setString("YOU WIN!");
	this->winText.setFont(this->font);
	this->winText.setCharacterSize(30);
	this->winText.setStyle(sf::Text::Bold);
	this->winText.setPosition(sf::Vector2f(400, 400));
	this->isPlayingDealer = false;
	this->isLose = false;
	this->deck.shuffle();
	this->players = players;
	this->initBackground();
	this->initFont();
	this->initButtons();
}

GameState::~GameState()
{
}


void GameState::renderPlayers(sf::RenderTarget* target)
{
	int i = 0;
	int d = 0;
	int ind = 0;
	for (auto& in : this->players)
	{
		if (in->getType())
		{
			for (auto& it : in->getHand())
			{
				this->playerCardSprite.setTexture(*it.getTexture());
				this->playerCardSprite.setPosition(sf::Vector2f(200 + (25 * i), 343));
				target->draw(this->playerCardSprite);
				i++;
			}
			this->playerInd = ind;
			ind++;
		}
		else
		{
			for (auto& it : in->getHand())
			{
				this->playerCardSprite.setTexture(*it.getTexture());
				this->playerCardSprite.setPosition(sf::Vector2f(200 + (25 * d), 150));
				target->draw(this->playerCardSprite);
				d++;
			}
			this->dealerInd = ind;
			ind++;
		}
	}
}

void GameState::initBackground()
{
	bool check = this->temp.loadFromFile("Sprites/Table.png");
	if (!check)
		EXIT_FAILURE;
	this->background.setTexture(temp);
	this->background.setColor(sf::Color::Red);
}

void GameState::initButtons()
{
	this->buttons["bet_button"] = new CircleButton(450, 450, 50, &this->font, 20, "Bet", sf::Color::Black, sf::Color(210, 210, 210), sf::Color::Yellow);
	this->buttons["hit_button"] = new CircleButton(560, 450, 50, &this->font, 20, "Hit", sf::Color::Black, sf::Color(210, 210, 210), sf::Color::Yellow);
	this->buttons["stay_button"] = new CircleButton(670, 450, 50, &this->font, 20, "Stay", sf::Color::Black, sf::Color(210, 210, 210), sf::Color::Yellow);
}

void GameState::initFont()
{
	if (!this->font.loadFromFile("Fonts/comic.ttf"))
		EXIT_FAILURE;
}

void GameState::endState()
{
}

void GameState::update(const float& dt)
{
	if (this->isPlayingDealer)
	{
		if (this->players[dealerInd]->getHand().size() > 1)
			std::this_thread::sleep_for(std::chrono::milliseconds(750));
		if (this->players[dealerInd]->getHandValue() < 17)
		{
			this->players[dealerInd]->addCard(this->deck.getCard());
		}
	}
	if (this->isLose == true || this->isWin == true)
	{
		this->endGame();
	}
	this->updateMousePosition();
	for (auto& in : this->buttons)
	{
		in.second->update(this->mousePosView);
	}
	if (this->buttons["bet_button"]->isPressed())
	{
		this->players[playerInd]->withdraw(1);
		while (this->players[playerInd]->getHand().size() < 2)
		{
			this->players[playerInd]->addCard(this->deck.getCard());
		}
		this->players[dealerInd]->addCard(this->deck.getCard());
	}
	if (this->buttons["hit_button"]->isPressed())
	{
		for (auto& in : this->players)
		{
			if (in->getType())
			{
				in->addCard(this->deck.getCard());
			}

		}
	}
	if (this->buttons["stay_button"]->isPressed())
	{
		this->isPlayingDealer = true;
	}

	this->checkGame();
}

void GameState::render(sf::RenderTarget* target)
{
	target->draw(this->background);
	for (auto& in : this->buttons)
	{
		in.second->render(target);
	}
	this->renderPlayers(target);
	if (isLose)
	{
		this->renderLoseText(target);
	}
	if (isWin)
	{
		this->renderWinText(target);
	}
}

void GameState::dealCards()
{
	for (auto& in : this->players)
	{
		in->addCard(this->deck.getCard());
	}
}

void GameState::checkGame()
{
	if (this->players[playerInd]->getHandValue() > 21)
		this->isLose = true;
	if (this->isPlayingDealer == true && this->players[dealerInd]->getHandValue() >= 17 && this->players[dealerInd]->getHandValue() <= 21)
	{
		if (this->players[dealerInd]->getHandValue() < this->players[playerInd]->getHandValue())
		{
			this->isWin = true;
			this->isPlayingDealer = false;
		}
		if (this->players[dealerInd]->getHandValue() > this->players[playerInd]->getHandValue())
		{
			this->isLose = true;
			this->isPlayingDealer = false;
		}
	}
	if (this->isPlayingDealer == true && this->players[dealerInd]->getHandValue() > 21)
	{
		this->isWin = true;
		this->isPlayingDealer = false;
	}
}

void GameState::endGame()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	//reset
	for (auto& in : this->players)
		in->clearHand();
	this->states->push(new GameState(this->window, this->states, this->players));
}

void GameState::renderLoseText(sf::RenderTarget* target)
{
	target->draw(this->loseText);
}

void GameState::renderWinText(sf::RenderTarget* target)
{
	target->draw(this->winText);
}