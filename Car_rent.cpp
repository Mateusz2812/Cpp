#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

class Car
{
private:
	string _marka;
	string _model;
	string _liczba_miejsc;
	string _typ;			//typ nadwozia
	string _cena;			//cena za dobę
	string _start;		//data poczatku najmu
	string _stop;			//konec najmu
	string _paliwo;			//rodzaj paliwa
	string _imiona;
	string _nazwiska;		//dane osob wypozyczajacych

public:
	Car(string marka, string model, string liczba_miejsc, string typ, string cena, string start, string stop, string paliwo, string imiona, string nazwiska) : _marka{ marka }, _model{ model }, _liczba_miejsc{ liczba_miejsc }, _typ{ typ }, _cena{ cena }, _start{ start }, _stop{ stop }, _paliwo{ paliwo }, _imiona{ imiona }, _nazwiska{ nazwiska }{ }

	string get_marka(void) { return _marka; }
	string get_model(void) { return _model; }
	string get_liczba_miejsc(void) { return _liczba_miejsc; }
	string get_typ(void) { return _typ; }
	string get_cena(void) { return _cena; }
	string get_start(void) { return _start; }
	string get_stop(void) { return _stop; }
	string get_paliwo(void) { return _paliwo; }
	string get_imiona(void) { return _imiona; }
	string get_nazwiska(void) { return _nazwiska; }

	void set_start(string start) { _start = start; }
	void set_stop(string stop) { _stop = stop; }
	void set_cena(string cena) { _cena = cena; }
	void set_imie(string imiona) { _imiona = imiona; }
	void set_nazwisko(string nazwiska) { _nazwiska = nazwiska; }

	void rezerwuj(string start, string stop, string imie, string nazwisko)		//dodaje rezerwacje
	{
		_start += start;
		_stop += stop;
		
		_imiona += imie;
		_imiona += '_';
		
		_nazwiska += nazwisko;
		_nazwiska += '_';
	}
};

void wczytaj(vector<Car>& L) //wczytuje dane z plików do programu
{
	fstream Model;
	fstream Marka;
	fstream Liczba_miejsc;
	fstream Typ;
	fstream Cena;
	fstream Start;
	fstream Stop;
	fstream Paliwo;
	fstream Imie;
	fstream Nazwisko;


	Model.open("model.txt", ios::in);
	Marka.open("marka.txt", ios::in);
	Liczba_miejsc.open("liczba_miejsc.txt", ios::in);
	Typ.open("typ.txt", ios::in);
	Cena.open("cena.txt", ios::in);
	Start.open("start.txt", ios::in);
	Stop.open("stop.txt", ios::in);
	Paliwo.open("paliwo.txt", ios::in);
	Imie.open("imie.txt", ios::in);
	Nazwisko.open("nazwisko.txt", ios::in);

	if (Model.good() == false || Marka.good() == false || Liczba_miejsc.good() == false || Typ.good() == false || Cena.good() == false || Start.good() == false || Stop.good() == false || Paliwo.good() == false || Imie.good() == false || Nazwisko.good() == false)
	{
		cout << "Operacja nie powiodla sie!";
		return;
	}

	string marka;
	string model;
	string liczba_miejsc;
	string typ;			//typ nadwozia
	string cena;			//cena za dobę
	string start;		//data poczatku najmu
	string stop;			//konec najmu
	string paliwo;		//rodzaj paliwa
	string imie;			
	string nazwisko;

	while (!Marka.eof())
	{
		getline(Marka, marka);
		getline(Model, model);
		getline(Liczba_miejsc, liczba_miejsc);
		getline(Typ, typ);
		getline(Cena, cena);
		getline(Start, start);
		getline(Stop, stop);
		getline(Paliwo, paliwo);
		getline(Imie, imie);
		getline(Nazwisko, nazwisko);


		L.push_back(Car(marka, model, liczba_miejsc, typ, cena, start, stop, paliwo, imie, nazwisko));

	};

	Marka.close();
	Model.close();
	Liczba_miejsc.close();
	Typ.close();
	Cena.close();
	Start.close();
	Stop.close();
	Paliwo.close();
	Imie.close();
	Nazwisko.close();
}

void zapisz(vector<Car>& L) //zapisuje wszystkie samochody do plików
{
	if (L.size() == 0)return;
	fstream Model;
	fstream Marka;
	fstream Liczba_miejsc;
	fstream Typ;
	fstream Cena;
	fstream Start;
	fstream Stop;
	fstream Paliwo;
	fstream Imie;
	fstream Nazwisko;


	Model.open("model.txt", ios::out);
	Marka.open("marka.txt", ios::out);
	Liczba_miejsc.open("liczba_miejsc.txt", ios::out);
	Typ.open("typ.txt", ios::out);
	Cena.open("cena.txt", ios::out);
	Start.open("start.txt", ios::out);
	Stop.open("stop.txt", ios::out);
	Paliwo.open("paliwo.txt", ios::out);
	Imie.open("imie.txt", ios::out);
	Nazwisko.open("nazwisko.txt", ios::out);


	if (Model.good() == false || Marka.good() == false || Liczba_miejsc.good() == false || Typ.good() == false || Cena.good() == false || Start.good() == false || Stop.good() == false || Paliwo.good() == false || Imie.good() == false || Nazwisko.good() == false)
	{
		cout << "Operacja nie powiodla sie!";
		return;
	}

	for (size_t i = 0; i < L.size() - 1; ++i)
	{
		Model << L[i].get_model() << endl;
		Marka << L[i].get_marka() << endl;
		Liczba_miejsc << L[i].get_liczba_miejsc() << endl;
		Typ << L[i].get_typ() << endl; 
		Cena << L[i].get_cena() << endl;
		Start << L[i].get_start() << endl;
		Stop << L[i].get_stop() << endl;
		Paliwo << L[i].get_paliwo() << endl;
		Imie << L[i].get_imiona() << endl;
		Nazwisko << L[i].get_nazwiska() << endl;
	}
	Model << L[L.size() - 1].get_model();
	Marka << L[L.size() - 1].get_marka();
	Liczba_miejsc << L[L.size() - 1].get_liczba_miejsc();
	Typ << L[L.size() - 1].get_typ();
	Cena << L[L.size() - 1].get_cena();
	Start << L[L.size() - 1].get_start();
	Stop << L[L.size() - 1].get_stop();
	Paliwo << L[L.size() - 1].get_paliwo();
	Imie << L[L.size() - 1].get_imiona() << endl;
	Nazwisko << L[L.size() - 1].get_nazwiska() << endl;

	Marka.close();
	Model.close();
	Liczba_miejsc.close();
	Typ.close();
	Cena.close();
	Start.close();
	Stop.close();
	Paliwo.close();
	Imie.close();
	Nazwisko.close();
}

void wyswietl(int nr_auta, vector<Car> L) //wyswietla jeden wybrany samochod
{
	nr_auta--;
	system("cls");
	cout << "Marka:\t\t\t";
	cout << L[nr_auta].get_marka() << endl;
	cout << "Model:\t\t\t";
	cout << L[nr_auta].get_model() << endl;
	cout << "Typ samochodu:\t\t";
	cout << L[nr_auta].get_typ() << endl;
	cout << "Liczba miejsc:\t\t";
	cout << L[nr_auta].get_liczba_miejsc() << endl;
	cout << "Paliwo:\t\t\t";
	cout << L[nr_auta].get_paliwo() << endl;
	cout << "Cena za dobe:\t\t";
	cout << L[nr_auta].get_cena() << endl;
}

void terminy(int nr, vector<Car> L)		//wyswietla terminy rezerwacji jednego auta
{
	nr--;
	if (L[nr].get_start() == "00000000")
	{
		cout << "\tBrak rezerwacji\n";
		return;
	}
	string start = L[nr].get_start();
	string stop = L[nr].get_stop();
	stringstream imiona;
	stringstream nazwiska;
	imiona << L[nr].get_imiona();
	nazwiska << L[nr].get_nazwiska();
	string aaa;
	vector<string>Imiona;
	vector<string>Nazwiska;

	while (getline(imiona, aaa, '_'))
	{
		Imiona.push_back(aaa);
	}
	while (getline(nazwiska, aaa, '_'))
	{
		Nazwiska.push_back(aaa);
	}

	

	int l = L[nr].get_start().length();
	cout << "-------------------------------------------------\n";
	cout << "|\t\tTERMINY REZERWACJI\t\t|\n";
	cout << "-------------------------------------------------\n";
	cout << "|\tOd\t\t|\tDo\t\t|\n";
	cout << "-------------------------------------------------\n";
	for (int i = 0; i < l / 8; i++)
	{
		cout << "|\t";
		cout << start[i * 8 + 6] << start[i * 8 + 7] << "." << start[i * 8 + 4] << start[i * 8 + 5] << "." << start[i * 8] << start[i * 8 + 1] << start[i * 8 + 2] << start[i * 8 + 3];
		cout << "\t|\t";
		cout << stop[i * 8 + 6] << stop[i * 8 + 7] << "." << stop[i * 8 + 4] << stop[i * 8 + 5] << "." << stop[i * 8] << stop[i * 8 + 1] << stop[i * 8 + 2] << stop[i * 8 + 3] ;
		cout << "\t|\t" << Imiona[i] << "\t" << Nazwiska[i] << "\n-------------------------------------------------\n";
	}
}

bool dostepny( string ustart, string ustop, string start, string stop)
{
	int l = start.length();
	
	for (int i = 0; i < l / 8; i++)
	{
		string nowy;
		for (int j = 0; j < 8; j++)
		{
			nowy += start[j + (i * 8)];
		}
		string nowy2;
		for (int j = 0; j < 8; j++)
		{
			nowy2 += stop[j + (i * 8)];
		}

		if ((ustart <= nowy2 && ustart >= nowy) || (ustop <= nowy2 && ustop >= nowy)) return false;
	}
	return true;
}

float cena_najmu(string cena, string start, string stop)		//oblicza calkowity koszt najmu
{
	stringstream cn(cena);
	stringstream st(start);
	stringstream sp(stop);

	float f_cena, f_start, f_stop;

	cn >> f_cena;
	st >> f_start;
	sp >> f_stop;

	return f_cena * (f_stop - f_start + 1);
}

bool cena_sort(Car a, Car b)
{
	return a.get_cena() < b.get_cena();
}

void sortuj(vector<Car>& L)		//sortuje auta wg ceny
{
	sort(L.begin(), L.end(), cena_sort);
}

void samochody(vector<Car> L)	// wyswietla samochody
{
	system("cls");
	for (size_t i = 0; i < L.size(); ++i)
	{
		cout << "------------------------------------------------------------------------\n";
		cout << i + 1 << "." << L[i].get_marka();
		if (L[i].get_marka().length() < 6) cout << "\t\t";
		else cout << "\t";
		cout << L[i].get_model();
		if (L[i].get_model().length() < 8) cout << "\t\t";
		else cout << "\t";
		cout << L[i].get_typ();
		if (L[i].get_typ().length() < 8) cout << "\t\t";
		else cout << "\t";
		
		cout << "l.miejsc: " << L[i].get_liczba_miejsc() << "\t" << L[i].get_cena() << "zl/dobe" << endl;
	}
	cout << "------------------------------------------------------------------------\n";
}

void nowy_samochod(vector<Car>& L) //dodaje nowy samochod do wektora
{
	system("cls");
	cin.get();

	cout << "Marka:\t";
	string Marka;
	getline(cin, Marka);

	cout << "Model:\t";
	string Model;
	getline(cin, Model);

	cout << "Typ nadwozia:\t";
	string Typ;
	getline(cin, Typ);

	cout << "Liczba miejsc:\t";
	string Miejsca;
	getline(cin, Miejsca);

	cout << "Cena za dobę:\t";
	string Cena;
	getline(cin, Cena);

	cout << "Rodzaj paliwa:\t";
	string Paliwo;
	getline(cin, Paliwo);

	bool blad;
	do
	{
		cout << "Dodaj samochod --> 1\t";
		cout << "Anuluj --> 2\n";
		int wybor;
		//cin >> wybor;
		while (!(cin >> wybor)) //dopóki strumień jest w stanie błędu -> dopóki podawane są błędne dane
		{
			cout << "BLAD!!! Wybierz numer opcji!\n";
			cin.clear(); //kasowanie flagi błędu strumienia
			cin.sync(); //kasowanie zbędnych znaków z bufora
			cin.ignore(1000, '\n');

		}
		switch (wybor)
		{
		case 1:
			blad = false;
			L.push_back( Car(Marka, Model, Miejsca, Typ, Cena, "00000000", "00000000", Paliwo, "0", "0"));   //dodawanie nowego samochodu
			zapisz(L);
			cout << "Dodano nowy samochod do bazy." << endl;
			system("pause");
			break;
		case 2:
			blad = false;
			break;
		default:
			cout << "Wybrana opcja nie instnieje. Wybierz jeszcze raz\n";
			blad = true;
			break;
		}
	} while (blad);

}

void usun(int nr_samochodu, vector<Car>& L) //usuwa wybrany samochod z wektora
{
	nr_samochodu--;
	L.erase(L.begin() + nr_samochodu);
}

void edytuj_cene(int nr, vector<Car>& L)		//edytuje cene samochodu
{
	system("cls");
	string cena;
	cin.get();
	cout << "Podaj nowa cene za dobe: ";
	getline(cin, cena);
	L[nr - 1].set_cena( cena );

	cout << "Zapisano.\n";
	system("break");

}

void menu_gl()
{
	system("cls");
	cout << "  WYPOZYCZALNIA SAMOCHODOW\n";
	cout << "--------------MENU--------------\n";
	cout << "1. Wypozycz samochod \n";
	cout << "2. Nasze samochody \n";
	cout << "3. Wyjdz\n";
	cout << "--------------------------------\n";
	cout << "4. Opcje administratora\n";
	cout << "--------------------------------\n\n";
}

void wypozycz_samochod(vector<Car>&L)
{
	if (L.size() == 0)
	{
		cout << "Chwilowy brak samochodow w systemie. Przepraszamy za niedogodnosci.\n";
		system("pause");
		return;
	}
	string start, stop, r, m, d, imie, nazwisko;
	int data;
	bool blad = false;
	vector<int> mapa;
	
	system("cls");
	cout << "Podaj date poczatku najmu:\n";
	cout << "Rok (RRRR):\t";

	while (!(cin >> data) || data < 2020 || data > 2030) //dopóki strumień jest w stanie błędu -> dopóki podawane są błędne dane
	{
		cout << "Podaj rok w formacie RRRR!!!:\t";
		cin.clear(); //kasowanie flagi błędu strumienia
		cin.sync(); //kasowanie zbędnych znaków z bufora
		cin.ignore(1000, '\n');
	}
	r = to_string(data);
	
	cout << "Nr Miesiaca:\t";
	
	while (!(cin >> data) || data < 1 || data > 12) //dopóki strumień jest w stanie błędu -> dopóki podawane są błędne dane
	{
		cout << "Podaj numer miesiaca!!!:\t";
		cin.clear(); //kasowanie flagi błędu strumienia
		cin.sync(); //kasowanie zbędnych znaków z bufora
		cin.ignore(1000, '\n');
	}
	if(data<10) m = "0" + to_string(data);
	else m = to_string(data);

	cout << "Dzien :\t";
	while (!(cin >> data) || data < 1 || data > 31) //dopóki strumień jest w stanie błędu -> dopóki podawane są błędne dane
	{
		cout << "Podaj numer dnia miesiaca!!!:\t";
		cin.clear(); //kasowanie flagi błędu strumienia
		cin.sync(); //kasowanie zbędnych znaków z bufora
		cin.ignore(1000, '\n');
	}
	if (data < 10) d = "0" + to_string(data);
	else d = to_string(data);
	start = r + m + d;

	cout << "Podaj date konca najmu:\n";
	cout << "Rok (RRRR):\t";
	while (!(cin >> data) || data < 2020 || data > 2030) //dopóki strumień jest w stanie błędu -> dopóki podawane są błędne dane
	{
		cout << "Podaj rok w formacie RRRR!!!:\t";
		cin.clear(); //kasowanie flagi błędu strumienia
		cin.sync(); //kasowanie zbędnych znaków z bufora
		cin.ignore(1000, '\n');
	}
	r = to_string(data);
	cout << "Nr Miesiaca:\t";
	while (!(cin >> data) || data < 1 || data > 12) //dopóki strumień jest w stanie błędu -> dopóki podawane są błędne dane
	{
		cout << "Podaj numer miesiaca!!!:\t";
		cin.clear(); //kasowanie flagi błędu strumienia
		cin.sync(); //kasowanie zbędnych znaków z bufora
		cin.ignore(1000, '\n');
	}
	if (data < 10) m = "0" + to_string(data);
	else m = to_string(data);
	cout << "Dzien :\t";
	while (!(cin >> data) || data < 1 || data > 31) //dopóki strumień jest w stanie błędu -> dopóki podawane są błędne dane
	{
		cout << "Podaj numer dnia miesiaca!!!:\t";
		cin.clear(); //kasowanie flagi błędu strumienia
		cin.sync(); //kasowanie zbędnych znaków z bufora
		cin.ignore(1000, '\n');
	}
	if (data < 10) d = "0" + to_string(data);
	else d = to_string(data);
	stop = r + m + d;

	cout << "Podaj imie:\n";
	cin >> imie;
	cout << "Podaj nazwisko:\n";
	cin >> nazwisko;

	if (start > stop)
	{
		cout << "Data odbioru nie moze byc po dacie zwrotu!!!\n";
		system("pause");
		return;
	}

	vector<Car>L2;
	for (size_t i = 0; i < L.size(); i++)
	{
		if (dostepny(start, stop, L[i].get_start(), L[i].get_stop()))
		{
			L2.push_back(L[i]);
			mapa.push_back(i);
		}
		else if (L[i].get_start() == "00000000")
		{
			L2.push_back(L[i]);
			mapa.push_back(i);
		}
	}

	do
	{
		system("cls");

		if (L2.size() == 0)
		{
			cout << "BRAK DOSTEPNYCH SAMOCHODOW W WYBRANYM TERMINIE\n";
			system("pause");
			//return;
		}
		samochody(L2);			//wyswietla dostepne samochody od najtanszego

		cout << "1.Wybierz samochod\t|\n" << "2.Wstecz\t\t|\n";
		cout << "------------------------\n";

		int wybor;
		cin >> wybor;
		switch (wybor)
		{
		case 1:
			cout << "Podaj numer samochodu: ";
			while (!(cin >> wybor)) //dopóki strumień jest w stanie błędu -> dopóki podawane są błędne dane
			{
				cout << "BLAD!!! Wybierz numer samochodu!\n";
				cin.clear(); //kasowanie flagi błędu strumienia
				cin.sync(); //kasowanie zbędnych znaków z bufora
				cin.ignore(1000, '\n');
			}

			if (wybor <= L2.size() && wybor > 0)
			{
				wyswietl(wybor, L2);
				cout << "------------------------\n";
				cout << "1.REZERWUJ\t\t|\n" << "2.Wstecz\t\t|\n";
				cout << "------------------------\n";
				int wybor2;
				while (!(cin >> wybor2)) //dopóki strumień jest w stanie błędu -> dopóki podawane są błędne dane
				{
					cout << "BLAD!!! Wybierz numer opcji!\n";
					cin.clear(); //kasowanie flagi błędu strumienia
					cin.sync(); //kasowanie zbędnych znaków z bufora
					cin.ignore(1000, '\n');
				}
				if (wybor2 == 1)
				{
					if (L[mapa[wybor - 1]].get_start() == "00000000")
					{
						L[mapa[wybor - 1]].set_start("");
						L[mapa[wybor - 1]].set_stop("");
						L[mapa[wybor - 1]].set_imie("");
						L[mapa[wybor - 1]].set_nazwisko("");

					}
					L[mapa[wybor - 1]].rezerwuj(start, stop, imie, nazwisko);
					blad = false;
					system("cls");
					cout << "\t\tZAREZERWOWANO!\n";
					zapisz(L);
					system("pause");
				}
				else
				{
					blad = true;
				}

			}
			else blad = true;
			break;
		case 2:
			blad = false;
			break;

		default:
			cout << "Wybrana opcja nie istnieje!";
			blad = true;
			break;
		}
	} while (blad);
	


}

void admin(vector<Car>& L)
{
	bool blad = true;
	int wybor;
	do
	{
		samochody(L);
		cout << "1.Edytuj cene samochodu\t|\n" << "2.Dodaj samochod\t|\n" << "3.Usun samochod\t\t|\n" << "4.Wroc\t\t\t|\n";
		cout << "------------------------\n";
		

		while (!(cin >> wybor)) //dopóki strumień jest w stanie błędu -> dopóki podawane są błędne dane
		{
			cout << "BLAD!!! Wybierz numer opcji!\n";
			cin.clear(); //kasowanie flagi błędu strumienia
			cin.sync(); //kasowanie zbędnych znaków z bufora
			cin.ignore(1000, '\n');
		}

		switch (wybor)
		{
		case 1:
			cout << "wybierz numer samochodu:\t";
			while (!(cin >> wybor)) //dopóki strumień jest w stanie błędu -> dopóki podawane są błędne dane
			{
				cout << "BLAD!!! Wybierz numer samochodu!\n";
				cin.clear(); //kasowanie flagi błędu strumienia
				cin.sync(); //kasowanie zbędnych znaków z bufora
				cin.ignore(1000, '\n');
			}

			if (wybor <= L.size() && wybor>0)
			{
				edytuj_cene(wybor, L);
				zapisz(L);
			}
			else cout << "Ten samochod nie istnieje!\n";
			system("pause");
			break;

		case 2:
			nowy_samochod(L);
			sortuj(L);
			zapisz(L);
			break;
		case 3:
			cout << "wybierz numer samochodu:\t";
			while (!(cin >> wybor)) //dopóki strumień jest w stanie błędu -> dopóki podawane są błędne dane
			{
				cout << "BLAD!!! Wybierz numer samochodu!\n";
				cin.clear(); //kasowanie flagi błędu strumienia
				cin.sync(); //kasowanie zbędnych znaków z bufora
				cin.ignore(1000, '\n');
			}

			if (wybor <= L.size() && wybor > 0)
			{
				usun(wybor, L);
				zapisz(L);
			}
			else cout << "Ten samochod nie istnieje!\n";
			system("pause");
			break;
		case 4:
			blad = false;
			break;
		default:
			break;
		}
	} while (blad);

}

int main()
{
	vector<Car>L;
	
	wczytaj(L);
	sortuj(L);
	int wybor;
	bool wyl = false;
	bool w = true;
	string haslo;
	do
	{
		menu_gl();
		while (!(cin >> wybor)) //dopóki strumień jest w stanie błędu -> dopóki podawane są błędne dane
		{
			cout << "BLAD!!! Wybierz numer opcji!\n";
			cin.clear(); //kasowanie flagi błędu strumienia
			cin.sync(); //kasowanie zbędnych znaków z bufora
			cin.ignore(1000, '\n');
		}

		switch (wybor)
		{
		case 1:
			wypozycz_samochod(L);
			break;
		case 2:			
			do
			{
				samochody(L);
				cout << "1.Wybierz samochod\t|\n" << "2.Wstecz\t\t|\n";
				cout << "------------------------\n";

				while (!(cin >> wybor) || (wybor != 1 && wybor != 2)) //dopóki strumień jest w stanie błędu -> dopóki podawane są błędne dane
				{
					cout << "BLAD!!! Wybierz numer opcji!\n";
					cin.clear(); //kasowanie flagi błędu strumienia
					cin.sync(); //kasowanie zbędnych znaków z bufora
					cin.ignore(1000, '\n');
				}
				if (wybor == 1)
				{
					int wybor2;
					cout << "Podaj numer samochodu: ";
					while (!(cin >> wybor2)) //dopóki strumień jest w stanie błędu -> dopóki podawane są błędne dane
					{
						cout << "BLAD!!! Wybierz numer samochodu!\n";
						cin.clear(); //kasowanie flagi błędu strumienia
						cin.sync(); //kasowanie zbędnych znaków z bufora
						cin.ignore(1000, '\n');
					}

					if (wybor2 <= L.size() && wybor2 > 0)
					{
						wyswietl(wybor2, L);	
						terminy(wybor2, L);
					}
					else cout << "Ten samochod nie istnieje!\n";
					system("pause");
				}
				else w = false;
			} while (w);
			break;

		case 3:
			wyl = true;
			break;
		case 4:
			system("cls");
			cout << "Podaj haslo:\t";
			cin >> haslo;
			if (haslo == "admin") admin(L);
			else
			{
				cout << "Niepoprawne haslo!\n";
				system("pause");
			}
			break;
		default:
			break;
		}

	} while (!wyl);
	zapisz(L);
}
