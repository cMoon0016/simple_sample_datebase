#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <windows.h>
#include <string.h>
#include <string>
#include "probka.h"
#include "funkcje.h"
#include "data.h"

using namespace std;

int znajdz_po_nazwie(vector<Probka> probki, int &indeks_wybranej_probki)
{
    system("cls");
    char naz[100];
    cout<<"..........WYSZUKIWANIE PROBKI PO NAZWIE.........."<<endl<<endl;
    cout<<"Podaj nazwe probki: ";
    cin.ignore();
    gets(naz);
    int indeks = -1;
    for(int i=0; i<probki.size(); i++)
    {
        if(!strcmp(probki[i].nazwa, naz))
        {
            indeks = i;
            break;
        }
    }
    system("cls");
    if(indeks == -1)
    {
        cout<<"..........BRAK PROBKI O PODANEJ NAZWIE.........."<<endl<<endl;
        return -1;
    }
    else
    {
        cout<<"..........ZNALEZIONO PROBKE.........."<<endl<<endl;
        indeks_wybranej_probki = indeks;
    }
}

void zapisz_do_pliku(vector<Probka> probki)
{
    cout<<"..........EKSPORTOWANIE DO PLIKU.........."<<endl<<endl;
    if(probki.empty())
    {
        cout<<"BRAK PROBEK"<<endl<<endl;
        return;
    }

    fstream plik;
    while(true)
    {
        cout<<"Czy chcesz dane do istniejacego pliku czy wyzerowac"<<endl;
        cout<<"istniejacy i zapisac w nim dane? [dopisac/wyzerowac] ";
        string decyzja;
        cin>>decyzja;
        transform(decyzja.begin(), decyzja.end(), decyzja.begin(), ::tolower);
        if(decyzja == "dopisac")
        {
            plik.open("baza_probek.txt", ios::out | ios::app);
            break;
        }
        else if(decyzja == "wyzerowac")
        {
            plik.open("baza_probek.txt", ios::out);
            break;
        }
        else
            cout<<"Bledny format [dopisac/wyzerowac]"<<endl;

    }


    if(!plik.good())
    {
        cout<<"NIE UDALO SIE OTWORZYC PLIKU .TXT"<<endl;
        return;
    }

    for(int i=0; i<probki.size(); i++)
    {
        plik<<"Nazwa: \t\t"<<probki[i].nazwa<<endl;
        plik<<"Stezenie: \t"<<probki[i].stezenie<<endl;
        plik<<"Objetosc: \t"<<probki[i].objetosc<<endl;
        plik<<"Wlasciciel: \t"<<probki[i].wlasciciel<<endl;
        plik<<"Data pobrania: \t"<<probki[i].data_pobrania.dzien<<"/"<<probki[i].data_pobrania.miesiac<<"/"<<probki[i].data_pobrania.rok<<endl;
        plik<<"Data badania: \t"<<probki[i].data_przeprowadzenia_badania.dzien<<"/"<<probki[i].data_przeprowadzenia_badania.miesiac<<"/"<<probki[i].data_przeprowadzenia_badania.rok<<endl;
        plik<<"Rodzaj: \t"<<probki[i].rodzaj<<endl<<endl;
    }
    cout<<"ZAPISANO POPRAWNIE DANE"<<endl<<endl;

}

string wytnij_do_odczytu(string &napis)
{
    char bufor;
    for(;;)
    {
        bufor = napis[0];
        if(bufor != 9) //9 to kod tabulatora
        {
            napis.erase(0, 1);
        }
        else if(bufor == 9)
        {
            napis.erase(0, 1);
            if(napis[0] == 9)
                napis.erase(0, 1);
            break;
        }
    }

    for(;;)
    {
        bufor = napis[0];
        if(bufor == 32)
        {
            napis.erase(0, 1);
        }
        else
        {
            break;
        }
    }

    return napis;
}

string wytnij_do_daty(string &wyciete)
{
    string gotowe;
    char bufor;
    for(;;)
    {
        bufor = wyciete[0];
        if(bufor != 47) //47 to slash
        {
            gotowe += wyciete[0];
            wyciete.erase(0, 1);
            if(wyciete.empty())
                break;
        }
        else
        {
            wyciete.erase(0,1);
            break;
        }
    }
    return gotowe;
}

void odczytaj_z_pliku(vector<Probka> &probki)
{
    static int ile_importowan = 0;
    ile_importowan++;
    if(ile_importowan>1)
    {
        cout<<"Importowano juz dane z pliku do programu, ponowne importowanie"<<endl;
        cout<<"moze spowodowac powielenie danych importowanych i problemy"<<endl;
        cout<<"w dzialaniu programu, jesli nie zmieniono pliku importowanego"<<endl;
        while(true)
        {
            cout<<"Czy mimo to chcesz zaimportowac dane? [tak/nie] ";
            string decyzja;
            cin>>decyzja;
            transform(decyzja.begin(), decyzja.end(), decyzja.begin(), ::tolower);
            if(decyzja == "tak")
            {
                system("cls");
                break;
            }
            else if(decyzja == "nie")
            {
                system("cls");
                cout<<"PRZERWANO IMPORTOWANIE DANYCH"<<endl;
                return;
            }
            else
                cout<<"Blad formatu [tak/nie]"<<endl;
        }
    }

    cout<<"......IMPORTOWANIE DANYCH Z PLIKU......"<<endl<<endl;
    fstream plik;
    plik.open("baza_probek.txt", ios::in);
    if(!plik.good())
    {
        cout<<"...BRAK PLIKU BAZA_PROBEK.TXT W FOLDERZE Z PROGRAMEM..."<<endl;
        return;
    }

    string linia;
    int nr_lini = 1;
    int ilosc_pustych = 0;
    int i = 0;

    //do stworzenia obiektu
    char naz[256];
    float stez;
    float obj;
    char wlas[100];
    int dz, dz2;
    int mies, mies2;
    int r, r2;
    string rodz;

    while(true)
    {
        if(!getline(plik, linia))
        {
            ilosc_pustych++;
            if(ilosc_pustych == 2)
                break;
            continue;
        }
        else
            ilosc_pustych = 0;

        switch(nr_lini)
        {
            case 1:
            {
                string n = wytnij_do_odczytu(linia);
                strcpy(naz, n.c_str());
                break;
            }

            case 2:
            {
                stez = stof(wytnij_do_odczytu(linia));
                break;
            }

            case 3:
            {
                obj = stof(wytnij_do_odczytu(linia));
                break;
            }

            case 4:
            {
                string n = wytnij_do_odczytu(linia);
                strcpy(wlas, n.c_str());
                break;
            }

            case 5:
            {
                string n = wytnij_do_odczytu(linia);
                dz = stoi(wytnij_do_daty(linia));
                mies = stoi(wytnij_do_daty(linia));
                r = stoi(wytnij_do_daty(linia));
                break;
            }

            case 6:
            {
                string n = wytnij_do_odczytu(linia);
                dz2 = stoi(wytnij_do_daty(linia));
                mies2 = stoi(wytnij_do_daty(linia));
                r2 = stoi(wytnij_do_daty(linia));
                break;
            }

            case 7:
            {
                rodz = wytnij_do_odczytu(linia);
                break;
            }
        }
        if(nr_lini%8 == 0)
        {
            probki.push_back(Probka(naz, stez, obj, wlas, Data(dz, mies, r), Data(dz2, mies2, r2), rodz));
            i++;
            nr_lini = 0;
        }
        nr_lini++;
    }
    cout<<"ZAIMORTOWANO DANE POPRAWNIE"<<endl<<endl;
    plik.close();
}

void wyszukaj_po_niepelnej_nazwie(vector<Probka> probki, int &indeks_wybranej_probki)
{
    char wyszukiwanie[256];
    cout<<"....WYSZUKIWANIE PO NIEPELNEJ NAZWIE PROBKI...."<<endl<<endl;
    cout<<"Co wyszukac: ";
    cin.ignore();
    gets(wyszukiwanie);

    vector<int> wyniki_wyszukiwania;
    for(int i=0; i<probki.size(); i++)
    {
        if(strstr(probki[i].nazwa, wyszukiwanie))
            wyniki_wyszukiwania.push_back(i);
    }

    if(wyniki_wyszukiwania.empty())
    {
        cout<<endl<<"NIE ZNALEZIONO PASUJACYCH PROBEK"<<endl<<endl;
        return;
    }

    if(wyniki_wyszukiwania.size() == 1)
    {
        cout<<endl<<"ZNALEZIONO JEDNA PASUJACA PROBKE"<<endl<<endl;
        probki[wyniki_wyszukiwania[0]].pokaz();
        cout<<endl;
        indeks_wybranej_probki = wyniki_wyszukiwania[0];
        return;
    }

    cout<<endl<<"ZNALEZIONO PROBKI:"<<endl;
    for(int i=0; i<wyniki_wyszukiwania.size(); i++)
    {
        probki[wyniki_wyszukiwania[i]].pokaz_liste();
        cout<<endl;
    }

    string decyzja;
    while(true)
    {
        cout<<endl<<"Czy chcesz wybrac probke z listy? [tak/nie] ";
        cin>>decyzja;
        cout<<endl;
        if(decyzja == "tak")
        {
            wyszukaj_po_niepelnej_nazwie(probki, indeks_wybranej_probki);
            return;
        }
        else if(decyzja == "nie")
            return;
        else
            cout<<"Bledny format [tak/nie]"<<endl;
    }

}

void wyswietl_liste_probek(vector<Probka> probki)
{
    cout<<".....LISTA WSZYSTKICH PROBEK....."<<endl<<endl;
    if(probki.empty())
        cout<<"...........BRAK PROBEK..........."<<endl<<endl;
    else
    {
        for(int i=0; i<probki.size(); i++)
        {
            probki[i].pokaz_liste();
            cout<<endl;
        }
    }
}

void usun_probke(vector<Probka> &probki, int &indeks_wybranej_probki)
{
    if(indeks_wybranej_probki == -1)
    {
        cout<<".....NIE WYBRANO ZADNEJ PROBKI....."<<endl<<endl;
        return;
    }
    else
    {
        probki.erase(probki.begin() + indeks_wybranej_probki);
        indeks_wybranej_probki = -1;
        cout<<".....USUNIETO PROBKE....."<<endl<<endl;
    }
}

bool czy_jest_liczba(string &napis)
{
    for(int i=0; i<napis.length(); i++)
    {
        char bufor = napis[i];
        if(bufor<48 || bufor>57)
        {
            if(bufor == 44)
            {
                bufor = 46;
                napis[i] = bufor;
            }
            if(bufor == 46 || bufor == 32)
                continue;
            else
            	return false;
        }
    }
    return true;
}
