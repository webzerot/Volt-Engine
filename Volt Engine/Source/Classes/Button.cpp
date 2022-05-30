#include <iostream>
#include <SFML/Graphics.hpp>

#include "../Headers/Button.h"
#include "../Headers/Globals.h"


Button::Button(float Width, float Height, std::string BtnText, std::string File_Path) {

	ACTIVE_BUTTON_OBJECTS.push_back(this);

	ButtonSizeX = Width;
	ButtonSizeY = Height;

	// if Use Text
	if (BtnText.empty() == 0) {
		ButtonTextString = BtnText;

		ButtonTextFont.loadFromFile(DefaultButtonTextFont);
		ButtonText.setFont(ButtonTextFont);

		ButtonText.setString(ButtonTextString);
	}

	if (File_Path.empty() == 0) {
		isTextured = true;
		btnTexture.loadFromFile(File_Path);
		const sf::Texture* constBtnTexture = &btnTexture;
		btnShape.setTexture(constBtnTexture);
	}
	else
		isTextured = false;

	btnShape.setSize(sf::Vector2f(Width, Height));
}

void Button::SetFont(std::string font_path) {
	// loading font
	if (!font_path.empty()) {
		ButtonTextFont.loadFromFile(font_path);

		ButtonText.setFont(ButtonTextFont);
	}
	else {
		std::cout << "Button::SetFont() was UnSuccessfull due to empty font! Using default one instead (\"" << DefaultButtonTextFont << "\")." << std::endl;
	}
}

void Button::DrawAt(sf::RenderWindow& window) {
	btnShape.setOutlineColor(ButtonOutlineColor);
	btnShape.setOutlineThickness(ButtonOutlineThickness);

	// getting mouse position
	mousePosX = sf::Mouse::getPosition(window).x;
	mousePosY = sf::Mouse::getPosition(window).y;
	mousePos = sf::Vector2f((float)mousePosX, (float)mousePosY);

	if (btnShape.getGlobalBounds().contains(mousePos))
		OnHover();
	else
		OnIdle();

	window.draw(this->btnShape);
	window.draw(this->ButtonText);
	btnShape.setPosition(sf::Vector2f(buttonPositionX, buttonPositionY));
	ButtonText.setCharacterSize(ButtonTextFontSize);
	ButtonText.setPosition(sf::Vector2f((ButtonSizeX / 2) - (ButtonText.getGlobalBounds().width / 2) + buttonPositionX,
		(ButtonSizeY / 2) - (ButtonText.getGlobalBounds().height / 2) + buttonPositionY));
}


bool Button::Clicked() {

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (btnShape.getGlobalBounds().contains(mousePos)) {

			return true;
		}
	}
	return false;

}

void Button::OnHover() {
	if (!isTextured) {
		btnShape.setFillColor(sf::Color(BtnColor[0], BtnColor[1], BtnColor[2], 200));
	}
	else {
		btnShape.setFillColor(sf::Color(255, 255, 255, 200));
	}

	ButtonText.setFillColor(sf::Color(BtnTextColor[0], BtnTextColor[1], BtnTextColor[2], 200));
}
void Button::OnIdle() {
	if (!isTextured) {
		btnShape.setFillColor(sf::Color(BtnColor[0], BtnColor[1], BtnColor[2], 255));
	}
	else {
		btnShape.setFillColor(sf::Color(255, 255, 255, 255));
	}

	ButtonText.setFillColor(sf::Color(BtnTextColor[0], BtnTextColor[1], BtnTextColor[2], 255));
}

