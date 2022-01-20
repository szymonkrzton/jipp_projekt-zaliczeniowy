#pragma once
#include "MCoord.h"
#include <iostream>

using namespace std;

class Node :public MCoord
{
	int numb;
	char str[512];
public:
	Node(int nb, char* st, double xx, double yy);
	Node();
	Node(Node& copy);
	Node& operator =(const Node& obj);
	bool operator ==(const Node& obj);
	friend ostream& operator<<(ostream& output, const Node& obj);
	friend istream& operator>>(istream& input, Node& obj);
};

