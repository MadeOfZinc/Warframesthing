#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <vector>

using namespace std;

class Warframes {
private:
	std::fstream warframefile;
	const string wfile = "warframes.txt";
public:
	void add(char* name[]);
	void openfile(string filename);
	void closefile();
	vector<string> getstring(int position);
	~Warframes();
	Warframes();
	void remove(char* name[]);
	void see();
};
