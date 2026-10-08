#pragma once
#include "cButton.h"
class cIncrimentButton :
    public cButton
{
private:
protected:
    float m_IncrimentBy = 0;

public:
    cIncrimentButton();
    ~cIncrimentButton();

    cIncrimentButton(sf::Vector2f _position, sf::Vector2f _size, std::string _textureFilePath, float _incrimentBy);

    void OnPressed(float* _propertyBeingAltered) override;
};

