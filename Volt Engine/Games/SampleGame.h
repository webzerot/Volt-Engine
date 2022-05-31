#pragma once

#include "../Source/Headers/VoltEngine.h"

Button myBtn(100, 50, "Click");
Text myTxt("Click this button", 30);

GameObject putin(150, 100, "images.jpg");
GameObject ob(100, 100);

Vector myVec(100, 200);

void Start() {

	myBtn.SetPosition(300, 225);
	myTxt.SetPosition(250, 150);
	ob.Set_Color(100, 135, 65);
}

void EventUpdate(EventArg) {

	if (input.GetKeyDown(Key::Space)) {
		print("SpaceBar is Pressed");
	}

	if (myBtn.Clicked()) {
		print("Button is Clicked");
	}

	// obj movemt
	if (input.GetKeyDown(Key::Down))
		ob.moveDown = true;
	else if (input.GetKeyDown(Key::Up))
		ob.moveUp = true;
	else if (input.GetKeyDown(Key::Right))
		ob.moveRight = true;
	else if (input.GetKeyDown(Key::Left))
		ob.moveLeft = true;
	else {
		ob.moveDown = false;
		ob.moveUp = false;
		ob.moveLeft = false;
		ob.moveRight = false;
	}
}

float speed = 100;
float posX, posY;
void Movement(float delta) {
	if (ob.moveLeft) {
		posX -= speed * delta;
	}
	else if (ob.moveRight) {
		posX += speed * delta;
	}
	else if (ob.moveUp) {
		posY -= speed * delta;
	}
	else if (ob.moveDown)
		posY += speed * delta;
}
void Update() {
	Set_Background_Color(*Main_Engine_Window,20, 51, 100);

	putin.transform.Position = myVec;

	Movement(Delta_Time);
	ob.Set_Position(posX, posY);

	Debug::Log(Delta_Time);
}