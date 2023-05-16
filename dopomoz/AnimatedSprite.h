#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h> 
#include <time.h>
#include <random>
#include <vector>
#include <chrono>
#include <thread>
#include "wizard.h"
#include "mage.h"

class AnimatedSprite: public sf::Sprite
{
private:
	//sf::RenderWindow* window;
	sf::Event evnt;
	sf::Time time;
	sf::Clock clock;
	sf::Vector2u TextureSize;
	//int x = 6;
	float deltaTime = 0.0f;
	//sf::RectangleShape klocek;
	//sf::FloatRect swistoklik;
public:
	//AnimatedSprite(int x);
	//sf::Vector2i mousepos = sf::Mouse::getPosition(	);
	//virtual void move_mouse();
	void rysuj(sf::RenderWindow& window);
};

