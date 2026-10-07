#pragma once

#include "SFML/Graphics.hpp"

class cBlock
{
private:
protected:
	char m_IdentityChar = 'X'; //default block identity

	sf::Vector2f m_Position;
	sf::Vector2f m_Size;
	sf::Texture* m_ptrTexture = nullptr;

	sf::RectangleShape* m_ptrBlockShape = nullptr;



public:
	cBlock();
	~cBlock();

	cBlock(char _identity, sf::Vector2f _position, sf::Vector2f _size, sf::Texture* _texture);


	inline sf::RectangleShape* GetBlockShpae()
	{
		return m_ptrBlockShape;
	}
	// shouldn't need a setter


	inline char GetBlockIdentity()
	{
		return m_IdentityChar;
	}


	inline sf::Vector2f GetPosition()
	{
		return m_Position;
	}

	void SetPosition(sf::Vector2f _position);


	inline sf::Vector2f GetSize()
	{
		return m_Size;
	}

	void SetSize(sf::Vector2f _size);





	void DrawBlock(sf::RenderWindow& _window);

	bool CollidingWithBlock(sf::RectangleShape* _collidingWith);
};

