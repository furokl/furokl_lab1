#include "draw.h"

Draw::Draw(int dx, int dy) 
	: Image(dx, dy) 
{
}

// similar to the event
void Draw::move() {
	while (true) {
		if (GetAsyncKeyState(0x1B)) { break; };				// close window
		if (GetAsyncKeyState(0x51)) { keyQ_draw(); }		// set XY
		if (GetAsyncKeyState(0x57)) { keyW_draw(); }		// set X
		if (GetAsyncKeyState(0x45)) { keyE_draw(); }		// set Y
		if (GetAsyncKeyState(0x52)) { keyR_draw(); }		// change color
		if (GetAsyncKeyState(0x27)) { keyRight_move(); }	// ->
		if (GetAsyncKeyState(0x25)) { keyLeft_move(); }		// <-
		if (GetAsyncKeyState(0x26)) { keyUp_move(); }		// up
		if (GetAsyncKeyState(0x28)) { keyDown_move(); }		// down
	}
}

// draw Q
void Draw::keyQ_draw() {
	system("cls");
	set(dx, dy, mcolor);
	show();
}

// draw W
void Draw::keyW_draw() {
	system("cls");
	setX(dy, mcolor);
	show();
}

// draw E
void Draw::keyE_draw() {
	system("cls");
	setY(dx, mcolor);
	show();
}

// change color R
void Draw::keyR_draw() {
	(mcolor == 1) ? mcolor = 0 : mcolor = 1;
	Sleep(250);
}

// move ->
void Draw::keyRight_move() {
	dx++;
	if (dx > 0 && dx <= Image::getMx()) { Sleep(100); }
	else dx--;
}

// move <-
void Draw::keyLeft_move() {
	dx--;
	if (dx > 0 && dx <= Image::getMx()) { Sleep(100); }
	else dx++;
}

// move Up
void Draw::keyUp_move() {
	dy--;
	if (dy > 0 && dy < Image::getMy()) { Sleep(100); }
	else dy++;
}

// move Down
void Draw::keyDown_move() {
	if (dy > 0 && dy < Image::getMy()) { 
		dy++;
		Sleep(100);
	}
}
