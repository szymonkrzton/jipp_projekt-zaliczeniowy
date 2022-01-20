#pragma once
using namespace std;

template<typename type> class Vector {
private:
	size_t defaultSize = 10;
	void realloc(size_t size);
protected:
	type* data;
	size_t allocatedDataSize;
	size_t usingDataSize;
public:
	/**
	 * Create empty vector - tworzenie pustego wektora
	*/
	Vector();

	/**
	 * Create vector with passed size - tworzenie wektora o podanym rozmiarze
	 * @param usingDataSize - size of creating vector (rozmiar dla tworzonego wektora)
	*/
	Vector(size_t usingDataSize);

	/**
	 * Deallocating, do cleanings
	 * Zwalnianie pamieci
	*/
	~Vector();

	/**
	 * Get element from specified index - pobieranie elementów spod przekazanego indeksu
	 * @param index - index of element (indeks elementu)
	 * @return reference to element (referencja do elementu)
	*/
	type* at(size_t index);

	/**
	 * Get address of first element - pobieranie adresu pierwszego elementu
	 * @return address of first element (adres pierwszego elementu)
	*/
	type* front();

	/**
	 * Get address of last element - pobieranie adresu ostatniego u¿ywanego elementu
	 * @return address of last element (adres ostatniego elementu)
	*/
	type* back();

	/**
	 * Get size of using data - pobieranie rozmiaru tablicy (uzywanej czesci)
	 * @return size of using vector (rozmiar uzywanego wektora)
	*/
	size_t size();

	/**
	 * Add new element on the end of vector - dodaj nowy element na koniec wektora
	 * @param newRecord - new value (nowa wartosc)
	*/
	void pushBack(type newRecord);

	/**
	 * Delete last element
	 * Usuwanie ostatniego elementu
	 */
	void popBack();

	/**
	 * Check vector is empty - sprawdzanie, czy wektor jest pusty
	 * @return true if vector is empty, false if not empty (prawda jezeli pusty, falsz jezeli niepusty)
	*/
	bool isEmpty();

	/** Dodatkowe
	 * Delete all elements
	 * Usuwanie wszystkich elementów z wektora
	 */
	void clear();

	/** Dodatkowe
	 * Reallocate data to fit allocated data to using data
	 * Realokowanie pamiêci, aby dopasowaæ rozmiar zaalokowanej tablicy do u¿ywanej
	 */
	void shrinkToFit();

	/**
	 * Delete element on passed index
	 * Usuwanie elementu pod wskazanym indeksem
	 * @param index - index of element to erase (indeks wskazanego elementu do usuniecia)
	*/
	void erase(size_t index);
};

template<typename type>
inline Vector<type>::Vector() {
	data = new type[defaultSize];
	allocatedDataSize = defaultSize;
	usingDataSize = 0;
}

template<typename type>
Vector<type>::Vector(size_t usingDataSize) {
	data = new type[usingDataSize];
	this->allocatedDataSize = usingDataSize;
	this->usingDataSize = 0;
}

template<typename type>
Vector<type>::~Vector() {
	delete[] data;
	data = nullptr;
}


template<typename type>
type* Vector<type>::at(size_t index) {
	if (index >= 0 && index < usingDataSize) return &data[index];
}

template<typename type>
type* Vector<type>::front() {
	if (size() >= 1) return &data[0];
}

template<typename type>
type* Vector<type>::back() {
	if (size() >= 1) return &data[usingDataSize - 1];
}

template<typename type>
size_t Vector<type>::size() {
	return usingDataSize;
}

template<typename type>
void Vector<type>::pushBack(type newRecord) {
	if (usingDataSize >= allocatedDataSize) realloc(allocatedDataSize * 2);
	data[usingDataSize++] = newRecord;
}

template<typename type>
void Vector<type>::popBack() {
	if (usingDataSize > 0) --usingDataSize;
}

template<typename type>
bool Vector<type>::isEmpty() {
	if (usingDataSize == 0) return true;
	else return false;
}

template<typename type>
void Vector<type>::clear() {
	delete[] data;

	data = new type[defaultSize];
	allocatedDataSize = defaultSize;
	usingDataSize = 0;
}

template<typename type>
void Vector<type>::shrinkToFit() {
	realloc(usingDataSize);
}

template<typename type>
void Vector<type>::erase(size_t index) {
	if (index >= 0 && index <= usingDataSize) {
		type* i = &data[index + 1];
		type* j = &data[index];

		for (; i < (data + usingDataSize); ++i, ++j) *j = *i;

		usingDataSize--;
	}
}

template<typename type>
void Vector<type>::realloc(size_t size) {
	if (size == allocatedDataSize) return;
	if (data == nullptr) {
		usingDataSize = 0;
		allocatedDataSize = 0;
	}

	size_t newSize;

	if (size < usingDataSize) newSize = usingDataSize;
	else newSize = size;

	type* temp = new type[newSize];
	allocatedDataSize = newSize;

	for (size_t i = 0; i < usingDataSize; i++) temp[i] = data[i];

	delete[] data;
	data = temp;
}


