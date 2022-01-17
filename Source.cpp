#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//Mat Cj Prg Nj Aj

class Student {
private:
	string jmeno;
	int rocnik;
	string predmet;
public:
	Student() {}
	Student(string jmeno, int rocnik, string predmet) {
		this->jmeno = jmeno;
		this->rocnik = rocnik;
		this->predmet = predmet;
	}
	string dejJmeno() { return jmeno; }
	int dejRocnik() { return rocnik; }
	string dejPredmet() { return predmet; }
};

class Skola {
private:
	Student* studenti;
	int pocet;
	int velikost;
	bool zmena;
public:
	Skola() {}
	Skola(string soubor) {
		pocet = 0;
		zmena = false;
		ifstream cteni(soubor);
		if (cteni.fail()) {
			cout << "chyba cteni souboru..." << endl;
			system("pause");
			exit(1);
		}
		string j, p;
		int r;
		while (cteni >> j >> r >> p) {
			pocet++;
		}
		cteni.clear();
		cteni.seekg(0);
		velikost = pocet + 3;
		studenti = new Student[velikost];
		for (int i = 0; i < pocet; i++) {
			cteni >> j >> r >> p;
			studenti[i] = Student(j, r, p);
		}
		cteni.close();
	}
	void vypisVse() {
		cout << "---------------------------------------------------------" << endl;
		for (int i = 0; i < pocet; i++) {
			cout << i + 1 << " - " << studenti[i].dejJmeno() << ", " << studenti[i].dejRocnik() << ". rocnik, predmet: " << studenti[i].dejPredmet() << endl;
		}
		cout << "---------------------------------------------------------" << endl;
	}
	void pridejStudenta() {
		zmena = true;
		string j, p;
		int r;
		cout << "zadej jmeno noveho studenta: ";
		cin >> j;
		cout << "zadej rocnik studenta: ";
		cin >> r;
		if (r == 1 || r == 2 || r == 3 || r == 4) {
			cout << "zadej doucovany predmet: ";
			cout << "Cj, Aj, Nj, Mat, Prg" << endl;
			cin >> p;
			if (p == "Mat" || p == "Aj" || p == "Cj" || p == "Prg" || p == "Nj") {
				if (pocet == velikost) {
					Student* pPole = new Student[pocet];
					for (int i = 0; i < pocet; i++) {
						pPole[i] = studenti[i];
					}
					delete[]studenti;
					velikost += 3;
					studenti = new Student[velikost];
					for (int i = 0; i < pocet; i++) {
						studenti[i] = pPole[i];
					}
					delete[]pPole;
				}
				pocet++;
				studenti[pocet - 1] = Student(j, r, p);
			}
			else {
				cout << "Spatne zadany doucovaci predmet";
				system("pause");
				exit(1);
			}
		}
		else {
			cout << "Spatne zadany rocnik";
			system("pause");
			exit(1);
		}
	}
	void smazatStudenta() {
		zmena = true;
		vypisVse();
		cout << "vyber studenta ke smazani, zadej cislo: ";
		int cislo;
		cin >> cislo;
		cislo--;
		pocet--;
		for (int i = cislo; i < pocet; i++) {
			studenti[i] = studenti[i + 1];
		}
	}
	void aktualizace() {
		if (zmena) {
			ofstream zapis("studenti.txt");
			for (int i = 0; i < pocet; i++) {
				zapis << studenti[i].dejJmeno() << " " << studenti[i].dejRocnik() << " " << studenti[i].dejPredmet() << endl;
			}
			zapis.close();
			cout << "byla provedena aktualizace..." << endl;
			system("pause");
		}
	}
	void vypisMatiky() {

		cout << " MATEMATIKA " << endl;
		for (int i = 0; i < velikost; i++)
		{
			if (studenti[i].dejPredmet() == "Mat") {
				cout << studenti[i].dejJmeno() << " " << studenti[i].dejRocnik()
					<< " " << studenti[i].dejPredmet() << endl;
			}


		}
		cout << endl;
	}
	void vypisNemciny() {

		cout << " NEMCINA " << endl;
		for (int i = 0; i < velikost; i++)
		{
			if (studenti[i].dejPredmet() == "Nj") {
				cout << studenti[i].dejJmeno() << " " << studenti[i].dejRocnik()
					<< " " << studenti[i].dejPredmet() << endl;
			}


		}
		cout << endl;
	}

	void vypisCestiny() {

		cout << " Cestiny " << endl;
		for (int i = 0; i < velikost; i++)
		{
			if (studenti[i].dejPredmet() == "Cj") {
				cout << studenti[i].dejJmeno() << " " << studenti[i].dejRocnik()
					<< " " << studenti[i].dejPredmet() << endl;
			}


		}
		cout << endl;
	}

	void vypisProgramovani() {

		cout << " PROGRAMOVANI " << endl;
		for (int i = 0; i < velikost; i++)
		{
			if (studenti[i].dejPredmet() == "Prg") {
				cout << studenti[i].dejJmeno() << " " << studenti[i].dejRocnik()
					<< " " << studenti[i].dejPredmet() << endl;
			}


		}
		cout << endl;
	}
	void vypisAnglictina() {

		cout << " ANGLICKYJAZYK " << endl;
		for (int i = 0; i < velikost; i++)
		{
			if (studenti[i].dejPredmet() == "Aj") {
				cout << studenti[i].dejJmeno() << " " << studenti[i].dejRocnik()
					<< " " << studenti[i].dejPredmet() << endl;
			}


		}
		cout << endl;
	}


};

int main() {
	Skola stredni("studenti.txt");
	int volba, volba2;

	do {
		system("cls");
		cout << "E V I D E N C E   S T U D E N T U" << endl << endl;
		cout << "Ovladani programu:" << endl;
		cout << "  1 - Vypis vsech studentu" << endl;
		cout << "  2 - Pridani noveho studenta" << endl;
		cout << "  3 - Smazani studenta" << endl;
		cout << "  4 - Menu doucovanych predmetu" << endl;
		cout << "  5 - Konec programu" << endl << endl;
		cout << "zadej volbu z menu: ";
		cin >> volba;

		system("cls");
		switch (volba) {
		case 1:
			cout << "Vypis vsech studentu" << endl << endl;
			stredni.vypisVse();
			system("pause");
			break;
		case 2:
			cout << "Pridani noveho studenta" << endl << endl;
			stredni.pridejStudenta();
			cout << "Vyber si z predmetu Cj, Mat, Prg, Nj, Aj" << endl;
			break;
		case 3:
			cout << "Smazani studenta" << endl << endl;
			stredni.smazatStudenta();
			break;
		case 4:
			//------------------------------------------------------------------------
			do {
				cout << "Menu doucovanych predmetu" << endl << endl;
				cout << "podmenu programu:" << endl;
				cout << "   1 - Cesky Jazyk" << endl;
				cout << "   2 - Matematika" << endl;
				cout << "   3 - Programovani" << endl;
				cout << "   4 - Nemcina" << endl;
				cout << "   5 - Anglictina" << endl;
				cout << "   6 - Vratit se zpet do menu" << endl << endl;

				cout << "zadej volbu [1-X]: ";
				cin >> volba2;

				system("cls");
				switch (volba2) {
				case 1:
					stredni.vypisCestiny();
					break;
				case 2:
					stredni.vypisMatiky();
					break;
				case 3:
					stredni.vypisProgramovani();
					break;
				case 4:
					stredni.vypisNemciny();
				case 5:
					stredni.vypisAnglictina();
					break;
				case 6:
					stredni.aktualizace();
					break;
				}

			} while (volba2 != 6);
			break;
		case 5:
			cout << "Ukonceni programu..." << endl;
			stredni.aktualizace();
			break;
		}
	} while (volba != 5);

	return 0;
}