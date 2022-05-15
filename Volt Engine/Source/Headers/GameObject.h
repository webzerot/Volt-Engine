#pragma once

class GameObject {

private:
	sf::Sprite GameObject_Sprite;
	sf::RectangleShape GameObject_RectangleShape;
	sf::Texture GameObject_Texture;

	bool useTexture = true;

	float GameObject_Position_X = 0;
	float GameObject_Position_Y = 0;

	float GameObject_Size_X = 150;
	float GameObject_Size_Y = 100;

public:
	// constructor
	GameObject(float Width, float Height,
		std::string Texture_File_Path = "");

	// sets the position of the GameObject
	void Set_Position(float x, float y);

	// getters
	sf::RectangleShape Get_RectangleShape() {
		return GameObject_RectangleShape;
	}
	// draws the object to window (use this in update)
	void DrawAt(sf::RenderWindow& window);
};