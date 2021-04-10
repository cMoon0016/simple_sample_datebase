#ifndef FUNKCJE_H_INCLUDED
#define FUNKCJE_H_INCLUDED
#include <vector>

int znajdz_po_nazwie(std::vector<Probka> probki, int &indeks_wybranej_probki);
void zapisz_do_pliku(std::vector<Probka> probki);
std::string wytnij_do_odczytu(std::string &napis);
std::string wytnij_do_daty(std::string &wyciete);
void odczytaj_z_pliku(std::vector<Probka> &probki);
void wyszukaj_po_niepelnej_nazwie(std::vector<Probka> probki, int &indeks_wybranej_probki);
void wyswietl_liste_probek(std::vector<Probka> probki);
void usun_probke(std::vector<Probka> &probki, int &indeks_wybranej_probki);
bool czy_jest_liczba(std::string &napis);


#endif // FUNKCJE_H_INCLUDED
