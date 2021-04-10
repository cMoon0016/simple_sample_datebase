#include <iostream>
#include <windows.h>
#include <vector>
#include <fstream>
#include <string.h>

#include "data.h"
#include "probka.h"
#include "menu.h"
#include "funkcje.h"

using namespace std;

int main()
{
    vector<Probka> probki;
    string dec;
    int decyzja;
    int indeks_wybranej_probki = -1;

    while(true)
    {
        system("cls");
        menu_wyswietl();
        if(indeks_wybranej_probki>-1)
            aktualnie_wybrana_probka(probki, indeks_wybranej_probki);
        cout<<"                    Decyzja: ";
        cin>>dec;
        if(czy_jest_liczba_data(dec))
            decyzja = stoi(dec);
        else
            continue;

        system("cls");
        switch(decyzja)
        {
            case 1:
            {
                probki.push_back(Probka());
                system("cls");
                cout<<"..........DODANO PROBKE.........."<<endl<<endl;
                break;
            }

            case 2:
            {
                wyswietl_liste_probek(probki);
                break;
            }

            case 3:
            {
                usun_probke(probki, indeks_wybranej_probki);
                break;
            }

            case 4:
            {
                if(indeks_wybranej_probki == -1)
                {
                    cout<<"..........NIE WYBRANO PROBKI.........."<<endl<<endl;
                }
                else
                    probki[indeks_wybranej_probki].zmien_dane();
                break;
            }

            case 5:
            {
                znajdz_po_nazwie(probki, indeks_wybranej_probki); //zmienic na zmienna przekazywana
                break;
            }
            case 6:
            {
                wyszukaj_po_niepelnej_nazwie(probki, indeks_wybranej_probki);
                break;
            }

            case 7:
            {
                zapisz_do_pliku(probki);
                break;
            }

            case 8:
                odczytaj_z_pliku(probki);
                break;

            case 9:
            {
                cout<<"..........ZAKONCZONO DZIALANIE PROGRAMU.........."<<endl;
                return 0;
            }

            default:
                cout<<"Bledny format [1-7]"<<endl;
        }
        system("pause");
    }
    return 0;
}
