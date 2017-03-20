#include "Sala.h"
#include <iostream>
#include <string>
// Sala lekcyjna - dynamicznie (jest ich wiele)

using namespace std;

Sala::Sala()
{
#ifdef  _DEBUG
	cout << "Wywolano konstruktor domyslny Sala" << endl;
#endif //  _DEBUG
	naKtorymPietrze = 1;
	liczbaLawek = 10;
	liczbaKrzesel = 2 * liczbaLawek;
}

Sala::Sala(int liczbaLawek)
{
	this->liczbaLawek = liczbaLawek;
	liczbaKrzesel = 2 * liczbaLawek;
	naKtorymPietrze = 1;
}

Sala::~Sala()
{
#ifdef _DEBUG
	cout << "destruktor Sala" << endl;
#endif // _DEBUG
}

void Sala::zmienLiczbeMebli(int liczbaLawek, int liczbaKrzesel)
{
	this->liczbaLawek = liczbaLawek;
	this->liczbaKrzesel = liczbaKrzesel;
}

void Sala::zmienPietro(int naKtorymPietrze)
{
	this->naKtorymPietrze = naKtorymPietrze;
}

void Sala::wyswietlZawartosc()
{
	cout << "Liczba lawek: " << liczbaLawek << endl;
	cout << "Liczba krzesel: " << liczbaKrzesel << endl;
	cout << "Pietro: " << naKtorymPietrze << endl;	
}

Sala& Sala::operator++()
{
	liczbaLawek++;
	liczbaKrzesel += 2;
	return *this;
}

Sala & Sala::operator--()
{
	if (liczbaLawek > 0) {
		liczbaLawek--;
	}
	if (liczbaKrzesel > 1) {
		liczbaKrzesel -= 2;
	}
	return *this;
}

ostream& operator<<(ostream& out, Sala& sala)
{
	out << "Liczba Lawek: " << sala.liczbaLawek << ", liczba Krzesel: " << sala.liczbaKrzesel << ", pietro: " << sala.naKtorymPietrze << endl;
	return out;
}