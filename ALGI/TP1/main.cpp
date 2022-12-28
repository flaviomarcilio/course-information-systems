#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

// Limites Máximos dados no problemas
#define V 10
#define N 1000
#define M 1000

// Determinar pares não alocados
#define UNMATCHED 0

using namespace std;

typedef pair<int,int> ii;

// Armazena a distância entre dois nós
struct percurso
{
    int origem;
    int destino;
    int distancia;
    percurso(int a, int b, int c) : origem(a), destino(b), distancia(c){};
};

// Relaciona o visitante com o nó do grafo
map<int, int> visitantes;
map<int, int>::iterator itV;

// Relaciona a bicicleta com o nó do grafo
map<int, int> bicicletas;
map<int, int>::iterator itB;

// Lista de adjacências - representando o grafo
vector<int> adj[N*M];

// Lista de preferências dos visitantes
vector<ii> prefVis[V];

// Lista de preferências das bicicletas - distâncias
vector<ii> prefBike[V];

// Comprimento de um nó a outro
vector<int> comprimento;

// Marca o nó ao ser visitado
vector<bool> visited;

// Lista com todas as distâncias entre visitantes e bicicletas
vector<percurso> percursos;

// Algoritmo Busca em Largura implementado com uma fila (Firt In - First Out)
void bfs(int s) {
    queue <int> q;
    q.push(s);
    comprimento.assign(N*M, 0);
    visited.assign(N*M, false);
    comprimento[s] = 0;
    visited[s] = true;

    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        for(int i = 0; i < adj[p].size() ; i++)
        {
            int noC = adj[p][i];
            if(visited[noC] == false)
            {
                // Calcula a distância total até o noC somando 1 a distância do nó pai
                comprimento[noC] = comprimento[p]+1;

                // Verifica se o noC é um nó correspondente a uma bicicleta
                // Se corresponde a uma bicicleta armazena a distância no vetor percursos
                itB = bicicletas.find(noC);
                if (itB != bicicletas.end())
                    percursos.push_back(percurso(s, noC, comprimento[noC]));

                // marca o nó como visitado para não ser visitado novamente
                visited[noC] = true;
                q.push(noC);
            }
        }
    }
}

// Função de comparação entre dois visitantes 
// Utilizaa para criar a lista de preferência
bool compareVis(ii a, ii b) 
{
    if (a.second == b.second)
        return a.first < b.first;
    return (a.second > b.second);
}

// Função de comparação entre duas bicicletas
// Utilizada para criar a lista de preferência
bool compareBik(ii a, ii b) 
{
    if (a.second == b.second)
        return (a.first < b.first);
    return (a.second < b.second); 
}

int main(int argc, char const *argv[])
{
    vector<string> aux;
	string x;

    int num, linhas, colunas;
    int grau, vis, bic;

    // Número de visitantes e bicicletas
    cin >> num;

    // Gale-Shapley - Definições Iniciais considerando IDs = 1 a num
    int visList[num+1][num+1];  // Matriz de preferências dos visitantes
    int bikList[num+1][num+1];  // Matriz de preferências das bicicletas
    int visAlocado[num+1]; // Alocação corrente dos visitantes
    int bikAlocada[num+1]; // Alocação corrente das bicicletas
    int visProxEscolha[num+1]; // A próxima bicicleta escolhida

    // Quantidade de linhas e colunas do mapa
    cin >> linhas >> colunas;

    // Para garantir que seja um mapa viável
    if (!linhas && !colunas) return 0;

    // Lendo o mapa
    for (int i = 0 ; i < linhas ; i++)
    {
        cin >> x;
        aux.push_back(x);
    }

    // Lendo as preferências dos visitantes
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            cin >> grau;
            prefVis[i].push_back(make_pair(j, grau));
        }

        // Criando a Ordem de Preferência dos Visitantes
        sort(prefVis[i].begin(), prefVis[i].end(), compareVis);
    }

    // Gale-Shapley - Inicializando a matriz de preferências dos visitantes
    for (int i = 1; i <= num; i++) {
        visAlocado[i] = UNMATCHED; // Definindo não alocado para todos os visitantes
        visProxEscolha[i] = 1;         // A primeira escolha será a primeira da lista
        for(int j = 0; j <= num; j++) {
            visList[i][j] = prefVis[i-1][j-1].first + 1; // Construindo a matriz de preferências
        }
    }

    // Criando o grafo com Listas de Adjacência
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            if (aux[i][j] != '-')
            {
                if (i > 0)
                {
                    // Criando o mapeamento de visitantes e bicicletas
                    vis = (int)aux[i][j];
                    bic = (int)aux[i][j];
                    if (vis >= 97 && vis <= 106)
                        visitantes[i * colunas + j] = vis;
                    if (bic >= 48 && bic <= 57)
                        bicicletas[i * colunas + j] = bic;

                    // Criando a Lista de Adjacência
                    if(aux[i - 1][j] != '-')
                    {
                        adj[i * colunas + j].push_back(colunas * (i - 1) + j);

                    }
                }
                if (i < linhas - 1)
                {
                    // Criando o mapeamento de visitantes e bicicletas
                    vis = (int)aux[i][j];
                    bic = (int)aux[i][j];
                    if (vis >= 97 && vis <= 106)
                        visitantes[i * colunas + j] = vis;
                    if (bic >= 48 && bic <= 57)
                        bicicletas[i * colunas + j] = bic;

                    // Criando a Lista de Adjacência
                    if(aux[i + 1][j] != '-')
                    {
                        adj[i * colunas + j].push_back(colunas * (i + 1) + j);
                    }
                }
                if (j > 0)
                {
                    // Criando o mapeamento de visitantes e bicicletas
                    vis = (int)aux[i][j];
                    bic = (int)aux[i][j];
                    if (vis >= 97 && vis <= 106)
                        visitantes[i * colunas + j] = vis;
                    if (bic >= 48 && bic <= 57)
                        bicicletas[i * colunas + j] = bic;

                    // Criando a Lista de Adjacência
                    if(aux[i][j-1] != '-')
                    {
                        adj[i * colunas + j].push_back(colunas * i + j - 1);
                    }
                }
                if (j < colunas - 1)
                {
                    // Criando o mapeamento de visitantes e bicicletas
                    vis = (int)aux[i][j];
                    bic = (int)aux[i][j];
                    if (vis >= 97 && vis <= 106)
                        visitantes[i * colunas + j] = vis;
                    if (bic >= 48 && bic <= 57)
                        bicicletas[i * colunas + j] = bic;

                    // Criando a Lista de Adjacência
                    if(aux[i][j+1] != '-')
                    {
                        adj[i * colunas + j].push_back(colunas * i + j + 1);
                    }
                }
            }
        }
    }

    // Calculando as distâncias entre cada visitante e as bicicletas
    for (auto& x: visitantes)
    {
        bfs(x.first);
    }

    // Criando a estrutura para facilitar a criação da lista de preferência das biciletas
    for (int i = 0; i < percursos.size(); i++)
    {
        int origem = percursos[i].origem;
        int destino = percursos[i].destino;
        int distancia = percursos[i].distancia;

        itB = bicicletas.find(destino);
        itV = visitantes.find(origem);
        prefBike[itB->second - 48].push_back(make_pair(itV->second, distancia));
    }

    for (int i = 0; i < num; i++)
    {
        // Criando a Ordem de Preferência das bicicletas
        sort(prefBike[i].begin(), prefBike[i].end(), compareBik);
    }

    // Gale-Shapley - Inicializando a matriz de preferências para as bicicletas
    for (int i = 1; i <= num; i++) 
    {
        bikAlocada[i] = UNMATCHED; // Definindo não alocada para todas as bicicletas
        for (int j = 0; j <= num; j++) 
        {
            bikList[i][j] = prefBike[i-1][j-1].first - 96; // Construindo a matriz de preferências
        }
    }

    // Algoritmo de Gale-Shapley
    bool VisLivre = true;
    int v = 1;
    while (VisLivre)
    {
        VisLivre = false;

        int b = visList[v][visProxEscolha[v]++];  // Bicicleta escolhida
        // Bicicleta não alocada
        if (bikAlocada[b] == UNMATCHED) 
        {
            // Alocação
            bikAlocada[b] = v;
            visAlocado[v] = b;
        } 
        else  // Bicicleta alocada
        {
            // Verifica se o visitante está mais perto do que o que foi alocado para a bicicleta
            bool existeOpcaoMelhor = false;
            for (int y = 1; y <= num; y++) 
            {
                if (bikList[b][y] == bikAlocada[b]) 
                {
                    existeOpcaoMelhor = false; break;
                }
                if (bikList[b][y] == v) 
                {
                    existeOpcaoMelhor = true; break;
                }
            }
            if (existeOpcaoMelhor) 
            {
                // Aloca a bicicleta com o novo visitante e desaloca o antigo
                visAlocado[bikAlocada[b]] = UNMATCHED;
                bikAlocada[b] = v;
                visAlocado[v] = b;
            }
        }

        // Encontra um novo visitante livre
        for(int x = 1; x <= num; x++) {
            if(visAlocado[x] == UNMATCHED) {
                v = x;
                VisLivre = true;
                break;
            }
        }
    }

    // Apresenta o resultado da alocação
    for(int i = 1; i <= num;  i++) {
        cout << (char)(i + 96) << " " << visAlocado[i] - 1 << endl;
    }

    return 0;
}