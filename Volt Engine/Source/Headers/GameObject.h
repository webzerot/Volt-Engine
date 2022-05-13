#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Vector2 {
public:
	float x = 0;
	float y = 0;
};

class Transform {
public:
	Vector2 Position;

	void SetPosition(float xPos, float yPos) {
		Position.x = xPos;
		Position.y = yPos;
	}
private:
};

class GameObject {

public:

	Transform transform;

	sf::Texture Texture;
	sf::Sprite Sprite;

	GameObject(std::string Image_Path);
	// gameobj positions
	float xDefaultPosition = 0;
	float yDefaultPosition = 0;


	// obj state
	bool is_Alive = true;

	void DrawAt(sf::RenderWindow& window) {

		window.draw(this->Sprite);
		Sprite.setPosition(sf::Vector2f(transform.Position.x, transform.Position.y));
	}

};

GameObject::GameObject(std::string Image_Path) {
	Texture.loadFromFile(Image_Path);
	Sprite.setTexture(Texture);
}
class KinematicObject : public GameObject {

public:
	// movement
	bool moveLeft = false;
	bool moveRight = false;
	bool moveUp = false;
	bool moveDown = false;

	// game obj speed
	float Speed = 0;

	void LoadImage(std::string Image_Path) {
		Texture.loadFromFile(Image_Path);
		Sprite.setTexture(Texture);
	}
};