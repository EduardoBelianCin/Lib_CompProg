#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
const int MAXN = 2e5 + 7;
vector<int> adj[MAXN];
int componente[MAXN];

void dfs(int u, int comp) {
    componente[u] = comp;
    for(int v : adj[u]) {
        if(componente[v] == -1) {
            dfs(v, comp);
        }
    }
}

void init(){
    memset(componente, -1, sizeof(componente));

    int num = 0;
    for(int i=1;i<=n;i++) {
        if(componente[i] == -1) {
            num++;
            dfs(i, num);
        }
    }
}


// Um componente conexo é um subconjunto de vértices do grafo
// original em que todos conseguem chegar uns aos outros.

// Podemos encontrar o componente conexo
// de um vértice usando apenas uma DFS ou BFS.

// Em matrizes, essa mesma ideia recebe o nome de Flood Fill.

// A intuição é que funciona como "pintar um desenho dentro das linhas".