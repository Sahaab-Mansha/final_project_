#ifndef Dark_H
#define Dark_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <Windows.h>
#include "Generic Scenes.h"
using namespace std;

class dark : public ending
{
private:
    vector<string> lines = { "Death might not have been the ideal ending, it never is. I might have fallen down here accidentally, \n but I chose to ask questions.", "However, it's not as bad as it seems. There is no pain, just serenity. I didn't know how \n long I drifted, or if time even existed in this in-between state.",
    "But slowly, a faint light emerged from the darkness, growing brighter and brighter \n until it solidified into a familiar sight - the train. But something was different. There was a strange \n hustle and bustle around the train, shouts here and there, running and panicked noises.",
    "I saw the passengers gather me in their arms, calling for help and shaking me.\n I looked serene, laying there.", "Sooner, my parents would get the call, and there would be a funeral. \n Maybe I will go and see them one last time, then go and explore the world.\n  Or there might be another form of after life. I might have died, but at least my soul is back home." };


public:
    dark(sf::RenderWindow* window)
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
        if (!darkending.loadFromFile("project_images/Dark Ending.png")) {
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

#endif // Dark_H
