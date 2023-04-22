#include <iostream>
#include "Talia.h"
#include "Gra.h"
#include "Gracz.h"
#include <conio.h>
#include <SFML/Graphics.hpp>


using namespace std;
using namespace sf;
const int WYSOKOSC = 800;
const int SZEROKOSC = 1400;


int main()
{

	// tworzenie okna gry i ustawianie jego parametrow
	RenderWindow window(VideoMode(SZEROKOSC, WYSOKOSC), "Poker projekt",Style::Titlebar | Style::Close);
	window.setFramerateLimit(60);
	Event event1;
	Texture stol, karty_tylem, srodek;
	string s = "stol";
	stol.loadFromFile("img\\"+s+".jpg");
	karty_tylem.loadFromFile("img\\tyl.png");
	srodek.loadFromFile("img\\wspolne.png");
	Sprite tlo(stol);
	Sprite karty_przeciwnika(karty_tylem);
	Sprite wspolne(srodek);
	Sprite kartywspolne;
	Texture Twspolne , Tgracza;
	Sprite karta_gracza;
	wspolne.setPosition(450 , 260 );


	Text napis1,napis2;
	Font font;
	font.loadFromFile("Dosis-Light.ttf");
	napis1.setFont(font);
	napis1.setCharacterSize(30);
	napis1.setString("Gracz 1(TY)");
	napis1.setFillColor(Color::Black);
	napis1.setStyle(Text::Bold);
	napis1.setPosition(600, 450);

	

	napis2 = napis1;
	napis2.setString("Gracz 2");
	napis2.setPosition(600, 10);


	Gra gra;
	Talia talia;
	Gracz g1;
	Gracz g2;
	
	talia.StworzTalie();
	gra.DobierzKarte(talia);
	g1.DobierzDoReki(talia);
	g2.DobierzDoReki(talia);

	Text kwota1, kwota2, pula, ostatni_wygrany, klawisze, ostatni_bet, ruch_g1, ruch_g2;

	kwota1 =  kwota2 = pula = klawisze = ostatni_wygrany = ostatni_bet = ruch_g1 = ruch_g2 = napis1;


	kwota1.setPosition(600, 650);
	kwota2.setPosition(600, 200);


	pula.setPosition(60, 600);
	pula.setCharacterSize(50);

	ostatni_wygrany.setPosition(50, 50);
	ostatni_wygrany.setCharacterSize(30);

	ostatni_bet.setPosition(50,300);
	ostatni_bet.setCharacterSize(30);

	ruch_g1.setPosition(50,200);
	ruch_g2.setPosition(50, 250);

	klawisze.setPosition(1100, 100);
	klawisze.setCharacterSize(30);
	klawisze.setString("Przyciski - Sterowanie: \n Obstawianie: \n 1 - 50 \n 2 - 100 \n 3 - 200 \n 4 - 500 \n 5 - All in \n Q - Sprawdz  \n W - Pass \n Skoncz ruch - Enter  \n R - Reset gry");
	
	
	g2.set_czywgrze(1);
	

	g1.Obstaw(50,gra);
	
	g2.Obstaw(50, gra);

	gra.set_ostatnibet(0);
	

	int g1_ruch = 0;
	int g2_ruch = 0;
	int ostatni_wyg = 0;
	
	bool czysprawdzono = false;
	
	while (true)
	{
		window.clear(Color::Black);
		window.draw(tlo);
		
		karty_przeciwnika.setPosition(600, 50);
		window.draw(karty_przeciwnika);

		window.draw(wspolne);
		pula.setString("W puli: " + to_string(gra.get_pula()));
		kwota1.setString("kwota gracza: " + to_string(g1.get_kwota()));
		kwota2.setString("kwota gracza: " + to_string(g2.get_kwota()));
		switch (ostatni_wyg)
		{
		case 0:
			ostatni_wygrany.setString("Ostatni wygrany: ");
			break;
		case 1:
			ostatni_wygrany.setString("Ostatni wygrany: Gracz 1");
			break;
		case 2:
			ostatni_wygrany.setString("Ostatni wygrany: Gracz 2");
			break;
		}
		window.draw(napis1);
		window.draw(napis2);

		window.draw(kwota1);
		window.draw(kwota2);

		window.draw(ruch_g1);

		switch (g1_ruch)
		{
		case 1:
			ruch_g1.setString("Gracz 1: Obstawil ");
			break;
		case 2:
			ruch_g1.setString("Gracz 1: Sprawdzil");
			break;
		case 3:
			ruch_g1.setString("Gracz 1: Pass");
			break;
		default:
			ruch_g1.setString("Gracz 1: ");
			break;
		}

		window.draw(ruch_g2);

		switch (g2_ruch)
		{
		case 1:
			ruch_g2.setString("Gracz 2: Obstawil ");
			break;
		case 2:
			ruch_g2.setString("Gracz 2: Sprawdzil ");
			break;
		case 3:
			ruch_g2.setString("Gracz 2: Pass ");
			break;
		default:
			ruch_g2.setString("Gracz 2: ");
			break;
		}
		ostatni_bet.setString("Ostatni bet: ");
		if(gra.get_ostatnibet() != 0) ostatni_bet.setString("Ostatni bet: " + to_string(gra.get_ostatnibet()));
		window.draw(ostatni_bet);

		window.draw(pula);
		window.draw(ostatni_wygrany);
		window.draw(klawisze);

	
		for (int i = 0; i < 2; i++)
		{
			Tgracza.loadFromFile("img\\" + g1.get_reka_nazwa(i) + ".png");
			karta_gracza.setTexture(Tgracza);
			karta_gracza.setPosition(600 + i*40, 500);
			window.draw(karta_gracza);

		}
		if (gra.get_faza() == 1)
		{
			for (int i = 0; i < 3; i++)
			{
				if (gra.get_wspolne_nazwa(i) == "przykladowa") continue;
				Twspolne.loadFromFile("img\\" + gra.get_wspolne_nazwa(i) + ".png");
				kartywspolne.setTexture(Twspolne);
				kartywspolne.setPosition(450 + i * 100, 260);
				window.draw(kartywspolne);
			}

		}
		if (gra.get_faza() == 2 )
		{
			for (int i = 0; i < 4; i++)
			{
				if (gra.get_wspolne_nazwa(i) == "przykladowa") continue;
				Twspolne.loadFromFile("img\\" + gra.get_wspolne_nazwa(i) + ".png");
				kartywspolne.setTexture(Twspolne);
				kartywspolne.setPosition(450 + i * 100, 260);
				window.draw(kartywspolne);
			}

		}

		if (gra.get_faza() == 3 )
		{	
			for (int i = 0; i < 5; i++)
			{
				if (gra.get_wspolne_nazwa(i) == "przykladowa") continue;
				Twspolne.loadFromFile("img\\" + gra.get_wspolne_nazwa(i) + ".png");
				kartywspolne.setTexture(Twspolne);
				kartywspolne.setPosition(450 + i * 100, 260);
				window.draw(kartywspolne);
			}

		}
		if (gra.get_koniecgry() == true) break;
		
		
		while (window.pollEvent(event1))
		{
			switch (event1.type)
			{
			case Event::Closed():
				window.close();
				break;
			case Event::KeyPressed:
				if (event1.key.code == Keyboard::Num1)
				{
					if (czysprawdzono == false)
					g1_ruch = g1.Obstaw(50, gra);
					break;
				}
				if (event1.key.code == Keyboard::Num2)
				{
					if (czysprawdzono == false)
					g1_ruch = g1.Obstaw(100, gra);
					break;
				}
				if (event1.key.code == Keyboard::Num3)
				{
					if (czysprawdzono == false)
					g1_ruch = g1.Obstaw(200, gra);
					break;
				}
				if (event1.key.code == Keyboard::Num4)
				{
					if (czysprawdzono == false)
					g1_ruch = g1.Obstaw(500, gra);
					break;
				}
				if (event1.key.code == Keyboard::Num5)
				{
					if (czysprawdzono == false)
					g1_ruch = g1.Obstaw(g1.get_kwota(), gra);
					break;
				}
				if (event1.key.code == Keyboard::Q)
				{
					if (czysprawdzono == false)
					g1_ruch = g1.Sprawdz(gra);
					break;
				}
				if (event1.key.code == Keyboard::W)
				{
					if (czysprawdzono == false)
					g1_ruch = g1.Pass(gra);

					
					break;
				}

				if (event1.key.code == Keyboard::Enter) // zakoncz obstawianie
				{
					
					if(gra.get_faza() == 3) cout << "\nGracz 1 \n";
					gra.SprawdzGracza(g1);
					
					if (gra.get_faza() == 3) cout << "\nGracz 2 \n";
					WS wynik_g2 = gra.SprawdzGracza(g2);
					
					// ruch gracza
					if(czysprawdzono == false) g2_ruch = g2.RuchGracza(g1_ruch, wynik_g2,gra);
					
					if (g1.get_czywgrze() == false || g2.get_czywgrze() == false) gra.set_fazato(3);


					if (gra.get_faza() == 3)
					{
						if (gra.PorownajGraczy(g1, g2) > 0)
						{
							ostatni_wyg = 1;
						}
						else
						{
							ostatni_wyg = 2;
						}
						if (g1.get_czywgrze() == false || g2.get_czywgrze() == false)
						{
							if (g1.get_czywgrze() == false) ostatni_wyg = 2;
							if (g2.get_czywgrze() == false) ostatni_wyg = 1;
						}
						switch (ostatni_wyg)
						{
						case 1:
							if (czysprawdzono == false)
							{
								g1.setkwota(gra.get_pula());
								czysprawdzono = true;
							}
							break;
						case 2:
							if (czysprawdzono == false)
							{
								g2.setkwota(gra.get_pula());
								czysprawdzono = true;
							}						
							break;
						}
						if (g1.get_kwota() == 0 || g2.get_kwota() == 0)
						{
							gra.set_koniecgry(true);
						}
					}
					if (gra.get_faza() != 3 && g1_ruch != 0)
					{
						gra.nastepnafaza();
						g1.setilosc_kart_wrece(gra.get_faza());
						gra.DobierzKarte(talia);
						g1_ruch = 0;
						
					}
					break;
				}
				if (event1.key.code == Keyboard::Z)
				{
					gra.nastepnafaza();
					g1.setilosc_kart_wrece(gra.get_faza());
					gra.DobierzKarte(talia);
					break;
				}
				if (event1.key.code == Keyboard::R)
				{
					gra.set_fazato(1);
					talia.setdlugosctalii(52);
					gra.DobierzKarte(talia);
					g1.DobierzDoReki(talia);
					g2.DobierzDoReki(talia);
					gra.set_pula(-gra.get_pula());
					g2.set_czywgrze(1);
					g1.Obstaw(50,gra);
					g2.Obstaw(50, gra);
					czysprawdzono = false;
					g1_ruch = 0;
					g2_ruch = 0;
					g1.set_czywgrze(true);
					g2.set_czywgrze(true);
					gra.set_ostatnibet(0);
					
					
					break;
				}
			}
		}
		window.display();
	}
	
	if (g1.get_kwota() == 0) cout << "\n\nKONIEC GRY WYGRAL GRACZ NR 2\n\n";
	if (g2.get_kwota() == 0) cout << "\n\nKONIEC GRY WYGRAL GRACZ NR 1\n\n";
	
	


	/*Karty k1(2, 2, "");
	Karty k2(3, 1, "");
	Karty k3(4, 0, "");
	Karty k4(5, 1, "");
	Karty k5(12, 3, "");
	Karty k6(13, 0, "");
	Karty k7(14, 1, "");
	
	gra.TestowanieSprawdzania(k1, k2, k3, k4, k5, k6, k7);

	system("PAUSE");*/
	

   
}

