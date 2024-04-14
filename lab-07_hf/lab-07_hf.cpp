#include <iostream> 
#include <fstream> 
#include <string> 
#include <ctime>
using namespace std;

struct workors
{
	string name;
	int birth_y;
	int work_h;
	int money;
};

int in_fajl(char* t, workors* tmb);
void birth_year(workors* tmb, int db);
int worked_hours(workors* tmb, int db);


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


int in_fajl(char* t, workors* tmb)
{
	
	ifstream in(t);
	if (in.fail())
	{
		cerr << "Hiba.";
		system("pause");
		exit(1);
	}

	int i = 0;
	int db;
	
	for (i = 0; i < 20 && !in.eof(); i++)
	{
		in >> tmb[i].name;
		db++;
		/*cin >> db;
		int* tmb = new int[db];
		if (tmb == NULL)
		{
			cout << "Hiba: keves memoria";
			system("pause");
			return 1;
		}
		delete[] tmb;*/
		cout << tmb[i].name << endl;

	}
	in.close();
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

