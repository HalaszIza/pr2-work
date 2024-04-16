#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Teglalap
{
	private: int mag, alap;	// tulajdonságok
	
	public: bool init(int a, int b)
	{
		if (a > 0 && b > 0)
		{
			mag = a;
			alap = b;
			return true;
		}
		cout << "Az alap es magassag nem lehet negativ!" << endl;
		return false;
		
	}

	public: int ter()		// metódusok, számol, értéket ad vissza
	{
		return alap * mag;
	}

	public: int ker()		// metódusok, számol, értéket ad vissza (az osztály függvénye)
	{
		return 2 * (alap + mag);
	}

	public: int getAlap()	//metódus, hogy el lehessen érni a privát adatokat
	{
		return alap;
	}

	public: int getMag()
	{
		return mag;
	}

};

int main()
{
	int old1, old2;
	cout << "Adja meg a teglalap oldalait: " << endl;

	Teglalap t1, t2;		//osztály alapján objektumok
	
	t1.init(5, 10);

	bool inited = false;	// hf: t2 oldalai nem lehetnek negatívak
	while (!inited)
	{
		cin >> old1;
		cin >> old2;
		inited = t2.init(old1, old2);
	}
		

	cout << "Az elso teglalap terulete: " << t1.ter() << endl;
	cout << "A masodik teglalap terulete: " << t2.ter() << endl;

	cout << "Az eslo teglalap magassaga: " << t1.getMag() << endl;

	return 0;

}


