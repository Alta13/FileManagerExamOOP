#pragma once
#include "FileManager.h"

class File : public FileManager
{
public:

	void SetFile(char* file) { strcpy_s(filename, file); }

	char* GetFile() { return filename; }

	File(const char* filename) : FileManager{ filename } {}

	File() : FileManager() {}

	~File() {};

	void Open();

	void Create();

	void Remove();

	void Rename();

	void Move();

	void Copy();

	void Info();

	void Search();

	int check = 0;

private:

	char path[200];
	char filename[200];
};
