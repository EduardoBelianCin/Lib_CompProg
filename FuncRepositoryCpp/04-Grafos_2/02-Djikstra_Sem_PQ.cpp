#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int n = 1e5 + 10;
vector<ll> dist(n + 1, LLONG_MAX);
vector<bool> vis(n + 1, false);
vector<vector<tuple<ll, ll>>> adj(n + 1);

int main() {

    // Exemplo: setar a distância inicial do vértice 1
    dist[1] = 0;

    // Dijkstra O(n^2)
    for (int i = 1; i <= n; i++) {

        int v = -1;
        ll mn = LLONG_MAX;

        // encontra vértice com menor distância não visitado
        for (int j = 1; j <= n; j++) {
            if ((!vis[j]) && (dist[j] < mn)) {
                mn = dist[j];
                v = j;
            }
        }

        if (v == -1) break;
        vis[v] = true;

        // relaxar arestas do vértice v
        for (auto [u, w] : adj[v]) {
            if (dist[u] > dist[v] + w) {
                dist[u] = dist[v] + w;
            }
        }
    }

    return 0;
}
