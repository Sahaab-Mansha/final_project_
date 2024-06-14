#pragma once
#include "player.h"
#include "initializer.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "find_the_difference.h"
#include "hangman.h"
#include "riddle.h"
#include "scene.h"
#include "Generic Scenes.h"
#include "Dark Ending.h"
#include "Bright Ending.h"
#include "Normal Ending.h"
using namespace sf;
class game_controller
{
    initializer init;
	player person;
	RenderWindow* window;
    scene** scenes;
    minigames** minigame;
    ending** endings = new ending * [3];

public:
    game_controller(RenderWindow* window) :init(window),window(window)
    {}
	int play()
	{
        endings[0] = new bright(window);
        endings[1] = new normal{ window };
        endings[2] = new dark{ window };
        sf::SoundBuffer buffer;
        if (!buffer.loadFromFile("project_sounds/Background.mp3")) {
            return 1;
        }
        sf::Sound sound;
        sound.setBuffer(buffer);
        init.initialize_scenes(scenes,minigame,sound);
        init.start();
        int next=0;
       person.set_name(init.getname());
       
       sound.play();

       SoundBuffer buffer2;
       if (!buffer2.loadFromFile("project_sounds/Normal Ending.mp3")) {
           return 1;
       }

       sf::Sound endsound1;
       endsound1.setBuffer(buffer2);
       
       SoundBuffer buffer3;
       sf::Sound endsound2;
       if (!buffer3.loadFromFile("project_sounds/Bright Ending.mp3")) {
           return 1;
       }
       endsound2.setBuffer(buffer3);

       
       SoundBuffer buffer4;
       sf::Sound endsound3;
       if (!buffer4.loadFromFile("project_sounds/Dark Ending.mp3")) {
           return 1;
       }
       endsound3.setBuffer(buffer4);
      
       

        while (window->isOpen())
        {
            while (next >= 0)
            {
                next=scenes[next]->play();
            }
            sound.stop();
            if (next == -10)
            {
                endsound1.play();
                endings[1]->printending();
                
            }
                

            else if (next == -20)
            {
                endsound2.play();
                endings[0]->printending();

            }

            else if (next == -30)
            {
                endsound3.play();
                endings[2]->printending();

            }
       
          
            break;
        }
        return 0;
	}

};

