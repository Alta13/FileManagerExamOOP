#pragma once
#include "File.h"
#include "Folder.h"
#include <Windows.h>
#include <time.h>
#define Manager Run()

class Menu
{
public:

	Menu() {}

	void Manager;

private:
	File newfile;
	Folder newfolder;
};
