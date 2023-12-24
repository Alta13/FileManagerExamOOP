#include <iostream>
#include "Menu.h"

int main() 
{
	setlocale(LC_ALL, "Rus");

	Menu show;

	try 
	{
		show.Manager;
	}
	catch (...)
	{
		cout << "Неустранимая ошибка\n";
	}
}