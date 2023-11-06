#pragma once

#include "iostream"
#include "File.h"
// jeg vil lage det slik at man lager en folder max5 og hver gang man lager en folder kommer man til en meny som repiterer 10 ganger der man har to valg. 
// lage en fil eller la den være tom, de tomme filene lages automatisk som clear file med 0mb i størelse. 
// om man senere vil legge inn filer i de "clear file" så kan man gå i folder managment der man har 5 valg, der de 5 valgene er de 5 max folderene,
// når man går in i en folder får man 10 valg (hver fil). velger man en fil får man muligheten til å lage en ny fil, gå tilbake eller la den vere tom/slette. 
// elimination tol gjør folders til clear folder 
// alle lagde filer med navn vil få størelse fra 1-1000mb 
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



