#include <SFML/Graphics.hpp>
#include <iostream>

#include "../Headers/GameObject.h"


// constructor
GameObject::GameObject(float Width, float Height, std::string Texture_File_Path) {

	// setting scale
	transform.Scale = Vector(Width, Height);

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
}

void GameObject::Set_Position(float x, float y) {

	transform.Position = Vector(x, y);
}

void GameObject::Set_Color(int Red, int Green, int Blue, int Alpha) {
	GameObject_Color.r = Red;
	GameObject_Color.g = Green;
	GameObject_Color.b = Blue;
	GameObject_Color.a = Alpha;

	GameObject_RectangleShape.setFillColor(GameObject_Color);
}

void GameObject::DrawAt(sf::RenderWindow& window) {
	// Setting Size
	GameObject_RectangleShape.setSize(sf::Vector2f(transform.Scale.GetX(), transform.Scale.GetY()));

	// Setting rotation of GameObject
	GameObject_RectangleShape.setRotation(transform.Rotation);

	// setting position
	GameObject_RectangleShape.setPosition(sf::Vector2f(transform.Position.GetX(), transform.Position.GetY()));

	// drawing the object
	window.draw(GameObject_RectangleShape);
}