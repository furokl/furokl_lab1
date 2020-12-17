#ifndef IMAGE_H
#define IMAGE_H

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
	void set(int, int, int);
	void setY(int, int);
	void setX(int, int);
	void show();
	static const int cinFunc();
};
#endif