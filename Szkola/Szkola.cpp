#include "Szkola.h"
#include <iostream>
#include <string>

using namespace std;

int Szkola::liczbaSzkol = 0;

int Szkola::liczbaMoichSzkol()
{
	return liczbaSzkol;
}

Szkola::Szkola()
{
#ifdef _DEBUG
		cout << "Wywolano domyslny konstruktor - Szkola" << endl;
#endif 
	rodzaj = "Podstawowa";
	liczbaSal = 1;
	salaLekcyjna = new Sala[liczbaSal];
	liczbaSzkol++;		
}

Szkola::Szkola(string rodzaj, int liczbaSal) {
#ifdef _DEBUG
	cout << "Wywolano konstruktor z parametrem - Szkola" << endl;
#endif // DEBUG

	this->rodzaj = rodzaj;
	this->liczbaSal = liczbaSal;
	salaLekcyjna = new Sala[liczbaSal];
	liczbaSzkol++;
}

Szkola::Szkola(const Szkola &szkola) {	//konstruktor kopiujacy, argumentem referencja do klasy szkola
#ifdef _DEBUG
	cout << "konstruktor kopiujacy Szkola" << endl;
#endif // DEBUG

	rodzaj = szkola.rodzaj;
	liczbaSal = szkola.liczbaSal;
	biliotekaSzkolna = szkola.biliotekaSzkolna;
	sekretariatDyrektora = szkola.sekretariatDyrektora;
							
	if (szkola.salaLekcyjna != nullptr) {
		salaLekcyjna = new Sala[liczbaSal];
		for (int i = 0; i < liczbaSal; i++) {
			salaLekcyjna[i] = szkola.salaLekcyjna[i];
		}
	}
	else {
		salaLekcyjna = nullptr;
	}

	liczbaSzkol++;
}

Szkola::~Szkola()
{
#ifdef _DEBUG
	cout << "Usuwana jest szkola" << endl;
#endif // _DEBUG
	if (salaLekcyjna != NULL) {
		delete[]salaLekcyjna;
	}	
	liczbaSzkol--;		
}

//	OPERATORY

Szkola & Szkola::operator=(const Szkola & szkola)
{
	if (this != &szkola) {
		rodzaj = szkola.rodzaj;
		liczbaSal = szkola.liczbaSal;
		biliotekaSzkolna = szkola.biliotekaSzkolna;
		sekretariatDyrektora = szkola.sekretariatDyrektora;
		
		if (salaLekcyjna != NULL) {
			delete[]salaLekcyjna;
		}
		salaLekcyjna = new Sala[liczbaSal];
		for (int i = 0; i < liczbaSal; i++) {
			salaLekcyjna[i] = szkola.salaLekcyjna[i];
		}		
	}
	return *this;
}

Szkola Szkola::operator!()
{
	if (rodzaj == "Gimnazjum") {
		rodzaj = "Liceum";
		cout<<endl << "Gimnazja sa likwidowane, ta szkola zmienia sie w liceum" << endl;
	}
	else {
		cout << "Ta szkola to nie gimnazjum, nie trzeba jej likwidowac" << endl;
	}
	return *this;
}

Szkola Szkola::operator+(const Sala & sala)
{
	Szkola nowa(*this);
	Sala *noweSale = new Sala[nowa.liczbaSal + 1];
	for (int i = 0; i < nowa.liczbaSal; i++) {
		noweSale[i] = nowa.salaLekcyjna[i];
	}
	noweSale[nowa.liczbaSal] = sala;
	delete[]nowa.salaLekcyjna;
	nowa.salaLekcyjna = noweSale;
	nowa.liczbaSal++;
	return nowa;
}

Szkola::operator int() const
{
	int pojemnoscSzkoly=0;
	for (int i = 0; i < liczbaSal; i++) {
		pojemnoscSzkoly+=salaLekcyjna[i].ileKrzesel();
	}
	return pojemnoscSzkoly;
}

bool Szkola::operator>(const Szkola& szkola) 
{
	if (this->liczbaSal > szkola.liczbaSal) {
		return true;
	}
	else if (this->liczbaSal < szkola.liczbaSal) {
		return false;
	}
	else {
		if (this->operator int() > szkola.operator int()) {
			return true;
		}
		else {
			return false;
		}
	}
}

Szkola Szkola::operator+(const Biblioteka& biblioteka)
{
	cout <<endl<< "Kazda szkola ma swoja biblioteke, niepotrzebna jej dodatkowa!" << endl;
	return Szkola();
}



// FUNKCJE ZMIENIAJACE PARAMETRY SZKO£Y
void Szkola::usunCzytelnieBiblioteki()
{
	biliotekaSzkolna.brakCzytelni();
}

void Szkola::innaLiczbaRegalow(int ileRegalow)
{
	biliotekaSzkolna.zmienLiczbeRegalow(ileRegalow);
}

void Szkola::innePietroDlaBiblioteki(int naKtorymPietrze)
{
	biliotekaSzkolna.zmienPietro(naKtorymPietrze);
}

void Szkola::innaLiczbaLawekIKrzesel(int numerSali, int liczbaLawek, int liczbaKrzesel)
{
	if (numerSali <= liczbaSal) {
		salaLekcyjna[numerSali - 1].zmienLiczbeMebli(liczbaLawek, liczbaKrzesel);	// numerSali-1, bo sala 1. ma indeks 0
	}
	else {
		cout << "Ta szkola nie ma tylu sal !" << endl;
	}
}

void Szkola::innePietroDlaSali(int numerSali, int naKtorymPietrze)
{
	salaLekcyjna[numerSali-1].zmienPietro(naKtorymPietrze);
}

void Szkola::dodajGabinetVice()
{
	sekretariatDyrektora.dodatkowePomieszczenieDlaVice();
}

void Szkola::innaLiczbaSekretarek(int liczbaSekretarek)
{
	sekretariatDyrektora.zmienLiczbeSekretarek(liczbaSekretarek);
}

void Szkola::dyrektorWrocil()
{
	sekretariatDyrektora.dyrektorJest();
}


void Szkola::wyswietlInfoOSzkole()
{
	cout << " *** INFORMACJE O SZKOLE ***" << endl;
	cout << "Rodzaj szkoly: " << rodzaj << endl;
	cout << "Liczba sal: " << liczbaSal << endl;
	for (int i = 0; i < liczbaSal; i++) {
		cout << "Sala nr " << i + 1 << endl;
		salaLekcyjna[i].wyswietlZawartosc();
	}
	biliotekaSzkolna.wyswietlZawartosc();
	sekretariatDyrektora.wyswietlZawartosc();
	cout << "****************************" << endl;
}

 

