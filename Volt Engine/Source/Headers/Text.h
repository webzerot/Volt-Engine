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