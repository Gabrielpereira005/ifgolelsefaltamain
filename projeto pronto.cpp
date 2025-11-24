#include <iostream>
#include <string>
#include <cstdlib>    // pra usar rand e gerar opções aleatórias

using namespace std;

// constantes: pontos de vitoria e empate
const int MAX_TIMES_PADRAO = 20;
const int MAX_TIMES_CHAMPIONS = 36;
const int pontosVitoria = 3; 
const int pontosEmpate = 1;

// vetor: lista de times do Brasileirao
string timesBrasileirao[] = { 
    "Palmeiras", "Flamengo", "Cruzeiro", "Mirassol", "Bahia",
    "Botafogo", "Fluminense", "Sao Paulo", "Vasco", "Corinthians",
    "Gremio", "Ceara", "Atletico Mineiro", "RB Bragantino",
    "Internacional", "Santos", "Vitoria", "Fortaleza",
    "Juventude", "Sport"
};

// vetor: lista de times da La Liga
string timesLaLiga[] = {
    "Real Madrid", "Barcelona", "Vilarreal", "Atletico de Madrid",
    "Real Betis", "Espanyol", "Getafe", "Alaves", "Elche",
    "Rayo Vallencano", "Athletic Club", "Celta", "Sevilla",
    "Real Sociedad", "Osasuna", "Levante", "Mallorca", "Valencia",
    "Real Oviedo", "Girona"
};

// vetor: lista de times da Premier League
string timesPremier[] = {
    "Arsenal", "Manchester City", "Liverpool", "Sunderland",
    "Bournemouth", "Tottenham", "Chelsea", "Manchester United",
    "Crystal Palace", "Brighton", "Aston Villa", "Brentford",
    "Newcastle", "Everton", "Fullham", "Leeds", "Burnley",
    "West Ham", "Nottingham Forest", "Wolves"
};

// vetor: lista de times da Champions
string timesChampions[] = {
    "PSG", "Bayern", "Inter", "Arsenal", "Real Madrid", "Borussia",
    "Manchester City", "Newcastle", "Barcelona", "Liverpool",
    "Chelsea", "Sporting", "Qarabag", "Galatasaray", "Tottenham",
    "PSV", "Atalanta", "Marseille", "Atletico de Madrid",
    "Club Brugge", "Athletic Club", "Frankfurt", "Napoli",
    "USG", "Juventus", "Glimt", "AS Monaco", "Slavia Praha",
    "Pafos", "Leverkusen", "Villareal", "Kobenhavn",
    "Olympiacos", "Kairat", "Benfica", "Ajax"
};

// funcao: mostra o menu principal
void menu() {
    cout << "SISTEMA DE CAMPEONATOS" << endl;
    cout << "----------------------" << endl;
    cout << "1 - Brasileirao" << endl;
    cout << "2 - La Liga" << endl;
    cout << "3 - Premier League" << endl;
    cout << "4 - Champions League" << endl;
    cout << "5 - Criar o seu (Custom)" << endl;
    cout << "0 - Sair" << endl;
    cout << "----------------------" << endl;
}

// funcao: simula um jogo, gera placares e atualiza a pontuacao
// vetor: usa vetores paralelos (pontosTimes e timesNomes)
void jogoSimples(int pontosTimes[], const string timesNomes[], int indiceTimeA, int indiceTimeB) {
    // rand() % 5: gera um numero aleatorio de gols entre 0 e 4 para cada time
    int golsTimeA = rand() % 5;
    int golsTimeB = rand() % 5;
    
    // string: exibe o placar real da simulacao
    cout << timesNomes[indiceTimeA] << " " << golsTimeA << " x " << golsTimeB << " " << timesNomes[indiceTimeB];

    // if/else: define o resultado e aplica os pontos
    if (golsTimeA > golsTimeB) { // if: Time A venceu
        pontosTimes[indiceTimeA] += pontosVitoria;
        cout << " -> Vitoria de " << timesNomes[indiceTimeA] << endl;
    } else if (golsTimeB > golsTimeA) { // else if: Time B venceu
        pontosTimes[indiceTimeB] += pontosVitoria;
        cout << " -> Vitoria de " << timesNomes[indiceTimeB] << endl;
    } else { // else: Empate
        pontosTimes[indiceTimeA] += pontosEmpate;
        pontosTimes[indiceTimeB] += pontosEmpate;
        cout << " -> Empate" << endl;
    }
}

// funcao: ordena os dois vetores em paralelo (selection sort)
// vetor: ordena o vetor de nomes[] e o de pontos[] juntos
void ordenarTabela(string timesNomes[], int pontosTimes[], int numTimes) { 
    int i, j, indiceMaior; 
    
    // vetor: variaveis temporarias para a troca
    int tempPontos;
    string tempNome; 

    for (i = 0; i < numTimes - 1; i++) {
        indiceMaior = i;
        for (j = i + 1; j < numTimes; j++) {
            if (pontosTimes[j] > pontosTimes[indiceMaior]) {
                indiceMaior = j;
            }
        }
        // if: verifica se precisa trocar
        if (indiceMaior != i) {
            // troca os pontos (vetor de int)
            tempPontos = pontosTimes[i];
            pontosTimes[i] = pontosTimes[indiceMaior];
            pontosTimes[indiceMaior] = tempPontos;
            
            // troca os nomes (vetor de string)
            tempNome = timesNomes[i]; 
            timesNomes[i] = timesNomes[indiceMaior];
            timesNomes[indiceMaior] = tempNome;
        }
    }
}

// funcao: mostra a tabela e o g4/z4
// vetor: exibe o conteudo dos vetores de nomes e pontos
void verTabela(string timesNomes[], int pontosTimes[], int numTimes, int numRebaixados) {
    ordenarTabela(timesNomes, pontosTimes, numTimes); 

    cout << endl << "TABELA FINAL (Pontos Corridos)" << endl;
    cout << "Pos | Time                           | Pts" << endl;
    cout << "----------------------------------------" << endl;

    // for: exibe cada time do vetor ordenado
    for (int i = 0; i < numTimes; i++) {
        cout << i + 1 << " | " << timesNomes[i];
        for(int s = 0; s < 30 - (int)timesNomes[i].length(); s++) cout << " ";
        cout << "| " << pontosTimes[i] << endl;
    }
    cout << "========================================" << endl;
    cout << "CAMPEAO: " << timesNomes[0] << endl;
    
    // if: logica para mostrar classificados/rebaixados
    if (numTimes >= 8) {
        cout << endl << "[ G4 - Classificados ]" << endl;
        for (int i = 0; i < 4; i++) cout << i + 1 << " - " << timesNomes[i] << endl;

        cout << endl << "[ Z" << numRebaixados << " - Rebaixados ]" << endl;
        int inicioZonaRebaixamento = numTimes - numRebaixados; 
        if (inicioZonaRebaixamento < 4) inicioZonaRebaixamento = 4;
        
        // for: exibe os rebaixados (fim do vetor)
        for (int i = inicioZonaRebaixamento; i < numTimes; i++) {
            cout << i + 1 << " - " << timesNomes[i] << endl;
        }
    }
}

// funcao: carrega e simula o modo de pontos corridos
void carregarPontosCorridos(const string& nomeCampeonato, string listaNomesTimes[], int numTimes, int numRebaixados) {
    cout << endl << "Modo: " << nomeCampeonato << " (" << numTimes << " times)" << endl;

    // vetor: copia a lista de nomes para um vetor auxiliar
    string timesSimulacao[numTimes];
    for(int i=0; i<numTimes; i++) {
        timesSimulacao[i] = listaNomesTimes[i];
    }
    
    // vetor: cria e inicializa o vetor de pontos com zero
    int pontosSimulacao[numTimes];
    for (int i = 0; i < numTimes; i++) {
        pontosSimulacao[i] = 0; 
    }
    
    cout << endl << "Simulando jogos (ida e volta)..." << endl;

    // for aninhado: logica principal de pontos corridos
    for (int i = 0; i < numTimes; i++) {
        for (int j = i + 1; j < numTimes; j++) {
            // jogo de ida e volta
            jogoSimples(pontosSimulacao, timesSimulacao, i, j); 
            jogoSimples(pontosSimulacao, timesSimulacao, j, i); 
        }
    }
    
    // passa os dois vetores para a funcao de exibicao
    verTabela(timesSimulacao, pontosSimulacao, numTimes, numRebaixados);
}

// funcao: simula uma partida mata-mata (ida e volta)
// string: retorna o nome do vencedor
string mataMata(const string& timeA, const string& timeB) { 
    // rand(): simula placares simples
    // A logica aqui precisa ser atualizada para considerar placares variaveis
    int idaTimeA = rand() % 4, idaTimeB = rand() % 4; 
    int voltaTimeA = rand() % 4, voltaTimeB = rand() % 4; 
    
    int totalTimeA = idaTimeA + voltaTimeA; 
    int totalTimeB = idaTimeB + voltaTimeB; 

    cout << " > " << timeA << " vs " << timeB << " | Placar: " << totalTimeA << " x " << totalTimeB << " | Passou: ";
    
    // if/else: define o classificado
    if (totalTimeA > totalTimeB) { 
        cout << timeA << endl; 
        return timeA; 
    }
    else if (totalTimeB > totalTimeA) { 
        cout << timeB << endl; 
        return timeB; 
    }
    else {
        // desempate por penaltis (sorteio simples)
        if (rand() % 2 == 0) { 
            cout << timeA << " (Penaltis)" << endl; 
            return timeA; 
        }
        else { 
            cout << timeB << " (Penaltis)" << endl; 
            return timeB; 
        }
    }
}

// funcao: simula uma rodada inteira de mata-mata
// vetor: timesRodadaAnterior e timesClassificados sao vetores de string
void rodadaMataMata(string timesRodadaAnterior[], int numTimes, string timesClassificados[], const string& nomeFase) { 
    if (numTimes < 2 || numTimes % 2 != 0) return;
    cout << endl << nomeFase << " (" << numTimes << " Times)" << endl;
    cout << "-----------------------------------" << endl;
    
    int contadorClassificados = 0; 
    // for: percorre o vetor de 2 em 2 para simular os confrontos
    for (int i = 0; i < numTimes; i += 2) {
        timesClassificados[contadorClassificados] = mataMata(timesRodadaAnterior[i], timesRodadaAnterior[i+1]);
        contadorClassificados++;
    }
}

// funcao: logica de mata-mata em cascata
void modoChampions(string listaNomesTimes[], int numTimes) { 
    int corteMataMata = 0; 
    // if/else: define a fase inicial (32, 16, 8, 4)
    if (numTimes >= 32) corteMataMata = 32;
    else if (numTimes >= 16) corteMataMata = 16;
    else if (numTimes >= 8) corteMataMata = 8;
    else if (numTimes >= 4) corteMataMata = 4;
    
    if (corteMataMata < 2) { 
        cout << "Numero de times muito baixo para mata-mata." << endl;
        return; 
    }
    
    cout << endl << "MODO CHAMPIONS (MATA-MATA)" << endl;
    cout << "-----------------------------------" << endl;
    cout << "Passam para o mata-mata: TOP " << corteMataMata << endl;

    // vetor: vetores de string para armazenar os classificados de cada fase
    string times32[32], times16[16], times8[8], times4[4], times2[2], campeao[1]; 

    // for: copia os nomes dos times iniciais para o primeiro vetor de fase
    for(int i=0; i < corteMataMata; i++) {
        if (corteMataMata == 32) times32[i] = listaNomesTimes[i];
        else if (corteMataMata == 16) times16[i] = listaNomesTimes[i];
        else if (corteMataMata == 8) times8[i] = listaNomesTimes[i];
        else if (corteMataMata == 4) times4[i] = listaNomesTimes[i];
    }

    // if: chamadas sequenciais para simular as fases
    if (corteMataMata >= 32) rodadaMataMata(times32, 32, times16, "16-AVOS");
    if (corteMataMata >= 16) rodadaMataMata(times16, 16, times8, "OITAVAS");
    if (corteMataMata >= 8) rodadaMataMata(times8, 8, times4, "QUARTAS");
    if (corteMataMata >= 4) rodadaMataMata(times4, 4, times2, "SEMIFINAL");

    rodadaMataMata(times2, 2, campeao, "FINAL");
    cout << endl << "*** CAMPEAO: " << campeao[0] << " ***" << endl;
}

// funcao: modo customizado
void modoCustom() {
    int quantidadeTimes, tipoFormato; 
    
    cout << endl << "Quantos times? (Min 2, Max 64): ";
    // cin: leitura simples
    cin >> quantidadeTimes; 
    
    // if: tratamento de erro basico
    if (quantidadeTimes < 2 || quantidadeTimes > 64) {
        cout << "Quantidade invalida. Usando padrao 8." << endl;
        quantidadeTimes = 8;
    }

    // vetor: armazena os nomes digitados
    string timesPersonalizados[64]; 
    
    cout << "Digite os nomes:" << endl;
    // for: loop para ler os nomes
    for (int i = 0; i < quantidadeTimes; i++) {
        cout << "Time " << i + 1 << ": ";
        // cin: le o nome do time (uma palavra)
        cin >> timesPersonalizados[i]; 
    }

    cout << endl << "Qual formato?" << endl;
    cout << "1 - Pontos Corridos" << endl;
    cout << "2 - Champions (Mata-mata)" << endl;
    cout << "Opcao: ";
    cin >> tipoFormato;

    // if/else: escolhe entre os modos
    if (tipoFormato == 2) {
        modoChampions(timesPersonalizados, quantidadeTimes);
    } else {
        carregarPontosCorridos("CUSTOM", timesPersonalizados, quantidadeTimes, 4); 
    }
}


// funcao principal
int main() {
    int opcaoMenu = -1; 

    // while: mantem o menu rodando ate o usuario sair
    while (opcaoMenu != 0) { 
        menu();
        cout << "Opcao: ";
        
        cin >> opcaoMenu;
        
        // if/else: selecao do campeonato
        if (opcaoMenu == 1) 
            carregarPontosCorridos("BRASILEIRAO", timesBrasileirao, MAX_TIMES_PADRAO, 4); 
        else if (opcaoMenu == 2) 
            carregarPontosCorridos("LA LIGA", timesLaLiga, MAX_TIMES_PADRAO, 3); 
        else if (opcaoMenu == 3) 
            carregarPontosCorridos("PREMIER LEAGUE", timesPremier, MAX_TIMES_PADRAO, 3); 
        else if (opcaoMenu == 4) 
            modoChampions(timesChampions, MAX_TIMES_CHAMPIONS);
        else if (opcaoMenu == 5) 
            modoCustom();
        else if (opcaoMenu != 0) 
            cout << "Opcao nao existe." << endl;
    }
    
    cout << "Saindo do simulador. Ate mais!" << endl;
    return 0;
}