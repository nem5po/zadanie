#pragma once

#include <iostream>

using namespace std;
class Sala
{
	int naKtorymPietrze;
	int liczbaLawek;
	int liczbaKrzesel;
public:	
	Sala();
	Sala(int liczbaLawek);
	~Sala();
	//zmiana parametrow:
	void zmienLiczbeMebli(int liczbaLawek, int liczbaKrzesel);
	void zmienPietro(int naKtorymPietrze);
	void wyswietlZawartosc();
	int ileKrzesel() { return liczbaKrzesel; }
	//operatory:
	Sala& operator++();
	Sala& operator--();	
	friend ostream& operator<<(ostream &out, Sala &sala);	
};

