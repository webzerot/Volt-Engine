#pragma once

#include "../Source/Headers/VoltEngine.h"

void Start(StartArg) {

}

void EventUpdate(EventArg) {

	if (Input.GetKeyDown(evt, Key::Space)) {
		print("SpaceBar is Pressed");
	}

}

void Update(UpdateArg) {
	Set_Background_Color(window,20, 51, 100);
}