#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <sstream>
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

    ifstream myfile ("Config.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,plik,'\n') )
        {
            licznik++;
        }
    myfile.close();
    }
    else
        cout << "Unable to open file";

    cout << "Zeskanowano " << licznik << " rekordow.\n";
    cout << "Podaj ilosc rekordow w pliku docelowym: ";
    cin >> iloscRekordow;
    string dane [licznik];
    long int licznik2= licznik -1;
    while(1)
    {
        ifstream myfile ("Config.txt");
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

        string nazwa = "Plik_";
        string nazwaLiczba_str = to_string(nazwaLiczba_int);
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
    return 0;
}
