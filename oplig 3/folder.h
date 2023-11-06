#pragma once

#include "iostream"
#include "File.h"

using namespace std;

class Folder

{

public:
	File files[10];
	Folder * folders;
	string creationdate;
	int size;
	int numberOfFiles;
	int numberOfFolders;
	Folder * getFolder(string name);
	string foldername;
	void createFile(string name);
	void createFolder(string name);
	void printfiles();
	void printFolders();
	void calcSize();
	void printLargestFile(string name);
	Folder();
	Folder(string name);


};



