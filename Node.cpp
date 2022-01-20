#include "Node.h"
#include <iostream>

using namespace std;

Node::Node(int nb, char* st, double xx, double yy) : MCoord(xx, yy) {
	numb = nb;
	strcpy_s(str, st);
}

Node::Node() : MCoord() {
	numb = 0;
	strcpy_s(str, "");
}

Node::Node(Node& copy) {
	pcoord[0] = copy.pcoord[0];
	pcoord[1] = copy.pcoord[1];
	numb = copy.numb;
	strcpy_s(str, sizeof(str), copy.str);
}

Node& Node::operator=(const Node& obj) {
	numb = obj.numb;
	strcpy_s(str, obj.str);
	pcoord[0] = obj.pcoord[0];
	pcoord[1] = obj.pcoord[1];

	return *this;
}

bool Node::operator==(const Node& obj) {
	if (numb == obj.numb && str == obj.str && pcoord[0] == obj.pcoord[0] && pcoord[1] == obj.pcoord[1]) return true;
	else return false;
}

ostream& operator<<(ostream& output, const Node& obj) {
	output << "Nazwa wierzcho³ka: " << obj.str << "\nNumer wierzcho³ka: " << obj.numb << "\nWspó³rzêdne wierzcho³ka: (" << obj.pcoord[0] << "," << obj.pcoord[1] << ")\n";
	return output;
}

istream& operator>>(istream& input, Node& obj) {
	cout << "Nazwa wierzcho³ka: ";
	input >> obj.str;
	cout << "Numer wierzcho³ka: ";
	input >> obj.numb;
	cout << "Wspó³rzêdna x: ";
	input >> obj.pcoord[0];
	cout << "Wspó³rzêdna y: ";
	input >> obj.pcoord[1];

	return input;
}