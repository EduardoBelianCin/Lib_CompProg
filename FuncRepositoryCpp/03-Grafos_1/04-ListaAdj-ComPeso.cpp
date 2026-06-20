#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pii pair<int,int>

const int MAXSZ = 1e3 + 5;
int n,m;

vector<pii> adj[MAXSZ];

void addEdge(int u, int v, int w){
    adj[u].push_back({v,w});
    // adj[v].push_back({u,w});
}
