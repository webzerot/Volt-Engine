#pragma once

class GameObject {

private:
	sf::Sprite GameObject_Sprite;
	sf::RectangleShape GameObject_RectangleShape;
	sf::CircleShape GameObject_CircleShape;
	sf::Texture GameObject_Texture;

public:
	// constructor
	GameObject(float Width, float Height,
		std::string Texture_File_Path = "",
		bool CircleShape = false,
		float GameObject_CircleShape_Radius = 10);

	// sets the position of the GameObject
	void Set_Position(float x, float y);

	// draws the object to window (use this in update)
	void DrawAt(sf::RenderWindow& window);
};