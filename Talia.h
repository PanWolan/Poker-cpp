#pragma once
#include "Karty.h"
#include <cstdlib>
#include <iostream>
#include <ctime>


using namespace std;

class Talia
{
	Karty mTalia[52];
	int dlugoscTalii;
public:
	Talia();
	void DodajKarte(const Karty& k, int nr);
	Karty StworzKarte(int wart, int kol, string nazw);
	void StworzTalie();
	int getdlugosctalii();
	void setdlugosctalii(int i);
	void WypiszTalie();
	Karty Dobieranie();
	void TasujTalie();
};

struct WS // Wyniki Sprawdzen
{
	int kombinacja;
	int wartkomb;
};