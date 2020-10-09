#include <iostream>

using std::cout;
using std::endl;

class Image
{
private:
	int mx;
	int my;
	int data[100'000];

public:
	Image(int tmx = 200, int tmy = 200) 
		: mx(tmx), my(tmy)
	{
		for (int i = 0; i < tmx*tmy; i++)
			data[i] = 0;
	}

	
	int getMx()				{ return mx; }
	int getMy()				{ return my; }
	int get(int x, int y)	{ return data[(x - 1) + (y - 1) * x]; }

	void show() {
		cout << "\t\t*Show func used* size: (" << mx << 'x' << my << ')' << endl;
		for (int i = 0; i < mx*my; i++) {
			cout << data[i];
			if (i % mx == mx - 1)
				cout << '\n';
		}
	}

	void set(int x, int y, int color) {
		cout << "\t\t*Setter used*\n\tx: " << x
			<< "\n\ty: " << y
			<< "\n\tcolor: " << color << endl;

		if (x < 1 || x > 200)	return;
		if (y < 1 || y > 200)	return;

		mx = x;
		my = y;
		for (int i = 0; i < x*y; i++)
			data[i] = color;
	}

	void set(int x, int color) {
		cout << "\t\t*Setter used*\n\tx: " << x
			<< "\n\tcolor: " << color << endl;

		if (x < 1 || x > 200)	return;
		if (my < 1 || my > 200)	return;

		for (int i = 0; i < my; i++) {
			int temp = x - 1 + i * mx;
			data[temp] = color;
		}
	}
};

int main() {
	cout << "\n\n\t\tProgramm started...\n\n";
	Image a(3, 3);
	a.show();
	a.set(5, 5, 1);
	a.show();
	a.set(2, 0);
	a.show();

	return 0;
}