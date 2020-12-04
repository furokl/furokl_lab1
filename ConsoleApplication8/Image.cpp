#include "image.h"

Image::Image(int x, int y)
	: mx(x), my(y) {
	data = new (std::nothrow) int[mx*my]();
	if (!data)
		cout << "Could not allocate memory" << endl;
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

		return data[(x - 1) + (y - 1) * x];
	}
	catch (const int ex) {
		cout << "!!!\tinvalid variable\tget:\t" << ex << endl;
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
		cout << "!!!\tinvalid variable\tset:\t" << ex << endl;
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
		cout << "!!!\tinvalid variable\tsetY:\t" << ex << endl;
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
		cout << "!!!\tinvalid variable\tsetX:\t" << ex << endl;
	}
}

// show picture
void Image::show() {
	for (int i = 0; i < mx*my; i++) {
		if (i == 0)
			cout << '\t';
		cout << data[i];
		if (i % mx == mx - 1)
			cout << "\n\t";
	}
	cout << '\n';
}

// cin >>
const int Image::cinFunc() {
	while (true) {
		int a;
		cin >> a;

		if (cin.fail()) {
			cin.clear(); 
			cin.ignore(32767, '\n');
			cout << "\n??\n";
		}
		else {
			cin.ignore(32767, '\n'); 
			return a;
		}
	}
}

