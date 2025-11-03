#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	int modo;
	
	cout << "Seja bem-vindo ao IF GOL ELSE FALTA" << endl;
	cout << " " << endl;
	cout << "Selecione a modalidade que deseja simular seu torneio:" << endl;
	cout << "1 - BRASILEIRAO" << endl;
	cout << "2 - LA LIGA" << endl;
	cout << "3 - PREMIERE LEAGUE" << endl;
	cout << "4 - CHAMPIONS LEAGUE" << endl;
	cout << "5 - FACA VOCE MESMO" << endl;
	
	cin >> modo;
	
	if(modo == 1)
	{
		cout << "Voce selecionou o modo BRASILEIRAO" << endl;
		cout << "Times participantes:" << endl;
		cout << "Palmeiras" << endl;
		cout << "Flamengo" << endl;
		cout << "Cruzeiro" << endl;
		cout << "Mirassol" << endl;
		cout << "Bahia" << endl;
		cout << "Botafogo" << endl;
		cout << "Fluminense" << endl;
		cout << "Sao Paulo" << endl;
		cout << "Vasco" << endl;
		cout << "Corinthians" << endl;
		cout << "Gremio" << endl;
		cout << "Ceara" << endl;
		cout << "Atletico Mineiro" << endl;
		cout << "RB Bragantino" << endl;
		cout << "Internacional" << endl;
		cout << "Santos" << endl;
		cout << "Vitoria" << endl;
		cout << "Fortaleza" << endl;
		cout << "Juventude" << endl;
		cout << "Sport" << endl;
	}
	
	else if(modo == 2)
	{
		cout << "Voce selecionou o modo LA LIGA" << endl;
		cout << "Times participantes:" << endl;
		cout << "Real Madrid" << endl;
		cout << "Barcelona" << endl;
		cout << "Vilarreal" << endl;
		cout << "Atletico de Madrid" << endl;
		cout << "Real Betis" << endl;
		cout << "Espanyol" << endl;
		cout << "Getafe" << endl;
		cout << "Alaves" << endl;
		cout << "Elche" << endl;
		cout << "Rayo Vallencano" << endl;
		cout << "Athletic Club" << endl;
		cout << "Celta" << endl;
		cout << "Sevilla" << endl;
		cout << "Real Sociedad" << endl;
		cout << "Osasuna" << endl;
		cout << "Levante" << endl;
		cout << "Mallorca" << endl;
		cout << "Valencia" << endl;
		cout << "Real Oviedo" << endl;
		cout << "Girona" << endl;
	}
	
	else if(modo == 3)
	{
		cout << "Voce selecionou o modo PREMIERE LEAGUE" << endl;
		cout << "Times participantes:" << endl;
		cout << "Arsenal" << endl;
		cout << "Manchester City" << endl;
		cout << "Liverpool" << endl;
		cout << "Sunderland" << endl;
		cout << "Bournemouth" << endl;
		cout << "Tottenham" << endl;
		cout << "Chelsea" << endl;
		cout << "Manchester United" << endl;
		cout << "Crystal Palace" << endl;
		cout << "Brighton" << endl;
		cout << "Aston Villa" << endl;
		cout << "Brentford" << endl;
		cout << "Newcastle" << endl;
		cout << "Everton" << endl;
		cout << "Fullham" << endl;
		cout << "Leeds" << endl;
		cout << "Burnley" << endl;
		cout << "West Ham" << endl;
		cout << "Nottingham Forest" << endl;
		cout << "Wolves" << endl;
	}
	
	else if(modo == 4)
	{
		cout << "Voce selecionou o modo CHAMPIONS LEAGUE" << endl;
		cout << "Times participantes:" << endl;
		cout << "PSG" << endl;
		cout << "Bayern" << endl;
		cout << "Inter" << endl;
		cout << "Arsenal" << endl;
		cout << "Real Madrid" << endl;
		cout << "Borussia" << endl;
		cout << "Manchester City" << endl;
		cout << "Newcastle" << endl;
		cout << "Barcelona" << endl;
		cout << "Liverpool" << endl;
		cout << "Chelsea" << endl;
		cout << "Sporting" << endl;
		cout << "Qarabag" << endl;
		cout << "Galatasaray" << endl;
		cout << "Tottenham" << endl;
		cout << "PSV" << endl;
		cout << "Atalanta" << endl;
		cout << "Marseille" << endl;
		cout << "Atletico de Madrid" << endl;
		cout << "Club Brugge" << endl;
		cout << "Athletic Club" << endl;
		cout << "Frankfurt" << endl;
		cout << "Napoli" << endl;
		cout << "USG" << endl;
		cout << "Juventus" << endl;
		cout << "Glimt" << endl;
		cout << "AS Monaco" << endl;
		cout << "Slavia Praha" << endl;
		cout << "Pafos" << endl;
		cout << "Leverkusen" << endl;
		cout << "Villareal" << endl;
		cout << "Kobenhavn" << endl;
		cout << "Olympiacos" << endl;
		cout << "Kairat" << endl;
		cout << "Benfica" << endl;
		cout << "Ajax" << endl;
		
	}
	
	else if(modo == 5)
	{
		cout << "Voce selecionou o modo FACA VOCE MESMO" << endl;
	}
	
	return 0;
}