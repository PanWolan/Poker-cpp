#include "Talia.h"

Talia::Talia()
{
	dlugoscTalii = 52;
	srand(time(NULL));
}

// kolory 0-3
// wart 2-14 // 11 = Jopek // 12 = Dama // 13 = Krol // 14 = AS
void Talia::DodajKarte(const Karty& k, int nr)
{
	mTalia[nr] = k;
}

Karty Talia::StworzKarte(int wart, int kol, string nazw)
{
	Karty k(wart, kol, nazw);
	return k;
}

void Talia::StworzTalie()
{
	string tmp ="Blad";
	for (int i = 0; i < 52; i++)
	{
		switch (i % 13 + 2)
		{
		case 14:
			tmp = "As ";
			break;
		case 2:
			tmp = "2 ";
			break;
		case 3:
			tmp = "3 ";
			break;
		case 4:
			tmp = "4 ";
			break;
		case 5:
			tmp = "5 ";
			break;
		case 6:
			tmp = "6 ";
			break;
		case 7:
			tmp = "7 ";
			break;
		case 8:
			tmp = "8 ";
			break;
		case 9:
			tmp = "9 ";
			break;
		case 10:
			tmp = "10 ";
			break;
		case 11:
			tmp = "Jopek ";
			break;
		case 12:
			tmp = "Dama ";
			break;
		case 13:
			tmp = "Krol ";
			break;
		default:
			cout << "B³¹d tworzenia kart ";
			break;
		}

		switch (i % 4)
		{
		case 0:
			tmp += "Pik";
			break;
		case 1:
			tmp += "Trefl";
			break;
		case 2:
			tmp += "Karo";
			break;
		case 3:
			tmp += "Kier";
			break;
		default:
			cout << "B³¹d tworzenia kart ";
			break;
		}
		DodajKarte(StworzKarte(i % 13 + 2, i % 4,tmp), i);
	}
}


int Talia::getdlugosctalii()
{
	return dlugoscTalii;
}

void Talia::setdlugosctalii(int i)
{
	dlugoscTalii = i;
}

void Talia::WypiszTalie()
{
	int licznik = 1;
	for (int i = 0; i < dlugoscTalii; i++)
	{
		cout << licznik<<". ";
		mTalia[i].WypiszKarte();
		licznik++;
	}
}

void Talia::TasujTalie()
{
	for (int i = 0; i < 30; i++)
	{
		int n1 = rand() % dlugoscTalii;
		int n2 = rand() % dlugoscTalii;
		Karty k = mTalia[n1];
		mTalia[n1] = mTalia[n2];
		mTalia[n2] = k;
	}
	/*int przesuniecie = 0;  
	for (int j = 0; j < dlugoscTalii; j++)
	{
		if (j % 2 == 0)
		{
			Karty k = mTalia[j - przesuniecie];
			mTalia[j] = mTalia[j + dlugoscTalii / 2 - przesuniecie];
			mTalia[j + 1] = k;
			przesuniecie++;
		}
	}*/
}

Karty Talia::Dobieranie()
{
	int numer = rand() % dlugoscTalii;
	Karty k = mTalia[numer];
	mTalia[numer] = mTalia[dlugoscTalii-1];
	mTalia[dlugoscTalii-1] = k;
	dlugoscTalii--;
	TasujTalie();
	
	return k;
}



