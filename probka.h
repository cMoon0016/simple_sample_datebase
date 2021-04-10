#ifndef PROBKA_H_INCLUDED
#define PROBKA_H_INCLUDED
#include <iostream>
#include <vector>
#include "data.h"


using namespace std;

class Probka
{
    private:
        char nazwa[256];
        float stezenie;
        float objetosc;
        char wlasciciel[100];
        Data data_pobrania;
        Data data_przeprowadzenia_badania;
        string rodzaj;

    public:
        Probka();
        Probka(char [256], float, float, char [100], Data, Data, string);
        void dodaj();
        void wczytaj_nazwe();
        void wczytaj_stezenie();
        void wczytaj_objetosc();
        void wczytaj_wlasciciela();
        void wczytaj_date_pobrania();
        void wczytaj_date_badania();
        void wczytaj_rodzaj();
        void usun();
        void pokaz();
        void pokaz_liste();
        void zmien_dane();
        void wyszukaj_po_nazwie();

        friend int znajdz_po_nazwie(vector<Probka> probka, int &indeks_wybranej_probki);
        friend void zapisz_do_pliku(vector<Probka> probki);
        friend void odczytaj_z_pliku(vector<Probka> &probki);
        friend void wyszukaj_po_niepelnej_nazwie(vector<Probka> probki, int &indeks_wybranej_probki);
} ;

#endif // PROBKA_H_INCLUDED
