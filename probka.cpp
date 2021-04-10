#include <iostream>
#include <algorithm>
#include <string.h>
#include "probka.h"
#include "data.h"
#include "funkcje.h"

using namespace std;

Probka::Probka()
{
    dodaj();
}

Probka::Probka(char naz[256], float stez, float obj, char wlas[100], Data pob, Data bad, string rodz)
{
    strcpy(nazwa, naz);
    stezenie = stez;
    objetosc = obj;
    strcpy(wlasciciel, wlas);
    data_przeprowadzenia_badania = bad;
    data_pobrania = pob;
    rodzaj = rodz;
}

void Probka::wczytaj_nazwe()
{
    cin.ignore();
    cout<<"Podaj nazwe probki (maks 256 znakow): ";
    gets(nazwa);
}

void Probka::wczytaj_stezenie()
{
    while(true)
    {
        string ste;
        cout<<"Podaj stezenie: ";
        cin>>ste;
        if(czy_jest_liczba(ste))
        {
            stezenie = stof(ste);
            if(stezenie>=0)
                break;
            else
                cout<<"Bledny format, stezenie nie moze byc ujemne"<<endl;
        }
        else
            cout<<"To nie jest liczba"<<endl;
    }
}

void Probka::wczytaj_objetosc()
{
    while(true)
    {
        string obj;
        cout<<"Podaj objetosc: ";
        cin>>obj;
        if(czy_jest_liczba(obj))
        {
            objetosc = stof(obj);
            if(objetosc>0)
                break;
            else
                cout<<"Bledny format, objetosc nie moze byc ujemna ani rowna 0"<<endl;
        }
        else
            cout<<"To nie jest liczba"<<endl;
    }
}

void Probka::wczytaj_wlasciciela()
{
    cin.ignore();
    cout<<"Podaj wlasciciela (maks 100 znakow): ";
    gets(wlasciciel);

}

void Probka::wczytaj_date_pobrania()
{
    while(true)
    {
        cout<<"Czy chcesz zmienic date pobrania probki (domyslnie taka jak data badania)[tak/nie]? ";
        string decyzja;
        cin>>decyzja;
        transform(decyzja.begin(), decyzja.end(), decyzja.begin(), ::tolower);
        if(decyzja=="tak")
            {
                while(true)
                {
                    data_pobrania.wczytaj();
                    if(data_pobrania.rok < data_przeprowadzenia_badania.rok)
                    {
                        break;
                    }
                    else if(data_pobrania.rok == data_przeprowadzenia_badania.rok)
                    {
                        if(data_pobrania.miesiac < data_przeprowadzenia_badania.miesiac)
                        {
                            break;
                        }
                        else if(data_pobrania.dzien <= data_przeprowadzenia_badania.dzien)
                        {
                            break;
                        }
                    }
                    cout<<"Data pobrania probki nie moze byc pozniejsza niz data przeprowadzenia badania"<<endl;
                }
                break;
            }
        else if(decyzja=="nie")
            {
                data_pobrania.rok = data_przeprowadzenia_badania.rok;
                data_pobrania.miesiac = data_przeprowadzenia_badania.miesiac;
                data_pobrania.dzien = data_przeprowadzenia_badania.dzien;
                break;
            }
        else
            {
                cout<<"Bledny format (tak/nie)"<<endl;
            }
    }
}

void Probka::wczytaj_date_badania()
{
    while(true)
    {
        cout<<"Czy chcesz zmienic date przeprowadzenia badania (domyslnie dzisiejsza data)[tak/nie]? ";
        string decyzja;
        cin>>decyzja;
        transform(decyzja.begin(), decyzja.end(), decyzja.begin(), ::tolower);
        if(decyzja=="tak")
        {
            data_przeprowadzenia_badania.wczytaj();
            break;
        }
        else if(decyzja=="nie")
            break;
        else
            cout<<"Bledny format (tak/nie)"<<endl;
    }
}

void Probka::wczytaj_rodzaj()
{
    while(true)
    {
        cout<<"Podaj rodzaj probki [staly/rozproszony/lotny]: ";
        cin>>rodzaj;
        if(rodzaj=="staly" || rodzaj=="rozproszony" || rodzaj=="lotny")
            break;
        else
            cout<<"Bledny format [staly/rozproszony/lotny]"<<endl;
    }
}

void Probka::dodaj()
{
    cout<<"DODAWANIE PROBKI"<<endl;
    cout<<"................"<<endl;
    wczytaj_nazwe();
    wczytaj_stezenie();
    wczytaj_objetosc();
    wczytaj_wlasciciela();
    wczytaj_date_badania();
    wczytaj_date_pobrania();
    wczytaj_rodzaj();
}

void Probka::pokaz()
{
    cout<<"Nazwa probki: \t\t\t";
    puts(nazwa);
    cout<<"Stezenie probki: \t\t"<<stezenie<<endl;
    cout<<"Objetosc probki: \t\t"<<objetosc<<endl;
    cout<<"Wlasciciel probki: \t\t";
    puts(wlasciciel);
    cout<<"Data pobrania probki: \t\t";
    data_pobrania.wyswietl();
    cout<<endl<<"Data przeprowadzania badania: \t";
    data_przeprowadzenia_badania.wyswietl();
    cout<<endl<<"Rodzaj probki: \t\t\t"<<rodzaj<<endl;
}

void Probka::pokaz_liste()
{
    cout<<"Nazwa: "<<nazwa<<"\t Stezenie: "<<stezenie<<"\t Objetosc: "<<objetosc<<"\t Wlasciciel: "<<wlasciciel<<"\t Data pobrania: ";
    data_pobrania.wyswietl();
    cout<<"\t Data badania: ";
    data_przeprowadzenia_badania.wyswietl();
    cout<<"\t Rodzaj: "<<rodzaj;
}

void Probka::zmien_dane()
{
    int zmiana = 1;
    int decyzja;

    while(zmiana)
    {
        cout<<"ZMIANA DANYCH PROBKI"<<endl;
        cout<<"...................."<<endl;
        cout<<"                    "<<endl;
        cout<<"Aktualne dane:"<<endl;
        pokaz();
        cout<<"                    "<<endl;
        cout<<"...................."<<endl;
        cout<<"                    "<<endl;
        cout<<"Jakie dane chcesz zmienic?"<<endl;
        cout<<"1. Nazwa"<<endl;
        cout<<"2. Stezenie"<<endl;
        cout<<"3. Objetosc"<<endl;
        cout<<"4. Wlasciciel"<<endl;
        cout<<"5. Data pobrania probki"<<endl;
        cout<<"6. Data badania"<<endl;
        cout<<"7. Rodzaj probki"<<endl;
        cout<<"8. Zakoncz zmiany"<<endl;
        cout<<"                    "<<endl;
        cout<<"...................."<<endl;
        cout<<"                    "<<endl;
        cout<<"Decyzja: ";
        cin>>decyzja;

        system("cls");
        switch(decyzja)
        {
            case 1:
            {
                char naz[256];
                string decyzja;
                cout<<"ZMIANA NAZWY PROBKI"<<endl;
                cout<<"..................."<<endl;
                cout<<"                   "<<endl;
                cout<<"Poprzednia nazwa:"<<endl;
                cin.ignore();
                puts(nazwa);
                cout<<"Nowa nazwa:"<<endl;
                gets(naz);
                for(;;)
                {
                    cout<<"Czy na pewno chcesz zmienic nazwe? [tak/nie]"<<endl;
                    cin>>decyzja;
                    transform(decyzja.begin(), decyzja.end(), decyzja. begin(), ::tolower);
                    system("cls");
                    if(decyzja == "tak")
                    {
                        strcpy(nazwa, naz);
                        cout<<"ZMIENIONO NAZWE PROBKI"<<endl;
                        break;
                    }
                    else if(decyzja == "nie")
                    {
                        cout<<"COFNIETO ZMIANE NAZWY"<<endl;
                        break;
                    }
                    else
                    {
                        cout<<"BLEDNY FORMAT [tak/nie]"<<endl;
                    }
                }
                break;
            }

            case 2:
            {
                string decyzja;
                float ste;
                cout<<"ZMIANA STEZENIA PROBKI"<<endl;
                cout<<"......................"<<endl;
                cout<<"                      "<<endl;
                cout<<"Poprzednie stezenie: "<<stezenie<<endl;
                cout<<"Nowe stezenie: ";
                cin>>ste;
                for(;;)
                {
                    cout<<"Czy na pewno chcesz zmienic stezenie? [tak/nie]"<<endl;
                    cin>>decyzja;
                    transform(decyzja.begin(), decyzja.end(), decyzja. begin(), ::tolower);
                    system("cls");
                    if(decyzja == "tak")
                    {
                        stezenie = ste;
                        cout<<"ZMIENIONO STEZENIE PROBKI"<<endl;
                        break;
                    }
                    else if(decyzja == "nie")
                    {
                        cout<<"COFNIETO ZMIANE STEZENIA"<<endl;
                        break;
                    }
                    else
                    {
                        cout<<"BLEDNY FORMAT [tak/nie]"<<endl;
                    }
                }
                break;
            }

            case 3:
            {
                string decyzja;
                float obj;
                cout<<"ZMIANA OBJETOSCI PROBKI"<<endl;
                cout<<"......................."<<endl;
                cout<<"                       "<<endl;
                cout<<"Poprzednie stezenie: "<<objetosc<<endl;
                cout<<"Nowa objetosc: ";
                cin>>obj;
                for(;;)
                {
                    cout<<"Czy na pewno chcesz zmienic objetosc? [tak/nie]"<<endl;
                    cin>>decyzja;
                    transform(decyzja.begin(), decyzja.end(), decyzja. begin(), ::tolower);
                    system("cls");
                    if(decyzja == "tak")
                    {
                        objetosc = obj;
                        cout<<"ZMIENIONO OBJETOSC PROBKI"<<endl;
                        break;
                    }
                    else if(decyzja == "nie")
                    {
                        cout<<"COFNIETO ZMIANE OBJETOSCI"<<endl;
                        break;
                    }
                    else
                    {
                        cout<<"BLEDNY FORMAT [tak/nie]"<<endl;
                    }
                }
                break;
            }

            case 4:
            {
                char wla[256];
                string decyzja;
                cout<<"ZMIANA WLASCICIELA PROBKI"<<endl;
                cout<<"........................."<<endl;
                cout<<"                         "<<endl;
                cout<<"Poprzedni wlasciciel:"<<endl;
                cin.ignore();
                puts(wlasciciel);
                cout<<"Nowy wlasciciel:"<<endl;
                gets(wla);
                for(;;)
                {
                    cout<<"Czy na pewno chcesz zmienic wlasciciela? [tak/nie]"<<endl;
                    cin>>decyzja;
                    transform(decyzja.begin(), decyzja.end(), decyzja. begin(), ::tolower);
                    system("cls");
                    if(decyzja == "tak")
                    {
                        strcpy(wlasciciel, wla);
                        cout<<"ZMIENIONO WLASCICIELA PROBKI"<<endl;
                        break;
                    }
                    else if(decyzja == "nie")
                    {
                        cout<<"COFNIETO ZMIANE WLASCICIELA"<<endl;
                        break;
                    }
                    else
                    {
                        cout<<"BLEDNY FORMAT [tak/nie]"<<endl;
                    }
                }
                break;
            }

            case 5:
            {
                cout<<"ZMIANA DATY POBRANIA PROBKI"<<endl;
                cout<<"..........................."<<endl;
                cout<<"                           "<<endl;
                cout<<"Poprzedna data: ";
                data_pobrania.wyswietl();

                while(true)
                {
                    cout<<"Czy chcesz zmienic date pobrania probki [tak/nie]? ";
                    string decyzja;
                    cin>>decyzja;
                    transform(decyzja.begin(), decyzja.end(), decyzja.begin(), ::tolower);
                    if(decyzja=="tak")
                    {
                        data_pobrania.wczytaj();
                        break;
                    }
                    else if(decyzja=="nie")
                    {
                        break;
                    }
                    else
                    {
                        cout<<"Bledny format (tak/nie)"<<endl;
                    }
                }
                break;
            }

            case 6:
            {
                cout<<"ZMIANA DATY BADANIA"<<endl;
                cout<<"..................."<<endl;
                cout<<"                   "<<endl;
                cout<<"Poprzedna data: ";
                data_przeprowadzenia_badania.wyswietl();

                while(true)
                {
                    cout<<"Czy chcesz zmienic date pobrania badania [tak/nie]? ";
                    string decyzja;
                    cin>>decyzja;
                    transform(decyzja.begin(), decyzja.end(), decyzja.begin(), ::tolower);
                    if(decyzja=="tak")
                    {
                        data_przeprowadzenia_badania.wczytaj();
                        break;
                    }
                    else if(decyzja=="nie")
                    {
                        break;
                    }
                    else
                    {
                        cout<<"Bledny format (tak/nie)"<<endl;
                    }
                }
                break;
            }

            case 7:
            {
                string rodz;
                cout<<"ZMIANA RODZAJU PROBKI"<<endl;
                cout<<"....................."<<endl;
                cout<<"                     "<<endl;
                cout<<"Poprzedni rodzaj: "<<rodzaj<<endl;

                while(true)
                {
                    cout<<"Nowy rodzaj [staly/rozprszony/lotny]: ";
                    cin>>rodz;
                    transform(rodz.begin(), rodz.end(), rodz.begin(), ::tolower);
                    if(rodz == "staly" || rodz == "rozproszony" || rodz == "lotny")
                        break;
                    else
                        cout<<"Bledny forma [staly/rozprszony/lotny]"<<endl;
                }

                for(;;)
                {
                    string decyzja;
                    cout<<"Czy na pewno chcesz zmienic rodzaj probki? [tak/nie]"<<endl;
                    cin>>decyzja;
                    transform(decyzja.begin(), decyzja.end(), decyzja. begin(), ::tolower);
                    system("cls");
                    if(decyzja == "tak")
                    {
                        rodzaj = rodz;
                        cout<<"ZMIENIONO RODZAJ PROBKI"<<endl;
                        break;
                    }
                    else if(decyzja == "nie")
                    {
                        cout<<"COFNIETO ZMIANE RODZAJU"<<endl;
                        break;
                    }
                    else
                    {
                        cout<<"BLEDNY FORMAT [tak/nie]"<<endl;
                    }
                }
                break;
            }

            case 8:
            {
                system("cls");
                cout<<"ZAKONCZONO ZMIANE PROBEK"<<endl;
                system("pause");
                return;
            }

            default:
            {
                cout<<"BLEDNY FORMAT [1-7]"<<endl;
            }
        }
    }
}
