#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXSZ = 1e3 + 5;
int n,m;

vector<int> adj[MAXSZ];

void addEdge(int u, int v){
    adj[u].push_back(v);
    // adj[v].push_back(u);
}