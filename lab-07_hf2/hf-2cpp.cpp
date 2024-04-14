#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;
struct dolgozok
{
    string nev;
    int szul, dol, fizetes;
};
class Munka
{
public:
    dolgozok* tmb;
    Munka(string fajl) {
        ifstream be(fajl);
        if (be.fail())
        {
            cerr << "Hiba a f�jl menyit�sakor" << endl;
        }
        sorok = 0;
        string line;
        while (getline(be, line))
        {
            sorok++;

        }
        be.close();
        tmb = new dolgozok[sorok];
    }
    void dolgozottmaj() {
        cout << "m�jusban " << sorok << " f� dolgozott" << endl;
    }
    void feltolt(string fajl) {
        ifstream be(fajl);
        if (be.fail())
        {
            cerr << "hiba" << endl;
        }
        for (size_t i = 0; i < sorok; i++)
        {
            be >> tmb[i].nev;
            do
            {
                cout << "Adja meg " << tmb[i].nev << " sz�let�si �v�t ";
                cin >> tmb[i].szul;
            } while (tmb[i].szul < 1957 || tmb[i].szul>2004);
            tmb[i].dol = rand() % 161;
            tmb[i].fizetes = tmb[i].dol * ber;
        }
        be.close();
    }
    void kiir() {
        cout << left;
        cout << setw(25) << "N�v" << setw(10) << "Sz�l�v" << setw(10) << "munka�ra" << setw(10) << "fizetes" << endl;
        for (size_t i = 0; i < sorok; i++)
        {
            cout << setw(25) << tmb[i].nev << setw(10) << tmb[i].szul << setw(10) << tmb[i].dol << setw(10) << tmb[i].fizetes << endl;
        }
    }
    int ossz() {
        int ora = 0;
        for (size_t i = 0; i < sorok; i++)
        {
            ora += tmb[i].dol;
        }
        return ora;
    }
    int leg�() {
        int max = tmb[0].szul;
        int maxind = 0;
        for (size_t i = 0; i < sorok; i++)
        {
            if (max > tmb[i].szul)
            {
                maxind = i;

            }
            max = tmb[maxind].szul;
        }
        return max;
    }
    int szazt() {
        int t�bb = 0;
        for (size_t i = 0; i < sorok; i++)
        {
            if (tmb[i].dol >= 100)
            {
                t�bb++;
            }
        }
        return t�bb;

    }
    void adatment(string fajl) {
        ofstream ki(fajl);
        if (ki.fail())
        {
            cerr << "hiba";
        }
        for (size_t i = 0; i < sorok; i++)
        {
            ki << tmb[i].nev << " " << tmb[i].szul << " " << tmb[i].dol << " " << tmb[i].fizetes << endl;
        }
        cout << "sikeres mentes";
    }
private:
    const int ber = 2800; int sorok;
};
void main()
{
    setlocale(LC_ALL, "");
    srand((unsigned)time(NULL));
    const string befajl = "majus.txt";
    const string kifajl = "majs_teljes.txt";
    Munka munka(befajl);
    munka.dolgozottmaj();
    munka.feltolt(befajl); munka.kiir();
    cout << "�sszesen: " << munka.ossz() << " �r�t dolgozak m�jusban" << endl;
    cout << "Legid�sebb dolgozo: " << 2024 - munka.leg�() << endl;
    cout << munka.szazt() << " f� dolgozott sz�z �r�n�l t�bet" << endl;
    munka.adatment(kifajl);
    system("pause");
}