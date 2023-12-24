#pragma once
#include <iostream>
#include <stdio.h>
#include <io.h>
#include <direct.h>
#include <fstream>

using namespace std;

class FileManager
{
public:

	FileManager(const char* filename)
	{
		if (fullpath) 
		{
			strcpy_s(fullpath, 200, filename);
		}
	}

	FileManager() {}

	virtual ~FileManager() {}

	char* GetName() { return fullpath; }

	void SetName(char* filename) { strcpy_s(fullpath, 200, filename); }

	void Open() {}

	void Create() {}

	void Remove() {}

	void Rename() {}

	void Move() {}

	void Copy() {}

	void Info() {}

	void Search() {}

private:
	char fullpath[200];
};
