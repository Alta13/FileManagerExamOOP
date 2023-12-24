#include "Menu.h"

void Menu::Manager
{
	char choice;
	char choice2;
	
	string str;
	wstring temp;
	LPCWSTR wideString;

	do
	{
		cout << "�������� ��������:\n"
			<< "0 - �����\n"
			<< "1 - ������� ����������\n"
			<< "2 - ������� ����\n"
			<< "3 - ������� �����\n"
			<< "4 - �����\n";
		cin >> choice;
		switch (choice)
		{
		case '1':
			system("CLS");
			newfile.Open();
			if (newfile.check > 0)
			{
				Sleep(1000); system("CLS"); newfile.check = 0; continue;
			}
			str = string(newfile.GetName());
			temp = wstring(str.begin(), str.end());
			wideString = temp.c_str();
			Sleep(1000);
			system("CLS");
			do
			{
				cout << "0 - ������� � ������� ����\n"
					<< "1 - �������������\n"
					<< "2 - �������\n"
					<< "3 - �����������\n"
					<< "4 - �������� ����������\n"
					<< "5 - �����������\n";

				cout << "�������� ��������: ";
				cin >> choice2;
				switch (choice2)
				{
				case '1':
					system("CLS");
					newfile.Rename();
					choice2 = '0';
					break;
				case '2':
					system("CLS");

					if ((FILE_ATTRIBUTE_DIRECTORY & GetFileAttributes(wideString)) == FILE_ATTRIBUTE_DIRECTORY)
					{
						newfolder.SetName(newfile.GetName());
						newfolder.Remove();
					}
					else
					{
						newfile.Remove();
					}
					choice2 = '0';
					break;
				case '3':
					system("CLS");
					newfile.Move();
					choice2 = '0';
					break;
				case '4':
					system("CLS");
					newfile.Info();
					break;
				case '5':
					system("CLS");
					if ((FILE_ATTRIBUTE_DIRECTORY & GetFileAttributes(wideString)) == FILE_ATTRIBUTE_DIRECTORY)
					{
						newfolder.SetFolder(newfile.GetFile());
						newfolder.SetName(newfile.GetName());
						newfolder.Copy();
					}
					else
					{
						newfile.Copy();
					}
					break;

					choice2 = '0';
				case '0':
					system("CLS");
					break;
				default:
					system("CLS");
					cout << "������! �������� ��������!";
					Sleep(1000);
					system("CLS");
					break;
				}
			} while (choice2 != '0');
			break;
		case '2':
			system("CLS");
			newfile.Create();
			break;
		case '3':
			system("CLS");
			newfolder.Create();
			break;
		case '4':
			system("CLS");
			newfile.Search();
			break;
		case '0':
			system("CLS");
			cout << endl;
			cout << "�������� ����������\n";
			Sleep(500);
			cout << ".";
			break;
		default:
			system("CLS");
			cout << "������! �������� ��������!";
			Sleep(1000);
			system("CLS");
			break;
		}
	} while (choice != '0');
}