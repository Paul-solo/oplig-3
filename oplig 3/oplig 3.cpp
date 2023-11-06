
#include <iostream>
#include "folder.h"
#include "File.h"
using namespace std;




int main()
{
	Folder root("root");

	Folder * activeFolder = &root;

	bool isAlive = true;
	while (isAlive) {
		cout << "\ntype 1 for file cration \n"
				"type 2 to see files created \n"
				"type 3 for folder managment\n"
				"type 4 to deleate folder/file(coming soon) \n"
				"type 5 to go back / end program ";

		int input;
		string inputstring1;
		string inputstring2;
		string inputstring3;
		string inputstring4;
		cin >> input;

		switch (input)
		{
		case 1:
			cout<< "enter name";
			cin>> inputstring1;
			cout << "type 1 to choose wich folder you want to place file " << inputstring1 << " inn ?\n"
					"if you dont have a folder yet, type 2 to create one\n";
			cin >> input;
			switch (input)
			{
			case 1:
				
				cout << "this is all created folders\n" "type inn the name of the folder you want your created file inn\n";
				activeFolder->printFolders();
				cin >> inputstring2;
				activeFolder = activeFolder->getFolder(inputstring2);

				if (activeFolder == nullptr)
				{
					cout << "error, no such folder with that name, try again";
				}
				else
				{
					activeFolder->createFile(inputstring1);
				}

				activeFolder = &root;

				break;
			case 2:
				
				cout << "type inn name of folder\n";
				cin >> inputstring2;

				activeFolder->createFolder(inputstring2);
				activeFolder = activeFolder->getFolder(inputstring2);
				activeFolder->createFile(inputstring1);
				activeFolder = &root;


			default:
				break;
			}
			break;
		case 2:
			activeFolder->printFolders();
			break;

		case 3:
			cout << "folder management\n\n"
					"type 1 for folder creation\n"
					"type 2 for folder content\n"
					"type 3 for biggest file in folder\n"
					"type 4 to create a subFolder\n"
					"type 5 to rename a folder or file\n"
					"type 6 to go back\n";
			cin >> input;

			switch (input)
			{
			case 1:
				cout << "type inn name of folder\n";
				cin >> inputstring1;

				activeFolder->createFolder(inputstring1);

				break;

			case 2:
				activeFolder->printFolders();

				break;

			case 3:
				activeFolder->printFolders();

				cout << "type inn name of folder to search\n";

				cin >> inputstring1;

				activeFolder = activeFolder->getFolder(inputstring1);

				if (activeFolder == nullptr)
				{
					cout << "error, no such folder with that name, try again";
				}
				else
				{
					activeFolder->printLargestFile(inputstring1);
				}

				activeFolder = &root;
				break;

			case 4:
				cout << "type inn name of subfolder\n";
				cin >> inputstring1;

				cout << "this is all created folders\n" "type inn the name of the folder you want your created subfolder inn\n";
				activeFolder->printFolders();
				cin >> inputstring2;
				activeFolder = activeFolder->getFolder(inputstring2);

				if (activeFolder == nullptr)
				{
					cout << "error, no such folder with that name, try again";
				}
				else
				{
					activeFolder->createFolder(inputstring1);
				}

				activeFolder = &root;

				break;

			case 5:
				cout << "type 1 to rename files\n"
					"type 2 to rename folders\n"
					"type 3 to go back\n";
				cin >> input;
				
				
				switch (input){
					
				case 1:
					cout << "this is all created folders\n" "type inn the name of the folder you want to rename\n";
					activeFolder->printFolders();
					cin >> inputstring2;
					cout << "this is all created files in folder ("<<inputstring2<< ") type inn the name of the file you want to rename\n";
					activeFolder->getFolder(inputstring2)->printfiles();
					cin >> inputstring3;
					cout << "type inn the new name\n";
					cin >> inputstring4;
					//activeFolder->getFolder(inputstring2)->files[i].name = inputstring4;
					break;

				case 2:

				cout << "type your new name\n";
				cin >> inputstring1;

				cout << "this is all created folders\n" "type inn the name of the folder you want to rename\n";
				activeFolder->printFolders();
				cin >> inputstring2;

				if (activeFolder->getFolder(inputstring2) == nullptr)
				{
					cout << "error, no such folder with that name, try again";
				}
				else
				{
					activeFolder->getFolder(inputstring2)->foldername = inputstring1;
					//activeFolder->Folder(string iputstring2).name = inputstring1;
					//activeFolder->foldername=(inputstring1);
				}
					break;

			default:

				break;
				}
				
				break;

			case 6:

				break;


			default:
				cout << "error wrong comand";
				break;
			}
			break;

		case 4:

			break;

		case 5:
			isAlive = false;
			break;
		default:
			cout << "error wrong comand";
			break;
		}

		cin.clear();
		cin.ignore();
		
	}

	//filforsk();
}
