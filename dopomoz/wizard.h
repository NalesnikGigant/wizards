#pragma once
#include "AnimatedSprite.h"

class wizard : public sf::Sprite
{
private:
	sf::Texture czarodziej;
	sf::Vector2u TextureSize;
	int x = 6;
	//sf::FloatRect swistoklik = getGlobalBounds();
	sf::Vector2u imageCount;
	sf::Vector2u currentimage;
	float totalTime;
	float switchTime;
	sf::RectangleShape ide;
	//bool keypress;
	float v_x = 25;
	float v_y = 20;

public:
	sf::IntRect anRe;
	wizard( sf::Vector2u imagecount, float swichtime);
	void animation(int row, float deltaTime);
	void walk(sf::Time czas, sf::Vector2u imagecount1, sf::Vector2u imagecount2);
	//void isanykeypressed();
	void idle(sf::Vector2u imagecount);
	void bound_check(sf::RenderWindow& okno);
	void grawitacja(sf::Time czas);
};

