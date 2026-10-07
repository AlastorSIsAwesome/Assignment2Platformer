/*******************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2026 Media Design School at Strayer
File Name : []
Description : [Implimentation file for cPlayer, handels animations for walking and switching between characters]
Author : [Alastor Spear]
Mail : alastor.spear@mds.ac.nz
*******************************/

#include "cPlayer.h"

 /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CON/DESTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

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
		m_AnimationRect.position.y = 0; //sister al starting position
	}
	else
	{
		m_AnimationRect.position.y = 64; // sister niki starting position
	}

	// animationRect setting
	m_AnimationRect.position.x = 0;
	m_AnimationRect.size.x = 32;
	m_AnimationRect.size.y = 64;

	// start animation clock
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


 /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ANIMATIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void cPlayer::AnimatePlayer(AnimationType _animationType)
{
	if (m_Clock.getElapsedTime().asSeconds() > 0.16f) // If its time to change the frame
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
		m_Clock.restart(); // reset clock
	}

	if (_animationType == WalkingLeft)
	{
		// makes the textureRect read backwards
		m_EntityShape.setTextureRect(sf::IntRect(sf::Vector2i(m_AnimationRect.position.x, m_AnimationRect.position.y), sf::Vector2i(-m_AnimationRect.size.x, m_AnimationRect.size.y)));
	}

	if (_animationType == WalkingRight)
	{
		// regular animation reading
		m_EntityShape.setTextureRect(sf::IntRect(sf::Vector2i(m_AnimationRect.position.x, m_AnimationRect.position.y), sf::Vector2i(m_AnimationRect.size.x, m_AnimationRect.size.y)));
	}
}


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ACTIVE CHARACTER SETTERS/GETTERS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

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