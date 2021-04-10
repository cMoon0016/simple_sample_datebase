#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED
#include <iostream>
#include <vector>

class Data
{
    public:
        int dzien;
        int miesiac;
        int rok;

    public:
        Data();
        Data(int, int, int);
        void wczytaj();
        void wyswietl();
};

bool czy_jest_liczba_data(std::string);
#endif // DATA_H_INCLUDED
