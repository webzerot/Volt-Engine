#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Windows.h>

#include "Headers/VoltEngine.h"

#include "../Games/SampleGame.h"

int WINDOW_WIDTH = 700;
int WINDOW_HEIGHT = 500;
const char* WINDOW_TITLE = "Volt Engine Window";


sf::Clock deltaClock; // clock used for the calculation of delta time
int main(int argc, char* argv[]) {

	// Show Console On Start
	ShowWindow(GetConsoleWindow(), SW_SHOW);

	// Creating the main engine Window
	sf::RenderWindow Main_Engine_Window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE, sf::Style::Close | sf::Style::Titlebar);

	// code on start after the window creation
	Start(Main_Engine_Window);

	while (Main_Engine_Window.isOpen()) {
		sf::Time Time_elapsed_from_last_frame = deltaClock.restart(); // getting the time of each frame
		float delta_time = Time_elapsed_from_last_frame.asSeconds();

		// check all the main engine window's events that were triggered since the last iteration of the loop
		sf::Event Main_Engine_Window_Event;
		while (Main_Engine_Window.pollEvent(Main_Engine_Window_Event)) {
			// close window event
			if (Main_Engine_Window_Event.type == sf::Event::Closed) {
				Main_Engine_Window.close();
			}

			EventUpdate(Main_Engine_Window_Event, delta_time);


			// keyboard keydown events
			if (Main_Engine_Window_Event.type == sf::Event::KeyPressed) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
					// do something when space is pressed
				}
			}
		}

		// -----------Main Code--------------
		Update(Main_Engine_Window, delta_time);


		/// ---------------- Drawing -------------////
		// drawing GameObjects
		for (GameObject* GameObj : ACTIVE_GAME_OBJECTS) {
			if (GameObj->Automatic_Drawing)
				GameObj->DrawAt(Main_Engine_Window);
		}
		// drawing Text Objects
		for (Text* TextObj : ACTIVE_TEXT_OBJECTS) {
			if (TextObj->Automatic_Drawing)
				TextObj->DrawAt(Main_Engine_Window);
		}
		// drawing Button Objects
		for (Button* ButtonObj : ACTIVE_BUTTON_OBJECTS) {
			if (ButtonObj->Automatic_Drawing)
				ButtonObj->DrawAt(Main_Engine_Window);
		}
		/// ---------------- Drawing -------------////

		// updating display
		Main_Engine_Window.display();
	}


	return EXIT_SUCCESS;
}