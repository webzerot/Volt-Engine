#include <iostream>
#include <SFML/Graphics.hpp>

#include "../Headers/Globals.h"
#include "../Headers/Input.h"



bool Input::GetKeyDown( int KeyCode) {

	sf::Event evt = *Main_Engine_Window_Event;

	if (evt.type == sf::Event::KeyPressed) {
		if (evt.key.code == KeyCode) {
			return true;
		}
	}
	return false;
}
bool Input::GetKeyUp(int KeyCode) {

	sf::Event evt = *Main_Engine_Window_Event;

	if (evt.type == sf::Event::KeyReleased) {
		if (evt.key.code == KeyCode) {
			return true;
		}
	}
	return false;
}
bool Input::GetKey(int KeyCode) {

	sf::Event evt = *Main_Engine_Window_Event;

	if (evt.key.code == KeyCode) {
		return true;
	}
	return false;
}

float Input::GetAxis(const std::string& axis) {

	sf::Event evt = *Main_Engine_Window_Event;

	if (axis == "Horizontal") {
		if (evt.type == sf::Event::KeyPressed) {

			// moveleft
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
				sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {

				return -1;
			}
			// move right
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
				sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				
				return 1;
			}
		}
		
	}

	else if (axis == "Vertical") {
		if (evt.type == sf::Event::KeyPressed) {

			// move up
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
				sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {

				return -1;
			}
			// move down
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
				sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {

				return 1;
			}
		}
	}

	else {

		std::cout << "Something is wrong with the Input" << std::endl;

	}


	return 0;
}

