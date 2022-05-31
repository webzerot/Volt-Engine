#pragma once

class mouse {

public:

	int GetMousePosX(sf::RenderWindow& window) {
		return sf::Mouse::getPosition(window).x;
	}
	int GetMousePosY(sf::RenderWindow& window) {
		return sf::Mouse::getPosition(window).y;
	}

};


class Input {

private:

public:

	mouse Mouse;

	//key codes start from 0 (A = 0, B = 1, C = 2...) or you can use sf::Keyboard::Keyname
	bool GetKeyDown(int KeyCode);

	//key codes start from 0 (A = 0, B = 1, C = 2...) or you can use sf::Keyboard::Keyname
	bool GetKeyUp(int KeyCode);

	//key codes start from 0 (A = 0, B = 1, C = 2...) or you can use sf::Keyboard::Keyname
	bool GetKey(int KeyCode);

	float GetAxis(const std::string& axis);

};