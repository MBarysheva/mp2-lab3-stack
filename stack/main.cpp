#include "Calculator.h"
#include "Stack.h"
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
	string expression;
	double res;
	TCalculator postfix;
	cout << "Enter your expression ";
	cin >> expression;
	cout << expression << endl;
	postfix.SetFormula(expression);
	cout << "Your expression: " << postfix.GetExpression() << endl;
	postfix.ToPostfix();
	cout << "Postfix form: " << postfix.GetPostfix() << endl;
	res = postfix.CalcPostfix();
	cout << "Result: ";
	cout << res << endl;
	return 0;
}

