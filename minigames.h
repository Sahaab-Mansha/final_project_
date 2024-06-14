#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
using namespace sf;
#include <iostream>
using namespace std;
#include <Windows.h>
class minigames
{
protected:
	RenderWindow* window;
	double points;
    void typewriterEffect(Text& text, float delay, Sprite& image) {

        std::string fullText = text.getString();


        text.setString("");


        for (size_t i = 0; i < fullText.size(); ++i) {

            text.setString(text.getString() + fullText[i]);


            window->clear();
            window->draw(image);
            window->draw(text);
            window->display();


            std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(delay * 1000)));
        }
    }
    void start(String first,String second)
    {
        Font font;
        font.loadFromFile("project_fonts/font.ttf");

        // Create a text object
        sf::Text text1(first, font, 50);
        text1.setFillColor(sf::Color::White); // Set text color
        text1.setStyle(sf::Text::Bold | sf::Text::Underlined); // Set text style
        text1.setPosition(730, 500);



        // Create a text object
        sf::Text text2(second, font, 50);
        text2.setFillColor(sf::Color::White); // Set text color
        text2.setStyle(sf::Text::Bold | sf::Text::Underlined); // Set text style
        text2.setPosition(700, 500);

        Texture texture;
        texture.loadFromFile("project_images/minigame1.jpg");
        Sprite image2;
        image2.setTexture(texture);
        image2.setScale(1.3f, 1.3f);
        window->clear();
        window->draw(image2);

        window->display();
        typewriterEffect(text1, 0.02, image2);
        Sleep(1000);
        typewriterEffect(text2, 0.02, image2);
        Sleep(200);
    }
public:
	minigames()
	{

	}

	virtual double play()=0;
};

