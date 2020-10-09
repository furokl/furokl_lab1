// Выполнил ст. группы М3О-214Б-19.
/*
	Практическое задание №1 - класс изображения.

0.	Необходимо разработать класс Image
1.	Создать переменную типа Image и убедиться путем вставки отладочной печати, что конструктор
	вызывается.
2.	Реализовать методы get и set в предположение, что двумерное изображение помещается в 
	одномерный массив data по строкам (первая строка, вторая строка и т.д.)
3.	Реализовать метод show и убедиться, при создании переменной для изображения 10 на 10 на
	экран выводится правильное изображение
4.	Добавить в класс метод для рисования вертикальных линий. Убедиться, что они работают путем
	выдачи изображения на экран при помощи метода show.
5.	Реализовать метод для сохранения изображения в файл в формате pnm
	(https://ru.wikipedia.org/wiki/Portable_anymap)
*/

#include <iostream>
#include <cassert>

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
		// Подразумевается, что картинка максимум 200x200, поскольку тяжело развернуть в консоли

		for (int i = 0; i < tmx*tmy; i++)
			data[i] = 0;

		assert(tmx >= 1 && tmx <= 200);
		assert(tmy >= 1 && tmy <= 200);
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
	// set x*y
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
	// set y
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
	Image a(20, 5);
	a.show();
	a.set(10, 10, 1);
	a.show();
	a.set(5, 0);
	a.set(6, 0);
	a.show();

	return 0;
}