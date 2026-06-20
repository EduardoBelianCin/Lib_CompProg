#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 2e5 + 7;
vector<int> adj[MAXN];
bool vis[MAXN];   // false para todos

void dfs(int u){
    vis[u] = true;
    for(int v : adj[u]){
        if(!vis[v]) { dfs(v); }
    }
}