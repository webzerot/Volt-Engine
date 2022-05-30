#pragma once
#include <SFML/Graphics.hpp>

class Button {

private:

	// properties
	float buttonPositionX = 0, buttonPositionY = 0;
	float ButtonSizeX = 0, ButtonSizeY = 0;

	sf::Color BtnColor = sf::Color(0,70,40);
	sf::Color BtnTextColor = sf::Color(255,255,255);

	// button
	sf::Texture btnTexture;
	sf::RectangleShape btnShape;

	// text
	std::string ButtonTextString = "";
	sf::Font ButtonTextFont;
	sf::Text ButtonText;
	std::string DefaultButtonTextFont = "Anton.ttf";

	int mousePosX = 0, mousePosY = 0;
	sf::Vector2f mousePos;

	// called when the mouse cursor is above the button in Update
	void OnHover();

	void OnIdle();

	bool isTextured = false;

public:
	int ButtonTextFontSize = 30;

	bool Automatic_Drawing = true;

	float ButtonOutlineThickness = 2;
	sf::Color ButtonOutlineColor;

	//constructor
	Button(float Width, float Height, std::string BtnText = "", std::string File_Path = "");
	// called when the button is clicked in EventUpdate
	bool Clicked();

	// this is called in update
	void DrawAt(sf::RenderWindow& window);

	void SetFont(std::string font_path);

	void SetPosition(float xPos, float yPos) {
		buttonPositionX = xPos;
		buttonPositionY = yPos;
	}

	void SetButtonColor(int Red, int Green, int Blue, int Alpha = 255) {
		BtnColor.r = Red;
		BtnColor.g = Green;
		BtnColor.b = Blue;
		BtnColor.a = Alpha;
	}
	void SetTextColor(int Red, int Green, int Blue, int Alpha = 255) {
		BtnTextColor.r = Red;
		BtnTextColor.g = Green;
		BtnTextColor.b = Blue;
		BtnTextColor.a = Alpha;
	}
	// changes the text of the button during runtime
	void ChangeButtonText(std::string& text) {
		ButtonText.setString(text);
	}
};