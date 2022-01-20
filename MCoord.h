#pragma once
#include <iostream>

using namespace std;
class MCoord
{
protected:
	double* pcoord;
public:
	MCoord(double xx, double yy);
	MCoord() { pcoord = NULL; }
	~MCoord();
};

