#include <SFML/Graphics.hpp>
#include <iostream>

#include "../Headers/GameObject.h"


// constructor
GameObject::GameObject(float Width, float Height, std::string Texture_File_Path) {

	// setting size
	GameObject_Size_X = Width;
	GameObject_Size_Y = Height;

	// checking if the user inserted a file path to a texture
	if (Texture_File_Path.empty()) {
		useTexture = false;
	}

	// loading the texture
		if (useTexture)
			GameObject_Texture.loadFromFile(Texture_File_Path);
	
	// loading texture to Sprite

		if (useTexture) {
			GameObject_RectangleShape.setTexture(&GameObject_Texture);
		}

	if (!useTexture) {
		//GameObject_RectangleShape.setFillColor(GameObject_Color);
	}

}

void GameObject::Set_Position(float x, float y) {
	GameObject_Position_X = x;
	GameObject_Position_Y = y;
}

void GameObject::DrawAt(sf::RenderWindow& window) {
	// Setting Size
	GameObject_RectangleShape.setSize(sf::Vector2f(GameObject_Size_X, GameObject_Size_Y));

	// setting position
	GameObject_RectangleShape.setPosition(sf::Vector2f(GameObject_Position_X, GameObject_Position_Y));

	// drawing the object
	window.draw(GameObject_RectangleShape);
}