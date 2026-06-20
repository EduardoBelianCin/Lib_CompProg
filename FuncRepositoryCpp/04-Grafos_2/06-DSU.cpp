#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e5 + 7;
int pai[MAXN], sz[MAXN];

int find(int u) {
    if(u==pai[u]) { return u; }
    return pai[u] = find(pai[u]);
}

void join(int u, int v) {
    u = find(u);
    v = find(v);
    if(u == v) { return; }
    if(sz[u] < sz[v]) { swap(u,v); }
    pai[v] = u;
    sz[u] += sz[v];
}

int main() {
    int n;
    // Inicialiaza os Grupos
    for(int u=1;u<=n;u++) {
        pai[u] = u;
        sz[u] = 1;
    }
}