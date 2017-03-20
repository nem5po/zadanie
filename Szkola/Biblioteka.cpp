#include "Biblioteka.h"
#include <iostream>
#include <string>


//Bilioteka - automatycznie - zawsze jest, 1 sztuka 
using namespace std;

Biblioteka::Biblioteka()
{
#ifdef _DEBUG
	cout << "Wywolano konstruktor Biblioteka" << endl;
#endif // _DEBUG

	naKtorymPietrze = 1;
	czyJestCzytelnia = true;
	ileRegalow = 20;
}


Biblioteka::~Biblioteka()
{
#ifdef _DEBUG
	cout << "destruktor Biblioteka" << endl;
#endif // _DEBUG

}

void Biblioteka::wyswietlZawartosc()
{
	cout << "INFO O BIBLIOTECE:" << endl;
	cout << "Biblioteka jest na " << naKtorymPietrze << " pietrze" << endl;
	cout << "Znajduje sie w niej " << ileRegalow << " regalow z ksiazkami" << endl;
	if (czyJestCzytelnia == true) {
		cout << "Jest w niej czytelnia" << endl;
	}
	else {
		cout << "Nie ma czytelni :(" << endl;
	}
}

void Biblioteka::brakCzytelni()
{
	czyJestCzytelnia = false;
}

void Biblioteka::zmienLiczbeRegalow(int ileRegalow)
{
	this->ileRegalow = ileRegalow;
}

void Biblioteka::zmienPietro(int naKtorymPietrze)
{
	this->naKtorymPietrze = naKtorymPietrze;
}

Biblioteka Biblioteka::operator^(int naKtorymPietrze)	
{
	this->naKtorymPietrze = naKtorymPietrze;
	return *this;
}


