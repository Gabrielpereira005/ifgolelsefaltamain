#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>  // <-- Adicionado
#include <vector>  // <-- Adicionado

using namespace std;

void ExibirMenu()
{
	cout << "Seja bem-vindo ao IF GOL ELSE FALTA" << endl;
	cout << " " << endl;
	cout << "Selecione a modalidade que deseja simular seu torneio:" << endl;
	cout << "1 - BRASILEIRAO" << endl;
	cout << "2 - LA LIGA" << endl;
	cout << "3 - PREMIERE LEAGUE" << endl;
	cout << "4 - CHAMPIONS LEAGUE" << endl;
	cout << "5 - FACA VOCE MESMO" << endl;
}

void SelecBrasileirao()
{
	cout << "Voce selecionou o modo BRASILEIRAO" << endl;
	
	// 1. Criar o array (compatível com C++98)
	string times_array[] = {
		"Palmeiras", "Flamengo", "Cruzeiro", "Mirassol", "Bahia",
		"Botafogo", "Fluminense", "Sao Paulo", "Vasco", "Corinthians",
		"Gremio", "Ceara", "Atletico Mineiro", "RB Bragantino",
		"Internacional", "Santos", "Vitoria", "Fortaleza",
		"Juventude", "Sport"
	};
	int num_times = sizeof(times_array) / sizeof(times_array[0]);
	
	// 2. Criar o vetor a partir do array
	vector<string> times(times_array, times_array + num_times);
	
	cout << "Times participantes:" << endl;
	// 3. Listar os times usando o loop
	for(size_t i = 0; i < times.size(); ++i) {
		cout << (i + 1) << " - " << times[i] << endl;
	}
	
	// 4. Pedir a seleção do time
	int timeEscolhido;
	cout << "\nEscolha o seu time (digite o numero): ";
	cin >> timeEscolhido;

	if(timeEscolhido >= 1 && timeEscolhido <= (int)times.size()) {
		cout << "Voce escolheu: " << times[timeEscolhido - 1] << "!" << endl;
	} else {
		cout << "Selecao invalida." << endl;
	}
}

void SelecLaliga()
{
	cout << "Voce selecionou o modo LA LIGA" << endl;
	
	string times_array[] = {
		"Real Madrid", "Barcelona", "Vilarreal", "Atletico de Madrid",
		"Real Betis", "Espanyol", "Getafe", "Alaves", "Elche",
		"Rayo Vallencano", "Athletic Club", "Celta", "Sevilla",
		"Real Sociedad", "Osasuna", "Levante", "Mallorca", "Valencia",
		"Real Oviedo", "Girona"
	};
	int num_times = sizeof(times_array) / sizeof(times_array[0]);
	vector<string> times(times_array, times_array + num_times);

	cout << "Times participantes:" << endl;
	for(size_t i = 0; i < times.size(); ++i) {
		cout << (i + 1) << " - " << times[i] << endl;
	}

	int timeEscolhido;
	cout << "\nEscolha o seu time (digite o numero): ";
	cin >> timeEscolhido;

	if(timeEscolhido >= 1 && timeEscolhido <= (int)times.size()) {
		cout << "Voce escolheu: " << times[timeEscolhido - 1] << "!" << endl;
	} else {
		cout << "Selecao invalida." << endl;
	}
}

void SelecPremierLeague()
{
	cout << "Voce selecionou o modo PREMIERE LEAGUE" << endl;
	
	string times_array[] = {
		"Arsenal", "Manchester City", "Liverpool", "Sunderland",
		"Bournemouth", "Tottenham", "Chelsea", "Manchester United",
		"Crystal Palace", "Brighton", "Aston Villa", "Brentford",
		"Newcastle", "Everton", "Fullham", "Leeds", "Burnley",
		"West Ham", "Nottingham Forest", "Wolves"
	};
	int num_times = sizeof(times_array) / sizeof(times_array[0]);
	vector<string> times(times_array, times_array + num_times);

	cout << "Times participantes:" << endl;
	for(size_t i = 0; i < times.size(); ++i) {
		cout << (i + 1) << " - " << times[i] << endl;
	}

	int timeEscolhido;
	cout << "\nEscolha o seu time (digite o numero): ";
	cin >> timeEscolhido;

	if(timeEscolhido >= 1 && timeEscolhido <= (int)times.size()) {
		cout << "Voce escolheu: " << times[timeEscolhido - 1] << "!" << endl;
	} else {
		cout << "Selecao invalida." << endl;
	}
}

void SelecChampionsLeague()
{
	cout << "Voce selecionou o modo CHAMPIONS LEAGUE" << endl;

	string times_array[] = {
		"PSG", "Bayern", "Inter", "Arsenal", "Real Madrid", "Borussia",
		"Manchester City", "Newcastle", "Barcelona", "Liverpool",
		"Chelsea", "Sporting", "Qarabag", "Galatasaray", "Tottenham",
		"PSV", "Atalanta", "Marseille", "Atletico de Madrid",
		"Club Brugge", "Athletic Club", "Frankfurt", "Napoli",
		"USG", "Juventus", "Glimt", "AS Monaco", "Slavia Praha",
		"Pafos", "Leverkusen", "Villareal", "Kobenhavn",
		"Olympiacos", "Kairat", "Benfica", "Ajax"
	};
	int num_times = sizeof(times_array) / sizeof(times_array[0]);
	vector<string> times(times_array, times_array + num_times);
	
	cout << "Times participantes:" << endl;
	for(size_t i = 0; i < times.size(); ++i) {
		cout << (i + 1) << " - " << times[i] << endl;
	}

	int timeEscolhido;
	cout << "\nEscolha o seu time (digite o numero): ";
	cin >> timeEscolhido;

	if(timeEscolhido >= 1 && timeEscolhido <= (int)times.size()) {
		cout << "Voce escolheu: " << times[timeEscolhido - 1] << "!" << endl;
	} else {
		cout << "Selecao invalida." << endl;
	}
}

void SelecFacaVoceMesmo ()
{
	cout << "Voce selecionou o modo FACA VOCE MESMO" << endl;
	// Aqui você pode adicionar a lógica para o usuário digitar
	// os próprios nomes dos times.
}

int main()
{
	int modo;

	ExibirMenu();
	cin >> modo;

	if(modo == 1)
	{
		SelecBrasileirao();
		// cin >> modo;  <-- Removido (não precisa ler de novo)
	}
	else if(modo == 2)
	{
		SelecLaliga();
		// cin >> modo;  <-- Removido
	}
	else if(modo == 3)
	{
		SelecPremierLeague();
		// cin >> modo;  <-- Removido
	}
	else if(modo == 4)
	{
		SelecChampionsLeague();
		// cin >> modo;  <-- Removido
	}
	else if(modo == 5)
	{
		SelecFacaVoceMesmo();
		// cin >> modo;  <-- Removido
	}
	else
	{
		cout << "Opcao invalida!" << endl;
	}

	return 0;
}
