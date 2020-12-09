#include "draw.h"
#include <Windows.h>

Draw::Draw(int dx, int dy) 
	: Image(dx, dy) 
{
}

// similar to the event
void Draw::move() {
	while (true) {
		if (GetAsyncKeyState(0x1B)) {	// close window
			break;
		};			
		if (GetAsyncKeyState(0x51)) {	// set XY
			keyQ_draw();
		}	
		if (GetAsyncKeyState(0x57)) {	// set X
			keyW_draw();
		}	
		if (GetAsyncKeyState(0x45)) {	// change color
			keyE_draw();
		}	
		if (GetAsyncKeyState(0x52)) {	// change color
			keyR_draw();
		}	
		if (GetAsyncKeyState(0x27)) {	// ->
			keyRight_move();
		}	
		if (GetAsyncKeyState(0x25)) {	// <-
			keyLeft_move();
		}	
		if (GetAsyncKeyState(0x26)) {	// up
			keyUp_move();
		}		
		if (GetAsyncKeyState(0x28)) {	// down
			keyDown_move();
		}	
	}
}

// draw Q
void Draw::keyQ_draw() {
	std::system("cls");		// clear window
	set(dx, dy, mcolor);
	show();
}

// draw W
void Draw::keyW_draw() {
	std::system("cls");
	setX(dy, mcolor);
	show();
}

// draw E
void Draw::keyE_draw() {
	std::system("cls");
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
