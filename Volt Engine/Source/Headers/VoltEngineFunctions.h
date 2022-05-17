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

// engine functions

void Set_Background_Color(sf::RenderWindow& window, int red, int green, int blue) {
	window.clear(sf::Color(red, green, blue));
}

void Set_Window_Title(sf::RenderWindow& window, const std::string& title) {
	window.setTitle(title);
}

void Set_Window_Size(sf::RenderWindow& window, int Width, int Height) {
	window.setSize(sf::Vector2u(Width, Height));
}

float Distance_Between(float object1X, float object1Y, float object2X, float object2Y) {

	float distance = sqrtf(powf(object1X - object2X, 2) + powf(object1Y - object2Y, 2));

	return distance;
}

bool Check_For_Collision(GameObject first_GameObject, GameObject second_GameObject) {

	sf::RectangleShape first_rect_shape = first_GameObject.Get_RectangleShape();
	sf::RectangleShape Second_rect_shape = second_GameObject.Get_RectangleShape();

	if (first_rect_shape.getGlobalBounds().intersects(Second_rect_shape.getGlobalBounds())) {
		return true;
	}

	return false;
}