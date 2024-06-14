#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include <Windows.h>
#include "sayings.h"
#include "minigames.h"
using namespace std;
using namespace sf;





class scene
{
private:
	RenderWindow* window;
	enemysaying* lines1;
	int no_of_lines;
	string file;
	vector<string> image_animations;
	int animation_scene_no;
	int time_delay;
	int no_animations;
	int points_required;
	int points=0;
	int badscene;
	int goodscene;
	minigames* minigame;
	Sound background_sound;
	string sound;
	void typewriterEffect(Text& text, float delay, Sprite image) {

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





	int printlines(enemysaying line, Sprite image)
	{
		Font font;
		if (!font.loadFromFile("project_fonts/font.ttf")) {

			cout << "cannot load";
		}
		string options;
		char alpha = 'A';
		options += line.saying;
		options += "\n";
		for (int i = 0; i < line.nextlines.size(); i++)
		{
			options += "\n";
			options += alpha;
			options += ") ";
			options += line.nextlines[i].saying;
			alpha++;
		}
		Text saying;
		saying.setFont(font);
		saying.setString(options);
		saying.setCharacterSize(26);
		saying.setFillColor(sf::Color::White);
		saying.setPosition(750.f, 700.f);
		typewriterEffect(saying, 0.001, image);


		while (window->isOpen())
		{
			sf::Event event;
			while (window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window->close();

				if (event.type == sf::Event::KeyPressed)
				{
					if (event.key.code == sf::Keyboard::A)
					{
						points += line.nextlines[0].points;
						return line.nextlines[0].nextsaying;
					}
					else if (event.key.code == sf::Keyboard::B&&line.nextlines.size()!=1)
					{
						points += line.nextlines[1].points;
						return line.nextlines[1].nextsaying;
					}
					else if (event.key.code == sf::Keyboard::C && line.nextlines.size() > 2)
					{
						points += line.nextlines[2].points;

						return line.nextlines[2].nextsaying;
					}
					else if (event.key.code == sf::Keyboard::D && line.nextlines.size() > 3)
					{
						points += line.nextlines[3].points;

						return line.nextlines[3].nextsaying;
					}
				}
			}


		}

	}
   
	
public:
	scene(RenderWindow* window,enemysaying* lines1, int no_of_lines,string file, vector <string> image_animations,int animation_no,int time_delay,int no_animations,int best_scene,int worst_scene,int points_required ,minigames* minigame,Sound &s,string animation_sound)
	{
		this->sound = animation_sound;
		this->background_sound = s;
		this->goodscene = best_scene;
		this->badscene = worst_scene;
		this->minigame = minigame;
		this->points_required = points_required;
		this->time_delay = time_delay;
		this->no_animations = no_animations;
		this->animation_scene_no = animation_no;
		this->window = window;
		this->lines1 = lines1;
		this->no_of_lines = no_of_lines;
		this->file = file;
		this->image_animations = image_animations;
		//SoundBuffer buffer;
		//if (!buffer.loadFromFile(soundfile)) {
		//	// Handle error if audio file cannot be loaded
		//}

		//// Create a sound object and set its buffer
		//sf::Sound sound;
		//sound.setBuffer(buffer);
		//this->image_animations = image_animations;

	}
	int play()
	{

		sf::Texture texture;
		int next = 0;
		if (!texture.loadFromFile(file)) {
			cout << "file not loaded successfully";
		}

		Sprite image;
		image.setTexture(texture);
		image.setScale(1.0f, 1.0f);
		if (animation_scene_no == 0)
		{
			animations();
		}
		while (next != -1)
		{
			
			next=printlines(lines1[next], image);
			if (next == animation_scene_no)
			{
				animations();
			}
		}
		if (minigame != nullptr)
		{
			points+=minigame->play();
		}
		if (points < this->points_required)
		{
			return badscene;
		}
		else if(points>=this->points_required)
		{
			return goodscene;
		}

	}
	void animations()
	{
		background_sound.setVolume(0.5);
		Sound sound_ani;
		SoundBuffer buffer;
		if (sound != "")
		{
			if(!buffer.loadFromFile(sound))
			{
				cout << "error in loading file";
			}
				

			// Create sound object
		   
			sound_ani.setBuffer(buffer);
		}
		Texture* textures = new Texture[image_animations.size()];
		Sprite* images;
		images = new Sprite[image_animations.size()];
		for (int i = 0; i < image_animations.size(); i++)
		{
			images[i].setScale(1.0f, 1.0f);
			textures[i].loadFromFile(image_animations[i]);
			images[i].setTexture(textures[i]);
		}
		if (sound != "")
			sound_ani.play();
		for (int j = 0; j < no_animations; j++)
		{
			for (int i = 0; i < image_animations.size(); i++)
			{
				window->clear();
				window->draw(images[i]);
				window->display();
				Sleep(time_delay);
			}
		}
		if (sound != "")
			sound_ani.stop();
	}

};