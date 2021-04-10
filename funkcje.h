#ifndef FUNKCJE_H_INCLUDED
#define FUNKCJE_H_INCLUDED
#include <vector>

int znajdz_po_nazwie(vector<Probka> probki, int &indeks_wybranej_probki);
void zapisz_do_pliku(vector<Probka> probki);
string wytnij_do_odczytu(string &napis);
string wytnij_do_daty(string &wyciete);
void odczytaj_z_pliku(vector<Probka> &probki);
void wyszukaj_po_niepelnej_nazwie(vector<Probka> probki, int &indeks_wybranej_probki);
void wyswietl_liste_probek(vector<Probka> probki);
void usun_probke(vector<Probka> &probki, int &indeks_wybranej_probki);
bool czy_jest_liczba(string &napis);


#endif // FUNKCJE_H_INCLUDED
