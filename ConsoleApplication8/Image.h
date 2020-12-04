#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
using std::cout;
using std::endl;

class Image
{
private:
	int mx;
	int my;
	int *data;
public:
	Image(int x, int y);
	~Image();
	int getMx() { return mx; }
	int getMy() { return my; }
	int get(int x, int y);
	void set(int x, int y, uint8_t color);
	void setY(int x, uint8_t color);
	void setX(int y, uint8_t color);
	void show();
};

#endif