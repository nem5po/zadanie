// Szkola.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include "Szkola.h"
#include "Projekt1.h"

//obiekt statyczny globalny
Szkola szkola0;
void testObiektow() {
	cout << "*** obiekt globalny ***" << endl << endl;
	szkola0.wyswietlInfoOSzkole();
	cout << endl << "zmieniam parametry biblioteki" << endl;
	szkola0.usunCzytelnieBiblioteki();
	szkola0.innaLiczbaRegalow(25);
	szkola0.innePietroDlaBiblioteki(2);
	szkola0.wyswietlInfoOSzkole();

	cin.get();
	system("cls");
		
	cout << "*** obiekty automatyczne ***" << endl << endl;
	cout << "SZKOLA 1 - DOMYSLNA" << endl;
	Szkola szkola1;
	szkola1.wyswietlInfoOSzkole();
	cout << endl << "zmieniam parametry sekretariatu" << endl;
	szkola1.dodajGabinetVice();
	szkola1.dyrektorWrocil();
	szkola1.innaLiczbaSekretarek(2);
	szkola1.wyswietlInfoOSzkole();

	cout << endl << "SZKOLA 2 -  KOPIA SZKOLY 1. po zmianach" << endl;
	Szkola szkola2(szkola1);
	szkola2.wyswietlInfoOSzkole();
	

	cin.get();
	system("cls");
	
	cout << endl << "SZKOLA 3 - Z PARAMETREM - gimnazjum o 3 salach" << endl;
	Szkola szkola3("Gimnazjum", 3);
	cout << endl << "zmieniam parametry sali" << endl;
	szkola3.innaLiczbaLawekIKrzesel(2, 12, 23);
	szkola3.innePietroDlaSali(1,2);
	szkola3.wyswietlInfoOSzkole();
	cout << "teraz likwiduja gimnazja, trzeba przerobic szkole na liceum" << endl;
	szkola3 = !szkola3;
	szkola3.wyswietlInfoOSzkole();
	cout << endl << "Liczba szkol do tej pory: " << szkola3.liczbaMoichSzkol() << endl;

	cin.get();
	system("cls");
	
	cout << "*** obiekt statyczny lokalny ***" << endl << endl;
	static Szkola szkola4;
	szkola4.wyswietlInfoOSzkole();
	cout << endl << "Do szkoly dodaje nowe sale" << endl << endl;
	Sala salaDodatkowaMniejsza;
	Sala salaDodatkowaWieksza;
	salaDodatkowaMniejsza.zmienPietro(2);
	--salaDodatkowaMniejsza;		//operatory ++ i -- oraz strumieniowy <<
	cout << salaDodatkowaMniejsza << endl;
	++salaDodatkowaWieksza;
	cout << salaDodatkowaWieksza << endl;	
	szkola4 = szkola4 + salaDodatkowaMniejsza;	//sprawdzenie operatora+ i przypisania=
	szkola4 = szkola4 + salaDodatkowaWieksza;
	szkola4.wyswietlInfoOSzkole();
	cout << endl << "Liczba szkol do tej pory: " << szkola3.liczbaMoichSzkol() << endl;
	
	cin.get();
	system("cls");
	
	cout <<  "*** obiekt dynamiczny ***" << endl << endl;
	Szkola *szkola5;
	szkola5 = new Szkola("Liceum", 2);
	szkola5->wyswietlInfoOSzkole();	
	if (*szkola5 > szkola4) {					//operator >
		cout << "ta szkola jest wieksza od poprzedniej" << endl;
		int liczbaUczniow = int(szkola5);
		cout << "uczy sie w niej " << liczbaUczniow << " uczniow" << endl;	//operator konwersji int(szkola) to liczba uczniow w tej szkole
	}
	else {
		cout << "ta szkola nie jest wieksza od poprzedniej" << endl;
		int liczbaUczniow = int(szkola4);
		cout << "w tamtej uczy sie " << liczbaUczniow << " uczniow" << endl;
	}

	if (szkola5 != NULL)
	{
		delete szkola5;
	}

	cin.get();
	system("cls");
	cout << "*** i jeszcze kilka operatorow***" << endl;
	cout << "SEKRETARIAT" << endl;
	Sekretariat sekretariat;
	sekretariat.dodatkowePomieszczenieDlaVice();
	sekretariat[3];			//operator []
	sekretariat[1];
	sekretariat[5];
	sekretariat.dodatkowePomieszczenieDlaVice();
	cout <<endl<< "BIBLIOTEKA - zmiana pietra i proba dodania jej do szkoly" << endl;
	Biblioteka biblioteka;
	biblioteka ^ 2;		//operator^ - umieszczenie biblioteki na innym pietrze
	biblioteka.wyswietlZawartosc();
	Szkola szkola6;
	szkola6 = szkola6 + biblioteka;		//operator+ dla biblioteki
		
}

void testOperatorow() {
	cout <<endl<< "OPERATORY ZWIAZANE Z KLASA SALA" << endl;
	cout << " operator++ i -- -> zmiana liczby lawek (i odpowiednio krzesel) w sali" << endl;
	Sala salaWieksza;
	Sala salaMniejsza;
	++salaWieksza;
	--salaMniejsza;

	cout << "operator strumieniowy <<" << endl;
	cout << salaWieksza << endl;
	cout << salaMniejsza << endl;


	cout << endl << "OPERATORY ZWIAZANE Z KLASA SZKOLA" << endl;
	cout << "Dodawanie sali do szkoly - operator+ oraz operator=" << endl;
	Szkola szkolaTestOperatora1;
	szkolaTestOperatora1 = szkolaTestOperatora1 + salaWieksza;
	szkolaTestOperatora1.wyswietlInfoOSzkole();

	cout << "operator!- jesli szkola to gimnazjum, jest zamieniana na liceum (bo gimnazja sa likwidowane)" << endl;
	Szkola szkolaTestOperatora2("Gimnazjum", 2);
	szkolaTestOperatora2 = !szkolaTestOperatora2;
	szkolaTestOperatora2.wyswietlInfoOSzkole();
	Szkola szkolaTestOperatora3("Liceum", 3);
	szkolaTestOperatora3 = !szkolaTestOperatora3;

	cout << "Operator konwersji - zwraca liczbe uczniow w szkole" << endl;
	int liczbaUczniow = int(szkolaTestOperatora3);
	cout << "w tej szkole jest " << liczbaUczniow << " uczniow" << endl;

	cout<<"Operator > - ktora szkola jest wieksza?"<<endl;
	Sala sala;
	szkolaTestOperatora3 = szkolaTestOperatora3 + sala;
	Szkola szkolaTestOperatora4;
	if (szkolaTestOperatora3 > szkolaTestOperatora4) {
		cout << "pierwsza szkola jest wieksza" << endl;
	}
	else {
		cout << "pierwsza szkola nie jest wieksza" << endl;
	}
	
	cout << endl << "OPERATORY ZWIAZANE Z KLASA SEKRETARIAT" << endl;
	cout << "operator[] -numeracja pomieszczen w sekretariacie" << endl;
	Sekretariat sekretariatTestOperatora1;
	sekretariatTestOperatora1[1];

	cout << endl << "OPERATOR ZWIAZANY Z KLASA BIBLIOTEKA" << endl;
	cout << "operator ^ - przenoszenie bibliteki na n-te pietro" << endl;
	Biblioteka biblioteka;
	biblioteka = biblioteka ^ 3;
	biblioteka.wyswietlZawartosc();
}

int main()
{
	testObiektow();

#ifdef _DEBUG
	cin.get();
	system("cls");
	testOperatorow();
#endif // _DEBUG


	return 0;
}

