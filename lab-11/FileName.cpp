#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

struct jatekos
{
	string nev;
	int szul;
	string poszt;
	int meccs;
	int loves;
	int gol;
};

class Labdarugo
{
	int db;
	jatekos* tmb;

public:
	Labdarugo(string filenev);
	~Labdarugo();
	void kiir();
	int OsszesLoves();
	jatekos LegtobbGol();
	void Fiatalok();
	jatekos* Egyenlo();

};

int main()
{
	string filenev = "jatekosok.txt";
	Labdarugo L(filenev);
	L.kiir();
	cout << endl;

	cout << "Osszes loves szama: " << L.OsszesLoves() << endl;
	cout << endl;

	jatekos legtobbetRugott = L.LegtobbGol();
	cout << "A legtobb golt lott jatekos neve: " << legtobbetRugott.nev << endl;
	cout << endl;

	L.Fiatalok();
	cout << endl;

	jatekos* e = L.Egyenlo();
	cout << e[0].nev << endl;

	return 0;
}


Labdarugo::Labdarugo(string filenev)
{
	ifstream be(filenev);
	if (be.fail())
	{
		cout << "Hibas fajlolvasa!";
		exit(1);
	}

	string sor;
	be >> db;
	tmb = new jatekos[db];

	for (int i = 0; i < db; i++)
	{
		getline(be, tmb[i].nev, ':');

		getline(be, sor, ':');
		tmb[i].szul = stoi(sor);

		getline(be, tmb[i].poszt, ':');

		getline(be, sor, ':');
		tmb[i].meccs = stoi(sor);

		getline(be, sor, ':');
		tmb[i].loves = stoi(sor);

		getline(be, sor);
		tmb[i].gol = stoi(sor);
	}
	be.close();

}

Labdarugo::~Labdarugo()
{
	delete[] tmb;
}

void Labdarugo::kiir()
{
	cout.setf(ios::left);
	cout << setw(12) << "Nev" << setw(8) << "Szul." << setw(10) << "Poszt" << setw(6) << "Meccs" << setw(6) << "Loves" << setw(6) << "Gol" << endl;

	for (int i = 0; i < db; i++)
	{
		cout << setw(12) << tmb[i].nev << setw(8) << tmb[i].szul << setw(10) << tmb[i].poszt << setw(6) << tmb[i].meccs << setw(6) << tmb[i].loves << setw(6) << tmb[i].gol <<endl;
	}

}

int Labdarugo::OsszesLoves()
{
	int szum = 0;
	for (int i = 0; i < db; i++)
	{
		szum += tmb[i].loves;
	}
	return szum;
}

jatekos Labdarugo::LegtobbGol()
{
	int index = 0;
	for (int i = 1; i < db; i++)
	{
		if (tmb[i].gol > tmb[index].gol)		//holtverseny eseten >= �s az utols�t irja ki
		{
			index = i;
		}
	}
	return tmb[index];
}

void Labdarugo::Fiatalok()
{
	int start = 1995;
	for (int i = 0; i < db; i++)
	{
		if (tmb[i].szul >= start)
		{
			cout << "Fiatal: " << tmb[i].nev << ", " << tmb[i].szul << endl;
		}
	}

}

jatekos* Labdarugo::Egyenlo()
{
	int egyenloek = 0;
	jatekos* e = new jatekos[db];
	for (int i = 0; i < db; i++)
	{
		for (int j = 0; j < db; j++)
		{
			if (j != i && tmb[i].gol == tmb[j].gol)
			{
				e[egyenloek] = tmb[i];
				egyenloek++;
			}
		}
	}
	jatekos* e2 = new jatekos[egyenloek];
	for (int i = 0; i < egyenloek; i++)
	{
		e2[i] = e[i];
	}
	return e2;
}



