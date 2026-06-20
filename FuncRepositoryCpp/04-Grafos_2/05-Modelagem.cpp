#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Modelagem é transformar o problema em outro grafo que represente os estados do problema e permita a utilização dos algoritmos clássicos.

const int n = 2500 + 1;
int parent[n];

int main() {

    vector<vector<ll>> dist(n+1, vector<ll>(n+1, LLONG_MAX));
    vector<vector<tuple<ll,ll>>> adj(n+1);
    priority_queue<tuple<ll,ll,ll>,
        vector<tuple<ll,ll,ll>>,
        greater<tuple<ll,ll,ll>>> pq;

    while(!pq.empty()){
        auto [d,v,c] = pq.top(); pq.pop();

        if(d <= dist[v][c]){
            for(auto [u,w] : adj[v]) {
                if(dist[u][c] > dist[v][c] + w) {
                    dist[u][c] = dist[v][c] + w;
                    pq.push({dist[u][c], u, c});
                }
                if(c < 10){
                    if(dist[u][c+1] > dist[v][c] + (w/2)) {
                        dist[u][c+1] = dist[v][c] + (w/2);
                        pq.push({dist[u][c+1], u, c+1});
                    }
                }
            }
        }
    }
}