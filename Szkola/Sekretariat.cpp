#include "Sekretariat.h"
#include <iostream>
#include <string>


using namespace std;

Sekretariat::Sekretariat()
{
#ifdef  _DEBUG
	cout << "Wywolano konstruktor domyslny Sekretariat" << endl;
#endif //  _DEBUG
	ilePomieszczen = 2;
	czyDyrektorTuJest = false;
	liczbaSekretarek = 1;
}


Sekretariat::~Sekretariat()
{
#ifdef _DEBUG
	cout << "destruktor Sekretariat" << endl;
#endif // _DEBUG
}

void Sekretariat::wyswietlZawartosc()
{
	cout << "Sekretariat sklada sie z " << ilePomieszczen << " pomieszczen" << endl;
	cout << "Liczba sekretarek: " << liczbaSekretarek << endl;
	if (czyDyrektorTuJest == true) {
		cout << "Dyrektor jest, ale zajety, nie mozna mu przeszkadzac" << endl;
	}
	else {
		cout << "Niestety dyrektora nie ma " << endl;
	}
}

void Sekretariat::dodatkowePomieszczenieDlaVice()
{
	if (ilePomieszczen == 3) {
		cout << "Nie mozna dodac pomieszczenia, gabinet dla vice dyrektora juz istnieje" << endl;
	}
	else {
		ilePomieszczen = 3;
	}
}

void Sekretariat::zmienLiczbeSekretarek(int liczbaSekretarek)
{
	this->liczbaSekretarek = liczbaSekretarek;
}

void Sekretariat::dyrektorJest()
{
	czyDyrektorTuJest = true;
}

void Sekretariat::operator[](int i)
{	
	if (i<= ilePomieszczen) {
		switch (i) {
		case 1:
			cout << "Pierwsze pomieszczenie -siedza tu sekretarki" << endl;
			break;
		case 2:
			cout << "Drugie pomieszczenie- gabinet dyrektora" << endl;
			break;
		case 3:
			cout << "Trzecie pomieszczenie- gabinet vice dyrektora" << endl;
			break;
		}
	}
	else {
		cout << "Ten sekratariat nie ma tylu pomieszczen!" << endl;
	}
}
