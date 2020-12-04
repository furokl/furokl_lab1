#include "draw.h"

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
	Sleep(100);
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
	if (dy > 0 && dy < Image::getMy()) {
		dy--;
		Sleep(100);
	}
}

// move Down
void Draw::keyDown_move() {
	if (dy > 0 && dy < Image::getMy()) {
		dy++;
		Sleep(100);
	}
}
