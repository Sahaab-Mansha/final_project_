#pragma once
#include "minigames.h"
#include "SFML/Audio.hpp"
#include <iostream>
#include <chrono>
#include <thread>
using namespace sf;
using namespace std;
#include <Windows.h>
class find_the_difference:public minigames
{

	
  
    void playsound(Sound &s)
    {
        s.play();
        Sleep(900);
        s.stop();
    }
public:
	find_the_difference(RenderWindow* window)
	{

        
        
		this->window = window;
		points = 0;
		
	}
    
	double play() override
    {
        SoundBuffer buffer;
        if (!buffer.loadFromFile("Project_sounds/minigame1.wav"))
        {
            std::cerr << "Failed to load audio file" << std::endl;
            return 1;
        }
        Sound sound;
        sound.setBuffer(buffer);

        bool* find;
        find = new bool[5];
        Texture texture;
        texture.loadFromFile("project_images/Scene 1 part 2.png");
        if (!texture.loadFromFile("project_images/Scene 1 part 2.png"))
        {
            cout << "picture not loaded";
        }

        Sprite image;
        image.setTexture(texture);
        image.setScale(1.0f,1.0f);
        start("Can you find\nthe differences!!!","Time:100s");
            auto start = std::chrono::steady_clock::now();
            std::this_thread::sleep_for(std::chrono::seconds(3));
		int differences = 0;
        Text text1;
        Font font;
        font.loadFromFile("project_fonts/font.ttf");
        text1.setFont(font);
        text1.setCharacterSize(30);
        text1.setFillColor(sf::Color::White); // Set text color
        text1.setStyle(sf::Text::Bold | sf::Text::Underlined); // Set text style
        text1.setPosition(1000, 0);
        while (window->isOpen()&&differences!=5)
        {
           

        
           
                Event event;
               
                    while (window->pollEvent(event))
                    {
                        if (event.type == sf::Event::Closed)
                            window->close();
                        else if (event.type == sf::Event::MouseButtonPressed)
                        {

                            if (event.mouseButton.button == sf::Mouse::Left)
                            {

                                Vector2i mousePosition = Mouse::getPosition(*window);
                                if (mousePosition.x >= 388 && mousePosition.x <= 505 && mousePosition.y >= 366 && mousePosition.y <= 388)
                                {
                                    if (find[0] != true)
                                    {
                                        playsound(sound);
                                        find[0] = true;
                                        differences++;

                                    }
                                }
                                else if (mousePosition.x >= 332 && mousePosition.x <= 469 && mousePosition.y >= 482 && mousePosition.y <= 550)
                                {
                                    if (find[1] != true)
                                    {
                                        playsound(sound);

                                        find[1] = true;
                                        differences++;
                                    }
                                }
                                else   if (mousePosition.x >= 189 && mousePosition.x <= 230 && mousePosition.y >= 914 && mousePosition.y <= 937)
                                {
                                    if (find[2] != true)
                                    {
                                        playsound(sound);

                                        find[2] = true;
                                        differences++;
                                    }
                                }
                                else if (mousePosition.x >= 1147 && mousePosition.x <= 1166 && mousePosition.y >= 407 && mousePosition.y <= 429)
                                {
                                    if (find[3] != true)
                                    {
                                        playsound(sound);


                                        find[3] = true;
                                        differences++;
                                    }
                                }
                                else if (mousePosition.x >= 24 && mousePosition.x <= 220 && mousePosition.y >= 11 && mousePosition.y <= 205)
                                {
                                    if (find[4] != true)
                                    {
                                        playsound(sound);

                                        find[4] = true;
                                        differences++;
                                    }
                                }
                                cout << "Mouse Clicked at: (" << mousePosition.x << ", " << mousePosition.y << ")" << endl;

                            }
                        }
                    }
                    string textString = "Found: " + std::to_string(differences);
                    text1.setString(textString);
                    window->clear();
                    window->draw(image);
                    window->draw(text1);
                    window->display();

                
                
        }
        auto end = std::chrono::steady_clock::now();
        auto duration = end - start;
        points = 100-std::chrono::duration<double>(duration).count();
       
        return points;
	}


};

