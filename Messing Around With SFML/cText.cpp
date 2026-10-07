#include "cText.h"

cText::cText()
{

	cUIElement(); // uses cUIElement's default constructor

	m_FontSize = 24;
}

cText::~cText()
{
	delete m_ptrText;
	m_ptrText = nullptr;
}

cText::cText(sf::Vector2f _position, sf::Font& _font, std::string _text, int _fontSize)
	: cUIElement(_position)/* uses cUIElement's  constructor*/, m_ptrFont(&_font), m_Text(_text), m_FontSize(_fontSize)
{
	m_ptrText = new sf::Text(*m_ptrFont, _text, m_FontSize);
	m_ptrText->setPosition(_position);
}

void cText::SetTextPosition(sf::Vector2f _position)
{
	m_Position = _position;
	m_ptrText->setPosition(_position);
}


void cText::DrawText(sf::RenderWindow& _window)
{
	_window.draw(*m_ptrText);
}
