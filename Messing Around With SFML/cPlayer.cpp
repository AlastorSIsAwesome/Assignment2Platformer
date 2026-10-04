#include "cPlayer.h"

cPlayer::cPlayer(sf::Vector2f _position, ActiveCharacter _character)
	: cEntity(_position) /*using cEntity's constructor*/, m_ActiveCharacter(_character)
{
	// set size
	m_EntityShape.setSize(sf::Vector2f(64.f, 128.f));

	// set texture
	m_EntityTexure.loadFromFile("textures/PlayerTexture.png");
	m_EntityShape.setTexture(&m_EntityTexure);

	// setting up animation stuff
	m_EntityShape.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(32, 64)));
	
	if (_character == SisterAl)
	{
		m_AnimationRect.position.y = 0;
	}
	else
	{
		m_AnimationRect.position.y = 64;
	}

	m_AnimationRect.position.x = 0;
	m_AnimationRect.size.x = 32;
	m_AnimationRect.size.y = 64;


	m_Clock.start();

	// set velocity
	m_Velocity = { 0.f, 0.f };
}

cPlayer::cPlayer()
{
	m_ActiveCharacter = SisterNiki;
}

cPlayer::~cPlayer()
{
}

void cPlayer::AnimatePlayer(AnimationType _animationType)
{

	if (m_Clock.getElapsedTime().asSeconds() > 0.16f)
	{
		if (_animationType == WalkingLeft || _animationType == WalkingRight) // ASK FOR HELP ON THIS
		{
			if (m_AnimationRect.position.x < 32)
			{
				m_AnimationRect.position.x += 32;
			}
			else if (m_AnimationRect.position.x >= 32)
			{
				m_AnimationRect.position.x = 0;
			}
		}

		else if (_animationType == Idle)
		{
			m_AnimationRect.position.x = 0;
		}


		m_EntityShape.setTextureRect(m_AnimationRect);
		m_Clock.restart();
	}

	if (_animationType == WalkingLeft)
	{
		//m_EntityShape.setScale(sf::Vector2f(-1.f, 1.f));
		m_EntityShape.setTextureRect(sf::IntRect(sf::Vector2i(m_AnimationRect.position.x, m_AnimationRect.position.y), sf::Vector2i(-m_AnimationRect.size.x, m_AnimationRect.size.y)));
	}

	if (_animationType == WalkingRight)
	{
		//m_EntityShape.setScale(sf::Vector2f(1.f, 1.f));
		
		m_EntityShape.setTextureRect(sf::IntRect(sf::Vector2i(m_AnimationRect.position.x, m_AnimationRect.position.y), sf::Vector2i(m_AnimationRect.size.x, m_AnimationRect.size.y)));
	}

}

void cPlayer::SetActiveCharacter(ActiveCharacter _character)
{
	m_ActiveCharacter = _character;

	if (_character == SisterAl) // if chaning to sister al
	{
		m_AnimationRect.position.y = 0; // set y position to allign
	}
	else // if not siter al, then it must be sister niki
	{
		m_AnimationRect.position.y = 64;
	}
}

void cPlayer::SetActiveCharacter()
{
	if (m_ActiveCharacter == SisterAl) // if currently al, switch to niki
	{
		m_ActiveCharacter = SisterNiki;
		m_AnimationRect.position.y = 64;
	}
	else // if currently niki, switch to al
	{
		m_ActiveCharacter = SisterAl;
		m_AnimationRect.position.y = 0;
	}
}

/*
	switch (m_ActiveCharacter)
	{
	case SisterAl:
	{
		if (m_Clock.getElapsedTime().asSeconds() > 0.16f)
		{
			if m_AnimationRect.left
		}

		break;
	}

	case SisterNiki:
	{
		break;
	}
	case Default: // fall through because Default has no assigned texture
	default:
	{
		break;
	}
	}

*/