#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// N até mais ou menos 5e3
const int MAXSZ = 1e3 + 5;
bool g[MAXSZ][MAXSZ];

void addEdge(int u, int v) {
    g[u][v] = 1;
    // g[v][u] = 1;
}

void removeEdge(int u, int v) {
    g[u][v] = 0;
    // g[v][u] = 0;
}