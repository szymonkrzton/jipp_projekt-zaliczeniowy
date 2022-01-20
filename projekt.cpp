// projekt.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "Vector.h"
#include "VectorFile.h"
#include "MCoord.h"
#include "Node.h"
#include <fstream>

using namespace std;

int main()
{
    cout << "Hello World!\n";
	/*
	VectorFile<int>* obj = new VectorFile<int>();
	obj->pushBack(5);
	obj->pushBack(4);
	obj->pushBack(3);
	obj->pushBack(2);
	cout << *obj->at(0);

	string toFile = "test.txt";

	*obj << toFile;

	VectorFile<int>* obj2 = new VectorFile<int>();
	*obj2 >> toFile;

	for (int i = 0; i < obj2->size(); i++) cout << *obj2->at(i);
	*/
	
	MCoord* mc1 = new MCoord(3, 5);
	Node* nd1 = new Node(1, "a", 2, 3);



}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
