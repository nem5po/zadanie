#pragma once

class Sekretariat
{
	int ilePomieszczen;
	int liczbaSekretarek;
	bool czyDyrektorTuJest;
public:
	Sekretariat();
	~Sekretariat();
	void wyswietlZawartosc();
	//zmiana parametrow
	void dodatkowePomieszczenieDlaVice();
	void zmienLiczbeSekretarek(int liczbaSekretarek);
	void dyrektorJest();
	//operator
	void operator[](int i);
};

