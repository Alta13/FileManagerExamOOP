#include "Folder.h"

void Folder::Create()
{
	char Name[50];
	char path[200];

	cout << "Введите местоположение папки:";
	cin.ignore();
	cin.getline(path, 200);
	cout << "Введите имя папки:";
	cin.getline(Name, 50);
	strcat_s(path, Name);

	if (_mkdir(path) == -1)
	{
		cout << "Ошибка! Папка не может быть создана.\n";
	}
	else
	{
		cout << "Папка успешно создана!" << endl;
	}
}

void Folder::Remove()
{
	char a[200] = "rmdir /s /q ";
	strcat_s(a, GetName());
	if (system(a))
	{
		cout << "Ошибка! Папка не может быть удалена.\n";
	}
	else
	{
		cout << "Папка успешно удалена.\n";
	}
}
void Folder::Copy()
{
	char newpath[200];
	char copyname[200];
	cout << "Введите путь: ";
	cin.ignore();
	cin.getline(newpath, 200);
	strcpy_s(copyname, foldername);
	strcat_s(newpath, copyname);
	_mkdir(newpath);
	string copy = "Копия " + string(GetName()) + " " + string(newpath);
	system(copy.c_str());
}