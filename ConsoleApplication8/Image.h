#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

class Image
{
private:
	int mx;
	int my;
	int *data;
public:
	Image(int, int);
	~Image();
	int getMx() { return mx; }
	int getMy() { return my; }
	int get(int, int);
	void set(int, int, uint8_t);
	void setY(int, uint8_t);
	void setX(int, uint8_t);
	void show();
	static const int cinFunc();
};
#endif