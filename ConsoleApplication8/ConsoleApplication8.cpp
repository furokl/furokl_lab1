#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
// 237x421
const int dataSize = 100'000;
const static int line = 80;		// Установка размера строки

float temp = ceil(static_cast<float>(dataSize) / static_cast<float>(line));
const static int column = static_cast<int>(temp);

/*
	Класс для индефикации пикселя

class ID_Generator
{
private:
	static int s_idGenerator;
	int m_id;

public:
	ID_Generator() { m_id = s_idGenerator++; }
	int getID() const { return m_id; }
};

int ID_Generator::s_idGenerator = 1;
*/
/*
	Класс для цвета

class RGBA
{
private:
	uint8_t m_red;
	uint8_t m_green;
	uint8_t m_blue;
	uint8_t m_alpha;

public:
	RGBA (uint8_t red = 0, uint8_t green = 0, uint8_t blue = 0, uint8_t alpha = 255)
		: m_red(red), m_green(green), m_blue(blue), m_alpha(alpha)
	{
	}

	void printRGBA(){
		cout << "R = " << static_cast<int>(m_red) << ';' <<
			" G = " << static_cast<int>(m_green) << ';' <<
			" B = " << static_cast<int>(m_blue) << ';' <<
			" A = " << static_cast<int>(m_alpha) << '\n';
	}
};
*/

class Image
{
private:
	int mx;
	int my;
	int data[100'000];

public:
	Image(int tmx, int tmy) {
		// Я не должен влезть сюда, чтобы выдавать картинку нужного размера?
		for (int i = 0; i < dataSize; i++)
			data[i] = 0;					
	}

	int getMx()				{ return mx; }
	int getMy()				{ return my; }
	int get(int x, int y)	{ return data[(x - 1) + (y - 1) * line]; }

	void show() {
		//for (const auto &i : data){		// если бы не if
		for (int i = 0; i < dataSize; i++) {
			cout << data[i];
			if (i % line == line - 1)
				cout << '\n';
		}
	}

	// один элемент
	void set(int x, int y, int color) {
		if (x < 1 || x > line)							return;
		if (y < 1 || y > column)						return;
		if ((y == column) && (x > (dataSize % line)))	return;		// если остаток

		mx = x;
		my = y;
		int temp = (x - 1) + (y - 1) * line;
		data[temp] = color;
	}

	// вертикальная полоска
	void set(int x, int color) {
		if (x < 1 || x >= line)		return;

		for (int i = 0; i < column; i++) {
			int temp = x - 1 + i * line;
			if (temp > dataSize)	return;		// если остаток
			data[temp] = color;
		}
	}
};

int main() {
	cout << "\n\n\t\tProgramm started...\n\n";
	Image picture(10, 10);
	cout << '\t' << line << 'x' << column << endl;
	picture.set(1, 1, 1);
	cout << "*setter used*\nx = " << picture.getMx() << "\ny = " << picture.getMy() << endl;
	cout << "color = " << picture.get(1, 1) << endl;
	picture.set(68, 1);
	cout << "\n*column setter used*" << endl;
	cout << "color = " << picture.get(68, 1) << endl;
	picture.show();
	cout << endl;

	return 0;
}