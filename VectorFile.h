#pragma once
#include "Vector.h"
#include <string>
#include <fstream>
template<typename type>
class VectorFile :public Vector<type>
{
public:
	VectorFile() : Vector<type>() {};
	VectorFile(size_t usingDataSize) : Vector(usingDataSize) {};
	void operator >>(const string file);
	void operator <<(const string file);
};

template<typename type>
inline void VectorFile<type>::operator >>(const string file) {
	type temp;
	ifstream input(file, ios::binary | ios::in);

		while (input >> temp) this->pushBack(temp);

		input.close();
}

template<typename type>
inline void VectorFile<type>::operator <<(const string file) {
	ofstream output(file, ios::binary | ios::out);

	if (!output.is_open()) {
		system("pause");
		exit(1);
	}

	for (size_t i = 0; i < this->usingDataSize; i++) output << this->data[i];

	output.close();
}
