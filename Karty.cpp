#include "Karty.h"
int Karty::get_kartak()
{
	return kolor;
}

int Karty::get_kartaw()
{
	return wartosc;
}
string Karty::get_kartan()
{
	return nazwa;
}
void Karty::WypiszKarte()
{
	cout << nazwa <<endl;
}
void Karty::set_Karta(int kol, int war, string nazw)
{
	kolor = kol;
	wartosc = war;
	nazwa = nazw;
}
Karty::Karty(int war, int kol, string nazw)
{
	wartosc = war;
	kolor = kol;
	nazwa = nazw;
}