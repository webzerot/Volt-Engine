#include <SFML/Graphics.hpp>
#include <iostream>

#include "../Headers/GameObject.h"

bool useTexture = true;
bool useCircleShape = false;

float GameObject_Position_X = 0;
float GameObject_Position_Y = 0;


// constructor
GameObject::GameObject(float Width, float Height, std::string Texture_File_Path, bool CircleShape, float GameObject_CircleShape_Radius) {

	// checking if the user inserted a file path to a texture
	if (Texture_File_Path.empty()) {
		useTexture = false;
	}

	// loading the texture
		if (useTexture)
			GameObject_Texture.loadFromFile(Texture_File_Path);
	
	// loading texture to Sprite
	//const sf::Texture* Const_GameObject_Texture = &GameObject_Texture;

	if (CircleShape == true) {
		useCircleShape = true;
		if (useTexture) {
			GameObject_CircleShape.setTexture(&GameObject_Texture);
		}
		GameObject_CircleShape.setRadius(GameObject_CircleShape_Radius);
	}
	else if (CircleShape == false){
		useCircleShape = false;
		if (useTexture) {
			GameObject_RectangleShape.setTexture(&GameObject_Texture);
		}
		GameObject_RectangleShape.setSize(sf::Vector2f(Width, Height));
	}

	if (!useTexture) {
		//GameObject_CircleShape.setFillColor(GameObject_Color);
		//GameObject_RectangleShape.setFillColor(GameObject_Color);
	}

}

void GameObject::Set_Position(float x, float y) {
	GameObject_Position_X = x;
	GameObject_Position_Y = y;
}

void GameObject::DrawAt(sf::RenderWindow& window) {

	if (useCircleShape) {
		// setting position
		GameObject_CircleShape.setPosition(sf::Vector2f(GameObject_Position_X, GameObject_Position_Y));

		// drawing the object
		window.draw(GameObject_CircleShape);
	}
	else if (!useCircleShape) {
		// setting position
		GameObject_RectangleShape.setPosition(sf::Vector2f(GameObject_Position_X, GameObject_Position_Y));

		// drawing the object
		window.draw(GameObject_RectangleShape);
	}
}