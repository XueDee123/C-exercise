#pragma once
class BaseCalculator
{
public:
	BaseCalculator(int a,int b):n1(a),n2(b)
	{}
	int n1;
	int n2;
	virtual int getRes()
	{
		return 0;
	}
};

