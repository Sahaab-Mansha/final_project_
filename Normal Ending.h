#ifndef Normal_H
#define Normal_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <Windows.h>
#include "Generic Scenes.h"

class normal : public ending
{
private:
    std::vector<std::string> lines = {"Falling, I am falling and falling. It might have been a few minutes, or nine days. \n I couldn't tell. Just the wind whistling by and the cold air cutting my cheeks.", 
    "I heard it first, the faint rhythmic ticking of a clock. Slowly, my eyes adjusted to the \n brightness of a room - my room. I looked to see my worried family’s face gleam with joy as they \n rushed to me, embracing me in their arms.",
    "Never before have I missed them as much as I did now, the experience sharp and \n clear in my mind. I had questions, so many questions.", "I am home. . . but the memories of another place. . . a place \n I traveled to, the questions bothered me. I sometimes felt a little empty, maybe I was going insane.", 
    "I don't know if this was the happy ending that I could have had. I am not the same person I was before.\n Sometimes, when I travel by train, the memories will pop in my head, try as I may, \n I can't escape it. I haven't slept in days."};

public:
    normal( sf::RenderWindow* window)
    {
        this->window = window;
    }

    void printending() const override
    {
        sf::Font font;
        if (!font.loadFromFile("project_fonts/font.ttf")) {
            std::cerr << "Error loading font" << std::endl;
            return;
        }

        sf::Texture darkending;
        if (!darkending.loadFromFile("project_images/Normal Ending with muted colours.png")) {
            std::cerr << "Error loading image" << std::endl;
            return;
        }

        sf::Sprite backgroundSprite;
        backgroundSprite.setTexture(darkending);

        for (const auto& line : lines)
        {
            sf::Text a(line, font, 30);
            a.setFillColor(sf::Color::White);
            a.setPosition(100, 100);
            typewriterEffect(a, 0.05f, backgroundSprite);
            Sleep(1000);
            window->clear();
            window->draw(backgroundSprite);
            window->display();
        }
    }

    void sound() const override
    {

    }
};

#endif // Normal_H
