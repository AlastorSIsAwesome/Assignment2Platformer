#include "cIncrimentButton.h"

cIncrimentButton::cIncrimentButton()
	:cButton() // uses cButton's default constructor
{
	m_IncrimentBy = 0;
}

cIncrimentButton::~cIncrimentButton()
{
}

cIncrimentButton::cIncrimentButton(sf::Vector2f _position, sf::Vector2f _size, std::string _textureFilePath, float _incrimentBy)
	: cButton(_position, _size, _textureFilePath), /*using cButton constuctor*/ m_IncrimentBy(_incrimentBy)
{
}

void cIncrimentButton::OnPressed(float* _propertyBeingAltered)
{
	_propertyBeingAltered += m_IncrimentBy;
}
