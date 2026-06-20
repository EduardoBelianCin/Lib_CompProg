#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 2e5 + 7;
vector<int> adj[MAXN];
bool vis[MAXN];
vector<int> ciclo;

int dfs(int atual, int anterior) {
    if(vis[atual]) { return atual; }    // ciclo encontrado: retorna início do ciclo
    vis[atual] = true;

    for(int nxt : adj[atual]) {
        if(nxt == anterior) { continue; }
        int fim = dfs(nxt,atual);

        if(fim == -2) { return -2; }    // ciclo já fechado e propagando término
        if(fim != -1) {
            ciclo.push_back(atual);
            if(atual == fim) { return -2; }    // ciclo fechado completamente
            else { return fim; }    // ainda estamos subindo no ciclo
        }
    }
    return -1;    // não encontrou ciclo pelo caminho
}

// OBS:

// Para encontrar ciclos em um grafo não direcionado,
// podemos usar uma busca em profundidade (DFS).

// Começamos a percorrer o grafo visitando vértices livremente.

// Se, em algum momento, chegarmos a um vértice que já foi visitado
// e não é o vértice anterior (de onde viemos),
// isso indica que existe um ciclo.

// Nesse caso, podemos voltar pelo caminho percorrido
// até reencontrar o mesmo vértice
// e registrar todos os nós que fazem parte do ciclo.