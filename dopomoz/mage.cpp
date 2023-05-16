#include "mage.h"
mage::mage() {
	if (!mag.loadFromFile("grass.png")) { std::cerr << "Could not load texture" << std::endl; }
	setTexture(mag);
	//setScale(10, 1 / 2);
	//setPosition(100, 400);
	
}