#include "AnimatedSprite.h"


//narysuj obrazy i 
void AnimatedSprite::rysuj(sf::RenderWindow &window) {
	//utwórz vector trzymaj¹cy wszystkie rysowane obiekty, a nastêpnie przypisz do niego klasy/obiekty klas
	std::vector<std::unique_ptr<sf::Drawable>> rysowane;
	rysowane.emplace_back(std::make_unique<wizard>( sf::Vector2u(8, 1), 0.3f));
	rysowane.emplace_back(std::make_unique<mage>);

	time = clock.getElapsedTime();
	while (window.isOpen()) {;
		window.setFramerateLimit(60);
		deltaTime = clock.restart().asSeconds();
		while (window.pollEvent(evnt)) {
			if (evnt.type == sf::Event::Closed)
				window.close();
		}
		window.clear();

		for (auto& rec : rysowane) {
			window.draw(*rec);
			wizard& z = dynamic_cast<wizard&>(*rec);

			z.animation(0, deltaTime);
			z.setTextureRect(z.anRe);

			z.walk(time, sf::Vector2u(7, 1), sf::Vector2u(8, 1));
			z.setTextureRect(z.anRe);
			z.idle(sf::Vector2u(8, 1));
			z.bound_check( window);
			//z.grawitacja(time);
		}
		/*for (auto& rec : rysowane) {
			mage& t = dynamic_cast<mage&>(*rec);
			window.draw(t);

		}*/
		window.display();
	}
}