#pragma once
#include "../stack/Stack.h"
#include "Text.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	TText t;
	char NameofFile[200], s[200];
	cout << "Your name of file: " << endl;
	cin >> NameofFile;
	t.Read(NameofFile);
	t.Print();
}