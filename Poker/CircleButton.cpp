#include "CircleButton.h"

CircleButton::CircleButton(float x, float y, float radius, sf::Font* font, int fontSize, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
	this->buttonState = CBTN_IDLE; 
	this->idleColor = idleColor;
	this->activeColor = activeColor;
	this->hoverColor = hoverColor;

	this->shape.setRadius(radius);
	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setFillColor(this->idleColor);
	
	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setCharacterSize(fontSize);
	this->text.setFillColor(sf::Color::White);
	this->text.setPosition(this->shape.getPosition().x + this->shape.getRadius() - this->text.getGlobalBounds().width, this->shape.getPosition().y + this->shape.getRadius() - this->text.getGlobalBounds().height);

	

}

CircleButton::~CircleButton()
{
}

const bool CircleButton::isPressed() const
{
	if (this->buttonState == CBTN_PRESSED)
		return true;
	else
		return false;
}

void CircleButton::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
	target->draw(this->text);
}

void CircleButton::update(sf::Vector2f mousePos)
{
	this->buttonState = CBTN_IDLE;
	//check hovering
	if (this->shape.getGlobalBounds().contains(mousePos))
	{
		this->buttonState = CBTN_HOVER;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->buttonState = CBTN_PRESSED;
		}
	}

	switch (this->buttonState)
	{
	case CBTN_IDLE:
		this->shape.setFillColor(this->idleColor);
		break;
	case CBTN_HOVER:
		this->shape.setFillColor(this->hoverColor);
		break;
	case CBTN_PRESSED:
		this->shape.setFillColor(this->activeColor);
		break;
	}
}
