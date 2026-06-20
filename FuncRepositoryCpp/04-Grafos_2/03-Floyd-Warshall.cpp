#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int n = 300 + 10;

int main() {
    vector<vector<ll>> dist(n+1, vector<ll>(n+1));
    vector<tuple<ll,int,int>> arestas;

    // Inicializa Dist com LLONG MAX
    for(int i=1;i<=n;i++) { for(int j=1;j<=n;j++) { dist[i][j] = LLONG_MAX; } }
    //dist[i][j] deve ser 0 se (i==j)
    for(int i=1;i<=n;i++) { dist[i][i] = 0; }
    //Cuidado com múltiplas arestas (pegue o mínimo) 
    for(auto& [cost,u,v] : arestas) { dist[u][v] = dist[v][u] = min(dist[u][v], cost); }


    for(int k=1;k<=n;k++) {
        for(int u=1;u<=n;u++) {
            for(int v=1;v<=n;v++){
                if((dist[u][k] != LLONG_MAX) && (dist[k][v] != LLONG_MAX)) {
                    dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
                }
            }
        }
    }
}
