#pragma once
#include "minigames.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <Windows.h>
#include <string>
using namespace sf;
using namespace std;





class riddles : public minigames
{
private:
    string riddlearr[5] = { "Voiceless it cries, Wingless flutters, Toothless bites, Mouthless mutters.",
   "This thing all things devours; Birds, beasts, trees, flowers; Gnaws iron, bites steel;\n Grinds hard stones to meal; Slays king, ruins town, And beats mountain down.",
   "It cannot be seen, cannot be felt, Cannot be heard, cannot be smelt. It lies behind stars \n and under hills, And empty holes it fills. It comes out first and follows after,\n Ends life, kills laughter."
   , "Thirty two white horses on a red hill,\n First they champ, Then they stamp, Then they stand still.",
   "A box without hinges, key, or lid, Yet golden treasure inside is hid" };


    string riddleanswers[5] = { "wind", "time", "dark", "teeth", "egg" };

    Event event;
    string toLowerCase(const string& str) {
        string lowerStr = str;
        std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(),
            [](unsigned char c) { return std::tolower(c); });
        return lowerStr;
    }

public:
    riddles(RenderWindow* window)
    {
        this->window = window;
        points = 0;
    }

    string answers(Sprite& backgroundSprite, Text& riddletext) {
        Font font;
        font.loadFromFile("project_fonts/font.ttf");
        Text inputtext;
        inputtext.setFont(font);
        inputtext.setCharacterSize(40);
        inputtext.setFillColor(Color::White);
        inputtext.setPosition(100, 500);
        string potentialanswer;

        while (true) {
            while (window->pollEvent(event)) {
                if (event.type == Event::Closed) {
                    window->close();
                }
                else if (event.type == Event::TextEntered) {
                    if (event.text.unicode < 128 && event.text.unicode != 8 && event.text.unicode != 13) {
                        potentialanswer += static_cast<char>(event.text.unicode);
                        inputtext.setString(potentialanswer);
                    }
                    else if (event.text.unicode == 8 && !potentialanswer.empty()) {
                        potentialanswer.pop_back();
                        inputtext.setString(potentialanswer);
                    }
                }
                else if (event.type == Event::KeyPressed) {
                    if (event.key.code == Keyboard::Enter && !potentialanswer.empty()) {
                        return potentialanswer;
                    }
                }
            }
            window->clear();
            window->draw(backgroundSprite);
            window->draw(riddletext);
            window->draw(inputtext);
            window->display();
        }
    }

    double play() override
    {
        Font riddlefonts;
        riddlefonts.loadFromFile("project_fonts/font.ttf");
        Texture riddleminigame;
        riddleminigame.loadFromFile("project_images/minigames canvas.png");
        sf::Text start("The wrong answer could be your last.", riddlefonts, 50);
        start.setFillColor(sf::Color::White);
        start.setStyle(sf::Text::Bold | sf::Text::Underlined);
        start.setPosition(600, 500);
        sf::Sprite backgroundSprite;
        backgroundSprite.setTexture(riddleminigame);
        typewriterEffect(start, 0.1f, backgroundSprite);

        for (size_t i = 0; i < 5; i++) {
            sf::Text riddletext(riddlearr[i], riddlefonts, 40);
            riddletext.setFillColor(sf::Color::White);
            riddletext.setPosition(100, 100);
            typewriterEffect(riddletext, 0.05f, backgroundSprite);

            std::string potentialanswer;
            std::string prompt = "What do you think? ";
            sf::Text promptText(prompt, riddlefonts, 40);
            promptText.setFillColor(sf::Color::White);
            promptText.setPosition(100, 300);
            typewriterEffect(promptText, 0.05f, backgroundSprite);

            potentialanswer = answers(backgroundSprite, riddletext);
            potentialanswer = toLowerCase(potentialanswer);

            if (potentialanswer == riddleanswers[i]) {
                points += 10;
                prompt = "Good Guess";
            }
            else {
                prompt = "Not Quite...";
              
            }

            sf::Text responseText(prompt, riddlefonts, 40);
            responseText.setFillColor(sf::Color::White);
            responseText.setPosition(100, 400);

            window->clear();
            window->draw(backgroundSprite);
            window->draw(riddletext);
            window->draw(responseText);
            window->display();

            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
        return points;
    }

};