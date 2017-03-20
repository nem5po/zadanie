#pragma once

#include "Sala.h"
#include "Biblioteka.h"
#include "Sekretariat.h"


using namespace std;

class Szkola
{	
	string rodzaj;
	int liczbaSal;
	Sala *salaLekcyjna;		//dynamicznie
	Biblioteka biliotekaSzkolna;	//automatycznie
	Sekretariat sekretariatDyrektora;
	static int liczbaSzkol;

public:
	static int liczbaMoichSzkol();
	Szkola();
	Szkola(string rodzaj,int liczbaSal);
	Szkola(const Szkola & szkola);
	~Szkola();
	
	//zmiana parametrow Biblioteki szkoly:
	void usunCzytelnieBiblioteki();
	void innaLiczbaRegalow(int ileRegalow);
	void innePietroDlaBiblioteki(int naKtorymPietrze);
	//zmiana parametrow Sali Lekcyjnej szkoly:
	void innaLiczbaLawekIKrzesel(int numerSali, int liczbaLawek, int liczbaKrzesel);
	void innePietroDlaSali(int numerSali, int naKtorymPietrze);
	//zmiana parametrow Sekretariatu szkoly:
	void dodajGabinetVice();
	void innaLiczbaSekretarek(int liczbaSekretarek);
	void dyrektorWrocil();
	
	void wyswietlInfoOSzkole();
		
	//operatory
	Szkola& operator=(const Szkola &szkola);
	Szkola operator!(); 
	Szkola operator+(const Sala &sala);
	operator int()const;
	bool operator>(const Szkola& szkola);
	Szkola operator+(const Biblioteka& biblioteka);
	
};


