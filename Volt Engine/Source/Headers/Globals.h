#pragma once
#include "GameObject.h"
#include "Text.h"
#include "Button.h"

extern std::list<GameObject*> ACTIVE_GAME_OBJECTS;

extern std::list<Text*> ACTIVE_TEXT_OBJECTS;

extern std::list<Button*> ACTIVE_BUTTON_OBJECTS;

extern sf::RenderWindow* Main_Engine_Window;

extern sf::Event* Main_Engine_Window_Event;

extern float Delta_Time;