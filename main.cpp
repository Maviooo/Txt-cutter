#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <windows.h>
#include <sstream>
#include <iomanip>
#include <direct.h>
using namespace std;
template <class T>
string to_string(T obj)
{
    stringstream ss;
    ss << obj;
    return ss.str();
}
int main()
{
    long int fakt =0;
    int nazwaLiczba_int =1;
    int iloscRekordow;
    int licznik =0;
    string plik;
    string sciezka;
    cout << "Podaj sciezke do pliku (jesli plik znajduje sie w tym samym miejscu co program wykonawczy wystarczy tylko nazwa i rozszerzenie):\n";
    getline(cin,sciezka);
    cout << "\n";
    ifstream myfile (sciezka);
    if (myfile.is_open())
    {
        while ( getline (myfile,plik,'\n') )
        {
            licznik++;
        }
        myfile.close();
        cout << "Zeskanowano " << licznik << " rekordow.\n";
        cout << "Podaj ilosc rekordow w pliku docelowym: ";
        cin >> iloscRekordow;
        string dane [licznik];
        long int licznik2= licznik -1;
        mkdir("OUT");
        while(1)
        {
            ifstream myfile (sciezka);
            if (myfile.is_open())
            {
                        for(long int i =0;i<=licznik2;i++)
                        {
                        getline (myfile,plik,'\n');
                        dane[i]=plik;
                        }
            }
            else
                cout << "Unable to open file";

            double length = 1;
            int iloscPlikow =1;
            int licznik_op =licznik;
            while ( licznik_op -= iloscRekordow )
                iloscPlikow++;
            while ( iloscPlikow /= 10)
                length++;
            stringstream aa;
            aa.width(length);
            aa << std::setfill('0') << nazwaLiczba_int;
            string nazwa = "OUT/Plik_";
            string nazwaLiczba_str = to_string(aa.str());
            nazwa+=nazwaLiczba_str;
            nazwa+=".txt";
            const char *nazwa_char = nazwa.c_str();
            ofstream outfile (nazwa_char);
            for(int a=1;a<=iloscRekordow;a++)
            {
                outfile << dane[fakt] << "\n";
                fakt++;
                if(fakt>=licznik)
                    break;
            }
            system("cls");
            cout << "Utworzono " << nazwaLiczba_int << " plik\n";
            outfile.close();
            if(fakt>=licznik)
                break;

            nazwaLiczba_int++;
        }
        myfile.close();
        system("cls");
        cout << "Pomyslnie utworzono wszystkie pliki.\n";
    }
    else
        {
        cout << "Unable to open file\n";
        getchar();
        }
    return 0;
}
