#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(a) (a).begin(),(a).end()

// Para encontrar uma MST podemos usar o algoritmo guloso de kruskal.
// Iterando pelas arestas ordenadas pelo custo, se a aresta atual conecta componentes distintos, adicionamos ela à resposta. Isto é, não forma um ciclo na árvore!
// Para verificar se um ciclo será formado, usamos DSU!

// N-1 ARESTAS = ARVORE
// MST = ARVORE COM MENOR CUSTO

const int MAXN = 1e5 + 7;
int pai[MAXN], sz[MAXN];

int find(int u){
    if(u==pai[u]) { return u; }
    return pai[u] = find(pai[u]);
}

void join(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v) { return; }
    if(sz[u] < sz[v]) { swap(u,v); }
    pai[v] = u;
    sz[u] += sz[v];
}

int main() {
    int n,m;

    vector<tuple<ll,int,int>> arestas;

    // Ordena por Custo das Estradas
    sort(all(arestas));
    ll totalCost = 0;

    // Inicialiaza os Grupos
    for(int u=1;u<=n;u++) {
        pai[u] = u;
        sz[u] = 1;
    }

    int arestas_usadas = 0;
    for(auto [cost,u,v] : arestas) {
        if(find(u) != find(v)){
            join(u,v);
            totalCost += cost;
            arestas_usadas++;
        }
    }

    if(arestas_usadas == n-1) { cout << totalCost << "\n"; }
    else { cout << "IMPOSSIBLE\n"; }
}