#pragma once
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Windows.h>
#include "scene.h"
#include "sayings.h"
#include "hangman.h"
#include "riddle.h"
#include "find_the_difference.h"
using namespace sf;
using namespace std;
class initializer
{
	RenderWindow* window;
	Event event;
	void display(Sprite x)
	{
		window->clear();
		window->draw(x);
		window->display();

	}

   public:
	initializer(RenderWindow* window)
	{
		this->window = window;
	}
	void start()
	{
		
		Texture texture;
		texture.loadFromFile("project_images/mian.png");
		Sprite sprite;
		
		sprite.setTexture(texture);
		sprite.setScale(0.5f, 0.7f);

		sf::SoundBuffer buffer;
		buffer.loadFromFile("project_sounds/click.mp3");

		// Create a sound and set its buffer
		sf::Sound sound;
		sound.setBuffer(buffer);

		bool clicked = false;
		while (clicked == false)
		{
			while (window->pollEvent(event))
			{

				if (event.type == Event::Closed)
					window->close();
				else if (event.type == sf::Event::MouseButtonPressed)
				{

					if (event.mouseButton.button == sf::Mouse::Left)
					{

						Vector2i mousePosition = Mouse::getPosition(*window);
						cout << "Mouse Clicked at: (" << mousePosition.x << ", " << mousePosition.y << ")" << endl;
						if (mousePosition.x >= 327 && mousePosition.x <= 549 && mousePosition.y >= 741 && mousePosition.y <= 843)
						{
							sound.play();
							Sleep(1000);
							clicked = true;
							break;
						}
					}
					
				}
			}
			display(sprite);
		}
	}
	string getname()
	{
		Texture texture2;
		texture2.loadFromFile("project_images/name 2.png");
		Sprite sprite2;
		string name = "";
		sprite2.setTexture(texture2);
		sprite2.setScale(0.5f, 0.7f);

		Font font;
	    font.loadFromFile("project_fonts/font.ttf");

		
		Text inputText;
		inputText.setFont(font);
		inputText.setCharacterSize(40);
		inputText.setFillColor(Color::White); 
		inputText.setPosition(50, 500); 


		
			while (true)
			{
				while (window->pollEvent(event))
				{
					if (event.type == Event::Closed)
						window->close();
					else if (event.type == Event::TextEntered)
					{
						// Handle text input
						if (event.text.unicode < 128 && event.text.unicode != 8) // Accept ASCII characters (excluding backspace)
						{
							// Add the input character to the text string
							name += static_cast<char>(event.text.unicode);
							inputText.setString(name);
						}
						else if (event.text.unicode == 8 && !name.empty())
						{
							// Remove the last character from the text string
							name.pop_back();
							inputText.setString(name);
						}
					}
					else if (event.type == Event::KeyPressed)
					{
						if (event.key.code == Keyboard::Enter&&!name.empty())
						{
							return name;
						}
					}
				}

				window->clear();
				window->draw(sprite2);
				window->draw(inputText);
				window->display();
			}
		
	
	
	}

	void initialize_scenes(scene**& scenes,minigames** &minigame,Sound& sound)
	{
		//scene1
		minigame = new  minigames*[3];
		minigame[0] = new find_the_difference{ window };
		minigame[1] = new hangman{ window };
		minigame[2] = new riddles{ window };
		enemysaying* lines1;
		scenes = new scene * [10];
		lines1 = new enemysaying[12];
		lines1[0] = { "",{{"Where am i?",1}} };
		lines1[1] = { "It seems thou hast risen from thine slumber of great length!",{{"Indeed",3},{"This doesn’t answer my question",2,-10},{"How peculiar",3}} };
		lines1[2] = { "Thou art a knave to speak to thine elder with such disrespect! \n Hast thou no courtesy? Show me deference, or feelest \n thou the sting of my wrath!",{{"…",3}} };
		lines1[3] = { "Hearest thou the town crier's call? We draw nigh unto the \n next waystation.Alight here, if such be thy destination!",{{"I don’t understand you.",4,-10},{"Will this train ever stop",4,-10},{"...",4}} };
		lines1[4] = { "Say, What name dost thou bear, lad?",{{"Tell correct name ",6,-20},{"Tell incorrect name",6},{"...",5}} };
		lines1[5] = { "Out with it, whelp! Speak louder, have ye no respect for thine elders?\n What is thy cursed name?",{{"tell correct name",6}} };
		lines1[6] = { "So, ye have chosen to share this path with us. \n Mayhap your intentions are as pure as the winter's wind. \n Would that not be equivalent to wishing misfortune?",{{"Winter winds are as harsh as they are pure",7},{"Its been a while since we stopped.",7,-10},{"I will be getting off on the next stop",7,-10},{"Winter winds are no longer as pure as ones memory serves.",7,10}} };
		lines1[7] = { "…",{{"Who are you",8},{"Where are you headed?",8},{"Why are there no other passengers around here",8,-10}} };
		lines1[8] = { "I am but a shepherd, on a righteous quest. My flock has strayed,\n and I follow their trail.",{{"...",9}} };
		lines1[9] = { "My poor flock",{{"sheep",10} } };
		lines1[10] = { "…",{{"This is an awfully long ride",-1,-10},{"I didn’t know shepherds existed in this day and age",11}} };
		lines1[11] = { "Did I not warn thee before? A loose tongue invites a sharper lesson. \nKeep thine eyes peeled and thy mouth shut, or worse may befall thee!",{{"trembles",-1}} };

		scenes[0] = new scene{ window,lines1 ,12,"project_images/scene1part1.png",{"project_images/scene 1.png","project_images/scene 1 part 2.png"},-1,100,5,1,2,30,minigame[0],sound,"project_sounds/jumpscare.mp3" };
		enemysaying* lines3;
		lines3 = new enemysaying[16];
		lines3[0] = { "",{{"where did the old man go?",14},{"This train ride is starting to mess with my head.", 15,-10   },{"Maybe I should get some fresh air . . . Please excuse me",1,-10}} };
		lines3[1] = { " Th€0nl¥£x!tl€@d d€€p€r in th€ d@rkn€$$.",{{"I am sorry",9},{"What do you mean?",2,-10},{"I think I have reached my stop-",2,-10}} };
		lines3[2] = { "D0n'T y0u UND3R5+@nd Th3r3 ar3 N0 exi7$",{{"...",3},{"WHAT",3}} };
		lines3[3] = { "J~s+ l|k3 l!f3, +he~e i$ n0 ba<k d00~s\nY0u Mu5+ C0nt!nu3 F0rw@rd",{{"my head hurts",4},{"I understand",4},{"i dont understand",4,-100}} };
		lines3[4] = { "...",{{"Am i dead? Is this the train to the after life?",5},{"Have i been kidnapped? Or experiencing some sort of hallucination?",6},{"Are you and the shepherd connected? Who are you?",7}} };
		lines3[5] = { "A5 0f now, y0u ar3 aliv3. A5 for wh3n the j0urn3y 3nds... it all d3pends on y0u.",{{"...",8}} };
		lines3[6] = { "Y0u d!d th!s t0 y0urself. @nd I can assur3 y0u, I am v3ry much r3al.",{{"...",8}} };
		lines3[7] = { "Y@u 7e!! m3",{{".",8}} };
		lines3[8] = { "Where's your stop?",{{"I am not sure anymore…",10},{"Where the sheep are",10},{"...",9}} };
		lines3[9] = { "What's the matter? Know too much?",{{"No.. i just can't seem to remember",10},{"I… don't think i am getting of",10,-10} } };
		lines3[10] = { "Time can be a fickle thing on this journey. Don't you worry, your destination awaits.",{{"Where are you headed?",11,-10},{"… is there anyone else on the train?",11,-10},{"dont want hte journey to end",12}} };
		lines3[11] = { "...",{{"i think i blanked out",12}} };
		lines3[12] = { "Are you afraid, traveler? Perhaps a little… unsettled by your sudden solitude?",{{"I prefer some company.",13,20},{"The silence is deafening.",13}} };
		lines3[13] = { "Looks like our time together has come to an end, traveler. \nHeed my warning as you continue, there are many paths you can take: \nsome more dangerous than others. The cat's curiosity \n lingered long after its ninth life expired.",{{"!!!",-1}} };
		lines3[14] = { "Wh€r€ @ $h€ph€rd u$u@lly i$, w!th hi$ fl0ck",{{"his flock his dead flock",1}} };
		lines3[15] = { "Th!nk you c@n ju$t tr0llou+ofh3r€ al!v3?",{{"..",1} } };
		scenes[2] = new scene{ window,lines3,14,"project_images/Scene 3 Evil Flower.png",{"project_images/Scene 3 Evil Flower.png","project_images/black.jpg"},0,100,5,3,4,20,minigame[1],sound,"project_sounds/jumpscare.mp3"};
		enemysaying* lines5;
		lines5 = new enemysaying[15];
		lines5[0] = { "Will you play with me?",{{"Um… sure",3} ,{"Who are you?",1}} };
		lines5[1] = { "Wh|| y0u n0t pl@y... w|th m3?",{{"No no, I will play. Let's play",3},{"I am sorry, i can't play right now.",2},{"...",2}} };
		lines5[2] = { "S0 ru$hy... I h@t3 p30pl3 wh0 ru$h",{{"Sorry, sorry… i will play with you",3},{"What the h What are you!!",-1}} };
		lines5[3] = { "You are a nice @dult hmun…",{{"I used to have a sister. I loved playing with her",8},{"A human?",4},{"Are you a soul?",6} } };
		lines5[4] = { "Qu3$ti0n$... qu3$ti0n$... Alw@y$ w!th th3 qu$sti0n$...",{{"...",6} }};
		lines5[5] = { "A soul do i look like a soul to you!",{{"mmmmm",6}} };
		lines5[6] = { "You ask many questions. Does it not get tiring?",{{"I am stuck in a place where I don't belong…",8},{"I need to keep asking questions so i can get out of here",8},{"Would you not also ask questions if in my position?",7}} };
		lines5[7] = { "Why would I ever be in your position?",{{"what do you mean?",8}} };
		lines5[8] = { "You played with me. Not many people do that",{{"That's… sad. Why not?",9},{"I thought people don't usually come here",9}} };
		lines5[9] = { "People don't come here, not alive anyways. You are an exception.",{{"what why mee",10}} };
		lines5[10] = { "Have you not noticed? The more you ask questions, the worse it gets for you?",{{".....",11}} };
		lines5[11] = { "Do humans not usually consider that asking too many questions \n might not be the correct answer.",{{"...",12}} };
		lines5[12] = { "It's like Persephone eating those pomegranate seeds. Once you know the \n truth you can't go back.",{{"I have to know",13},{"...",13} } };
		lines5[13] = { "There will be no going back after this, it will just get worse… are you sure of this?",{{"yes",-1,-100},{"no",-1,100}} };
		scenes[4] = new scene{ window,lines5,14,"project_images/evil baby.png",{"project_images/evil baby.png","project_images/evil baby with blood.png","project_images/evil baby with blood full train.png"},2,400,2,-10,6,100,nullptr,sound,"project_sounds/jumpscare.mp3" };




		enemysaying* lines7 = new enemysaying[23];
		lines7[0] = { "", {{"Who are you?", 1}, {"Am I dead?", 1},{"Where am i?",1}}};
		lines7[1] = { "Were you not warned what would happen if you kept on going, if you came here", {{"I was told that I would never return", 6}, {"I was not…", 2}} };
		lines7[2] = { "Then it is a tragedy.", {{"Am i dead?", 3}} };
		lines7[3] = { "not yet but very close",{{"...",5},{"when would i die",4}} };
	    lines7[4] = { "All in due time",{{"...",5}} };
		lines7[5] = { "Was your life so unfortunate that you were so willing to throw \n it away for answers?", {{"I would not have been able to live if I suddenly spawned back home.", 8}, {"I somehow doubt i would have been sent home in one piece", 6}} };
		lines7[6] = { "Your distrust roots deep.", {{"One does not so easily trust kidnappers", 7}, {"I was not given a reason to trust", 7}} };
		lines7[7] = { "You may have been spooked, but no one here has harmed you.\n Surely that thought must have crossed your mind for\n you to talk so freely to me.",{{"...",8}} };
		lines7[8] = { "So, you have questions, questions more important than your life.", {{"If I ask them, will I die?", 9}, {"Where am I?", 10}, {"Did all the people I meet evil? Or dead?", 11}, {". . . (continue)", 12}} };
		lines7[9] = { "Yes, but you will not immediately drop dead, but you have already\nreached the point of no return. Gazing at me was the\n pomegranate seed, in this case.", {{". . .", 8}} };
		lines7[10] = { "On a journey. A journey that is about to end I suppose. You will \n see your destination soon enough.", {{". . .", 8}} };
		lines7[11] = { "Evil? Based on appearance? All they have done is answer your \n questions, and warn you as much as they could in their power. I rule over them,\n the 'ugly ones' as they are called by your kind.", {{". . .", 8}} };
		lines7[12] = { "As for where you are… think of it as… new world.", {{"How did I end up here?", 13}, {"Do other people come here as well?", 14}, {"Why a train? Why a run down train?", 15}, {". . . (continue)",16}} };
		lines7[13] = { "This is a second dimension of sorts… you might have been traveling \n normally, on your way home from work, and then clipped through. Of Course there \n are ways of going back, but the worlds doesn't allow it if you spend too much time here, learn too \n much about this world.", {{". . .", 12}} };
		lines7[14] = { "From time to time. They aren't usually as friendly, and most \n choose to not ask questions. That's how they end up on the bright side of this world.", {{". . .", 12}} };
		lines7[15] = { "It is difficult to understand something that is different \n for your kind. Some worlds aren't like yours.", {{". . .", 12}} };
		lines7[16] = { "There are two levels of this world, our side, the dark side.\n And then there is the bright side. Many of the upright ones consider us to be \n evil and them to be kind. Alas, we are not so simple.", {{"I haven't met any of the 'bright ones'.", 17}, {"I met some of the bright ones.", 18}} };
		lines7[17] = { "You asked too many questions. You were disturbing the natural order of the world.", {{". . .",19} } };
		lines7[18] = { "Your journey has come to an end. Since you mingled with our \n world too much, your destination is not so pleasant.", {{". . .",19} }};
		lines7[19] = { "Goodbye, upright one. I hope the answers were worth it", {{"They were, thank you.", 20}, {"They were not.", 21}} };
		lines7[20] = { "Glad to hear",{ {". . .",-1} }};
		lines7[21] = { "I am sorry to hear that… but here is nothing that can be done.", {{". . .",-1} }};


		scenes[6] = new scene{ window,lines7,22,"Project_images/Scene 7 With box.png",{},0,0,0,-30,-30,0,nullptr,sound,""};
		enemysaying* lines2;
		lines2 = new enemysaying[11];
		lines2[0] = { "You seem troubled, traveler. Is everything okay?",{{"Who are you?",1},{"This train is creepy. How long does it take to reach the next station?",1},{"Yeah . . .",2}} };
		lines2[1] = { "....",{{". . .",2}} };
		lines2[2] = { "This journey can be… tedious at times. But fear not, \n traveler! Let us celebrate the beauty of the present moment.",{{"Celebrate? How?",3},{"I'm not much of a party animal.",5,-10}} };
		lines2[3] = { "It's a dance party! The music is blasting. Join us!",{{"A dance party?",4},{"I hear no music.",4}} };
		lines2[4] = { "Music? Dance? Now why would we do that?\n We are a chill board game party.",{{"You just said it was a dance party.",5,-10},{". . . i must be mistaken",5}} };
		lines2[5] = { "Let the party begin my dude!",{{". . .",6}} };
		lines2[6] = { "Isn't this fun?",{{"What did you do to me?",7},{"What. . . what is this?",7}} };
		lines2[7] = { "Just a little something to enhance the experience, \n dear traveler. Now, come, let us dance!",{{"I can't. . .",8},{"Dancing?",8}} };
		lines2[8] = { "Come now, don't be a sore loser. Have fun, relax",{{"Okay",-1,20},{"No, I don't understand… What did you do to me?",9,-20}} };
		lines2[9] = { "Questions and questions darling, why \n worry that little head of yours?",{{"I am trapped here. I need to get out!",10}} };
		lines2[10] = { "Yeah, but is this not more fun? What \n will answers get you that this life can't?",{{". . .",-1}} };

		scenes[1] = new scene{ window,lines2,11,"Project_images/Good Evil Flower Normal.png",{"Project_images/Flower Hallucination 1.png","Project_images/Flower Hallucination 2.png","Project_images/Flower Hallucination 3.png"},6,100,15,3,4,40,minigame[1],sound,"project_sounds/dance.mp3"};
		enemysaying* lines4;
		lines4 = new enemysaying[23];
		lines4[0] = { "Hey there, new guy! Heard you were thrown a right bash!\n They really know how to party, don't they?",{{"Who are you?",1},{"What was that stuff? ",3},{"This train is messed up. I need to get off.",13}} };
		lines4[1] = { "Just a party goer in this eternal life",{{"You are immortal?",2},{"You party everyday?",2}} };
		lines4[2] = { "You and I are not so different",{{"How so?",3}} };
		lines4[3] = { "Oh, that, my friend? Just a little something to help you unwind! \n Takes the edge right off, you know? Makes you see \n the world in a whole new light!",{{"See the world… differently?",4},{"I don't feel good. I want to stop.",5},{"Sounds… dangerous. ",10}} };
		lines4[4] = { "Just a little magic in this party world",{{"I am not interested",5},{"I don't want your magic.",5}}};
		lines4[5] = { "Does the party not excite you? A world with no consequences!",{{"My head hurts, that doesn't feel like a lack on consequence",6}} };
		lines4[6] = { "Pain? Well that is because you are still HUMAN!",{{"… what do you mean?",7}} };
		lines4[7] = { "What?",{{"What do you mean I am still human",8}}};
		lines4[8] = { "What is a human?",{{"A human, you mentioned it…",9}} };
		lines4[9] = { "hahaHA what a silly thought. I dont even know what a humnam is!",{{"human",22},{"are you not human",22}}};

		lines4[10] = { "How do you like it here",{{"I want to get off…",11}} };
		lines4[11] = { "Get off? But why? This is the good life, my friend! \n No worries, no troubles, just endless fun! Don't you want to be happy?",{{"This isn't happiness.",12},{"Maybe… but I need answers.",12},{"I miss the real world.",12}} };
		lines4[12] = { "Oh Don't worry, I was once like you too! So full \n of questions and skepticism! But look at me now! Beyond happy!",{{"What do you mean like me?",13}} };
		lines4[13] = { "Oh yeah, the real world… such a harsh place. \n Full of pain, loss, and responsibility. Why cling \n to such negativity? Here, you can forget all that. Be happy!",{{"Earth? Are you talking about earth?",17},{"Be… happy… the real world is a pain",14}} };
		lines4[14] = { "Yes! Forget all your worries, like I forgot mine!",{{". . .",15}} };
		lines4[15] = { "You will forget and be like me! Forever! Is that not exciting!",{{"Don't shout man, I almost lost my cool. \n Why don't you ask… him?",16}} };
		lines4[16] = { "Don't shout man, I almost lost my cool. \n Why don't you ask… him?",{{". . .",-1,100}} };
		lines4[17] = { "Earth… my home…",{{"You are from earth?",18}} };
		lines4[18] = { "I… fell. I fell here! And now… I stay here forever! I party everyday!",{{"So you just left loved ones behind? \n Didn't even try to escape?",19}} };
		lines4[19] = { "Escape? Why would I do that?",{{"Pathetic. . .",20}} };
		lines4[20] = { "Sad… I really wanted you to stay. But you can't \n stay anymore. Not in this wonderland anyways.",{{"what do u mean",21,100}} };
		lines4[21] = { "Goodbye",{{"no i want to stay",-1},{"Good ridance",-1}}};
		lines4[22] = { "....",{{"....",10,-10}} };
		scenes[3] = new scene{ window,lines4,23,"Project_images/Evil Puppet.png",{"Project_images/Evil Puppet.png","Project_images/Evil Puppet Sad Animation.png"},5,400,3,5,4,100 ,minigame[2],sound,"project_sounds/jumpscare.mp3" };
		enemysaying* lines6;
		lines6 = new enemysaying[13];

		lines6[0] = { "Welcome, traveler. You've reached your destination – the Everlasting Garden.",{{"Who are you?",1},{"This place is beautiful… is this where I am supposed to be?",5},{"What happened to the train?",8},{". . . (conitnue)",10}}};
		lines6[1] = { "Does my looks not make it clear?",{{"Am I in heaven?",2}} };
		lines6[2] = { "Heaven? Is that what you call it?",{{"You said everlasting garden",3}} };
		lines6[3] = { "Oh my child, everlasting doesn't mean good, when has everlasting \n ever meant something good? And even a barren \n wasteland can be called a garden if you throw around a couple flowers.",{{"But this place looks so beautiful",4}}};
		lines6[4] = { "Beauty does not mean happiness, or good, for that matter.",{{"...",0}}};
		lines6[5] = { "Beautiful, yes. But is it what you truly desired?  You never sought answers, didn't\n try to escape. Did you truly think an eternal paradise\n was the solution?",{{"It all seemed so fun. . . Like a train ride to heaven.I thought \n I died and was in the afterlife.",6}} };
		lines6[6] = { "Not even close, you are very much alive.And, unfortunately will always be alive.\n This is just… another dimension you managed to slip into",{{"Another dimension?",7}} };
		lines6[7] = { "Indeed",{{"...",0} } };
		lines6[8] = { "The train is a world of sorts. Miniature worlds. You traveled \n through some, maybe enjoyed even. But because you were an anomaly, \n you ended up here.",{{"I wasn't supposed to be here…",10}} };
		lines6[9] = { "You had ways to escape. But you chose to ignore asking questions.",{{"...",0}} };
		lines6[10] = { "Look around you, this. . . garden is but a prison. Those blissful puppets \n were once travelers, who slipped through their own world and ended up here.\n And now, their memories fade, and they live here forever, riding until \n they are nothing but empty shells of themselves. A fate, I consider, worse than death.",{{"Is there any way I can get out?",11}} };
		lines6[11] = { "At this stage? You are doomed. The darkness has the answers you are \n looking for, answers you wouldn't have found here.",{{"So. . . that's it?",12}} };
		lines6[12] = { "Unfortunately for you, this is the end as you remember it. \n Alas, you might enjoy the first couple of decades here.",{{"Not when I know the ending. . .",-1}} };

		scenes[5] = new scene{ window,lines6,12,"Project_images/Scene 6.png",{{}},0,0,0,-20,-20,0,nullptr,sound,""};
	}

	
};

