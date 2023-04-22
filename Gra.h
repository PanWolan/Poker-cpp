#pragma once
#include "Talia.h"
#include "Gracz.h"
#include <cstdlib>
#include <algorithm>


class Gra 
{
	Karty wspolne[5];
	Karty karty_gracza[7];
	int faza;
	WS tabKombinacji[10];
	int pula;
	int ostatni_bet;
	bool koniec_gry;

public:
	friend class Gracz;
	Gra();
	void DobierzKarte(Talia &t);
	void Wypisz();
	void SortowanieReki();
	int get_pula();
	void set_pula(int i);
	void set_fazato(int i);
	void nastepnafaza();
	int get_faza();
	int get_ostatnibet();
	void set_ostatnibet(int i);
	bool get_koniecgry();
	void set_koniecgry(bool i);
	
	WS SprawdzGracza(Gracz &g);
	WS Najwyzsza();
	WS Para();
	WS DwiePary();
	WS Trojka();
	WS Strit();
	WS Ful();
	WS Kolor();
	WS Kareta();
	WS Poker();
	WS PokerKr();
	string get_wspolne_nazwa(int i);

	void setwspolne(Karty k);
	void TestowanieSprawdzania(Karty k1, Karty k2, Karty k3, Karty k4, Karty k5, Karty k6, Karty k7);
	int PorownajGraczy(Gracz g1, Gracz g2);
};

//int operator >(WS& t, WS& d);


