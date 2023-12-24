#include "File.h"
#include <string>

void File::Open()
{
	_finddata_t fileInfo;
	char find[200];
	char fullpath[200];
	char file[200];
	cout << "Введите путь: ";
	cin.ignore();
	cin.getline(find, 200);
	strcpy_s(path, find);
	strcpy_s(fullpath, find);
	strcat_s(find, "*.*");
	auto res = _findfirst(find, &fileInfo);
	if (res != -1)
	{
		do
		{
			if (res != -1)
				cout << fileInfo.name << endl;
		} while (_findnext(res, &fileInfo) != -1);
		cout << "Выберите файл: ";
		cin.getline(file, 200);
		SetFile(file);
		strcpy_s(filename, file);
		strcat_s(fullpath, file);
		SetName(fullpath);
		cout << filename << " Выбран.\n";

	}
	else
	{
		check++;
		cout << "Ошибка! Не верная директория!" << endl;
	}

}

void File::Create()
{
	string newname, path;
	cout << "Введите местонахождение файла:";
	cin.ignore();
	getline(cin, path);
	cout << "Введите имя файла:";
	getline(cin, newname);
	path += newname;
	fstream newFile;
	newFile.open(path, std::ios::out);
	if (newFile.is_open())
	{
		cout << "Файл успешно создан!" << endl;
	}
	else
	{
		cout << "Ошибка! Файл не может быть создан!" << endl;
	}
}

void File::Remove()
{
	char Name[50];
	strcpy_s(Name, GetName());
	if (remove(Name) != 0)
	{
		cout << "Ошибка! Невозможно удалить файл.\n";
	}
	else
	{
		cout << "Файл успешно удален.\n";
	}
}

void File::Rename()
{
	char newName[50];
	char filepath[200];
	strcpy_s(filepath, path);
	cout << "Введите новое имя: ";
	cin.ignore();
	cin.getline(newName, 50);
	strcat_s(filepath, newName);
	if (rename(GetName(), filepath) != 0)
	{
		cout << "Ошибка! Файл не может быть переименован!\n";
	}
	else
	{
		cout << "Файл успешно переименован.\n";
	}
}

void File::Move()
{
	char name[100], newLocation[100];
	strcpy_s(name, GetName());
	cout << "Введите новое местоположение: ";
	cin.ignore();
	cin.getline(newLocation, 100);
	strcat_s(newLocation, filename);
	if (rename(name, newLocation) != 0)
	{
		cout << "Ошибка! Файл не может быть перемещен!.\n";
	}
	else
	{
		cout << "Файл успешно перемещен.\n";
	}
}

void File::Copy()
{
	char* buffer;
	buffer = new char;
	char newpath[200];
	char copyname[200];
	int count = 0;
	cout << "Введите путь: ";
	cin.ignore();
	cin.getline(newpath, 200);
	strcpy_s(copyname, filename);
	strcat_s(newpath, copyname);
	ifstream infile(GetName(), ios::binary);
	ofstream outfile(newpath, ios::binary);

	while (!infile.eof())
	{
		infile.read(buffer, sizeof(char));
		outfile.write(buffer, sizeof(char));
	}
	if (!outfile.is_open())
	{
		cout << "Ошибка! Файл не может быть скопирован.\n";
	}
	else
	{
		cout << "Файл успешно скопирован.\n";
		delete buffer;
	}
}

void File::Info()
{
	_finddata_t fileInfo;
	auto res = _findfirst(GetName(), &fileInfo);
	if (res != -1)
	{
		cout << "Информация о файле:\n"
			<< ((fileInfo.attrib & _A_HIDDEN) ? "Скрытый файл" : "Открытый файл") << endl
			<< ((fileInfo.attrib & _A_RDONLY) ? "Только для чтения" : "Не только для чтения") << endl
			<< "\nИмя файла: " << fileInfo.name << endl
			<< "\nРазмер файла: " << fileInfo.size << " байт" << endl;
	}
	else
	{
		cout << "Ошибка! Файл не найден\n";
	}
}
void File::Search()
{
	_finddata_t fileInfo;
	char path[200];
	char mask[20];
	cout << "Введите путь: ";
	cin.ignore();
	cin.getline(path, 200);
	cout << "Введите маску ( например \"*.txt\"): ";
	cin >> mask;
	strcat_s(path, mask);
	auto res = _findfirst(path, &fileInfo);
	cout << "Найденные файлы: " << endl;
	if (res != -1)
	{
		do
		{
			if (res != -1)
			{
				cout << fileInfo.name << endl;
			}
		} while (_findnext(res, &fileInfo) != -1);
		{
			cout << endl;
		}
	}
	else
	{
		cout << "Таких файлов нет.\n";
	}
}