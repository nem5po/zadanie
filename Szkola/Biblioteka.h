#pragma once


class Biblioteka
{
	int naKtorymPietrze;
	bool czyJestCzytelnia;
	int ileRegalow;

public:
	Biblioteka();
	~Biblioteka();
	void wyswietlZawartosc();
	//zmiana parametrow:
	void brakCzytelni();
	void zmienLiczbeRegalow(int ileRegalow);
	void zmienPietro(int naKtorymPietrze);
	//operator - zmiana pietra
	Biblioteka operator^(int naKtorymPietrze);
};

