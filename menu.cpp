#include <iostream>
#include "menu.h"
#include "probka.h"

using namespace std;

void menu_wyswietl()
{
    cout<<"...................BAZA PROBEK..................."<<endl;
    cout<<"                                                 "<<endl;
    cout<<"                 1. Dodaj probke                 "<<endl;
    cout<<"             2. Wyswietl liste probek            "<<endl;
    cout<<"         3. Usun aktualnie wybrana probke        "<<endl;
    cout<<"               4. Zmien dane probki              "<<endl;
    cout<<"           5. Wyszukaj probke po nazwie          "<<endl;
    cout<<"        6. Wyszukiwanie po niepelnej nazwie      "<<endl;
    cout<<"           7. Eksportuj probki do pliku          "<<endl;
    cout<<"            8. Importuj probki z pliku           "<<endl;
    cout<<"                9. Zakoncz program               "<<endl;
    cout<<"                                                 "<<endl;
    cout<<"................................................."<<endl;
    cout<<"                                                 "<<endl;
}

void aktualnie_wybrana_probka(vector<Probka> &probki, int indeks_wybranej_probki)
{
    cout<<"............AKTUALNIE WYBRANA PROBKA............."<<endl;
    cout<<"                                                 "<<endl;
    probki[indeks_wybranej_probki].pokaz();
    cout<<"                                                 "<<endl;
    cout<<"................................................."<<endl;
    cout<<"                                                 "<<endl;
}

