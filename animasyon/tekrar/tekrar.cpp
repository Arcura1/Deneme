#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <math.h>
#include <locale.h>

using namespace std;



//////////////////////////////////kodlar////////////////////////////////////

void kursoruGizle()
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(out, &cursorInfo);
}

void gotoxy() {
	COORD coord;
	coord.X = 0;
	coord.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}
void sin2(char* ptr, int x) {
	int sayac = 0, uzun;
	float Sin;
	for (float j = 0; j < 6.28; j += 0.0405) {
		Sin = sin(j);
		uzun = Sin * x;
		if (sayac < 78) {
			*(ptr + (80 * (20 - uzun)) + 78 - sayac) = 'a';
		}
		else if (sayac) {
			*(ptr + (80 * (19 - uzun)) + sayac - 77) = 'a';
		}

		sayac++;
	}
	sayac = 0;

}

void sınır(char* ptr) {

	for (int x = 0; x < 80; x++) {
		*(ptr + x) = '@';
		*(ptr + (80 * 39) + x) = '@';
	}
	for (int x = 0; x < 40; x++) {
		*(ptr + (x * 80)) = '@';
		*(ptr + (x * 80) + 79) = '@';
	}

}
void ekranciz(char* ptr) {
	gotoxy();
	int x = 0, y = 0;
	while (x < 3200)
	{
		cout << *(ptr + (x - 1));
		if (x % 80 == 0) {
			cout << endl;

		}

		x++;

	}

}
void bosluk(char* ptr) {
	int x = 0;
	while (x < 3200) {
		*(ptr + x) = ' ';
		x++;
	}
}

void intro(char* ptr) {
	//bosluk(ptr);
	for (int x = 20; x > 0; x--) {
		sin2(ptr, x);
		ekranciz(ptr);
	}
}
void klavye(char a[256]) {
	for (int x = 0; x < 256; x++)
		a[x] = (char)(GetAsyncKeyState(x) >> 8);


}


int main()
{
	char *ptr;
	char sahne[40][80];
	ptr = &(sahne[0][0]);
	bosluk(ptr);
	sınır(ptr);
	intro(ptr);
	
	
	ekranciz(ptr);



}

