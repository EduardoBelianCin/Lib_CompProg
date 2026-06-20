#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pli pair<ll,int>

const int MAXN = 1e5 + 10;

vector<ll> djikstra(vector<vector<pli>> adj) {
    vector<ll> dist(MAXN, LLONG_MAX);
    priority_queue<pli, vector<pli>, greater<pli>> pq;

    // custo e inicial
    pq.push({0,1});
    dist[1] = 0;

    while(!pq.empty()) {
        auto [total, atual] = pq.top(); pq.pop();

        if(total <= dist[atual]) {
            for(auto [peso, proximo] : adj[atual]) {
                if(dist[proximo] > dist[atual] + peso) {
                    dist[proximo] = dist[atual] + peso;
                    pq.push({dist[proximo], proximo});
                }
            }
        }
    }
    return dist;
}



int main() {
    int n = 1e5 + 10;
    vector<ll> dist(n+1, LLONG_MAX);
    vector<vector<pair<int,ll>>> adj(n+1);
    priority_queue<pli, vector<pli>, greater<pli>> pq;

    // custo e inicial
    pq.push({0,1});
    dist[1] = 0;

    while(!pq.empty()) {
        auto [d,u] = pq.top(); pq.pop();

        if(d <= dist[u]) {
            for(auto [v,w] : adj[u]) {
                if(dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
    }
}
