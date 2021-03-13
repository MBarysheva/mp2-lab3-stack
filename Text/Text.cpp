#pragma once
#include <iostream>
#include <cstdlib>
#include "../stack/Stack.h"
#include "Text.h"
int main()
{
	TText t;
	t.Read("Text.txt");
	t.Print();
}