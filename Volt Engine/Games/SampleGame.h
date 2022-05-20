#pragma once

#include "../Source/Headers/VoltEngine.h"

Button myBtn(100, 50, "Click");
Text myTxt("Click this button", 30);

GameObject putin(150, 100, "images.jpg");

Vector myVec(100, 200);

void Start(StartArg) {

	myBtn.SetPosition(300, 225);
	myTxt.SetPosition(250, 150);
}

void EventUpdate(EventArg) {

	if (input.GetKeyDown(evt, Key::Space)) {
		print("SpaceBar is Pressed");
	}

	if (myBtn.Clicked()) {
		print("Button is Clicked");
	}
}

void Update(UpdateArg) {
	Set_Background_Color(window,20, 51, 100);

	putin.transform.Position = myVec;

	myBtn.DrawAt(window);
	myTxt.DrawAt(window);

	putin.DrawAt(window);
}