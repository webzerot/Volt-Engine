#include <iostream>
#include <SFML/Graphics.hpp>

#include "../Headers/Input.h"



bool input::GetKeyDown(sf::Event& evt, int KeyCode) {

	if (evt.type == sf::Event::KeyPressed) {
		if (evt.key.code == KeyCode) {
			return true;
		}
	}
	return false;
}
bool input::GetKeyUp(sf::Event& evt, int KeyCode) {

	if (evt.type == sf::Event::KeyReleased) {
		if (evt.key.code == KeyCode) {
			return true;
		}
	}
	return false;
}
bool input::GetKey(sf::Event& evt, int KeyCode) {
	if (evt.key.code == KeyCode) {
		return true;
	}
	return false;
}

