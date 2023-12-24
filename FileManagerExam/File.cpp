#include "File.h"
#include <string>

void File::Open()
{
	_finddata_t fileInfo;
	char find[200];
	char fullpath[200];
	char file[200];
	cout << "������� ����: ";
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
		cout << "�������� ����: ";
		cin.getline(file, 200);
		SetFile(file);
		strcpy_s(filename, file);
		strcat_s(fullpath, file);
		SetName(fullpath);
		cout << filename << " ������.\n";

	}
	else
	{
		check++;
		cout << "������! �� ������ ����������!" << endl;
	}

}

void File::Create()
{
	string newname, path;
	cout << "������� ��������������� �����:";
	cin.ignore();
	getline(cin, path);
	cout << "������� ��� �����:";
	getline(cin, newname);
	path += newname;
	fstream newFile;
	newFile.open(path, std::ios::out);
	if (newFile.is_open())
	{
		cout << "���� ������� ������!" << endl;
	}
	else
	{
		cout << "������! ���� �� ����� ���� ������!" << endl;
	}
}

void File::Remove()
{
	char Name[50];
	strcpy_s(Name, GetName());
	if (remove(Name) != 0)
	{
		cout << "������! ���������� ������� ����.\n";
	}
	else
	{
		cout << "���� ������� ������.\n";
	}
}

void File::Rename()
{
	char newName[50];
	char filepath[200];
	strcpy_s(filepath, path);
	cout << "������� ����� ���: ";
	cin.ignore();
	cin.getline(newName, 50);
	strcat_s(filepath, newName);
	if (rename(GetName(), filepath) != 0)
	{
		cout << "������! ���� �� ����� ���� ������������!\n";
	}
	else
	{
		cout << "���� ������� ������������.\n";
	}
}

void File::Move()
{
	char name[100], newLocation[100];
	strcpy_s(name, GetName());
	cout << "������� ����� ��������������: ";
	cin.ignore();
	cin.getline(newLocation, 100);
	strcat_s(newLocation, filename);
	if (rename(name, newLocation) != 0)
	{
		cout << "������! ���� �� ����� ���� ���������!.\n";
	}
	else
	{
		cout << "���� ������� ���������.\n";
	}
}

void File::Copy()
{
	char* buffer;
	buffer = new char;
	char newpath[200];
	char copyname[200];
	int count = 0;
	cout << "������� ����: ";
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
		cout << "������! ���� �� ����� ���� ����������.\n";
	}
	else
	{
		cout << "���� ������� ����������.\n";
		delete buffer;
	}
}

void File::Info()
{
	_finddata_t fileInfo;
	auto res = _findfirst(GetName(), &fileInfo);
	if (res != -1)
	{
		cout << "���������� � �����:\n"
			<< ((fileInfo.attrib & _A_HIDDEN) ? "������� ����" : "�������� ����") << endl
			<< ((fileInfo.attrib & _A_RDONLY) ? "������ ��� ������" : "�� ������ ��� ������") << endl
			<< "\n��� �����: " << fileInfo.name << endl
			<< "\n������ �����: " << fileInfo.size << " ����" << endl;
	}
	else
	{
		cout << "������! ���� �� ������\n";
	}
}
void File::Search()
{
	_finddata_t fileInfo;
	char path[200];
	char mask[20];
	cout << "������� ����: ";
	cin.ignore();
	cin.getline(path, 200);
	cout << "������� ����� ( �������� \"*.txt\"): ";
	cin >> mask;
	strcat_s(path, mask);
	auto res = _findfirst(path, &fileInfo);
	cout << "��������� �����: " << endl;
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
		cout << "����� ������ ���.\n";
	}
}