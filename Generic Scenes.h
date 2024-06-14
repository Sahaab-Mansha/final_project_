#ifndef GenericEndings_H
#define GenericEndings_H

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <chrono>
#include <thread>

class ending
{
public:
    virtual void printending() const = 0;
    virtual void sound() const = 0;

protected:
    sf::RenderWindow* window;
    ending()
    {

    }
    void typewriterEffect(sf::Text& text, float delay, sf::Sprite& image) const {
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
};

#endif 
