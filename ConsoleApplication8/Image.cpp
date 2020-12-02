#include "image.h"

Image:: Image(int x, int y)
	: mx(x), my(y)
{
}
Image:: ~Image()
{
	delete[] data;
	data = nullptr;
}
// геттер точки
int Image::get(int x, int y) {
	try {
		if (x < 1 || x > mx)
			throw x;
		if (y < 1 || y > my)
			throw y;

		return data[(x - 1) + (y - 1) * x];
	}
	catch (const int ex) {
		cout << "!!!\tinvalid variable\tget:\t" << ex << '\n';
	}
}
// сеттер точки
void Image::set(int x, int y, int color) {
	try {
		if (x < 1 || x > mx)
			throw x;
		if (y < 1 || y > my)
			throw y;

		data[mx * (y - 1) + (x - 1)] = color;
	}
	catch (const int ex) {
		cout << "!!!\tinvalid variable\tset:\t" << ex << '\n';
	}
}
// сеттер полоски по y
void Image::setY(int x, int color) {
	try {
		if (x < 1 || x > mx)
			throw x;

		for (int i = 0; i < my; i++)
			data[mx * i + (x - 1)] = color;
	}
	catch (const int ex) {
		cout << "!!!\tinvalid variable\tsetY:\t" << ex << '\n';
	}
}
// сеттер полоски по x
void Image::setX(int y, int color) {
	try {
		if (y < 1 || y > mx)
			throw y;

		for (int i = 0; i < mx; i++)
			data[mx * (y - 1) + i] = color;
	}
	catch (const int ex) {
		cout << "!!!\tinvalid variable\tsetX:\t" << ex << '\n';
	}
}
// демонстрация изображения
void Image::show() {
	for (int i = 0; i < mx*my; i++) {
		cout << data[i];
		if (i % mx == mx - 1)
			cout << '\n';
	}
	cout << '\n';
}

