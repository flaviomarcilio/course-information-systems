#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define CIDADES 1001
#define RODOVIAS 10001

struct aresta
{
    int origem, destino, peso;
};

// Lista de Adjacências para representar o grafo
vector<aresta> adj[CIDADES];

// Matriz para marcar quais arestas foram visitadas
bool arestaVisitada[CIDADES][CIDADES];

// Máximo peso que é possível chegar no nó
vector<int> pesoMaximo;

// Algoritmo Busca em Largura implementado com uma fila (Firt In - First Out)
void bfs(int s) {
    queue<int> fila;
    fila.push(s);

    pesoMaximo.assign(CIDADES, 0);
    fill(*arestaVisitada, *arestaVisitada + CIDADES*CIDADES, false);

    while(!fila.empty())
    {
        int origem = fila.front();
        fila.pop();
        for(int i = 0; i < adj[origem].size() ; i++)
        {
            aresta *edge = &adj[origem][i];

            if (!arestaVisitada[edge->origem][edge->destino])
            {
                // Coloca o nó destino na fila para percorrer seus nós adjacentes
                fila.push(edge->destino);

                // Marca a aresta como visitada para não ser visitada novamente
                arestaVisitada[edge->origem][edge->destino] = true;

                int pesoEnviado = 0;
                if (edge->origem == s)
                    pesoEnviado = edge->peso;
                else
                    pesoEnviado = pesoMaximo[edge->origem];
                
                int pesoInicial = pesoMaximo[edge->destino];

                // Determina o peso máximo que pode chegar até o nó destino
                if (pesoEnviado > edge->peso && edge->peso > pesoMaximo[edge->destino])
                    pesoMaximo[edge->destino] =  edge->peso;
                else if (pesoEnviado <= edge->peso && pesoEnviado > pesoMaximo[edge->destino])
                    pesoMaximo[edge->destino] = pesoEnviado;

                int pesoFinal = pesoMaximo[edge->destino];

                // Quando o peso máximo que chega no nó aumenta, habilita a busca nas
                // arestas adjacentes permitindo encontrar um novo caminho melhor
                if (pesoInicial != 0 && pesoFinal > pesoInicial)
                    for (int j = 0; j <= CIDADES; j++)
                        arestaVisitada[edge->destino][j] = false;

            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int cidades, rodovias, consultas;
    int u, v, w;
    aresta edge;
    int origem, destino;

    cin >> cidades >> rodovias >> consultas;

    // Construção do grafo
    for (int i = 0; i < rodovias; i++)
    {
        cin >> u >> v >> w;
        edge.origem = u;
        edge.destino = v;
        edge.peso = w;
        adj[u].push_back(edge);
    }

    // Determina o maior peso permitido na rota entre duas cidades
    for (int i = 0; i < consultas; i++)
    {
        cin >> origem >> destino;

        bfs(origem);

        cout << pesoMaximo[destino] << endl;
    }   
    
    return 0;
}