#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>   

using namespace std;

// configs
int QTD_BR = 20;
int QTD_LALIGA = 20;
int QTD_PREMIER = 20;
int QTD_CHAMPIONS = 36;
int MAX_CUSTOM = 64; 

// pontos
int P_VIT = 3;
int P_EMP = 1;

// listas de times
string timesBR[] = {
    "Palmeiras", "Flamengo", "Cruzeiro", "Mirassol", "Bahia",
    "Botafogo", "Fluminense", "Sao Paulo", "Vasco", "Corinthians",
    "Gremio", "Ceara", "Atletico Mineiro", "RB Bragantino",
    "Internacional", "Santos", "Vitoria", "Fortaleza",
    "Juventude", "Sport"
};

string timesLaLiga[] = {
    "Real Madrid", "Barcelona", "Vilarreal", "Atletico de Madrid",
    "Real Betis", "Espanyol", "Getafe", "Alaves", "Elche",
    "Rayo Vallencano", "Athletic Club", "Celta", "Sevilla",
    "Real Sociedad", "Osasuna", "Levante", "Mallorca", "Valencia",
    "Real Oviedo", "Girona"
};

string timesPremier[] = {
    "Arsenal", "Manchester City", "Liverpool", "Sunderland",
    "Bournemouth", "Tottenham", "Chelsea", "Manchester United",
    "Crystal Palace", "Brighton", "Aston Villa", "Brentford",
    "Newcastle", "Everton", "Fullham", "Leeds", "Burnley",
    "West Ham", "Nottingham Forest", "Wolves"
};

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

void menu() {
    cout << "\n=== SISTEMA DE CAMPEONATOS ===" << endl;
    cout << "1 - Brasileirao" << endl;
    cout << "2 - La Liga" << endl;
    cout << "3 - Premier League" << endl;
    cout << "4 - Champions League" << endl;
    cout << "5 - Criar o seu (Custom)" << endl;
    cout << "0 - Sair" << endl;
    cout << "==============================" << endl;
}

// Funcao pra mostrar tabela, classificados e rebaixados
void verTabela(string t[], int p[], int n, int n_rebaixados) {
    // vetores auxiliares pra ordenar sem baguncar o original
    int p_ord[n];
    string t_ord[n];
    
    for (int i = 0; i < n; i++) {
        p_ord[i] = p[i];
        t_ord[i] = t[i];
    }
    
    // ordenando (selection sort)
    for (int i = 0; i < n - 1; i++) {
        int maior = i;
        for (int j = i + 1; j < n; j++) {
            if (p_ord[j] > p_ord[maior]) {
                maior = j;
            }
        }
        if (maior != i) {
            swap(p_ord[i], p_ord[maior]);
            swap(t_ord[i], t_ord[maior]);
        }
    }

    cout << "\n TABELA FINAL" << endl;
    cout << "Pos | Time                | Pts" << endl;
    cout << "---------------------------------" << endl; 

    for (int i = 0; i < n; i++) {
        cout << i + 1;
        if (i + 1 < 10) cout << " ";
        cout << " | " << t_ord[i];
        
        // espacamento pra ficar bonito
        for(int s = 0; s < 20 - (int)t_ord[i].length(); s++) cout << " ";
        
        cout << " | " << p_ord[i] << endl;
    }
    cout << "=================================" << endl;
    cout << "CAMPEAO: " << t_ord[0] << endl; 
    
    // so mostra g4 e z4 se tiver time suficiente
    if (n >= 8) {
        cout << "\n[ G4 - Classificados ]" << endl;
        for (int i = 0; i < 4; i++) cout << i+1 << "o - " << t_ord[i] << endl;

        cout << "\n[ Z" << n_rebaixados << " - Rebaixados ]" << endl;
        // logica pra pegar os ultimos
        int inicio_z = n - n_rebaixados;
        if (inicio_z < 4) inicio_z = 4; // protecao

        for (int i = inicio_z; i < n; i++) {
            cout << i+1 << "o - " << t_ord[i] << endl;
        }
    }
}

void jogoSimples(int pts[], int t1, int t2, string t[]) {
    int r = rand() % 3; 
    cout << t[t1] << " x " << t[t2] << ": ";

    if (r == 0) { // empate
        pts[t1] += P_EMP;
        pts[t2] += P_EMP;
        cout << "Empate (1-1)" << endl;
    } else if (r == 1) { // t1 venceu
        pts[t1] += P_VIT;
        cout << t[t1] << " ganhou (2-0)" << endl;
    } else { // t2 venceu
        pts[t2] += P_VIT;
        cout << t[t2] << " ganhou (0-1)" << endl;
    }
}

// logica mata mata
string mataMata(string tA, string tB) {
    int idaA = rand() % 4, idaB = rand() % 4;
    int voltaA = rand() % 4, voltaB = rand() % 4; 
    
    int totA = idaA + voltaA;
    int totB = idaB + voltaB;

    cout << " > " << tA << " vs " << tB << " | Placar: " << totA << " x " << totB << " | Passou: ";
    
    if (totA > totB) { cout << tA << endl; return tA; }
    else if (totB > totA) { cout << tB << endl; return tB; }
    else {
        // sorteio se empatar tudo
        if (rand() % 2 == 0) { cout << tA << " (Penaltis)" << endl; return tA; }
        else { cout << tB << " (Penaltis)" << endl; return tB; }
    }
}

// --- CORREÇÃO FEITA AQUI: adicionei espaço "string venc[]" ---
void rodadaMataMata(string t[], int n, string venc[], string nome) {
    if (n < 2 || n % 2 != 0) return; 
    cout << "\n--- " << nome << " (" << n << " Times) ---" << endl;
    int c = 0;
    for (int i = 0; i < n; i += 2) {
        venc[c] = mataMata(t[i], t[i+1]);
        c++;
    }
}

// Modo Champions Dinamico
void modoChampions(string t_orig[], int qtd) {
    cout << "\n--- MODO CHAMPIONS (MATA-MATA) ---\n" << endl;

    for (int i = 0; i < qtd; i++) cout << i + 1 << " - " << t_orig[i] << endl;
    
    int esc;
    while (true) {
        cout << "\nEscolha seu time (numero): ";
        if (cin >> esc) {
            if (esc >= 1 && esc <= qtd) break;
            else cout << "Numero invalido..." << endl;
        } else {
            cout << "Digite so o numero." << endl;
            cin.clear(); cin.ignore(256, '\n');
        }
    }
    cout << "Time escolhido: " << t_orig[esc - 1] << endl;

    // Fase de liga rapida
    int p[qtd];
    string t_ord[qtd];
    int p_ord[qtd];
    
    for(int i=0; i<qtd; i++) p[i] = 0;

    cout << "\n[ Simulando Fase de Liga... ]" << endl;
    int jogos = (qtd < 8) ? (qtd - 1) : 6;
    
    for (int i = 0; i < qtd; i++) {
        for (int k = 0; k < jogos; k++) {
            int x = rand() % 3;
            if (x == 1) p[i] += 3; else if (x == 0) p[i] += 1;
        }
    }

    // ordenar liga pra definir quem passa
    bool usado[qtd]; 
    for(int i=0; i<qtd; i++) usado[i]=false;
    
    for (int i = 0; i < qtd; i++) {
        int max = -1, idx = -1;
        for (int j = 0; j < qtd; j++) {
            if (p[j] > max && !usado[j]) { max = p[j]; idx = j; }
        }
        if (idx != -1) {
            p_ord[i] = max; t_ord[i] = t_orig[idx]; usado[idx] = true;
        }
    }

    cout << "\n--- Classificacao Liga ---" << endl;
    for (int i = 0; i < qtd; i++) cout << i+1 << ". " << t_ord[i] << " (" << p_ord[i] << " pts)" << endl;

    // define o corte
    int corte = 2;
    if (qtd >= 32) corte = 32;
    else if (qtd >= 16) corte = 16;
    else if (qtd >= 8) corte = 8;
    else if (qtd >= 4) corte = 4;

    cout << "\nPassam para o mata-mata: TOP " << corte << endl;

    string t32[32], t16[16], t8[8], t4[4], t2[2], camp[1];

    // cascata de fases
    if (corte == 32) {
        for(int i=0;i<32;i++) t32[i]=t_ord[i];
        rodadaMataMata(t32, 32, t16, "16-AVOS");
    } else if (corte >= 16 && qtd < 32) {
        for(int i=0;i<16;i++) t16[i]=t_ord[i];
    }

    if (corte >= 16) rodadaMataMata(t16, 16, t8, "OITAVAS");
    else if (corte == 8) for(int i=0;i<8;i++) t8[i]=t_ord[i];

    if (corte >= 8) rodadaMataMata(t8, 8, t4, "QUARTAS");
    else if (corte == 4) for(int i=0;i<4;i++) t4[i]=t_ord[i];

    if (corte >= 4) rodadaMataMata(t4, 4, t2, "SEMIFINAL");
    else if (corte == 2) for(int i=0;i<2;i++) t2[i]=t_ord[i];

    rodadaMataMata(t2, 2, camp, "FINAL");
    cout << "\n*** CAMPEAO: " << camp[0] << " ***" << endl;
}

// Selecao padrao (pontos corridos)
void carregarCamp(string nome, string t[], int n, int n_reb) {
    cout << "\nModo: " << nome << " (" << n << " times)" << endl;

    for (int i = 0; i < n; i++) cout << i + 1 << " - " << t[i] << endl;

    int esc;
    while (true) {
        cout << "\nEscolha seu time (numero): ";
        if (cin >> esc) {
            if (esc >= 1 && esc <= n) break;
            else cout << "Numero invalido." << endl;
        } else {
            cout << "Digite apenas numeros." << endl;
            cin.clear(); cin.ignore(256, '\n');
        }
    }

    cout << "Voce pegou: " << t[esc - 1] << endl; 
    cout << "\nSimulando jogos (ida e volta)..." << endl;

    int p[n];
    for (int i = 0; i < n; i++) p[i] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            jogoSimples(p, i, j, t); 
            jogoSimples(p, j, i, t); 
        }
    }
    
    verTabela(t, p, n, n_reb);
}

void modoCustom() {
    int qtd;
    cout << "\nQuantos times? (Max " << MAX_CUSTOM << "): ";
    
    while (!(cin >> qtd) || qtd < 2 || qtd > MAX_CUSTOM) {
        cout << "Quantidade invalida: ";
        cin.clear(); cin.ignore(256, '\n');
    }
    cin.ignore(256, '\n'); 

    string t[qtd];
    cout << "Digite os nomes:" << endl;
    for (int i = 0; i < qtd; i++) {
        cout << "Time " << i + 1 << ": ";
        getline(cin, t[i]);
    }

    int tipo;
    cout << "\nQual formato?" << endl;
    cout << "1 - Pontos Corridos" << endl;
    cout << "2 - Champions (Mata-mata)" << endl;
    cout << "Opcao: ";
    if (!(cin >> tipo)) tipo = 1;

    if (tipo == 2) {
        modoChampions(t, qtd);
    } else {
        carregarCamp("CUSTOM", t, qtd, 4); // padrao 4 rebaixados no custom
    }
}

int main() {
    srand(time(0));
    int op;

    while (true) {
        menu();
        cout << "Opcao: ";
        if (!(cin >> op)) {
            cout << "Digite um numero valido." << endl;
            cin.clear(); cin.ignore(256, '\n'); 
            continue; 
        }

        if (op == 0) break; 
        else if (op == 1) carregarCamp("BRASILEIRAO", timesBR, QTD_BR, 4);
        else if (op == 2) carregarCamp("LA LIGA", timesLaLiga, QTD_LALIGA, 3);
        else if (op == 3) carregarCamp("PREMIER LEAGUE", timesPremier, QTD_PREMIER, 3);
        else if (op == 4) modoChampions(timesChampions, QTD_CHAMPIONS);
        else if (op == 5) modoCustom();
        else cout << "Opcao nao existe." << endl; 
    }
    return 0;
}