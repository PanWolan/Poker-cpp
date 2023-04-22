#include "Gra.h"


Gra::Gra()
{
	pula = 0;
	faza = 1;
	ostatni_bet = 0;
	koniec_gry = false;
}

void Gra::DobierzKarte(Talia& t)
{
	Karty k1(0, 4, "przykladowa");
	if (faza == 1)
	{
		wspolne[0] = t.Dobieranie();
		wspolne[1] = t.Dobieranie();
		wspolne[2] = t.Dobieranie();
		setwspolne(k1);
	}
	if(faza == 2) wspolne[3] = t.Dobieranie();
	if(faza == 3) wspolne[4] = t.Dobieranie();
		
}

WS Gra::SprawdzGracza(Gracz &g)
{
	Karty k1(0, 4, "przykladowa");
	if (faza == 1)
	{
		for (int i = 0; i < 3; i++)
		{
			
			karty_gracza[i] = wspolne[i];
			karty_gracza[3] = k1;
			karty_gracza[4] = k1;
		}
		karty_gracza[5] = g.get_reka(0);
		karty_gracza[6] = g.get_reka(1);
	}

	if (faza == 2)
	{
		for (int i = 0; i < 4; i++)
		{
			karty_gracza[i] = wspolne[i];
			karty_gracza[4] = k1;
		}
		karty_gracza[5] = g.get_reka(0);
		karty_gracza[6] = g.get_reka(1);
	}

	if (faza == 3)
	{
		for (int i = 0; i < 5; i++)
		{
			karty_gracza[i] = wspolne[i];
		}
		karty_gracza[5] = g.get_reka(0);
		karty_gracza[6] = g.get_reka(1);
	}
	
	if (faza == 3)
	{
		if (karty_gracza[5].get_kartaw() > karty_gracza[6].get_kartaw()) g.setNajwyzsza_karta(karty_gracza[5].get_kartaw());
		if (karty_gracza[6].get_kartaw() > karty_gracza[5].get_kartaw()) g.setNajwyzsza_karta(karty_gracza[6].get_kartaw());

	}
	
	if(get_faza() == 3)Wypisz();
	//Sortowanie Reki do Sprawdzania
	 SortowanieReki();
	// wywo³ania sprawdzen
	WS tabKombinacji[10] = { {0,0},  {0,0},  {0,0},  {0,0},  {0,0},  {0,0},  {0,0},  {0,0},  {0,0},  {0,0}};
	
	tabKombinacji[9] = Najwyzsza(); 
	tabKombinacji[8] = Para();
	tabKombinacji[7] = DwiePary();
	tabKombinacji[6] = Trojka();
	tabKombinacji[5] = Strit(); 
	tabKombinacji[4] = Kolor();
	tabKombinacji[3] = Ful(); // do sprawdzenia
	tabKombinacji[2] = Kareta();
	tabKombinacji[1] = Poker(); 
	tabKombinacji[0] = PokerKr();
	

	int id = 9;
	for (int i = 8; i >=0; i--)
	{
		if (tabKombinacji[i].kombinacja == 1) id = i;
	}
	if (get_faza() == 3)
	{
		switch (id)
		{
		case 0:
			cout << "Posiadasz Pokera krolewskiego ";
			break;
		case 1:
			cout << "Posiadasz Pokera o wartosci najzwyzszej karty " << tabKombinacji[id].wartkomb << endl;
			break;
		case 2:
			cout << "Posiadasz Karete o wartosci " << tabKombinacji[id].wartkomb << endl;
			break;
		case 3:
			cout << "Posiadasz Fula wartosci Trojek " << tabKombinacji[id].wartkomb << endl;
			break;
		case 4:
			cout << "Posiadasz Kolor " << endl;
			break;
		case 5:
			cout << "Posiadasz Strit o wartosci najwyzszej karty  " << tabKombinacji[id].wartkomb << endl;
			break;
		case 6:
			cout << "Posiadasz Trojke o wartosci " << tabKombinacji[id].wartkomb << endl;
			break;
		case 7:
			cout << "Posiadasz Dwie Pary " << tabKombinacji[id].wartkomb << endl;
			break;
		case 8:
			cout << "Posiadasz Pare o wartosci " << tabKombinacji[id].wartkomb << endl;
			break;
		case 9:
			cout << "Posiadasz Najzwysza karte o wartosci " << tabKombinacji[id].wartkomb << endl;
			break;
		default:
			cout << "Blad" << endl;
			break;
		}
	}
	
	WS wynik{id, tabKombinacji[id].wartkomb};
	g.setKombinacja(wynik);
	return wynik;
}

void Gra::Wypisz()
{
	for (int i = 0; i < 7; i++)
	{
		if (i == 5 || i == 6) cout << "Karta z reki: ";
		karty_gracza[i].WypiszKarte();
	}
	cout << "\n";
}

void Gra::SortowanieReki()
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (karty_gracza[j].get_kartaw() > karty_gracza[j+1].get_kartaw())
			{
				swap(karty_gracza[j], karty_gracza[j + 1]);
			}
		}
	}
}


int Gra::get_pula()
{
	return pula;
}

void Gra::set_pula(int i)
{
	pula += i;
}

void Gra::set_fazato(int i)
{
	faza = i;
}

void Gra::nastepnafaza()
{
	faza++;
}

int Gra::get_faza()
{
	return faza;
}

int Gra::get_ostatnibet()
{
	return ostatni_bet;
}

void Gra::set_ostatnibet(int i)
{
	ostatni_bet = i;
}

bool Gra::get_koniecgry()
{
	return koniec_gry;
}

void Gra::set_koniecgry(bool i)
{
	koniec_gry = i;
}



WS Gra::Najwyzsza()
{
	WS najw{1,karty_gracza[6].get_kartaw()};
	return najw;
}

WS Gra::Para()
{
	WS Para{0,0};
	for (int i = 6; i > 0; i--)
	{
		if (karty_gracza[i].get_kartaw() == karty_gracza[i - 1].get_kartaw() && karty_gracza[i].get_kartaw() != 0)
		{
			Para.wartkomb = karty_gracza[i].get_kartaw();
			Para.kombinacja = 1;
			return Para;
		}
	}
	return Para;
}

WS Gra::DwiePary()
{
	WS dwiepary{0,0};
	int licznik = 0;
	for (int i = 6; i > 0; i--)
	{
		if (karty_gracza[i].get_kartaw() == karty_gracza[i - 1].get_kartaw() && karty_gracza[i].get_kartaw() != 0)
		{
			if(licznik == 0) dwiepary.wartkomb = karty_gracza[i].get_kartaw();
			licznik++;
			
		}
		if (licznik == 2)
		{
			dwiepary.kombinacja = 1;
			return dwiepary;
		}
	}
	return dwiepary;
}

WS Gra::Trojka()
{
	WS Trojka{0,0};
	for (int i = 6; i > 1; i--)
	{

		if (karty_gracza[i].get_kartaw() == karty_gracza[i - 1].get_kartaw() 
			&& karty_gracza[i].get_kartaw() == karty_gracza[i - 2].get_kartaw()
			&& karty_gracza[i].get_kartaw() != 0)
		{
			Trojka.kombinacja = 1;
			Trojka.wartkomb = karty_gracza[i].get_kartaw();
		}
	}
	return Trojka;
}

WS Gra::Strit()
{
	int licznik = 0;
	WS strit{ 0,0 };

	for (int i = 6; i > 1; i--)
	{
		licznik = 1;
		for (int j = 1; j < 5; j++)
		{
			if (karty_gracza[i].get_kartaw() == karty_gracza[i - j].get_kartaw() + j)
			{
				licznik++;
			}
			else break;
		}
		if (licznik == 5)
		{
			strit.kombinacja = 1;
			strit.wartkomb = karty_gracza[i].get_kartaw();
		}
		if (licznik == 4 && karty_gracza[i].get_kartaw() == 5 && karty_gracza[6].get_kartaw() == 14)
		{
			strit.kombinacja = 1;
			strit.wartkomb = 5;
		}
	}
	return strit;
}

WS Gra::Ful()
{
	WS Ful{ 0,0 };
	int licznik = 0;
	bool trojka = false;
	bool para = false;

	for (int i = 6; i > 3-faza; i--)
	{
		licznik = 1;
		for (int j = 0; j < i; j++)
		{
			if (karty_gracza[i].get_kartaw() == karty_gracza[i - j - 1].get_kartaw())
			{
				licznik++;
			}
			if (licznik == 2 && karty_gracza[i].get_kartaw() != Ful.wartkomb)
			{

				para = true;
				
			}
			if (licznik == 3)
			{
				licznik = 0;
				para = false;
				trojka = true;
				Ful.wartkomb = karty_gracza[i].get_kartaw();
				break;
			}
			if (para == true && trojka == true)
			{
				Ful.kombinacja = 1;
				return Ful;
			}
		}
		
	}
	return Ful;

}

WS Gra::Kolor()
{
	int k;
	int licznik = 0;
	WS kolor{0,0};
	for (int i = 0; i < 6; i++)
	{
		k = karty_gracza[i].get_kartak();
		licznik = 0;
		for (int j = 0; j < 7; j++)
		{
			if (k == karty_gracza[j].get_kartak())
			{
				licznik++;
			}
			if (licznik == 5)
			{
				kolor.kombinacja = 1;
				WS tmp = Najwyzsza();
				kolor.wartkomb = tmp.wartkomb;
				return kolor;
			}
		}
	}
	return kolor;
}

WS Gra::Kareta()
{
	
	WS Kareta{0,0};
	for (int i = 6; i > 2; i--)
	{
		if (karty_gracza[i].get_kartaw() == karty_gracza[i - 1].get_kartaw() 
			&& karty_gracza[i].get_kartaw() == karty_gracza[i - 2].get_kartaw()
			&& karty_gracza[i].get_kartaw() == karty_gracza[i - 3].get_kartaw())
		{
			Kareta.kombinacja = 1;
			Kareta.wartkomb = karty_gracza[i].get_kartaw();
		}
	}
	return Kareta;
}

WS Gra::Poker()
{
	int licznik = 0;
	WS poker{ 0,0 };
	for (int i = 6; i > 1; i--)
	{
		licznik = 1;
		for (int j = 1; j < 5; j++)
		{
			if (karty_gracza[i].get_kartaw() == karty_gracza[i - j].get_kartaw() + j)
			{
				licznik++;
			}
			else break;
		}
		if (licznik == 5)
		{
			poker.kombinacja = 1;
			poker.wartkomb = karty_gracza[i].get_kartaw();
		}
		if (licznik == 4 && karty_gracza[i].get_kartaw() == 5 && karty_gracza[6].get_kartaw() == 14)
		{
			poker.kombinacja = 1;
			poker.wartkomb = 5;
		}
	}
	WS kol = Kolor();
	if (poker.kombinacja == 1 && kol.kombinacja != 1)
	{
		poker.kombinacja = 0;
	}
	return poker;
}

WS Gra::PokerKr()
{
	WS pokerkr = Poker();
	if (pokerkr.kombinacja == 1 && pokerkr.wartkomb == 14)
	{
		return pokerkr;
	}
	else
	{
		pokerkr.kombinacja = 0;
		pokerkr.wartkomb = 0;
		return pokerkr;
	}
	

}

string Gra::get_wspolne_nazwa(int i)
{
	return wspolne[i].get_kartan();
}




void Gra::setwspolne(Karty k)
{
		wspolne[3] = k;
		wspolne[4] = k;
}

void Gra::TestowanieSprawdzania(Karty k1, Karty k2, Karty k3, Karty k4, Karty k5, Karty k6, Karty k7)
{
	karty_gracza[0] = k1;
	karty_gracza[1] = k2;
	karty_gracza[2] = k3;
	karty_gracza[3] = k4;
	karty_gracza[4] = k5;
	karty_gracza[5] = k6;
	karty_gracza[6] = k7;

	//Sortowanie Reki do Sprawdzania
	SortowanieReki();
	// wywo³ania sprawdzen

	tabKombinacji[9] = Najwyzsza();
	tabKombinacji[8] = Para();
	tabKombinacji[7] = DwiePary();
	tabKombinacji[6] = Trojka();
	tabKombinacji[5] = Strit();
	tabKombinacji[4] = Kolor();
	tabKombinacji[3] = Ful();
	tabKombinacji[2] = Kareta();
	tabKombinacji[1] = Poker();
	tabKombinacji[0] = PokerKr();
	// usuwanie wartosci zawartych w innych
	int id = 9;
	for (int i = 8; i >= 0; i--)
	{
		if (tabKombinacji[i].kombinacja == 1) id = i;
	}
	switch (id)
	{
	case 0:
		cout << "Posiadasz Pokera krolewskiego ";
		break;
	case 1:
		cout << "Posiadasz Pokera o wartosci najzwyzszej karty " << tabKombinacji[id].wartkomb << endl;
		break;
	case 2:
		cout << "Posiadasz Karete o wartosci " << tabKombinacji[id].wartkomb << endl;
		break;
	case 3:
		cout << "Posiadasz Fula wartosci Trojek " << tabKombinacji[id].wartkomb << endl;
		break;
	case 4:
		cout << "Posiadasz Kolor " << endl;
		break;
	case 5:
		cout << "Posiadasz Strit o wartosci najwyzszej karty  " << tabKombinacji[id].wartkomb << endl;
		break;
	case 6:
		cout << "Posiadasz Trojke o wartosci " << tabKombinacji[id].wartkomb << endl;
		break;
	case 7:
		cout << "Posiadasz Dwie Pary " << tabKombinacji[id].wartkomb << endl;
		break;
	case 8:
		cout << "Posiadasz Pare o wartosci " << tabKombinacji[id].wartkomb << endl;
		break;
	case 9:
		cout << "Posiadasz Najzwysza karte o wartosci " << tabKombinacji[id].wartkomb << endl;
		break;
	default:
		cout << "Blad" << endl;
		break;
	}
}

int Gra::PorownajGraczy(Gracz g1, Gracz g2)
{
	if (g1 > g2 == 1) return 1;
	if (g1 > g2 == 0)
	{
		if (g1.Najwyzsza_karta > g2.Najwyzsza_karta) return 1;
		else return -1;
	}
	else return -1;
}

