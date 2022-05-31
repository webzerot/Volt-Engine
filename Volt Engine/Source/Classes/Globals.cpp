#include "../Headers/Globals.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>

std::list<GameObject*> ACTIVE_GAME_OBJECTS;

std::list<Text*> ACTIVE_TEXT_OBJECTS;

std::list<Button*> ACTIVE_BUTTON_OBJECTS;

sf::RenderWindow* Main_Engine_Window;

sf::Event* Main_Engine_Window_Event;

float Delta_Time;