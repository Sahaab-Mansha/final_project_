#ifndef Bright_H
#define Bright_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <Windows.h>
#include "Generic Scenes.h"

class bright : public ending
{
private:
    std::vector<std::string> lines = {"Decades blurred into centuries. The initial despair that gripped me had morphed into a dull ache, a constant reminder \n of the life I'd forfeited. The Everlasting Garden, once alluring, now stretched before me like a mocking tapestry.\n Each vibrant flower, each gurgling stream, was a cruel reminder of the fading beauty within me.", 
    "Memories were the first casualties. Faces, once etched into my soul, started to blur.\n Voices, once familiar, echoed in the vast emptiness of my mind. I clung desperately \n to remnants – a laugh, a scent,a touch – but even those were slowly dissolving like salt in an endless sea.", 
    "The bliss the puppets experienced was a lie. Their vacant eyes held a terrifying emptiness, devoid of joy or sorrow. \n I watched them, a chilling premonition of my own future. My reflection in the \n crystal-clear lakes confirmed my fears. The vibrancy in my eyes had dimmed, replaced by a hollow despair.", 
    "Pain, however, remained my constant companion. The sun's warmth became an agonizing burn,\n the gentle breeze a biting chill. Every breath was a battle, every movement a herculean effort. Yet, death, the sweet release \n I craved, remained a taunting illusion.", 
    "In the end, no matter how long I waited, there was no final act of \n mercy anyone in this wretched world could provide me."};

public:
    bright(sf::RenderWindow* window)
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
        if (!darkending.loadFromFile("project_images/Bright Ending.png")) {
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

#endif // Bright_H
