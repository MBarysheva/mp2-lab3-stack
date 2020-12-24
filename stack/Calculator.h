#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include "Stack.h"
using namespace std;

class TCalculator
{
	string infix;                        // ������ � �������
	string postfix;                      // ������ � ���������
	string formula;
	Stack <char> st;       
	Stack <double> st2;             
    int Priority(char elem);       
public:
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
	void SetFormula(string str);
	bool CheckBrackets();
	void ToPostfix();                     // ������� � ����������� �����
	double CalcPostfix();                 // ���������� ��������� �� ����������� �����
};


