#include "wizard.h"
//przypisz stoj¹cego czarodzieja
wizard::wizard(/*sf::Texture* tex,*/ sf::Vector2u imagecount, float swichtime) {
	if (!czarodziej.loadFromFile("Idle.png")) { std::cerr << "Could not load texture" << std::endl; }
	setTexture(czarodziej);
	setPosition(206.0f,206.0f);
	//ide.setTexture(&czarodziej);
	imageCount = imagecount;
	switchTime = swichtime;
	totalTime = 0.0f;
	currentimage.x = 0;
	//keypress = false;
	anRe.width = czarodziej.getSize().x / float(imageCount.x);
	anRe.height = czarodziej.getSize().y / float(imageCount.y);
	/*TextureSize = czarodziej.getSize();
	TextureSize.x /= 7;	*/		
	setTextureRect(anRe);

	sf::FloatRect swistoklik = getGlobalBounds();
}
//animuj ró¿nych czarodziei
void wizard::animation (int row, float deltaTime) {


	currentimage.y = row;
	totalTime += deltaTime;
	if (totalTime >= switchTime) {
		totalTime -= switchTime;
		currentimage.x++;
		if (currentimage.x > imageCount.x-1) {
			currentimage.x = 0;
		}
	}
	anRe.left = currentimage.x * anRe.width;
	anRe.top = currentimage.y * anRe.height;

}
//idŸ w prawo gdy nacisnê D i biegnij w prawo gdy nacisnê Lshift i D
void wizard::walk(sf::Time czas, sf::Vector2u imagecount1, sf::Vector2u imagecount2) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		move(v_x * czas.asSeconds(), 0);
		if (!czarodziej.loadFromFile("Walk.png")) { std::cerr << "Could not load texture" << std::endl; }
		this->setTexture(czarodziej);
		imageCount = imagecount1;

		anRe.width = czarodziej.getSize().x / float(imageCount.x);
		anRe.height = czarodziej.getSize().y / float(imageCount.y);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)&& sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
		move(v_x * 10 * czas.asSeconds(), 0);
		if (!czarodziej.loadFromFile("Run.png")) { std::cerr << "Could not load texture" << std::endl; }
		this->setTexture(czarodziej);
		imageCount = imagecount2;

		anRe.width = czarodziej.getSize().x / float(imageCount.x);
		anRe.height = czarodziej.getSize().y / float(imageCount.y);
	}
}
//przypisuj stoj¹cego czarodzieja gdy siê nie rusza
void wizard::idle(sf::Vector2u imagecount) {
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		if (!czarodziej.loadFromFile("Idle.png")) { std::cerr << "Could not load texture" << std::endl; }
		this->setTexture(czarodziej);
		imageCount = imagecount;

		anRe.width = czarodziej.getSize().x / float(imageCount.x);
		anRe.height = czarodziej.getSize().y / float(imageCount.y);
	}
}
//teleportuj czarodzieja z prawej krawêdzi do lewej
void wizard::bound_check(sf::RenderWindow& okno) {
	sf::FloatRect swistoklik = getGlobalBounds();
	//std::cout << swistoklik.left <<" " << swistoklik.width <<std::endl;
	if (swistoklik.left + swistoklik.width > 1000) { setPosition(0, getPosition().y); }
}
//nie dzia³aj¹ca funkcja sprawiaj¹ca ¿e 
void wizard::grawitacja(sf::Time czas) {
	//ti *= czas.asSeconds();
	move(0, v_y * czas.asSeconds() );

}