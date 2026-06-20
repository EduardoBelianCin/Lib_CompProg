#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 2e5 + 7;
vector<int> adj[MAXN];
int dist[MAXN];

void MultiSourceBFS(const vector<int>& Vertices) {
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    for(int V : Vertices) {
        dist[V] = 0;
        q.push(V);
    }

    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : adj[u]) {
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

// OBS:

// Problema: Dado um grafo com K vértices marcados.
// Queremos saber, para cada vértice, a menor distância até algum vértice marcado.

// Solução: No início da BFS, defina a distância de cada vértice marcado como 0.

// Inicie a fila da BFS já contendo todos os vértices marcados.

// Intuição: As camadas da BFS vão se formar
// ao redor de cada vértice marcado, simultaneamente.

// Assim, qualquer vértice será alcançado primeiro
// justamente pelo vértice marcado que está mais próximo dele.

// Observação: Cada vértice continua sendo visitado apenas uma única vez.