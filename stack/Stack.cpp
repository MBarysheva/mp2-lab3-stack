#include "Calculator.h"
#include "Stack.h"
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;
void TCalculator::SetFormula(string str)
{
	infix = " ";
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^')
		{
			infix += " ";
		}
		infix += str[i];
	}
	if (!CheckBrackets())
	{
		throw 0;
	}
	Stack<char> s(infix.size());
	Stack<double> d(infix.size());
	st = s;
	st2 = d;
}

bool TCalculator::CheckBrackets()
{
	st.Clear();
	st2.Clear();
	for (int i = 0; i < infix.size(); i++)
	{
		if (infix[i] == '(')
		{
			if (st.Full())
			{
				return false;
			}
			else
			{
				st.Push('(');
			}
		}
		if (infix[i] == ')')
		{
			if (st.Empty() == true)
			{
				return false;
			}
			else
			{
				st.Pop();
			}
		}
	}
	return st.Empty();
}
int TCalculator::Priority(char elem)
{
	switch (elem)
	{
	case  '(': return 0;
	case  ')': return 1;
	case  '+': 
	case  '-': return 2;
	case  '*': 
	case  '/': return 3;
	case  '^': return 4;
	}
}
void  TCalculator::ToPostfix()
{
	if (!CheckBrackets())
	{
		throw 0;
	}
	st.Clear();
	st2.Clear();
	postfix = " ";
	string scr = "( " + infix + " )";
	char elem = ' ! ';
	unsigned int i = 0;
	st.Clear();
	while (i < scr.size())
	{
		if (scr[i] == '+' || scr[i] == '-' || scr[i] == '*' || scr[i] == '/' || scr[i] == '^')
		{
			postfix += " ";
			elem = st.Pop();
			while (Priority(elem) >= Priority(scr[i]))
			{
				postfix += elem;
				elem = st.Pop();
			}
			st.Push(elem);
			st.Push(scr[i]);
		}
		else
			if (scr[i] == '(')
			{
				st.Push(scr[i]);
			}
			else
				if (scr[i] == ')')
				{
					elem = st.Pop();
					while (elem != '(')
					{
						postfix += elem;
						elem = st.Pop();
					}
				}
				else
					if (scr[i] >= '0' && scr[i] <= '9')
					{
						postfix += scr[i];
					}
		i++;
	}
	if (!st.Empty())
	{
		throw 0;
	}
}
double  TCalculator::CalcPostfix()
{
	if (!CheckBrackets())
	{
		throw 0;
	}
	st2.Clear();
	char* tmp;
	unsigned int i = 0;
	double res = 0;
	while (i < postfix.size())
	{
		if (postfix[i] >= '0' && postfix[i] <= '9')
		{
			double d = strtod(&postfix[i], &tmp);
			int j = tmp - &postfix[i];
			i += j - 1;
			st2.Push(d);
		}
		if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^')
		{
			if (st2.Empty())
			{
				throw 0;
			}
			else
			{
				double tmp1, tmp2;
				tmp1 = st2.Pop();
				tmp2 = st2.Pop();
				switch (postfix[i]) {
				case '+':
					res = tmp1 + tmp2;
					st2.Push(res); break;
				case '-':
					res = tmp2 -  tmp1; st2.Push(res); break;
				case '*':
					res = tmp1 * tmp2; st2.Push(res); break;
				case '/':
					res = tmp2 / tmp1; st2.Push(res); break;
				case '^':
					res = pow(tmp1, tmp2); st2.Push(res); break;
				default: if (formula[i] != ' ')
					st2.Push(formula[i] - '0');
					break;
				}
			}
		}
		i++;
	}
	if (st2.Empty())
	{
		throw 0;
	}
	else
	{
		res = st2.Pop();
		return res;
	}
}


