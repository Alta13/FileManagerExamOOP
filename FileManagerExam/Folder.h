#pragma once
#include "FileManager.h"

class Folder : public FileManager
{
public:

	Folder(const char* filename) : FileManager{ filename } {}

	Folder() : FileManager() {}

	char* GetFolder() { return foldername; }

	void SetFolder(char* folder) { strcpy_s(foldername, folder); }

	~Folder() {}

	void Create();

	void Remove();

	void Copy();

private:
	char foldername[20];
};
