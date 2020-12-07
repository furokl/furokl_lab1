#ifndef DRAW_H
#define DRAW_H

#include "Image.h"
#include <Windows.h>

using std::system;	// clear window

class Draw : public Image
{
private:
	int dx = 1;
	int dy = 1;
	uint8_t mcolor = 1;
public:
	Draw(int, int);
	void move();
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
