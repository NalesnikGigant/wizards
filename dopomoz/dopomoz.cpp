#include "AnimatedSprite.h"


int main()
{
    srand(time_t(NULL));
    sf::RenderWindow window(sf::VideoMode(1000, 600), "My window", sf::Style::Titlebar | sf::Style::Close);
    AnimatedSprite x;
    x.rysuj(window);
    return 0;
}
