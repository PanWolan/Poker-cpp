#pragma once
#include <iostream>
#include <string>
using namespace std;

class Karty
{
	int wartosc;
	int kolor;
	string nazwa;
public:
	void set_Karta(int kol, int war, string nazw);
	int get_kartak();
	int get_kartaw();
	string get_kartan();
	void WypiszKarte();
	Karty(int war = 0, int kol = 4, string="przykladowa");
	
};

