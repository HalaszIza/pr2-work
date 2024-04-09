#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

struct dolgozok
{
	string nev;
	int szul_ev;
	int dolg_ora;
	int fizetes;
};

int beolvas(char* t, dolgozok* tmb);
int szuletesi_ev(dolgozok* tmb, int db); // void
int dolgozott_orak(dolgozok* tmb, int db);
 

int main()
{
	
	char fajl[] = "majus.txt";
	dolgozok adatok[20];
	int i = 0;
	srand((unsigned)time(NULL));

	int dolgozok_db = beolvas(fajl, adatok);
	cout << dolgozok_db << " fo dolgozott majusban." << endl;

	cout << endl << szuletesi_ev(adatok, dolgozok_db) << endl;

}

int beolvas(char* t, dolgozok* tmb)
{
	ifstream be(t);
	if (be.fail())
	{
		cerr << "Hiba.";
		system("pause");
		exit(1);
	}

	int i = 0;
	int db = 0;
	for (i = 0; i < 20 && !be.eof(); i++)
	{
		be >> tmb[i].nev;
		db++;
		cout << tmb[i].nev << endl;
	}
	be.close();
	return db;

}

int szuletesi_ev(dolgozok* tmb, int db)
{
	int i = 0;
	 

	do 
	{
		cout << "Adja meg szuletesi evet : (1957 - 2004)";
		cin >> tmb[i].szul_ev;
		cin.ignore();
		if (tmb[i].szul_ev < 1957 || tmb[i].szul_ev > 2004)
		{
			cout << "Hibas adat, adja meg ujbol!" << endl;
		}
	} while (tmb[i].szul_ev < 1957 || tmb[i].szul_ev > 2004);

	return tmb[i].szul_ev;

}

int dolgozott_orak(dolgozok* tmb, int db)
{
	int i = 0;

	

}


