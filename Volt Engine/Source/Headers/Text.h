#pragma once

class Text {

private:

	sf::Text text;
	sf::Font font;

	std::string textOfTextClass;
	std::string defaultFontPath = "Anton.ttf";

	int TextColor[3] = { 255,255,255 };

	float PosX = 0, PosY = 0;


public:

	int FontSize = 10;

	Text(std::string str, int font_size = 10, std::string font_path = "");
	void SetFont(std::string font_path);
	void SetPosition(float x, float y);
	void ChangeText(std::string str);
	void SetColor(int red, int green, int blue);
	// cant be used in start()
	float GetWidth();
	// cant be used in start()
	float GetHeight();
	// this functions is callled in Update
	void DrawAt(sf::RenderWindow& window);

};


Text::Text(std::string str, int font_size, std::string font_path) {
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
