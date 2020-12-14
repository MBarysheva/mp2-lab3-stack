#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include "Stack.h"
using namespace std;

class TCalculator
{
	string infix;                        // строка в инфиксе
	string postfix;                      // строка в постфиксе
	string formula;
	Stack <char> st;       
	Stack <double> st2;             
    int Priority(char elem);       
public:
	TCalculator() : st(100), st2(200) 
	{
		infix = " ";
		postfix = " ";
	}
	TCalculator(const TCalculator& calc) 
	{
		infix = calc.infix;
		postfix = calc.postfix;
		st = calc.st;
		st2 = calc.st2;
	}            
	string GetExpression()   
	{
		return infix;
	}
	void SetExpression(string expr)
	{
		infix = expr;
		if (CheckBrackets())
		{
			ToPostfix();
		}
	}
	string GetPostfix()   
	{
		return postfix;
	}
	~TCalculator() {};
	void SetFormula(string str);
	bool CheckBrackets();
	void ToPostfix();                     // Перевод в постфиксную форму
	double CalcPostfix();                 // Вычисление выражения по постфиксной форме
};


