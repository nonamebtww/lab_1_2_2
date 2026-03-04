#include <locale>
#include <windows.h>

#include "menu.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "ru_RU.UTF-8");

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	return menu_start();
}