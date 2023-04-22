#pragma once
#include "Talia.h"
#include "Gra.h"


class Gracz
{
	Karty reka[2];
	int kwota;
	int Najwyzsza_karta;
	WS kombinacja;
	int ilosc_kart_wrece;
	bool czy_wgrze;
public:
	friend class Gra;
	void setKombinacja(WS wynik);
	WS getKombinacja();
	int getNajwyzsza_karta();
	void setNajwyzsza_karta(int naj);
	void DobierzDoReki(Talia& t);
	Karty get_reka(int n);
	string get_reka_nazwa(int i);
	int get_kwota();
	void setkwota(int pula);
	bool get_czywgrze();
	void set_czywgrze(bool i);

	int Obstaw(int ilosc, Gra &g);
	int Pass(Gra &g);
	int Sprawdz(Gra &g);

	int RuchGracza(int RuchPoprz, WS wynik, Gra& g);

	Gracz();
	int getilosc_kart_wrece();
	void setilosc_kart_wrece(int faza);
	friend int operator > (Gracz& t, Gracz& d);
};

