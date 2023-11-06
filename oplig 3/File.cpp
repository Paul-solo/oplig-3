#include "File.h"
#include "iostream"
#include <ctime>
#include <chrono>

using namespace std;
File::File()
{
	size = rand() % 100;
	
	creationdate = ""; 
	
	auto start = std::chrono::system_clock::now();
	auto legacyStart = std::chrono::system_clock::to_time_t(start);
	char tmBuff[30];
	ctime_s(tmBuff, sizeof(tmBuff), &legacyStart);
	creationdate = tmBuff;
}
