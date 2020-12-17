#include "image.h"
#include <iostream>

Image::Image(int x, int y)
	: mx(x), my(y) {
	data = new (std::nothrow) int[mx*my]();	// () - null
	if (!data)
		std::cout << "Could not allocate memory" << std::endl;
}
Image::~Image() {
	delete[] data;
	data = nullptr;
}

// get X, Y
int Image::get(int x, int y) {
	try {
		if (x < 1 || x > mx)
			throw x;
		if (y < 1 || y > my)
			throw y;

		return data[(x - 1) + (y - 1) * mx];
	}
	catch (const int ex) {
		std::cout << "!!!\tinvalid variable\tget:\t" << ex << std::endl;
	}
}

// set X, Y
void Image::set(int x, int y, int color) {
	try {
		if (x < 1 || x > mx)
			throw x;
		if (y < 1 || y > my)
			throw y;

		data[mx * (y - 1) + (x - 1)] = color;
	}
	catch (const int ex) {
		std::cout << "!!!\tinvalid variable\tset:\t" << ex << std::endl;
	}
}

// set Y line
void Image::setY(int x, int color) {
	try {
		if (x < 1 || x > mx)
			throw x;

		for (int i = 0; i < my; i++)
			data[mx * i + (x - 1)] = color;
	}
	catch (const int ex) {
		std::cout << "!!!\tinvalid variable\tsetY:\t" << ex << std::endl;
	}
}

// set X line
void Image::setX(int y, int color) {
	try {
		if (y < 1 || y > mx)
			throw y;

		for (int i = 0; i < mx; i++)
			data[mx * (y - 1) + i] = color;
	}
	catch (const int ex) {
		std::cout << "!!!\tinvalid variable\tsetX:\t" << ex << std::endl;
	}
}

// show picture
void Image::show() {
	for (int i = 0; i < mx*my; i++) {
		if (i == 0)
			std::cout << '\t';
		std::cout << data[i];
		if (i % mx == mx - 1)
			std::cout << "\n\t";
	}
	std::cout << '\n';
}

// std::cin >>
const int Image::cinFunc() {
	while (true) {
		int a;
		do{
			std::cin >> a;
			if (a < 0 || a > 32767)
				std::cout << "!!!\tinvalid value,\tretry:\t\t   ";
		} while (a < 0 || a > 32767);

		if (std::cin.fail()) {
			std::cin.clear(); 
			std::cin.ignore(32767, '\n');
			std::cout << "\n??\n";
		}
		else {
			std::cin.ignore(32767, '\n'); 
			return a;
		}
	}
}
