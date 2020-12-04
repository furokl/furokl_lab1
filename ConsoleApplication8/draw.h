#ifndef DRAW_H
#define DRAW_H

#include "Image.h"

class Draw : public Image
{
private:
	int dx;
	int dy;
	int mcolor = 1;
public:
	Draw(int x, int y)
		: dx(x), dy(y) 
	{
	}
	void move() {
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

	void keyQ_draw();
	void keyW_draw();
	void keyE_draw();
	void keyR_draw();
	void keyRight_move();
	void keyLeft_move();
	void keyUp_move();
	void keyDown_move();

};

#endif
