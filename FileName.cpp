#include <SFML/Graphics.hpp>
#include "initializer.h"
#include "game_controller.h"
#include "hangman.h"
using namespace sf;

int main()
{
    RenderWindow window(sf::VideoMode(1920, 1080), "SFML Window");
    game_controller controller(&window);
    controller.play();
    return 0;
}

    


