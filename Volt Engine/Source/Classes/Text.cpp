#include <SFML/Graphics.hpp>
#include <iostream>

#include "../Headers/Text.h"
#include "../Headers/Globals.h"

Text::Text(std::string str, int font_size, std::string font_path) {
	
	ACTIVE_TEXT_OBJECTS.push_back(this);

	textOfTextClass = str;
	FontSize = font_size;

	if (!font_path.empty()) {
		font.loadFromFile(font_path);
	}
	else {
		font.loadFromFile(defaultFontPath);
	}

	text.setFont(font);
}

float Text::GetWidth() {
	return text.getGlobalBounds().width;
}
float Text::GetHeight() {
	return text.getGlobalBounds().height;
}

void Text::SetFont(std::string font_path) {


	// loading font
	if (!font_path.empty()) {
		font.loadFromFile(font_path);

		text.setFont(font);
	}
	else {
		std::cout << "Text::SetFont() was UnSuccessfull due to empty font! Using default one instead (\"" << defaultFontPath << "\")." << std::endl;
	}

}

void Text::SetPosition(float x, float y) {
	PosX = x;
	PosY = y;
}

void Text::ChangeText(std::string str) {
	textOfTextClass = str;
}
void Text::SetColor(int red, int green, int blue) {
	TextColor[0] = red;
	TextColor[1] = green;
	TextColor[2] = blue;
}

void Text::DrawAt(sf::RenderWindow& window) {

	// setting color of text
	text.setFillColor(sf::Color(TextColor[0], TextColor[1], TextColor[2]));

	// setting string of text
	text.setString(textOfTextClass);

	// changing font size
	text.setCharacterSize(FontSize);

	//setting the position of the text
	text.setPosition(sf::Vector2f(PosX, PosY));

	window.draw(text);
}