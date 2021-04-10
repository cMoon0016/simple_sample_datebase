#include <iostream>
#include <windows.h>
#include <winbase.h>
#include "data.h"


using namespace std;

Data::Data()
{
    SYSTEMTIME st;
    GetSystemTime(&st);

    rok = st.wYear;
    miesiac = st.wMonth;
    dzien = st.wDay;
}

Data::Data(int dz, int mies, int r)
{
    dzien = dz;
    miesiac = mies;
    rok = r;
}

bool czy_jest_liczba_data(string napis)
{
    for(int i=0; i<napis.length(); i++)
    {
        char bufor = napis[i];
        if(bufor<48 || bufor>57)
        {
            if(bufor==32)
                continue;
            else
                return false;
        }
    }
    return true;
}

void Data::wczytaj()
{
    SYSTEMTIME st;
    GetSystemTime(&st);

    string r;
    int przestepny=0;
    while(true)
    {
        cout<<"Podaj rok: ";
        cin>>r;
        if(czy_jest_liczba_data(r))
        {
            rok = stoi(r);
            if(rok<1920 || rok>st.wYear)
            {
                cout<<"Chyba pomyliles rok [obecnie mamy: "<<st.wYear<<"]"<<endl;
                continue;
            }
            if((rok%4==0 && rok%100!=0) || (rok%400==0))
                przestepny=1;
            break;
        }
        else
            cout<<"To nie jest liczba"<<endl;
    }

    string mies;
    while(true)
    {
        cout<<"Podaj miesiac: ";
        cin>>mies;
        if(czy_jest_liczba_data(mies))
        {
            miesiac = stoi(mies);
            if(rok == st.wYear)
            {
                if(miesiac > st.wMonth)
                {
                    cout<<"Chyba pomyliles miesiac, obecnie mamy "<<st.wMonth<<" miesiac"<<endl;
                    continue;
                }
            }
            if(miesiac>0 && miesiac<=12)
                break;
            else
                cout<<"Bledny format (1-12)"<<endl;
        }
        else
            cout<<"To nie jest liczba"<<endl;
    }


    int poprawny_dzien=0;
    string dz;
    while(!poprawny_dzien)
    {
        cout<<"Podaj dzien: ";
        cin>>dz;
        if(czy_jest_liczba_data(dz))
            dzien = stoi(dz);
        else
        {
            cout<<"To nie jest liczba"<<endl;
            continue;
        }

        if(rok == st.wYear && miesiac == st.wMonth)
        {
            if(dzien > st.wDay)
            {
                cout<<"Chyba pomyliles dzien, obecnie mamy "<<st.wDay<<" dzien"<<endl;
                continue;
            }
        }

        switch(miesiac)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if(dzien<=31 && dzien>=1)
                    poprawny_dzien=1;
                else
                    cout<<"Bledny format (1-31)"<<endl;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if(dzien<=30 && dzien>=1)
                    poprawny_dzien=1;
                else
                    cout<<"Bledny format (1-30)"<<endl;
                break;
            case 2:
                if(przestepny)
                {
                    if(dzien<=29 && dzien>=1)
                        poprawny_dzien=1;
                    else
                        cout<<"Bledny format (1-29): "<<endl;
                }
                else
                {
                    if(dzien<=28 && dzien>=1)
                        poprawny_dzien=1;
                    else
                        cout<<"Bledny format (1-28): "<<endl;
                }
                break;
        }
    }
}


void Data::wyswietl()
{
    cout<<dzien<<"/"<<miesiac<<"/"<<rok;
}
