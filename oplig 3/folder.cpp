#include "folder.h"
#include "iostream"
#include <ctime>
#include <chrono>

using namespace std;

Folder * Folder::getFolder(string name)
{
	for (int i = 0; i < numberOfFolders; i++)
	{
		if (name == folders[i].foldername)
		{
			return &folders[i];
		}
	}
	
	return nullptr;
}

void Folder::createFile(string name)
{
	if (numberOfFiles < 10) {
		File file;
		file.name = name;
		files[numberOfFiles] = file;
		numberOfFiles++;
	}
	else {
		cout << "error file: "<< name <<", cant store more than 10 files. file "<< name <<" has been deleted";
	}

	calcSize();
}

void Folder::createFolder(string name)
{
	if (numberOfFolders < 5) {
		folders[numberOfFolders] = Folder(name);
		numberOfFolders++;
	}
	else {
		cout << "error folder: " << name << ", cant store more than 5 folders. folder " << name << " has been deleted";
	}
}

void Folder::printfiles()
{
	for (int i = 0; i < numberOfFiles; i++)
	{
		cout << "folder " << foldername << ": contains File " << files[i].name << " size: " << files[i].size << "MB created; " << files[i].creationdate;
	}

	cout << endl;
}

void Folder::printFolders()
{
	for (int i = 0; i < numberOfFolders; i++)
	{
		cout << "Folder " << folders[i].foldername << " size: " << folders[i].size << "MB created; " << folders[i].creationdate;
		folders[i].printfiles();

		if (folders[i].numberOfFolders > 0)
		{
			for (int j = 0; j < numberOfFolders; j++)
			{
				cout << "Sub-Folder in " << folders[i].foldername << ": " << folders[i].folders[j].foldername << " size: " << folders[i].size << "MB created; " << folders[i].creationdate;
			}

			cout << endl;
		}
	}
}

void Folder::calcSize()
{
	size = 0;

	for (int i = 0; i < numberOfFiles; i++)
	{
		size += files[i].size;
	}
}

void Folder::printLargestFile(string name)
{
	if (numberOfFiles > 0)
	{
		int largestSize = -1;
		int largestFileIndex;

		for (int i = 0; i < numberOfFiles; i++)
		{
			if (files[i].size > largestSize)
			{
				largestSize = files[i].size;
				largestFileIndex = i;
			}
		}

		cout << files[largestFileIndex].name << " size: " << files[largestFileIndex].size << " creation date: " << files[largestFileIndex].creationdate;
	}
	else
	{
		cout << "There are no files in this folder\n";
	}
}

Folder::Folder() {
	numberOfFiles = 0;
	numberOfFolders= 0;
	size = 0;

	folders = NULL;

	foldername = "";

	auto start = std::chrono::system_clock::now();
	auto legacyStart = std::chrono::system_clock::to_time_t(start);
	char tmBuff[30];
	ctime_s(tmBuff, sizeof(tmBuff), &legacyStart);
	creationdate = tmBuff;
}

Folder::Folder(string name)
{
	numberOfFiles = 0;
	numberOfFolders = 0;
	size = 0;

	folders = new Folder[5];

	foldername = name;

	auto start = std::chrono::system_clock::now();
	auto legacyStart = std::chrono::system_clock::to_time_t(start);
	char tmBuff[30];
	ctime_s(tmBuff, sizeof(tmBuff), &legacyStart);
	creationdate = tmBuff;
}

