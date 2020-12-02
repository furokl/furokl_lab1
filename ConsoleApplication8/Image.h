#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>

using std::cout;

class Image
{
private:
	int mx;
	int my;
	int *data = new int[mx*my]();
public:
	Image(int x, int y)
		: mx(x), my(y){
	}
	~Image(){
		delete[] data;
		data = nullptr;
	}
	int getMx() { return mx; }
	int getMy() { return my; }
	int get(int x, int y);
	void set(int x, int y, int color);
	void setY(int x, int color);
	void setX(int y, int color);
	void show();
};
#endif