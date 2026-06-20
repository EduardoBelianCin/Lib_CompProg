#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// N até mais ou menos 5e3
const int MAXSZ = 1e3 + 5;
const int INF = 2e9;
int g[MAXSZ][MAXSZ];
int n,m;

void init(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            g[i][j] = INF;
        }
    }
}

void addEdge(int u, int v, int w){
    g[u][v] = w;
    // g[v][u] = w;
}

void removeEdge(int u, int v, int w){
    g[u][v] = INF;
    // g[v][u] = INF;
}
