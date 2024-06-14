#pragma once
#include "minigames.h"
#include <string>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class hangman :
    public minigames
{
    
    string get_random_word()
    {
        srand(time(0));
        
        string words[] = { "phantom", "eerie", "haunted", "specter", "creepy", "macabre", "ghoul", "wraith", "spine-chilling", "supernatural", "sinister", "bone-chilling", "cursed", "petrifying", "apparition", 
            "grim", "unearthly", "menacing", "dreadful", "shadowy" };

        return words[rand() % 20];
    }
    bool search(char* arr,int size, char s)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == s)
                return true;
        }
        return false;
    }
    bool in_word(string word, char s, bool*& found,int& guessed)
    {
        int count = 0;
        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] == s)
            {
                found[i] = true;
                guessed++;
                count++;
            }
        }
        if (count == 0)
            return false;
        return true;
    }
    void printword(string word, int size, bool* guessed,Text& text)
    {
        int s = 0;
        

        string spacedWord;
        for (int i = 0; i < word.size(); i++)
        {
            if (guessed[i] == false)
            {
                spacedWord += '_';
            }
            else
                spacedWord += word[i];
            spacedWord += '  ';

        }
        text.setString(spacedWord);
    }
public:
    hangman(RenderWindow*window)
    {
      
        points = 0;
        this->window = window;
    }
    
    double play() override
    {
        char* searched = new char[10];
        int size = 0;
        Texture texture0;
        texture0.loadFromFile("project_images/hangman o.png");
        Sprite image0;
        image0.setTexture(texture0);
        image0.setScale(0.67f, 0.7f);


        Texture texture1;
        texture1.loadFromFile("project_images/hangman 1.png");
        Sprite image1;
        image1.setTexture(texture1);
        image1.setScale(0.67f, 0.7f);

        Texture texture2;
        texture2.loadFromFile("project_images/hangman 2.png");
        Sprite image2;
        image2.setTexture(texture2);
        image2.setScale(0.67f, 0.7f);

        Texture texture3;
        texture3.loadFromFile("project_images/hangman 3.png");
        Sprite image3;
        image3.setTexture(texture3);
        image3.setScale(0.67f, 0.7f);

        Texture texture4;
        texture4.loadFromFile("project_images/hangman 4.png");
        Sprite image4;
        image4.setTexture(texture4);
        image4.setScale(0.67f, 0.7f);

        Texture texture5;
        texture5.loadFromFile("project_images/hangman 5.png");
        Sprite image5;
        image5.setTexture(texture5);
        image5.setScale(0.67f, 0.7f);

        Texture texture6;
        texture6.loadFromFile("project_images/hangman 6.png");
        Sprite image6;
        image6.setTexture(texture6);
        image6.setScale(0.67f, 0.7f);

        Texture texture7;
        texture7.loadFromFile("project_images/hangman end.png");
        Sprite image7;
        image7.setTexture(texture7);
        image7.setScale(0.67f, 0.7f);



        char alphabet;
        Text text;
        Font font;
        if (!font.loadFromFile("project_fonts/font.ttf")) {
            cerr << "Error loading font!" << std::endl;

        }

        text.setFont(font);
        text.setCharacterSize(60);
        text.setFillColor(Color::White);
        text.setPosition(700, 200);

        Text text2;
        text2.setFont(font);
        text2.setCharacterSize(40);
        text2.setFillColor(Color::White);
        text2.setPosition(600, 400);
        text2.setString("Enter alphabet");

        Text text3;
        text3.setFont(font);
        text3.setCharacterSize(30);
        text3.setFillColor(Color::Red);
        text3.setPosition(600, 500);
      //  text3.setString("Already Entered");

        Text text4;
        text4.setFont(font);
        text4.setCharacterSize(40);
        text4.setFillColor(Color::Red);
        text4.setPosition(600, 500);
       // text4.setString("Wrong!!");
        int count = 0;
        int guessed = 0;
        start("Hang The Man", "Each guess holds the\nkey to survival");
        string word = get_random_word();
        bool* found = new bool[word.size()] {};
        int tries = 0;
        bool entered;
        while (window->isOpen() && tries != 6&&guessed!=word.size())
        {
            
            Event event;
            entered = false;
            
           

            while (window->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window->close();
                
                else if (event.type == Event::TextEntered)
                {
                    if (count == 0)
                    {
                        count++;
                        continue;

                    }
                    
                    if (event.text.unicode >= 97 && event.text.unicode <= 122 && event.text.unicode != 8)
                    {
                        text4.setString("");
                        text3.setString("");
                        alphabet = static_cast<char>(event.text.unicode);
                        entered = true;
                    }
                   
                
                }
     
            }
            if (entered == true)
            {
                if (in_word(word, alphabet, found, guessed) == false)
                {
                    if (search(searched, size, alphabet) == true)
                    {

                        text3.setString("Already entered");

                    }
                    else if (search(searched, size, alphabet) == false)
                    {
                        tries++;
                        searched[size] = alphabet;
                        size++;
                        text4.setString("WRONG X");
                    }
                }
               
               
            }
            window->clear();
            if (tries == 0)
                window->draw(image0);
            else if (tries == 1)
                window->draw(image1);
            else if (tries == 2)
                window->draw(image2);
            else if (tries == 3)
                window->draw(image3);
            else if (tries == 4)
                window->draw(image4);
            else if (tries == 5)
                window->draw(image5);
            else if (tries == 6)
            {
                window->draw(image6);
                window->display();
                Sleep(1000);
                window->clear();
                window->draw(image7);
                window->display();
                Sleep(1000);
                break;
            }
            
            printword(word, word.size(), found, text);
            window->draw(text);
            window->draw(text2);
            window->draw(text3);
            window->draw(text4);

            window->display();

        }
        return guessed*10;
    }


};

