#include "Gracz.h"


void Gracz::setKombinacja(WS wynik)
{
	kombinacja = wynik;
}

WS Gracz::getKombinacja()
{
	return kombinacja;
}

int Gracz::getNajwyzsza_karta()
{
	return Najwyzsza_karta;
}

void Gracz::setNajwyzsza_karta(int naj)
{
	Najwyzsza_karta = naj;
}

void Gracz::DobierzDoReki(Talia& t)
{
	reka[0] = t.Dobieranie();
	reka[1] = t.Dobieranie();
}


Karty Gracz::get_reka(int n)
{
	return reka[n];
}

string Gracz::get_reka_nazwa(int i)
{
	return reka[i].get_kartan();
}

int Gracz::get_kwota()
{
	return kwota;
}

void Gracz::setkwota(int pula)
{
	kwota += pula;
}

bool Gracz::get_czywgrze()
{
	return czy_wgrze;
}

void Gracz::set_czywgrze(bool i)
{
	czy_wgrze = i;

}
int Gracz::Obstaw(int ilosc, Gra& g)
{
	if (ilosc > kwota)
	{

	}
	else
	{
		this -> kwota -= ilosc;
		g.set_pula(ilosc);
		g.set_ostatnibet(ilosc);

	}

	return 1;
}

int Gracz::Sprawdz(Gra &g)
{
	g.set_pula(g.get_ostatnibet());
	this->kwota -= g.get_ostatnibet();

	return 2;
}

int Gracz::Pass(Gra &g)
{
	g.set_fazato(3);
	set_czywgrze(false);
	return 3;
}

int Gracz::RuchGracza(int RuchPoprz, WS wynik , Gra &g)
{
	if (RuchPoprz == 2) // sprawdzil
	{
		switch (wynik.kombinacja)
		{
		case 9:
			Sprawdz(g);
			return 2;
			break;
		case 8:
			if (g.get_faza() == 1) { Sprawdz(g); Obstaw(100, g); return 1; }
			if (g.get_faza() == 2) { Sprawdz(g); Obstaw(50, g); return 1; }
			if (g.get_faza() == 3) { Sprawdz(g); return 2; }
			break;
		case 7:
			if (g.get_faza() == 1) { Sprawdz(g); Obstaw(200, g); return 1; }
			if (g.get_faza() == 2) { Sprawdz(g); Obstaw(100, g); return 1; }
			if (g.get_faza() == 3) { Sprawdz(g); return 2; }
			break;
		case 6:
			if (g.get_faza() == 1) { Sprawdz(g); Obstaw(200, g); return 1; }
			if (g.get_faza() == 2) { Sprawdz(g); Obstaw(100, g); return 1; }
			if (g.get_faza() == 3) { Sprawdz(g); return 2; }
			break;
		case 5:
			if (g.get_faza() == 1) { Sprawdz(g); Obstaw(200, g); return 1; }
			if (g.get_faza() == 2) { Sprawdz(g); Obstaw(200, g); return 1; }
			if (g.get_faza() == 3) { Sprawdz(g); return 2; }
			break;
		case 4:
			if (g.get_faza() == 1) { Sprawdz(g); Obstaw(200, g); return 1; }
			if (g.get_faza() == 2) { Sprawdz(g); Obstaw(200, g); return 1; }
			if (g.get_faza() == 3) { Sprawdz(g); return 2; }
			break;
		case 3:
			if (g.get_faza() == 1) { Sprawdz(g); Obstaw(200, g); return 1; }
			if (g.get_faza() == 2) { Sprawdz(g); Obstaw(200, g); return 1; }
			if (g.get_faza() == 3) { Sprawdz(g); return 2; }
			break;
		case 2:
			if (g.get_faza() == 1) { Sprawdz(g); Obstaw(500, g); return 1; }
			if (g.get_faza() == 2) { Sprawdz(g); Obstaw(200, g); return 1; }
			if (g.get_faza() == 3) { Sprawdz(g); return 2; }
			break;
		case 1:
			if (g.get_faza() == 1) { Sprawdz(g); Obstaw(500, g); return 1; }
			if (g.get_faza() == 2) { Sprawdz(g); Obstaw(500, g); return 1; }
			if (g.get_faza() == 3) { Sprawdz(g); return 2; }
			break;
		case 0:
			if (g.get_faza() == 1) { Sprawdz(g); Obstaw(kwota, g); return 1; }
			if (g.get_faza() == 2) { Sprawdz(g); Obstaw(kwota, g); return 1; }
			if (g.get_faza() == 3) { Sprawdz(g); return 2; }
			if (g.get_faza() == 3) { Sprawdz(g); return 2; }
			break;
		}
	}
	if (RuchPoprz == 1) // obstawil
	{
		switch (wynik.kombinacja)
		{
		case 9:
			if (wynik.wartkomb < 10)
			{
				if (g.get_ostatnibet() <= 100 && g.get_faza() == 1) { Sprawdz(g); return 1; }
				else { Pass(g); return 3; }
			}
			if (wynik.wartkomb > 9)
			{
				if (g.get_ostatnibet() <= 100 && g.get_faza() == 1 || g.get_faza() == 2) { Sprawdz(g); return 1; }
				else { Pass(g); return 3; }
			}
			break;
		case 8:
			if (g.get_ostatnibet() <= 200) { Sprawdz(g); return 2; }
			else { Pass(g); return 3; }
			break;
		case 7:
			if (g.get_ostatnibet() <= 100 && g.get_faza() == 1) { Sprawdz(g); Obstaw(100, g); return 1; }
			if (g.get_ostatnibet() <= 100 && g.get_faza() == 2) { Sprawdz(g); Obstaw(50, g); return 1; }
			if (g.get_ostatnibet() <= 100 && g.get_faza() == 3) { Sprawdz(g); return 2; }
			if (g.get_ostatnibet() <= 200 && g.get_ostatnibet() > 100) { Sprawdz(g); return 2; }
			else { Pass(g); return 3; }
			break;
		case 6:
			if (g.get_ostatnibet() <= 100 && g.get_faza() == 1) { Sprawdz(g); Obstaw(100, g); return 1; }
			if (g.get_ostatnibet() <= 100 && g.get_faza() == 2) { Sprawdz(g); Obstaw(50, g); return 1; }
			if (g.get_ostatnibet() <= 100 && g.get_faza() == 3) { Sprawdz(g); return 2; }
			if (g.get_ostatnibet() <= 200 && g.get_ostatnibet() > 100) { Sprawdz(g); return 2; }
			if (g.get_ostatnibet() <= 500 && g.get_ostatnibet() > 200 && g.get_faza() == 1) { Sprawdz(g); return 2; }
			if (g.get_ostatnibet() > kwota) { Obstaw(kwota, g); return 1; }
			else { Pass(g); return 3; }
			break;
		case 5:
			if (g.get_ostatnibet() <= 100 && g.get_faza() == 1) { Sprawdz(g); Obstaw(200, g); return 1; }
			if (g.get_ostatnibet() <= 100 && g.get_faza() == 2) { Sprawdz(g); Obstaw(100, g); return 1; }
			if (g.get_ostatnibet() <= 100 && g.get_faza() == 3) { Sprawdz(g); return 2; }
			if (g.get_ostatnibet() <= 200 && g.get_ostatnibet() > 100 && g.get_faza() == 1 || g.get_faza() == 3) { Sprawdz(g); return 2; }
			if (g.get_ostatnibet() <= 200 && g.get_ostatnibet() > 100 && g.get_faza() == 2) { Sprawdz(g); Obstaw(100, g); return 1; }
			if (g.get_ostatnibet() <= 500 && g.get_ostatnibet() > 200) { Sprawdz(g); return 2; }
			if (g.get_ostatnibet() <= kwota && g.get_ostatnibet() > 500 && g.get_faza() == 1) { Sprawdz(g); return 2; }
			if (g.get_ostatnibet() > kwota) { Obstaw(kwota, g); return 1; }
			else { Pass(g); return 3; }
			
			break;
		case 4:
			if (g.get_ostatnibet() <= 100 && g.get_faza() == 1) { Sprawdz(g); Obstaw(200, g); return 1; }
			if (g.get_ostatnibet() <= 100 && g.get_faza() == 2) { Sprawdz(g); Obstaw(200, g); return 1; }
			if (g.get_ostatnibet() <= 100 && g.get_faza() == 3) { Sprawdz(g); return 2; }
			if (g.get_ostatnibet() <= 200 && g.get_ostatnibet() > 100 && g.get_faza() == 1) { Sprawdz(g); Obstaw(200, g); return 1; }
			if (g.get_ostatnibet() <= 200 && g.get_ostatnibet() > 100 && g.get_faza() == 2) { Sprawdz(g); Obstaw(100, g); return 1; }
			if (g.get_ostatnibet() <= 200 && g.get_ostatnibet() > 100 && g.get_faza() == 3) { Sprawdz(g); return 2; }
			if (g.get_ostatnibet() > kwota) { Obstaw(kwota, g); return 1; }
			else { Sprawdz(g); return 2; }
			break;
		case 3:
			if (g.get_ostatnibet() <= 100 && g.get_faza() == 1) { Sprawdz(g); Obstaw(200, g); return 1; }
			if (g.get_ostatnibet() <= 100 && g.get_faza() == 2) { Sprawdz(g); Obstaw(200, g); return 1; }
			if (g.get_ostatnibet() <= 100 && g.get_faza() == 3) { Sprawdz(g); return 2; }
			if (g.get_ostatnibet() <= 200 && g.get_ostatnibet() > 100 && g.get_faza() == 1) { Sprawdz(g); Obstaw(200, g); return 1; }
			if (g.get_ostatnibet() <= 200 && g.get_ostatnibet() > 100 && g.get_faza() == 2) { Sprawdz(g); Obstaw(100, g); return 1; }
			if (g.get_ostatnibet() <= 200 && g.get_ostatnibet() > 100 && g.get_faza() == 3) { Sprawdz(g); return 2; }
			if (g.get_ostatnibet() > kwota) { Obstaw(kwota, g); return 1; }
			else { Sprawdz(g); return 2; }
			break;
		case 2:
			if (g.get_ostatnibet() <= 100 && g.get_faza() == 1) { Sprawdz(g); Obstaw(200, g); return 1; }
			if (g.get_ostatnibet() <= 100 && g.get_faza() == 2) { Sprawdz(g); Obstaw(200, g); return 1; }
			if (g.get_ostatnibet() <= 100 && g.get_faza() == 3) { Sprawdz(g); return 2; }
			if (g.get_ostatnibet() <= 200 && g.get_ostatnibet() > 100 && g.get_faza() == 1) { Sprawdz(g); Sprawdz(g); Obstaw(200, g); return 1; }
			if (g.get_ostatnibet() <= 200 && g.get_ostatnibet() > 100 && g.get_faza() == 2) { Sprawdz(g); Sprawdz(g); Obstaw(200, g); return 1; }
			if (g.get_ostatnibet() <= 200 && g.get_ostatnibet() > 100 && g.get_faza() == 3) { Sprawdz(g); return 2; }
			if (g.get_ostatnibet() <= 500 && g.get_ostatnibet() > 200 && g.get_faza() == 1) { Sprawdz(g); Sprawdz(g); Obstaw(200, g); return 1; }
			if (g.get_ostatnibet() <= kwota && g.get_ostatnibet() > 500 && g.get_faza() == 1) { Sprawdz(g); Sprawdz(g); Obstaw(200, g); return 1; }
			if (g.get_ostatnibet() > kwota) { Obstaw(kwota, g); return 1; }
			else { Sprawdz(g); return 2; }
			break;
		case 1:
			Obstaw(kwota, g);
			return 1;
			break;
		case 0:
			Obstaw(kwota, g);
			return 1;
			break;
		}
	}
	
}

Gracz::Gracz()
{
	Najwyzsza_karta = 0;
	kwota = 2000;
	ilosc_kart_wrece = 2;
}

int Gracz::getilosc_kart_wrece()
{
	return ilosc_kart_wrece;
}

void Gracz::setilosc_kart_wrece(int faza)
{
	ilosc_kart_wrece = faza + 2;
}

int operator>(Gracz& t, Gracz& d)
{
	if (t.kombinacja.kombinacja < d.kombinacja.kombinacja) return 1;
		if (t.kombinacja.kombinacja == d.kombinacja.kombinacja)
		{
			if (t.kombinacja.wartkomb > d.kombinacja.wartkomb) return 1;
			else if (t.kombinacja.wartkomb == d.kombinacja.wartkomb)
			{
				return 0;
			}
			else return -1;
		}
		else return -1;
	return 0;
}
