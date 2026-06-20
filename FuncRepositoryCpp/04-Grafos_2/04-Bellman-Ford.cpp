#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int n = 2500 + 1;
int parent[n];

int main() {

    vector<tuple<int,int,ll>> edges;
    vector<ll> dist(n+1, 0);
    // Bellman-Ford
    for(int rep=0;rep<n-1;rep++) {
        for(auto [u,v,w] : edges) {
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                // V foi alcançado por U
                parent[v] = u;
            }
        }
    }

    // Ciclo Negativo?
    bool cicloNegativo = false;
    for(auto [u,v,w] : edges) {
        if(dist[v] > dist[u] + w) {
            cicloNegativo = true;
            parent[v] = u;
        }
    }
}