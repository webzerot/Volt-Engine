#pragma once

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include <iostream>
#include <Windows.h>

#include "Button.h"
#include "Text.h"
#include "SoundClass.h"
#include "Input.h"
#include "GameObject.h"
#include "VoltEngineFunctions.h"
#include "Debug.h"
#include "Vector.h"
#include "Transform.h"
#include "Globals.h"
#include "Random.h"
#include "Time.h"

// pre declared functions
void Start(sf::RenderWindow& window);
void Update(sf::RenderWindow& window);
void EventUpdate(sf::Event& event);

// engine macros
#define print(x) std::cout<<x<<std::endl;

#define OnKeyUp(sf_event) sf_event.type==sf::Event::KeyReleased
#define OnKeyDown(sf_event) sf_event.type==sf::Event::KeyPressed
#define PressedKey sf::Keyboard::isKeyPressed
#define Key sf::Keyboard

#define StartArg
#define EventArg sf::Event& evt
#define UpdateArg

class Console {
public:
	static void Hide() {
		ShowWindow(GetConsoleWindow(), SW_HIDE);
	}
	static void Show() {
		ShowWindow(GetConsoleWindow(), SW_SHOW);
	}
};
Input input;
