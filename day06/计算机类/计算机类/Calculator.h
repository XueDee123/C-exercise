#pragma once
#include<string>
class Calculator
{
public:
	Calculator(int a,int b):n1(a),n2(b)
	{}
	int n1;
	int n2;
	int getRes(std::string oper)
	{
		if (oper == "+")return n1 + n2;
		else if (oper == "-")return n1 - n2;
		else if (oper == "*")return n1 * n2;
		else if (oper == "/")return n1 / n2;
	}
};

